#include <stdio.h>
int main()
{
	int x, y;
	char text[20];

	scanf("%2d %d %*f %5s", &x, &y, &text);
	/* input: 1234 5.7 elephant */
	printf("%d %d %s", x, y, text);
	/* output: 12 34 eleph */
	return 0;
}