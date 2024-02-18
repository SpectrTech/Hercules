#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 5 // Change this if you want to
#define TOR_SERVICE_FILE "/usr/lib/systemd/system/tor.service"
#define BUFFER 1024

int banner(void) {
    printf("  ___ ___                             .__                 \n");
    printf(" /   |   \\   ___________   ____  __ __|  |   ____   ______\n");
    printf("/    ~    \\_/ __ \\_  __ \\_/ ___\\|  |  \\  | _/ __ \\ /  ___/\n");
    printf("\\    Y    /\\  ___/|  | \\/\\  \\___|  |  /  |_\\  ___/ \\___ \\ \n");
    printf(" \\___|_  /  \\___  >__|    \\___  >____/|____/\\___  >____  >\n");
    printf("       \\/       \\/            \\/                \\/     \\/\n");
    printf(" Version 0.0.1b\n\n");
    return 0;
}

int main(int argc, char* argv[]) {
    banner();

    const char* service_name = "tor.service";
    if (access(TOR_SERVICE_FILE, F_OK) == 0) {
        printf("[+] Tor service file found! Path: %s\n", TOR_SERVICE_FILE);
    } else {
        printf("[!] Tor service file not found! DEFINED: %s\n", TOR_SERVICE_FILE);
        exit(EXIT_FAILURE);
    }

    printf("[*] Checking the status of the tor.service ...\n");
    
    char command[BUFFER];
    snprintf(command, sizeof(command), "systemctl is-active %s", service_name);
    int status = system(command);
    if (status == 0) {
        printf("[+] Tor.service is running!\n");
    } else {
        printf("[!] Tor.service is not running!\n");
        printf("[*] Starting tor.service ...\n");
        system("systemctl start tor.service --now");
    }

    while (1 == 1) {
        printf("[*] Changing tor proxies ...\n");
        system("systemctl restart tor.service --now");
        printf("[*] Tor proxies successfully changed!\n");
        sleep(DELAY);
    }
    return 0;
}