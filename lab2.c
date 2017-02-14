// lab2.c - measure execution time of C code
//Matt Noblett
//Lab 2
//Winter 2017 - Tao 361
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
	const int MaxSize = 75000;
	int i, j, temp;
    //Used to keep track of the beginning and the end of the block of code time.
    time_t begin, end;
    double diff_t;

	// Part one: processing a statically allocated array

    time(&begin);
	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; ++i)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; --j)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}
    time(&end);
    diff_t = difftime(end, begin);
    printf("Static Array Execution time: %f\n", diff_t);

	// Part two: processing a dynamically allocated array
    time(&begin);

    //Declaration of the Array
    int *dynamicArray;
    
    dynamicArray = (int*)calloc(MaxSize, sizeof(int));
    //Populates the array 
    for(i = 0; i < MaxSize; ++i){
        *(dynamicArray + 1) = MaxSize - i;
    }
    int *jp,*ip;
    //Loops through the array, same as the static array does
    for(ip = dynamicArray; ip < dynamicArray + MaxSize -1; ++ip){
        for(jp = dynamicArray + MaxSize - 1; jp > ip; --jp){
            temp = *(jp + 1);
            *(jp+1) = *(jp);
            *(jp) = temp;
        }
    }
    time(&end);
    diff_t = difftime(end, begin);
    printf("Dynamic Array Execution time: %f\n", diff_t);




	// Display the amount of time used for each part above




	return 0;
}
