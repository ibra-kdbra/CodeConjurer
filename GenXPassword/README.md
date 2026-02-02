<h1 align="center">GenXPassword</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Windows-0078d7?style=for-the-badge&logo=windows&logoColor=ffffff" alt="Windows">
  <img src="https://img.shields.io/badge/mac%20OS-313131?style=for-the-badge&logo=macos&logoColor=d7d7d7" alt="macOS">
  <img src="https://img.shields.io/badge/Linux-ffffff?style=for-the-badge&logo=linux&logoColor=000000" alt="Linux">
  <br>
</p>

<p align="center"><i>Shuffled random and customizable password generator.</i></p>


<div align="center">
  
  <img alt="light" width="350" src="./screenshots/1.png"> <img alt="dark" width="350" src="./screenshots/2.png">
</div>

 
## Features
* Support for languages: Arabic, English, French, Japanese, Spanish.
* Generates passwords of variable length, from 1 to 512 characters.
* Support for custom characters.
* TrayIcon Available
* Modular source code
* Cross-Platform
  - Windows, MacOS and Linux.

<div  align="center" >
  <img alt="languages" width="250" src="./screenshots/languages.png">
</div>

## Requirements
**Windows:** No requirements<br>
**Linux:** Any X11/Xorg-based windowing system, QT-6<br>
**MacOS:** Unknown.

## Usage & build

```bash
qmake
make
./build/bin/GenXPassword
```

## Installation
Open a terminal in the root folder of **GenXPassword**, then follow the instructions for your operating system.

### Unix like systems

For Arch and Arch-based systems:
```bash
chmod +x ./install_scripts/install.sh
sudo ./install_scripts/install.sh
```
For Debian and Debian-based systems (Ubuntu, Mint, etc.):
```bash
chmod +x ./install_scripts/install_debian.sh
sudo ./install_scripts/install_debian.sh
```
<!--- ### Windows TODO --->

### MacOS

```bash
chmod +x ./install_scripts/install_macos.sh
sudo ./install_scripts/install_macos.sh
```
