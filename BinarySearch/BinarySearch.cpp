// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int Binary_Search_Recursive(int arr[], int start, int end, int key);
int Binary_Search_Iterate(int arr[], int start, int end, int key);

int main()
{
	int numbers[] = { 2, 8, 22, 44, 56, 65, 72, 101, 208, 452, 801 };
	int result;

	if ((result = Binary_Search_Recursive(numbers, 0, 10, 22)) != -1)
	{
		printf("found position: %d\n", result);
	}
	else
	{
		printf("not found\n");
	}
	
    return 0;
}

int Binary_Search_Recursive(int arr[], int start, int end, int key)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;

	if (arr[mid] > key)
		return Binary_Search_Recursive(arr, start, mid - 1, key);
	if (arr[mid] < key)
		return Binary_Search_Recursive(arr, mid + 1, end, key);

	return mid;

}

int Binary_Search_Iterate(int arr[], int start, int end, int key)
{
	int mid = 0;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (arr[mid] > key)
			end = mid - 1;
		else if (arr[mid] < key)
			start = mid + 1;
		else
			return mid;
	}

	return -1;
}
