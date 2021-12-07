# simple shell

## Our Gates of sHELL. 0x16. C - simple_shell

```
For Holberton School.
Cohort 16.
```
   By Julien Barbier, co-founder & CEO
   Project to be done in teams of 2 people (your team: Daniel Rivera, Diego jojoa.
   Ongoing project - started 11-25-2021, must end by 12-09-2021 (in 14 days) - you're done with 0% of tasks.
   Checker will be released at 12-07-2021 09:07 PM.
   Manual QA review must be done (request it when you are done with the project)
   QA review fully automated.
		  ```

## Description

The simple shell is an simple application that reads lines from the terminal, interprets them, and executes them. This shell includes simple basic functionality of a traditional Unix-like command line user interface. Standard functions and system calls employed in simple_shell include: `stat, execve, exit, fork, free, getline, malloc, perror, wait, write.`

# Requirements

simple_shell is designed to run in the `Ubuntu 14.04.5 LTS` linux environment and to be compiled using the GNU compiler with flags`-Wall, -Werror, -Wextra, and -pedantic.`

# Installation

   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Run the shell in non-interactive mode:
   - Example `echo "ls -l" | ./hsh`

## Files included


| File                   | Details                                       |
|----------------------- | ------------------------------------------    |
| [simple_shell.c](./hsh)| interpret a command and display it in output  |
| [main.h](./hsh)        | containts all the prototypes                  |
| [path.c](./hsh)        | compares the strings of the PATH 		 |
| [codes.c](./hsh)	 | functions for printing strings                |
| [free.c](./hsh)	 | function for free a double pointer	         |
| [built-ins.c](./hsh)	 | get the function corresponding to especifier  |
| [_string.c](./hsh)	 | compare count and concatenate the strings	 |

# simple shell

# Ejecutando las pruebas

$ dddd
./hsh: 3: dddd: not found

code:
 #include "main.h"

  /**
   * __error - show the specific error
   * @arg: pointer
   * @size: counter
   * @command: pointer
   */

 void __error(char *arg, int size, char *command)
 {
         _puts(arg);
         _puts(": ");
         _puts_number(size);
         _puts(": ");
         _puts(command);
         _puts(": not found");
         _puts("\n");
 }

 /**
  * _puts_number - convert char to int
  * @size: integer
  */

 void _puts_number(int size)
 {
            int div, len;
            unsigned int n1;

           div = 1;
           len = 0;

           n1 = size;

           for (; n1 / div > 9; )
                   div *= 10;

           for (; div != 0; )
              {
                    len += _putchar('0' + n1 / div);
                    n1 %= div;
                    div /= 10
              }
  }
							```

Author
```
* **Diego Jojoa @diegojojoayandun** - [Diegojojoa](https://github.com/diegojojoayandun)
* **Daniel Ruiz @ruizdani301** - [DanielRuiz](https://github.com/ruizdani301)
```