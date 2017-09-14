// StringNumberConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "math.h"
#include "limits.h"

char* Int2Char(int number);
int Char2Int(char* string);

int main()
{
	int number1 = 1234;
	int number2 = -1234;
	char* string1 = "1234";
	char* string2 = "-1234";
	char* string3 = NULL;
	char* string4 = "123%Q#6";
	char* string5 = "abcdef";

	printf("number: %d, string: %s\n", number1, Int2Char(number1));
	printf("number: %d, string: %s\n", number2, Int2Char(number2));
	printf("string: %s, number: %d\n", string1, Char2Int(string1));
	printf("string: %s, number: %d\n", string2, Char2Int(string2));
	printf("string: NULL, number: %d\n", Char2Int(string3));
	printf("string: %s, number: %d\n", string4, Char2Int(string4));
	printf("string: %s, number: %d\n", string5, Char2Int(string5));

    return 0;
}

char* Int2Char(int number)
{
	//in case there are minus number, get the absolute number first
	int absNumber = abs(number);
	int temp = absNumber;
	int count = 0;

	//count the slots that we should allocate for holding the result string
	while (temp)
	{
		temp /= 10;
		count++;
	}

	//we need one more space to hold minus sign
	if (number < 0)
	{
		count++;
	}

	//allocate the string buffer on the heap
	char* result = (char*)malloc(sizeof(char)*(count + 1));
	
	for (int i = count - 1; i >= 0; i--)
	{
		//0n48 is '0' in ASCII chart, use OR to speed up than plus operation
		result[i] = (char)((absNumber % 10) | 48);
		absNumber /= 10;
	}

	//put the minus sign in front
	if (number < 0)
	{
		result[0] = '-';
	}

	//put the null-terminated 
	result[count] = '\0';

	return result;
}

int Char2Int(char* string)
{
	if (!string)
	{
		printf("Char2Int: cannot covert null string to integer\n");
		return INT_MIN;
	}

	int result = 0;
	int i;
	int intValue;

	for (((string[0] == '-') ? (i = 1) : (i = 0)); string[i] != '\0'; i++)
	{
		//cannot reverse OR operation, hence use minus to get the digit
		intValue = (int)(string[i] - 48);

		if (intValue <= 0 || intValue >= 9)
		{
			//Anything but a digit
			printf("Char2Int: string contains non-digit characters\n");
			return INT_MIN;
		}
		else
		{
			result = result * 10 + intValue;
		}
	}

	if (string[0] == '-')
	{
		result = 0 - result;
	}

	return result;

}
