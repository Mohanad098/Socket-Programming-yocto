# IoT Device Communication System Using C++ with Yocto
--------------------------------------
## Overview
### This project demonstrates an IoT device communication system developed in C++, utilizing Yocto for creating a custom Linux environment. The system supports both TCP and UDP communication channels and is designed for deployment on a Raspberry Pi 4 or for testing in QEMU.
-----------------------------------------
## Project Structure

The project's class structure centers around a Socket interface with specific implementations for TCP and UDP communications. The Channel class provides a common base for server and client operations, allowing shared functionality, while the start function is implemented separately by each derived class for distinct server and client behaviors.

Socket Interface: Defines a common API for TCP and UDP implementations.
TCP/UDP Classes: Implement the specific functionalities for each protocol.
Channel Class: Provides core functionality, managing a socket pointer to interact with protocol-specific methods.
### For more detailed function descriptions, see the UML figure.
--------------------------------------
## Development Environment Setup
To set up the development environment on QEMU with Yocto, follow these steps:

1. Install Dependencies
Ensure you have all necessary dependencies for Yocto development.

2. Clone Yocto and Checkout Branch

```bash
mkdir yocto && cd yocto
git clone https://github.com/yocto/yocto.git
git checkout kirkstone
```
3. Configure Project and Machine
Edit the local.conf file to specify the machine and project name.

4. Source and Build
Return to the yocto directory and set up the environment:

```bash
source oe-init-build-env
bitbake core-image-minimal
```
5. Run QEMU
Launch QEMU for the selected machine and environment.

## Usage Instructions
1. Setting Up the Application
Navigate to the recipes-example in poky/meta/final-project/files and follow these steps:

```bash
mkdir -p build && cd build
cmake ..
make
```
2. Running TCP Communication
To start the TCP communication:

- On QEMU (Yocto):

1) Source the build environment.
2) Run bitbake and launch QEMU.
3) Execute the TCP_server binary.

- On Ubuntu:

1) Navigate to Application/out in the terminal.
2) Run the TCP_client binary.
The server and client will establish a TCP connection and exchange data.

3. Running UDP Communication
For UDP, follow the same steps as TCP or continue from the previous setup:

1) On QEMU: Run the UDP_server binary.
2) On Ubuntu: Open two terminal windows in Application/out and run UDP_client1 in one and UDP_client2 in the other.
