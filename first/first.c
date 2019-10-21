#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short set(unsigned short, int, int);
unsigned short comp(unsigned short, int);
void get(unsigned short, int);
void printResult(unsigned short);
void printError();

unsigned short set(unsigned short x, int n, int v)
{
    int set;
    if (v == 1)
    {
        set = x | (1 << n);
    }
    else if (v == 0)
    {
        set = ~x;
        set = ~(set | (1 << n));
    }
    else
    {
        printError();
    }
    return set;
}

unsigned short comp(unsigned short x, int n)
{
    int comp = x ^ (1 << n);
    return comp;
}

void get(unsigned short x, int n)
{
    int get = (x >> n) & 1;
    get = get & 1;
    printf("%hu\n", get);
}

void printResult(unsigned short n)
{
    printf("%hu\n", n);
}

void printError()
{
    printError();
}

int main(int argc, char **argv)
{
    unsigned short result;

    FILE *filePtr;
    filePtr = fopen(argv[1], "r");

    if (filePtr == NULL)
    {
        printError();
        return 0;
    }

    fscanf(filePtr, "%hu\n", &result);
    char *operInput = (char *)malloc(sizeof(char) * 10);

    int numInputOne;
    int numInputTwo;

    while (!feof(filePtr))
    {
        unsigned short num = result;
        fscanf(filePtr, "%s\t%d\t%d\t", operInput, &numInputOne, &numInputTwo);

        if (strcmp(operInput, "get") == 0)
        {
            get(num, numInputOne);
        }
        else if (strcmp(operInput, "comp") == 0)
        {
            result = comp(num, numInputOne);
            printResult(result);
        }
        else if (strcmp(operInput, "set") == 0)
        {
            result = set(num, numInputOne, numInputTwo);
            printResult(result);
        }
        else
        {
            printError();
            return 0;
        }
    }

    free(operInput);
    fclose(filePtr);
    return 0;
}