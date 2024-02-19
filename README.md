## Hercules - Toolkit v0.0.2b

**DISCLAIMER**: This tool is for educational purposes **ONLY**. (Read the LICENSE)

Hercules is a tool to hide your identity online.
It changes your tor proxies automaticly every 20 seconds,
(you can change that in the source code. #define DELAY ...)
To hide your identity you will need to use the proxy running
on socks4://127.0.0.1:9050
Remember that some servers are blocking requests coming in by
tor proxies, so if a page does not load, please wait until Hercules
gives your a new updated IP-Address. Some servers also have a outdated
list of tor proxies.

### Installation:
```
apt update
apt install gcc tor -y
git clone https://github.com/RussianHzcker/Hercules.git
cd Hercules
make
./hercules.elf
```

### How to use:
```
./hercules.elf
proxychains ...
```
Copyright (c) RussianHzcker 2024
