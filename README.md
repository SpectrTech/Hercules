## Hercules - Toolkit v0.0.1b

**DISCLAIMER**: This tool is for educational purposes **ONLY**. (Read the LICENSE)

Hercules is a tool to hide your identity online.
It changes your tor proxies automaticly every 5 seconds,
(you can change that in the source code. #define DELAY ...)
To hide your identity you will need to use the proxy running
on socks4://127.0.0.1:9050

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
