# _printf Function

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

        int len;
	int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
							```

Author
```
* **Diego Jojoa @diegojojoayandun** - [Diegojojoa](https://github.com/diegojojoayandun)
* **Daniel Ruiz @ruizdani301** - [DanielRuiz](https://github.com/ruizdani301)
```