#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkParity(unsigned short);
int checkPairs(unsigned short);
unsigned short get(unsigned short, int);
void printParity(unsigned short);
void printPairs(int);

int checkParity(unsigned short n)
{
    int parity = 0;

    while (n != 0)
    {
        parity ^= n;
        n >>= 1;
    }

    parity &= 1;
    return parity;
}

unsigned short get(unsigned short x, int n)
{
    x = (x >> n) & 1;
    x &= 1;
    return x;
}

int checkPairs(unsigned short num)
{
    int numAdj = 0;
    int numOfPairs = 0;
    int temp;

    for (int i = 0; i < 15; i++)
    {
        temp = get(num, i);
        if ((temp & 1) == 1)
        {
            numAdj++;
        }
        else
        {
            numAdj = 0;
        }

        if (numAdj == 2)
        {
            numOfPairs++;
            numAdj = 0;
        }
    }

    return numOfPairs;
}

void printParity(unsigned short num)
{
    if (checkParity(num) == 1)
    {
        printf("%s\t", "Odd-Parity");
    }
    else
    {
        printf("%s\t", "Even-Parity");
    }
}

void printPairs(int num)
{
    printf("%d\n", checkPairs(num));
}

int main(int argc, char **argv)
{
    unsigned short num = atoi(argv[1]);

    printParity(num);
    printPairs(num);

    return 0;
}