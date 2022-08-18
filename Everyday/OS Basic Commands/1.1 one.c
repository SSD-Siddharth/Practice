#include<stdio.h>
int main() 
{
	int a, b, c,d;	
	//strings are in double quotes only
	// single quotes are characters
	// format string - mention for data types
	// % is must for each variable
	// followed by character -indicating data types
	// d or i - integer
	// first argument must be a string 
	// other argument will be addresses
	// c does not initialize the memory it only allocates
	scanf("%d", &a);
	scanf("%d%d", &b, &c);
	d = a+b+c;
	printf("The added value of %d, %d and %d is %d",a,b,c,d);
}



