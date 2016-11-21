//
//  main.cpp
//  MergeSort
//
//  Created by 이창기 on 2016. 11. 21..
//  Copyright © 2016년 이창기. All rights reserved.
//

#include <iostream>

void mergeSort(int *array, int low, int high, int input_Number);
void printArray(int *array, int input_Number);
void merge(int *array, int low, int middle, int high, int input_Number);

int main(int argc, const char * argv[])
{
    int input_Number;
    int number;
    int count = 0;
    
    std::cout << "insert Sort Number Count :";
    std::cin >> input_Number;
    
    int *array = new int[input_Number];
    
    do
    {
        std::cin >> number;
        array[count] = number;
        count++;
    }while(count != input_Number);
    
    std::cout << "========================================" << std::endl;
    printArray(array, input_Number);
    mergeSort(array, 0, input_Number - 1, input_Number);
    std::cout << "========================================" << std::endl;
    printArray(array, input_Number);
    std::cout << "========================================" << std::endl;
    
    
    return 0;
}

void mergeSort(int *array, int low, int high, int input_Number)
{
    if(low < high)
    {
        int middle = (high + low)/2;
        mergeSort(array, low, middle, input_Number);
        mergeSort(array, middle+1, high, input_Number);
        merge(array, low, middle, high, input_Number);
    }
    
}

void printArray(int *array, int input_Number)
{
    int i = 0;
    
    while(input_Number != i)
    {
        std::cout << array[i] << std::endl;
        i++;
    }
}

void merge(int *array, int low, int middle, int high, int input_Number)
{
    int *helper = new int[input_Number];
    
    for(int i = low; i <= high; i++)
    {
        helper[i] = array[i];
    }
    
    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;
    
    while(helperLeft <= middle && helperRight <= high)
    {
        if(helper[helperLeft] <= helper[helperRight])
        {
            array[current] = helper[helperLeft];
            helperLeft++;
        }
        else
        {
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }
    
    int remaining = middle - helperLeft;
    
    for(int i = 0; i<=remaining; i++)
    {
        array[current+i] = helper[helperLeft+i];
    }
    
}
