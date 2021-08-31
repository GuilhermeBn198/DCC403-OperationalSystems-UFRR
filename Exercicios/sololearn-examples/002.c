/*
The optional - specifies left alignment of the data in the string.
The optional width gives the minimum number of characters for the data.
The period . separates the width from the precision.
The optional precision gives the number of decimal places for numeric data. If s is used as the conversion character, then precision determines the number of characters to print.
The conversion character converts the argument, if necessary, to the indicated type:
d decimal
c character
s string
f float
e scientific notation
x hexadecimal

For example:
*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Color: %s, Number: %d, Float: %5.2f \n", "red", 42, 3.14159);

	printf("Pi = %3.2f ", 3.14159);

	printf ("pi = %8.5f ", 3.14159);

	printf ("pi = %-8.5f ", 3.14159);

	printf("there are %d %s in the tree. ", 22, "apples");
	return 0;
}
