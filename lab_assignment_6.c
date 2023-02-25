#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	if (low > high)
	{
		return -1;
	}

    // find the inital middle value
	int mid_val = (low + high) / 2;

    // case if middle value is greater than the intended target
    if (numbers[mid_val] > value)
    {
        // the low value remains; the middle value changes by one element
        return search(numbers, low, mid_val - 1, value);
    }

    // case if the middle value is less than the intended target
    else if (numbers[mid_val] < value)
	{
        // the high value remains; the middle value changes by one element
	    return search(numbers, mid_val + 1, high, value);
	}

    // case if the middle value is equivalent to the intended target
    else 
    {
        return mid_val;
    }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}