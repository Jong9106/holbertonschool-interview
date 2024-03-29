
# 0x1B. Radix Sort

-   By:  Alexa Orrico, Software Engineer at Holberton School
-   Weight:  1
-   Ongoing second chance project - started  Nov 7, 2022 12:00 AM, must end by  Nov 14, 2022 12:00 AM
-   An auto review will be launched at the deadline

#### In a nutshell…

-   **Auto QA review:**  0.0/11 mandatory
-   **Altogether:**  **0.0%**
    -   Mandatory: 0.0%
    -   Optional: no optional tasks

## Requirements

### General

-   Allowed editors:  `vi`,  `vim`,  `emacs`
-   All your files will be compiled on Ubuntu 14.04 LTS
-   Your programs and functions will be compiled with  `gcc 4.8.4`  using the flags  `-Wall`  `-Werror`  `-Wextra`  and  `-pedantic`
-   All your files should end with a new line
-   A  `README.md`  file, at the root of the folder of the project, is mandatory
-   Your code should use the  `Betty`  style. It will be checked using  [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")  and  [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   You are not allowed to use global variables
-   No more than 5 functions per file
-   Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like  _printf, puts, …_  is totally forbidden.
-   In the following examples, the  `main.c`  files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own  `main.c`  files at compilation. Our  `main.c`  files might be different from the one shown in the examples
-   The prototypes of all your functions should be included in your header file called  `sort.h`
-   Don’t forget to push your header file
-   All your header files should be include guarded
-   A list/array does not need to be sorted if its size is less than 2.

## More Info

For this project you are given the following  `print_array`  function:

```
alexa@ubuntu-xenial:0x1B-radix_sort$ cat `print_array.c`
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
alexa@ubuntu-xenial:0x1B-radix_sort$

```

-   Our file  `print_array.c`  will be compiled with your function during the correction.
-   Please declare the prototype of the function  `print_array`  in your  `sort.h`  header file