// ShortenUrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "math.h"

#define START_OF_A 10
#define START_OF_a 36

double UrlToNumber(char* Url);

int main(int argc, char **argv)
{
	char* url = "LpuPe81bc2w";

	double num = UrlToNumber(url);
	if (num < 0)
	{
		printf("main: out of range, illegal character, or null string\n");
		printf("main: see details from UrlToNumber\n");
	}
	else
	{
		printf("num: %.0f\n", num);
	}
	

	return 0;
}

/*
UrlToNumber: Convert the string into the Based-62 numbers

Argument:
Url: passing the shorten Url that needs to be decoded to numbers
*/

double UrlToNumber(char* Url)
{
	/*
	Using ASCII chart as my table instead of creating the array to find the index
	0~9 : 0~9
	A~Z : 10~35
	a~z : 36~61
	*/

	if (!Url)
	{//NULL string handling, log error and return -1
		printf("UrlToNumber: NULL String\n");
		return -1;
	}

	double result = 0; //use double to hold a larger number
	int len = static_cast<int>(strlen(Url));

	for (int i = len - 1; i >= 0; i--)
	{
		//the power for each slot
		int power = len - i - 1;

		if (Url[i] >= '0' && Url[i] <= '9')
		{
			result += (Url[i] - '0')*(pow(62, power));
		}
		else if (Url[i] >= 'A' && Url[i] <= 'Z')
		{
			result += (Url[i] - 'A' + START_OF_A)*(pow(62, power));
		}
		else if (Url[i] >= 'a' && Url[i] <= 'z')
		{
			result += (Url[i] - 'a' + START_OF_a)*(pow(62, power));
		}
		else
		{//illegal character handling, log error and return -1
			printf("UrlToNumber: illegal character\n");
			return -1;
		}
	}

	return result;
}
