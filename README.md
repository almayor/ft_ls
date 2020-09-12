# ft_ls

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Disclaimer
> In [School 42](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written to comply with. coding standard (also known as the "[Norm](./docs/subjects/norme.en.pdf)"). As a result, the implementation of certain parts may appear strange.
 
## Overview

* [Official instructions](docs/ft_ls.en.pdf)
* The goal of this project is to practice writing extensible code with modular organization, as well as learning concepts related to Unix directory system.
* As per instructions, the project is realised using a C library compiled during [previous projects](http://github.com/almayor/libftprintfgnl).
* Only the following functions are allowed for the mandatory part

	* `write`
	* `opendir`
	* `readdir`
	* `closedir`
	* `stat`
	* `lstat`
	* `getpwuid`
	* `getgrgid`
	* `listxattr`
	* `getxattr`
	* `time`
	* `ctime`
	* `readlink`
	* `malloc`
	* `free`
	* `perror`
	* `strerror`
	* `exit`

## Work

The problem is to recreate the behaviour of `ls` Linux command as closely as possible. Please note that my machine runs on *OSX Catalina  10.15.1*, so I can only guarantee that it works as expected on it.

_Flags realised_

* `-1`
* `-A`
* `-a` (mandatory)
* `-C`
* `-c`
* `-d`
* `-F`
* `-f`
* `-G`
* `-h`
* `-i` (only works in combination with `-l`)
* `-k`
* `-L`
* `-l` (mandatory)
* `-m`
* `-n`
* `-o`
* `-p`
* `-q`
* `-R` (mandatory)
* `-r` (mandatory)
* `-S`
* `-s` (only works in combination with `-l`)
* `-T`
* `-t` (mandatory)
* `-u`
* `-U`
* `-v`
* `-x`

Support of the following environmental variables is implemented

* `BLOCKSIZE`
* `CLICOLOR`
* `CLICOLOR_FORCE`
* `LSCOLORS`

Colors, ACL and extended attributes are all supported. Performance as tested on a very large directory with `-lR` specified is ~70% of the standard `ls`.

## Build

To build executables, run

```sh
git clone git@github.com:almayor/ft_ls.git
cd ft_ls
git submodule update --init --recursive
make
```

## Acknowledgements

I am grateful to the entire team behind School 42 and its [Moscow branch](https://21-school.ru
), as well as to my fellow students for help and support.

---
If you have any questions, please contact me on Github.
