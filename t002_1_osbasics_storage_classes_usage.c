/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 16 Feb 2016 17:11:00 IST
 *   File           : t002_1.c
 *   Title          : Extern variable usage in C 
 *   Description    : To understand various segements of a running program,it 
 *                    is important to know the working of storage classes in C.
 *                    This program demonstrates extern variable usage by 
 *                    accessing a global variable from another file.
 *   Usage          : Compile t002_2.c along with this 
 *
 *----------------------------------------------------------------------------*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun(void);
int global;
int main()
{
	/* default value of global variable */
	printf("global = %d\n", global);
	global = 10;
	/* call a function defined in another c file*/
	fun();
	/* Check again the value after function call*/
	printf("global = %d\n", global);
}

