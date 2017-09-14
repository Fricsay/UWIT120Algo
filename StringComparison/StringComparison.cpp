// StringCompare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "malloc.h"

bool StringCompare(char str1[], char str2[], bool caseInsensitive);
bool StringCompare_Sensitive(char str1[], char str2[], int len);
bool StringCompare_Insensitive(char str1[], char str2[], int len);

int main()
{
	char str1[] = "hElLo";
	char str2[] = "HeLlO";

	printf("%s\n", (StringCompare(str1, str2, false) ? "true" : "false"));
	printf("%s\n", (StringCompare(str1, str2, true) ? "true" : "false"));
	printf("%s\n", (StringCompare(str1, str2, false) ? "true" : "false"));
    return 0;
}

bool StringCompare(char str1[], char str2[], bool caseInsensitive)
{
	//considering both null strings are equal
	if (str1 == NULL && str2 == NULL)
		return true;

	//only one null string is not equal
	if (str1 == NULL)
		return false;
	
	if (str2 == NULL)
		return false;

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	//uneqaul lengths means two different strings
	if (len1 != len2)
		return false;

	if (caseInsensitive)
		return StringCompare_Insensitive(str1, str2, len1);
	else
		return StringCompare_Sensitive(str1, str2, len1);
}

bool StringCompare_Sensitive(char str1[], char str2[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

bool StringCompare_Insensitive(char str1[], char str2[], int len)
{
	//prepare the buffer in case we need to keep the original strings unmodified
	char* temp1 = (char*)malloc(sizeof(char)*(len + 1));
	
	for (int i = 0; i < len; i++)
	{
		//copy the original strings
		temp1[i] = str1[i];

		//lowercase the characters
		if (temp1[i] <= 'Z' && temp1[i] >= 'A')
			//using the mask to lowercase
			temp1[i] = (temp1[i] | 0b00100000);
	}

	temp1[len] = '\0';

	//do the same to the second string
	char* temp2 = (char*)malloc(sizeof(char)*(len + 1));

	for (int i = 0; i < len; i++)
	{
		temp2[i] = str2[i];

		if (temp2[i] <= 'Z' && temp2[i] >= 'A')
			//using the mask to lowercase
			temp2[i] = (temp2[i] | 0b00100000);
	}

	temp2[len] = '\0';

	//compare both strings
	bool result = StringCompare_Sensitive(temp1, temp2, len);


	if (temp1)
		free(temp1);
	if (temp2)
		free(temp2);

	return result;
}
