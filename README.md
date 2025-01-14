# bfu is an interpreter and eventual compiler for brainfvck

The goal of this project is to make a general tool for everything related to
    this language, covering the many edge cases not specified by the creator.
    It's also my testbed for weird compiler experiments and ELF manipulation

## Compiling
> [!NOTE]
> Non-UNIX systems are not supported at the moment (I realy
    only tested this in GNU/Linux, but it should work on other unixes)

Assuming you have make and a C compiler installed, clone the repo, cd into it
    and you'll be able run some commmands:

```sh
make <phony_target>
```

Replace <phony_target> with:
- default   (creates an release executable, used when no arguments are provided)
- debug     (creates an debug executable)
- clean     (deletes all object files and executables)
- distclean (deletes all object files)

release creates an binary in bin/, debug creates in debug/

> [!NOTE]
> By default the makefile will attempt to use the 'cc' compiler, aka the 
    default compiler installed in your system, if you wish to use a
    different one just change that variable

## Usage
In a terminal, run the binary and provide a file as an argument, or pipe some
    input into it:

```sh
./bfu hello.b
```

or

```sh
cat hello.b | ./bfu
```

## Known problems
- The binary crashes on some inputs
- Loop handling is extremely lazy and inefficient
- Purely interpreted, no compiling capabilities
- No flags or flag handling
- Naming convention could use some help
