<div align="center">
<h1>maize</h1>
A 64-bit kernel by hobbyists.
</div>

## About

Maize is a project in it's infancy, created by 3 people as a hobby while learning C and C++.
It probably will never be a kernel ready for daily use in a productive system (although if
it ever becomes one, we will be pleasantly surprised), and is intended solely as a hobby and learning project.

![image](https://user-images.githubusercontent.com/65955464/124764901-1571ef00-df53-11eb-8960-c5c13602c6c3.png)

## Build Instructions

### Dependencies

#### For Build environment:

- libuuid
- libfuse
- pkgconfig

For more instructions see [echFS GitHub page](https://github.com/echfs/echfs)

#### For Build:

- GNU Make
- QEMU
- GCC 10+
- NASM
- Parted

### Building

Clone this repository:

```shell
git clone --recurse-submodules https://github.com/meracious/maize.git
```

Move to the cloned repository:

```shell
cd maize
```

Run the following command as root to build limine and echFS utils:

```shell
make setup
```

Build the kernel:

```shell
make
```

Run the kernel with qemu:

```shell
make run
```

## Contributing

Open up a PR on this repository. To discuss stuff with us, contact us via email.
