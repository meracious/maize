# maize
A 64-bit kernel by hobbyists.

To be edited by Axarva and Ayush:p

## About
By axarva

## Build Instructions
Dependencies for setting up build environment-
- libuuid
- libfuse
- pkgconfig
These are available on all distros.
For more instrcutions see [echFS GitHub page](https://github.com/echfs/echfs)

Programs reuired-
- GNU Make
- QEMU
- GCC 10+
- NASM
- Parted

Clone this repository with-
```
git clone --recurse-submodules https://github.com/meracious/maize.git
```
For the first time run 
```
make setup
```
as root to build limine and echFS utils

To build the kernel itself run `make` in project's root.
Run the kernel with `make run`

## Contributing
By axarva :p lol
Discord etc

## In Action
By clawbhaiya
