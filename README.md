# simple shell

## this is a README.md for Repository 0x16. C - simple_shell

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

For this project, students are expected to look at these concepts:
...
* Everything you need to know to start coding your own shell
* Approaching a Project

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