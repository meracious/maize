<div align="center">
  <h1>maize</h1>
  <p>A 64-bit kernel by hobbyists.</p>
</div>

## About

The Maize kernel is a project in it's infancy and is intended solely as a hobby and learning project.

## In Action

![image](https://user-images.githubusercontent.com/65955464/124764901-1571ef00-df53-11eb-8960-c5c13602c6c3.png)

## Build Instructions

### Dependencies:

#### For Build environment:

- libuuid
- libfuse
- pkgconfig

##### Installation (run as root):

Debian based distributions:

```shell
apt install uuid-dev libfuse-dev pkg-config
```

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

Open up a PR on this repository.
