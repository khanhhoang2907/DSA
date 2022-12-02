#pragma once
#include <fstream>
#include <chrono>
#include <string.h>
#include <iomanip>
#include "DataGenerator.h"
#include "sortx.h"
void command5(char Algorithm1[], char Algorithm2[], char inputSize[], char inputOrder[]) {
    cout << "============\n";
    cout << "| Command5 |\n";
    cout << "============\n";
    cout << "COMPARE MODE\n";
    cout << "Algorithms: " << setw(14) << Algorithm1 << " | " << setw(14) << Algorithm2 << endl;
    int n = atoi(inputSize);
    cout << "Input Size: " << n << endl;
    cout << "Input Order: " << inputOrder << endl;
    cout << "---------------------------------------\n";

    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];
    int* d = new int[n];
    if (!strcmp(inputOrder, "-rand"))
        GenerateData(a, n, 0);
    else if (!strcmp(inputOrder, "-nsorted"))
        GenerateData(a, n, 3);
    else if (!strcmp(inputOrder, "-sorted"))
        GenerateData(a, n, 1);
    else if (!strcmp(inputOrder, "-rev"))
        GenerateData(a, n, 2);

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    string outputFile = "input.txt";
    ofstream fout;
    fout.open(outputFile);
    if (!fout.is_open()) {
        cout << "Can't open file to write.\n";
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << a[i] << " ";
    fout.close();


    duration<double, std::milli> time1, time2;
    if (!strcmp(Algorithm1, "selection-sort"))
        time1 = selectionSortTime(a, n);
    else if (!strcmp(Algorithm1, "insertion-sort"))
        time1 = insertionSortTime(a, n);
    else if (!strcmp(Algorithm1, "bubble-sort"))
        time1 = bubbleSortTime(a, n);
    else if (!strcmp(Algorithm1, "shaker-sort"))
        time1 = shakerSortTime(a, n);
    else if (!strcmp(Algorithm1, "shell-sort"))
        time1 = shellSortTime(a, n);
    else if (!strcmp(Algorithm1, "heap-sort"))
        time1 = heapSortTime(a, n);
    else if (!strcmp(Algorithm1, "merge-sort"))
        time1 = mergeSortTime(a, n);
    else if (!strcmp(Algorithm1, "quick-sort"))
        time1 = quickSortTime(a, n);
    else if (!strcmp(Algorithm1, "counting-sort"))
        time1 = countingSortTime(a, n);
    else if (!strcmp(Algorithm1, "radix-sort"))
        time1 = radixSortTime(a, n);
    else if (!strcmp(Algorithm1, "flash-sort"))
        time1 = flashSortTime(a, n);
    else {
        cout << "Invalid sort algorithm.\n";
        return;
    }
    delete[] a;

    if (!strcmp(Algorithm2, "selection-sort"))
        time2 = selectionSortTime(b, n);
    else if (!strcmp(Algorithm2, "insertion-sort"))
        time2 = insertionSortTime(b, n);
    else if (!strcmp(Algorithm2, "bubble-sort"))
        time2 = bubbleSortTime(b, n);
    else if (!strcmp(Algorithm2, "shaker-sort"))
        time2 = shakerSortTime(b, n);
    else if (!strcmp(Algorithm2, "shell-sort"))
        time2 = shellSortTime(b, n);
    else if (!strcmp(Algorithm2, "heap-sort"))
        time2 = heapSortTime(b, n);
    else if (!strcmp(Algorithm2, "merge-sort"))
        time2 = mergeSortTime(b, n);
    else if (!strcmp(Algorithm2, "quick-sort"))
        time2 = quickSortTime(b, n);
    else if (!strcmp(Algorithm2, "counting-sort"))
        time2 = countingSortTime(b, n);
    else if (!strcmp(Algorithm2, "radix-sort"))
        time2 = radixSortTime(b, n);
    else if (!strcmp(Algorithm2, "flash-sort"))
        time2 = flashSortTime(b, n);
    else {
        cout << "Invalid sort algorithm.\n";
        return;
    }
    delete[] b;

    cout << "Running time: " << setw(9) << fixed << setprecision(2) << time1.count() << " ms | " << setw(9) << fixed << setprecision(2) << time2.count() << " ms\n";

    long long count1 = 0, count2 = 0;
    if (!strcmp(Algorithm1, "selection-sort"))
        selectionSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "insertion-sort"))
        insertionSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "bubble-sort"))
        bubbleSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "shaker-sort"))
        shakerSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "shell-sort"))
        shellSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "heap-sort"))
        heapSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "merge-sort"))
        mergeSortCompare(c, 0, n - 1, count1);
    else if (!strcmp(Algorithm1, "quick-sort"))
        quickSortCompare(c, 0, n - 1, count1);
    else if (!strcmp(Algorithm1, "counting-sort"))
        countingSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "radix-sort"))
        radixSortCompare(c, n, count1);
    else if (!strcmp(Algorithm1, "flash-sort"))
        flashSortCompare(c, n, count1);
    else {
        cout << "Invalid sort algorithm.\n";
        return;
    }
    delete[] c;

    if (!strcmp(Algorithm2, "selection-sort"))
        selectionSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "insertion-sort"))
        insertionSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "bubble-sort"))
        bubbleSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "shaker-sort"))
        shakerSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "shell-sort"))
        shellSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "heap-sort"))
        heapSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "merge-sort"))
        mergeSortCompare(d, 0, n - 1, count2);
    else if (!strcmp(Algorithm2, "quick-sort"))
        quickSortCompare(d, 0, n - 1, count2);
    else if (!strcmp(Algorithm2, "counting-sort"))
        countingSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "radix-sort"))
        radixSortCompare(d, n, count2);
    else if (!strcmp(Algorithm2, "flash-sort"))
        flashSortCompare(d, n, count2);
    else {
        cout << "Invalid sort algorithm.\n";
        return;
    }
    delete[] d;

    cout << "Comparisions: " << setw(12) << count1 << " | " << setw(12) << count2 << endl;
}