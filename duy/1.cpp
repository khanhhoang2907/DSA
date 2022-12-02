
#pragma once
#include "string.h"
#include "sort.h"

const int x = 11;
const char* ALG[] = { "selection", "insertion", "bubble", "shaker", "shell", "heap", "merge", "quick", "counting", "radix", "flash" };
//                        0            1           2         3         4        5       6        7         8          9       10

// Hàm lấy sortType 0 --> 10, trả về false nếu sai tham số đầu vào
bool GetSortType(char* alg, int& choose)
{
    for (int i = 0; i < ALG; i++)
    {
        if (strcmp(alg, ALG[i]) == 0)
        {
            choose = i;
            return 1;
        }
    }
    return 0;
}

void choosesort(int* a, int n, int choose)
{
    switch (choose)
    {
    case 0:
        selectionSort(a, n);
        break;
    case 1:
        insertionSort(a, n);
        break;
    case 2:
        bubbleSort(a, n);
        break;
    case 3:
        shakerSort(a, n);
        break;
    case 4:
        shellSort(a, n);
        break;
    case 5:
        heapSort(a, n);
        break;
    case 6:
        mergeSort(a, n);
        break;
    case 7:
        quickSort(a, n);
        break;
    case 8:
        countingSort(a, n);
        break;
    case 9:
        radixSort(a, n);
        break;
    case 10:
        flashSort(a, n);
        break;
    default:
        std::cout << "Wrong!";
        break;
    }
}

void sort_runtime(int* a, int n, int choose)
{
    switch (choose)
    {
    case 0:
        selectionSortTime(a, n);
        break;
    case 1:
        insertionSortTime(a, n);
        break;
    case 2:
        bubbleSortTime(a, n);
        break;
    case 3:
        shakerSortTime(a, n);
        break;
    case 4:
        shellSortTime(a, n);
        break;
    case 5:
        heapSortTime(a, n);
        break;
    case 6:
        mergeSortTime(a, 0, n - 1);
        break;
    case 7:
        quickSortTime(a, 0, n - 1);
        break;
    case 8:
        countingSortTime(a, n);
        break;
    case 9:
        radixSortTime(a, n);
        break;
    case 10:
        flashSortTime(a, n);
        break;
    default:
        std::cout << "Wrong!";
        break;
}

    void sort_compare(int* a, int n, int choose)
    {
        switch (choose)
        {
        case 0:
            selectionSortCompare(a, n);
            break;
        case 1:
            insertionSortCompare(a, n);
            break;
        case 2:
            bubbleSortCompare(a, n);
            break;
        case 3:
            shakerSortCompare(a, n);
            break;
        case 4:
            shellSortCompare(a, n);
            break;
        case 5:
            heapSortCompare(a, n);
            break;
        case 6:
            mergeSortCompare(a, 0, n - 1);
            break;
        case 7:
            quickSortCompare(a, 0, n - 1);
            break;
        case 8:
            countingSortCompare(a, n);
            break;
        case 9:
            radixSortCompare(a, n);
            break;
        case 10:
            flashSortCompare(a, n);
            break;
        default:
            std::cout << "Wrong!";
            break;
        }
    }