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

/** swaps position arr_i with arr_j  */
void swap(int * arr_i, int * arr_j)
{
    int temp = *arr_i;  //position  temp equal to arr_i position.
    *arr_i = *arr_j;   // position arr_i equal to arr_j position.
    *arr_j = temp;     //position arr_j equal to arr_i position.

}
/** ssort accepts two arguments: an (unsorted) array of integers and its size,
 * and sorts the array in place. */
void ssort(int arr[], int len_arr){
    int smaller;
    for (int i = 0; i < len_arr; i++)
    {
        smaller = i;  // got the i of arr[i] which is the previous element position of the array.
        for (int j = i + 1; j < len_arr; j++) // got the element behind the front of element.
        {
            if (arr[j] < arr[smaller])// if the last element smaller than previous one.
            {
                smaller = j;        // assign smaller one equal to j.
            }
        }

        swap(&arr[i], &arr[smaller]);    // put smaller one to front of position.
    }
}

/** arr1 function that merges two accepts array, already that are sorted,
arrays of integers (and their sizes), and returns dynamically allocated array (pointer)
that contains the given two - merged.  */
int * mergefuc(int arr1[], int len_arr1, int arr2[], int len_arr2)
{
    int * array = malloc(sizeof(int) * (len_arr1 + len_arr2)); //Assign the integer length of numbers of
                                                                    // the corresponding address to
                                                                    // the pointer variable.
    int i;

    for ( i = 0; i < len_arr1; i++)
    {
        array[i] = arr1[i]; // Assign the arr1's elements to merged array address.
    }


    for (int j = 0; j < len_arr2; j++)
    {
        array[i++] = arr2[j];//Assign arr2's elements to merged array address.
    }

    ssort(array, (len_arr1 + len_arr2)); //sort function to sort array after merge.

    return array;
}



