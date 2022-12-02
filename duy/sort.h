#pragma once
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

//1. selectionSort(a,n);
duration<double, std::milli> selectionSortTime(int a[], int n) {
    auto start = steady_clock::now();
    selectionSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//2. insertionSort(a,n);
duration<double, std::milli> insertionSortTime(int a[], int n) {
    auto start = steady_clock::now();
    insertionSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//3. bubbleSort(a,n);
duration<double, std::milli> bubbleSortTime(int a[], int n) {
    auto start = steady_clock::now();
    bubbleSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//4. shakerSort(a,n);
duration<double, std::milli> shakerSortTime(int a[], int n) {
    auto start = steady_clock::now();
    shakerSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//5. shellSort(a,n)
duration<double, std::milli> shellSortTime(int a[], int n) {
    auto start = steady_clock::now();
    shellSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//6. heapSort(a,n);
duration<double, std::milli> heapSortTime(int a[], int n) {
    auto start = steady_clock::now();
    heapSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//7. mergeSort(a,n)
duration<double, std::milli> mergeSortTime(int a[], int n) {
    auto start = steady_clock::now();
    mergeSort(a, 0, n - 1);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//8. quickSort(a,n)
duration<double, std::milli> quickSortTime(int a[], int n) {
    auto start = steady_clock::now();
    quickSort(a, 0, n - 1);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//9. countingSort(a,n);
duration<double, std::milli> countingSortTime(int a[], int n) {
    auto start = steady_clock::now();
    countingSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//10. radixSort(a,n)
duration<double, std::milli> radixSortTime(int a[], int n) {
    auto start = steady_clock::now();
    radixSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}

//11. flashSort
duration<double, std::milli> flashSortTime(int a[], int n) {
    auto start = steady_clock::now();
    flashSort(a, n);
    auto end = steady_clock::now();
    return duration<double, std::milli>(end - start);
}


//1. Selection sort:
//�ua ph?n t? nh? nh?t v? d?u, l?p l?i n l?n
void selectionSort(int a[], int n) {
    // Di chuy?n ranh gi?i c?a m?ng d� s?p x?p v� chua s?p x?p
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        // T�m ph?n t? nh? nh?t trong m?ng chua s?p x?p
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        // �?i ch? ph?n t? nh? nh?t v?i ph?n t? d?u ti�n
        swap(a[min_idx], a[i]);
    }
}
//2. Insertion sort:
//Di chuy?n nh?ng ph?n t? nh? hon key v? tru?c key
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
//3. Bubble sort:
//So s�nh 2 ph?n t? li�n ti?p t? d?u m?ng r?i d?i ch? ch�ng (n?u c?n), l?p l?i cho d?n khi du?c m?ng tang
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

//4. Shaker Sort (C?i ti?n c?a Buble Sort):
//So s�nh 2 ph?n t? li�n ti?p t? d?u m?ng v� 2 ph?n t? li�n ti?p cu?i m?ng r?i d?i ch? ch�ng (n?u c?n), l?p l?i cho d?n khi du?c m?ng tang
void shakerSort(int a[], int n) {
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (Left < Right) {
        for (int i = Left; i < Right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void shellSort(int a[], int n) {
    // interval l� bi?n kho?ng c�ch gi?a c�c ph?n t?
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

//6. Heap sort:
//6.a H�m di?u ch?nh max heap
void heapify(int a[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && a[left] > a[largest])
        largest = left;

    if (right < N && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, N, largest);
    }
}

//6.b H�m t?o max heap
void builMaxHeap(int a[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);
}

//6.c H�m Heap Sort:
void heapSort(int a[], int N)
{
    //�?u ti�n t?o max heap
    builMaxHeap(a, N);

    for (int i = N - 1; i >= 0; i--) {
        //Ho�n d?i max tr�n d?u max heap v?i gi� tr? cu?i m?ng
        //Sau d� l?i di?u ch?nh max heap l?i
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

//7. Merge sort:
//7.a H�m Chia nh? v� gh�p c�c m?ng chia nh? d� d� (nhung d� du?c s?p x?p tang d?n) l?i
void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //T?o 2 m?ng con
    int* L = new int[n1];
    int* R = new int[n2];

    //Sao ch�p d? li?u t? m?ng g?c sang 2 m?ng con
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    //Gh�p 2 m?ng con l?i r?i sao ch�p d? li?u dua cho m?ng g?c
    i = 0; //V? tr� kh?i d?u c?a m?ng con L
    j = 0; //V? tr� kh?i d?u c?a m?ng con R
    k = l; //V? tr� kh?i d?u c?a m?ng g?c (du?c sao ch�p d? li?u d� s?p x?p tang d?n v�o)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    //N?u m?ng con L v?n c�n ph?n t? chua du?c sao ch�p th� sao ch�p v? ch�ng v? m?ng g?c
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    //N?u m?ng con R v?n c�n ph?n t? chua du?c sao ch�p th� sao ch�p v? ch�ng v? m?ng g?c
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

//7.b H�m Merge sort
//l = 0, r = n - 1, m l� gi� tr? ? gi?a;
void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        //T�nh m th? n�y gi�p tr�nh tr�n s? n?u l ho?c r qu� l?n
        int m = l + (r - l) / 2;
        //Chia nh? c�c m?ng ra r?i gh�p t?ng th? l?i (Theo ki?u d? quy)
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}


//8. Quick sort:
//8.a H�m t�m ph?n t? Pivot:
//start = 0; end = n - 1
int partition(int a[], int start, int end) {
    int pivot = a[(start + end) / 2];

    // S?p x?p m?ng b�n tr�i v� m?ng b�n ph?i c?a ph?n t? Pivot
    int i = start, j = end;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i++], a[j--]);
        }
    }
    return i;
}

//8.b H�m Quick sort
void quickSort(int a[], int start, int end) {
    //�i?u ki?n d?ng d? quy (l� khi m?ng d� du?c s?p x?p tang d?n ho�n to�n)
    if (start >= end)
        return;

    // Tao ph?n t? pivot
    int p = partition(a, start, end);

    // S?p x?p m?ng b�n tr�i
    quickSort(a, start, p - 1);

    // S?p x?p m?ng b�n ph?i
    quickSort(a, p + 1, end);
}

//9. Counting sort:
//LUU �: CH? S? D?NG CHO M?NG C� T?T C? PH?N T? KH�NG �M
//S?p x?p b?ng d?m ph�n ph?i (s? l?n xu?t hi?n)
//� tu?ng c� ph?n li�n quan d?n b?ng bam
//C?n t?o 1 m?ng con c� k�ch thu?c max - 0 - 1 ph?n t?, v?i v? tr� t? 0 d?n max v?i max l� gi� tr? l?n nh?t trong m?ng g?c , m?i ph?n t? luu s? l?n xu?t hi?n c?a gi� tr? ph?n t? tuong ?ng v?i v? tr� c?a n�
//Gi� tr? ban d?u c?a m?i ph?n t? trong m?ng con l� 0
//�?m s? l?n xu?t hi?n c?a c�c ph?n t? trong m?ng g?c r?i dua v�o m?ng con, sau d� th?c hi?n s?p x?p d�y d?a tr�n m?ng con

//9.c H�m t�m gi� tr? ph?n t? l?n nh?t
int findMaxValue(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

//9.b Counting sort
void countingSort(int a[], int n) {

    //T?o m?ng con d?m s? l?n xu?t hi?n c?a c�c gi� tr?
    int maxValue = findMaxValue(a, n);
    int countArraySize = maxValue + 1;
    int* countArray = new int [countArraySize] {0};

    //�?m s? l?n xu?t hi?n c?a 1 ph?n t? trong m?ng g?c r?i luu s? l?n xu?t hi?n d� v�o m?ng con
    for (int i = 0; i < n; i++)
        countArray[a[i]]++;

    //S?p x?p m?ng g?c b?ng c�ch l?y s? l?n xu?t hi?n c?a t?ng gi� tr? trong m?ng con d?m vi?t th�nh d�y r?i sao ch�p v�o m?ng g?c
    for (int i = 1; i <= maxValue; i++)
        countArray[i] = countArray[i] + countArray[i - 1];

    int* temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = temp[i];
    delete[] countArray;
    delete[] temp;
}
//10. Radix sort:
//S?p x?p theo co s?
//D�ng th�ng ch?a, x�t t? 0 d?n 9, s?p x?p m?ng theo ch? s? h�ng don  v?, d?n h�ng ch?c, d?n h�ng tram, d?n ... m v?i m l� s? ch? s? c?a s? l?n nh?t

//10.a H�m s?p x?p m?ng d?a theo co s? exp truy?n v�o
// exp = 1
void expSort(int a[], int n, int exp)
{
    //M?ng gi? k?t qu? sau khi s?p x?p
    int* budget = new int[n];
    //M?ng th�ng ch?a theo co s?
    int digit[10] = { 0 };

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        digit[(a[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (int i = 1; i < 10; i++)
        digit[i] += digit[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        budget[digit[(a[i] / exp) % 10] - 1] = a[i];
        digit[(a[i] / exp) % 10]--;
    }

    // Copy the output array to a[], so that a[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        a[i] = budget[i];
}

//10.b H�m Radix sort:
void radixSort(int a[], int n) {
    //T�m s� lu?ng ch? s? c?a s? l?n nh?t trong m?ng
    int maxValue = findMaxValue(a, n);

    //S?p x?p m?ng theo ch? s? h�ng don v?, ch?c, tram, ....
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        expSort(a, n, exp);
    }
}

//11. Flash sort:
//11.a H�m t�m gi� tr? nh? nh?t trong m?ng
int findMinValue(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

//11.b H�m Flash sort
void flashSort(int a[], int n) {
    int minVal = findMinValue(a, n);
    int maxVal = findMaxValue(a, n);

    //N?u m?ng ch? c� 1 ph?n t? ho?c nhi?u ph?n t? nhung c�c ph?n t? d?u b?ng nhau th� kh�ng c?n s?p x?p
    if (minVal == maxVal)
        return;

    //Chia c�c l?p ra v?i di?u ki?n l� b?t k� ph?n t? c?a l?p tru?c ph?i nh? hon b?t k� ph?n t? c?a l?p sau

    // T�nh S? l?p chia ra. Thu?ng ngu?i ta s? chia l� 0.45 x s? lu?ng ph?n t? c?a m?ng
    int nClass = int(0.45 * n);

    //M?ng classes v?i m?i ph?n t? l� 1 l?p v� d? li?u c?a n� l� s? lu?ng ph?n t? n?m trong l?p d�
    int* classes = new int[nClass] {0};

    //T�nh ph?n t? c1 d? x�c d?nh l?p m� ph?n t? a[i] s? du?c th�m v�o (c�ng th?c du?c �p d?ng d� du?c ch?ng minh)
    double c1 = (double)((nClass - 1) / (maxVal - minVal));

    for (int i = 0; i < n; i++) {
        int k = int((a[i] - minVal) * c1);
        ++classes[k];
    }

    //T�nh index cu?i c�ng c?a t?ng l?p
    for (int i = 1; i < nClass; i++)
        classes[i] = classes[i] + classes[i - 1];

    //Sau khi c� s? lu?ng ph?n t? t?ng l?p th� ti?n h�nh s?p x?p c�c ph?n t? trong l?p d�, r?i gh�p c�c l?p v? th�nh 1 m?ng k?t qu
    //S? d?ng ho�n v? cho c�c ph?n t? trong c�c s�, n?u th�m 1 ph?n t? v�o l?p n�y th� ph?i d?y 1 ph?n t? sang x� kia
    swap(maxVal, a[0]);
    int nmove = 0;
    int j = 0;
    int k = nClass - 1;
    int t = 0;
    int flash;

    while (nmove < n - 1) {
        while (j > classes[k] - 1) {
            j++;
            k = (int)(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != classes[k]) {
            k = (int)(c1 * (a[j] - minVal));
            int hold = a[t == --classes[k]];
            a[t] = flash;
            hold = flash;
            ++nmove;
        }
    }
    insertionSort(a, n);
    delete[] classes;
}

void selectionSortCompare(int a[], int n, long long& count) {
    // Di chuy?n ranh gi?i c?a m?ng d� s?p x?p v� chua s?p x?p
    int min_idx;
    for (int i = 0; ++count && i < n - 1; i++) {
        // T�m ph?n t? nh? nh?t trong m?ng chua s?p x?p
        min_idx = i;
        for (int j = i + 1; ++count && j < n; j++)
            if (++count && a[j] < a[min_idx])
                min_idx = j;

        // �?i ch? ph?n t? nh? nh?t v?i ph?n t? d?u ti�n
        swap(a[min_idx], a[i]);
    }
}

void insertionSortCompare(int a[], int n, long long& count) {
    for (int i = 1; count++ && i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (count++ && j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSortCompare(int a[], int n, long long& count) {
    for (int i = 0; ++count && i < n - 1; i++)
        for (int j = 0; ++ count && j < n - i - 1; j++)
            if (++count && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void shakerSortCompare(int a[], int n, long long& count) {
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (count++ && Left < Right) {
        for (int i = Left; ++count && i < Right; i++) {
            if (++count && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; ++ count && i > Left; i--) {
            if (++count && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void shellSortCompare(int a[], int n, long long& count) {
    // interval l� bi?n kho?ng c�ch gi?a c�c ph?n t?
    for (int interval = n / 2; count++ && interval > 0; interval /= 2) {
        for (int i = interval; count++ && i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; count++ && j >= interval && a[j - interval] > temp; j -= interval) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

void heapSortCompare(int a[], int N, long long& count)
{
    //�?u ti�n t?o max heap
    builMaxHeap(a, N);

    for (int i = N - 1; count++ && i >= 0; i--) {
        //Ho�n d?i max tr�n d?u max heap v?i gi� tr? cu?i m?ng
        //Sau d� l?i di?u ch?nh max heap l?i
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void mergeSortCompare(int a[], int l, int r, long long& count)
{
    if (count++ && l < r) {
        //T�nh m th? n�y gi�p tr�nh tr�n s? n?u l ho?c r qu� l?n
        int m = l + (r - l) / 2;
        //Chia nh? c�c m?ng ra r?i gh�p t?ng th? l?i (Theo ki?u d? quy)
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void quickSortCompare(int a[], int start, int end, long long& count) {
    //�i?u ki?n d?ng d? quy (l� khi m?ng d� du?c s?p x?p tang d?n ho�n to�n)
    if (count++ && start >= end)
        return;

    // Tao ph?n t? pivot
    int p = partition(a, start, end);

    // S?p x?p m?ng b�n tr�i
    quickSort(a, start, p - 1);

    // S?p x?p m?ng b�n ph?i
    quickSort(a, p + 1, end);
}

void countingSortCompare(int a[], int n, long long& count) {

    //T?o m?ng con d?m s? l?n xu?t hi?n c?a c�c gi� tr?
    int maxValue = findMaxValue(a, n);
    int countArraySize = maxValue + 1;
    int* countArray = new int [countArraySize] {0};

    //�?m s? l?n xu?t hi?n c?a 1 ph?n t? trong m?ng g?c r?i luu s? l?n xu?t hi?n d� v�o m?ng con
    for (int i = 0; count++ && i < n; i++)
        countArray[a[i]]++;

    //S?p x?p m?ng g?c b?ng c�ch l?y s? l?n xu?t hi?n c?a t?ng gi� tr? trong m?ng con d?m vi?t th�nh d�y r?i sao ch�p v�o m?ng g?c
    for (int i = 1; count++ && i <= maxValue; i++)
        countArray[i] = countArray[i] + countArray[i - 1];

    int* temp = new int[n];
    for (int i = 0; count++ && i < n; i++)
    {
        temp[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
    }

    for (int i = 0; count++ && i < n; i++)
        a[i] = temp[i];
    delete[] countArray;
    delete[] temp;
}

void radixSortCompare(int a[], int n, long long& count) {
    //T�m s� lu?ng ch? s? c?a s? l?n nh?t trong m?ng
    int maxValue = findMaxValue(a, n);

    //S?p x?p m?ng theo ch? s? h�ng don v?, ch?c, tram, ....
    for (int exp = 1; count++ && maxValue / exp > 0; exp *= 10) {
        expSort(a, n, exp);
    }
}

void flashSortCompare(int a[], int n, long long& count) {
    int minVal = findMinValue(a, n);
    int maxVal = findMaxValue(a, n);

    //N?u m?ng ch? c� 1 ph?n t? ho?c nhi?u ph?n t? nhung c�c ph?n t? d?u b?ng nhau th� kh�ng c?n s?p x?p
    if (count++ && minVal == maxVal)
        return;

    //Chia c�c l?p ra v?i di?u ki?n l� b?t k� ph?n t? c?a l?p tru?c ph?i nh? hon b?t k� ph?n t? c?a l?p sau

    // T�nh S? l?p chia ra. Thu?ng ngu?i ta s? chia l� 0.45 x s? lu?ng ph?n t? c?a m?ng
    int nClass = int(0.45 * n);

    //M?ng classes v?i m?i ph?n t? l� 1 l?p v� d? li?u c?a n� l� s? lu?ng ph?n t? n?m trong l?p d�
    int* classes = new int[nClass] {0};

    //T�nh ph?n t? c1 d? x�c d?nh l?p m� ph?n t? a[i] s? du?c th�m v�o (c�ng th?c du?c �p d?ng d� du?c ch?ng minh)
    double c1 = (double)((nClass - 1) / (maxVal - minVal));

    for (int i = 0; count++ && i < n; i++) {
        int k = int((a[i] - minVal) * c1);
        ++classes[k];
    }

    //T�nh index cu?i c�ng c?a t?ng l?p
    for (int i = 1; count++ && i < nClass; i++)
        classes[i] = classes[i] + classes[i - 1];

    //Sau khi c� s? lu?ng ph?n t? t?ng l?p th� ti?n h�nh s?p x?p c�c ph?n t? trong l?p d�, r?i gh�p c�c l?p v? th�nh 1 m?ng k?t qu
    //S? d?ng ho�n v? cho c�c ph?n t? trong c�c s�, n?u th�m 1 ph?n t? v�o l?p n�y th� ph?i d?y 1 ph?n t? sang x� kia
    swap(maxVal, a[0]);
    int nmove = 0;
    int j = 0;
    int k = nClass - 1;
    int t = 0;
    int flash;

    while (count++ && nmove < n - 1) {
        while (count++ && j > classes[k] - 1) {
            j++;
            k = (int)(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (count++ && k < 0)
            break;
        while (count++ && j != classes[k]) {
            k = (int)(c1 * (a[j] - minVal));
            int hold = a[t == --classes[k]];
            a[t] = flash;
            hold = flash;
            ++nmove;
        }
    }
    insertionSort(a, n);
    delete[] classes;
}


