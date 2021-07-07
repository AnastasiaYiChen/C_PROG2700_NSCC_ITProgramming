/*
 ============================================================================
 Name        : Sort.c
 Author      : Yi Chen
 Version     :
 Copyleft    : 03-09-2020
 Description : C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>


void ssort(int *, int); //declare sort function
int * mergefuc(int arr1[], int, int arr2[], int); //declare merge function

int main() {

    int size=10; //size of array
    int arr[] = {23, 8, 13, 3, 0, 5, 1,32, 9, 2};


    int n=8;    //size of array2
    int arr2[] = {10, 7, 6, 32, 13, 7, 3, 9};


    ssort(arr, size);
    ssort(arr2, n);


    int * dynamicArray = mergefuc(arr, size, arr2, n); //  assign merge function to dynamicArray


    for (int i = 0; i < size + n; i++) {
        printf("%d ", dynamicArray[i]);    // print the array after merge
    }

    free(dynamicArray);

    return 0;
}
