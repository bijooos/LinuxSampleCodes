/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 16 Feb 2016 17:05:14 IST
 *   File           : t001.c
 *   Title          : Library usage in C - Square root 
 *   Description    : Understand difference between library functions and user
 *   		          defined functions with example of square root calculation
 *
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float mysqrt(int num);
int main()
{
	int num;
	printf("Enter the number to find square root\n");
	scanf("%d", &num);
	float res = mysqrt(num);
	printf("Square root of %d is %f \n", num, res);
	printf("Sqrt output is       %f \n", sqrt(num));
}
float mysqrt(int num)
{
	int count = 10;
	float guess = 30;

	while(count--)
	{
		guess = guess - (fabsf(guess * guess - num) / (2 * guess));
	}
	return fabsf(guess);
}
