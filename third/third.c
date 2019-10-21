#include <stdio.h>
#include <stdlib.h>

unsigned short get(unsigned short, int);
int isPalindrome(unsigned short);
void printResult(unsigned short);

unsigned short get(unsigned short x, int n)
{
	x = (x >> n) & 1;
    x &= 1;
	return x;
}

int isPalindrome(unsigned short x)
{
	int left = 0;
	int right = 15;
	
	while (left < right)
	{
		if (get(x, left) != get(x, right))
		{
			return 0;
		}
		left++;
		right--;
	}
	return 1;
}

void printResult(unsigned short num)
{
	if (isPalindrome(num))
	{
		printf("%s\n", "Is-Palindrome");
	}
	else
	{
		printf("%s\n", "Not-Palindrome");
	}
}

int main(int argc, char **argv)
{
	unsigned short num = atoi(argv[1]);
	printResult(num);

	return 0;
}