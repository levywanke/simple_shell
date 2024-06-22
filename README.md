
# Simple Shell

This is a custom implementation of a Unix shell in C, as part of the ALX SE program. The shell is capable of executing commands, handling arguments, and managing processes using system calls and basic shell functionalities.

## Table of Contents
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Examples](#examples)
* [Built-in Commands](#built-in-commands)
* [Files](#files)
* [Authors](#authors)
* [License](#license)

## Description

This project implements a simple Unix shell capable of running commands and managing processes. It handles command execution using `execve` and supports basic shell functionalities like prompt display, command execution, and error handling.

## Installation

To compile the shell, clone the repository and compile using `gcc`:

```bash
git clone https://github.com/your_username/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

To start the shell, run the compiled executable:

```bash
./hsh
```

The shell will display a prompt where you can type commands. It supports interactive mode and non-interactive mode by reading commands from standard input.

## Examples

### Interactive Mode

```bash
$ ./hsh
($) /bin/ls
file1  file2
($) echo "Hello, Shell!"
Hello, Shell!
($) exit
$
```

### Non-interactive Mode

```bash
$ echo "/bin/ls" | ./hsh
file1  file2
$
```

## Built-in Commands

The shell supports the following built-in commands:

- `exit`: Exits the shell.
- `env`: Prints the current environment.

Other built-in commands like `cd`, `setenv`, `unsetenv`, etc., are not implemented in this version.

## Files

- `shell.c`: Contains the main functions for shell execution.
- `prompt.c`: Handles the display of the shell prompt.
- `exec.c`: Implements functions for executing commands using `execve`.
- `helpers.c`: Includes helper functions for various shell operations.

## Authors

- Levy Wanyonyi ([@levy](https://github.com/levy))
- Clinton Otondi ([@clinton](https://github.com/clinton))
