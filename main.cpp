/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ammy_
 *
 * Created on 26 de junio de 2016, 08:53 PM
 */

// C++ implementation of Cocktail Sort
#include<iostream>
using namespace std;
 
// Sorts arrar a[0..n-1] using Cocktail sort
int CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int swaps = 0, end = n-1;
 
    while (swapped)
    {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;
 
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
                swaps++;
            }
        }
 
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
 
        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;
 
        // move the end point back by one, because
        //  item at the end is in its rightful spot
        --end;
 
        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
                swaps++;
            }
        }
 
        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
    return swaps;
}
 
/* Prints the array */
void printArray(int a[], int n)
{
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }   
    printf("\n");
}
 
// Driver code
int main()
{
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
      cout << CocktailSort(arr,n);
//    printf("Sorted array :\n");
//    printArray(arr,n);
    return 0;
}

