#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

// HÃ m hoÃ¡n vá»‹ giÃ¡ trá»‹ hai biáº¿n
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}



//--------------------- SELECTION SORT -----------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
int FindIndexofLargest(int arr[], int size)
{
    int largest = 0;
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] > arr[largest]) { largest = i; }
    }
    return largest;
}

int Median(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    if (a[r] < a[l])
    {
        swap(a[l], a[r]);
    }
    if (a[mid] < a[l])
    {
        swap(a[l], a[mid]);
    }
    if (a[r] < a[mid])
    {
        swap(a[mid], a[r]);
    }
    return mid;
}

int countMedian(int a[], int l, int r, long long& countCmp)
{
    int mid = (l + r) / 2;
    if (++countCmp && a[r] < a[l])
    {
        swap(a[l], a[r]);
    }
    if (++countCmp && a[mid] < a[l])
    {
        swap(a[l], a[mid]);
    }
    if (++countCmp&& a[r] < a[mid])
    {
        swap(a[mid], a[r]);
    }
    return mid;
}

void SelectionSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    for (int i = n - 1; i > 0; i--)
    {
        int largest = FindIndexofLargest(arr, i);
        swap(arr[i], arr[largest]);
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
int Count_FindIndexofLargest(int arr[], int size, long long& comp)
{
    int largest = 0;
    for (int i = 1; ++comp, i <= size; i++)
    {
        if (++comp && arr[i] > arr[largest]) { largest = i; }
    }
    return largest;
}

void Count_SelectionSort(int arr[], int n, long long& comp)
{
    for (int i = n - 1; ++comp, i > 0; i--)
    {
        int largest = Count_FindIndexofLargest(arr, i, comp);
        swap(arr[i], arr[largest]);
    }
}




//--------------------- INSERTION SORT -----------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void InsertionSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    for (int i = 1; i < n; i++)
    {
        int data = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > data)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = data;
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_InsertionSort(int arr[], int n, long long& comp)
{
    for (int i = 1; ++comp, i < n; i++)
    {
        int data = arr[i];
        int j = i - 1;
        while ((++comp && j >= 0) && (+comp && arr[j] > data))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = data;
    }
}




//----------------------- BUBBLE SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void BubbleSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_BubbleSort(int arr[], int n, long long& comp)
{
    for (int i = 0; ++comp, i < n - 1; i++)
    {
        for (int j = 0; ++comp, j < n - 1 - i; j++) {
            if (++comp && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}




//------------------------ HEAP SORT -------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void HeapRebuild(int pos, int arr[], int n)
{
    int k = pos;
    bool isHeap = false;
    while (isHeap == false && ((2 * k + 1) < n))
    {
        int j = 2 * k + 1;
        if (j < n - 1)
            if (arr[j] < arr[j + 1])
                j = j + 1;

        if (arr[k] >= arr[j])
            isHeap = true;
        else {
            swap(arr[j], arr[k]);
            k = j;
        }
    }
}

void HeapConstruction(int arr[], int n)
{
    int pos = n / 2;
    while (pos >= 0)
    {
        HeapRebuild(pos, arr, n);
        pos = pos - 1;
    }
}

void HeapSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    HeapConstruction(arr, n);
    int r = n - 1;
    while (r > 0)
    {
        swap(arr[0], arr[r]);
        HeapRebuild(0, arr, r);
        r = r - 1;
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_HeapRebuild(int pos, int arr[], int n, long long& comp)
{
    int k = pos;
    bool isHeap = false;
    while ((++comp && isHeap == false) && (++comp && ((2 * k + 1) < n)))
    {
        int j = 2 * k + 1;
        if (++comp && j < n - 1)
            if (++comp && arr[j] < arr[j + 1])
                j = j + 1;

        if (++comp && arr[k] >= arr[j])
            isHeap = true;
        else {
            swap(arr[j], arr[k]);
            k = j;
        }
    }
}

void Count_HeapConstruction(int arr[], int n, long long& comp)
{
    int pos = n / 2;
    while (++comp && pos >= 0)
    {
        Count_HeapRebuild(pos, arr, n, comp);
        pos = pos - 1;
    }
}

void Count_HeapSort(int arr[], int n, long long& comp)
{
    Count_HeapConstruction(arr, n, comp);
    int r = n - 1;
    while (++comp && r > 0)
    {
        swap(arr[0], arr[r]);
        Count_HeapRebuild(0, arr, r, comp);
        r = r - 1;
    }
}




//------------------------ MERGE SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void Merge(int arr[], int left, int mid, int right)
{
    //Khoi tao
    int numLeft = mid - left + 1;
    int numRight = right - mid;

    int* arrLeft = new int[numLeft];
    int* arrRight = new int[numRight];

    //Chep gia tri ra mang phu da sap xep de gop
    for (int i = 0; i < numLeft; i++)
        arrLeft[i] = arr[left + i];
    for (int i = 0; i < numRight; i++)
        arrRight[i] = arr[mid + i + 1];

    int pos1 = 0, pos2 = 0, posA = left;

    //Gop hai mang trai phai lai
    while (pos1 < numLeft && pos2 < numRight)
    {
        if (arrLeft[pos1] <= arrRight[pos2])
        {
            arr[posA] = arrLeft[pos1];
            pos1++;
        }
        else {
            arr[posA] = arrRight[pos2];
            pos2++;
        }
        posA++;
    }

    //TH: Neu 1 trong 2 mang trai hay mang phai da hoan thanh xong truoc mang con lai
    while (pos1 < numLeft) {
        arr[posA] = arrLeft[pos1];
        pos1++; posA++;
    }
    while (pos2 < numRight) {
        arr[posA] = arrRight[pos2];
        pos2++; posA++;
    }
}

void MergeSort(int arr[], int left, int right, double& time_used)
{
    clock_t start = clock();

    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid, time_used);
        MergeSort(arr, mid + 1, right, time_used);
        Merge(arr, left, mid, right);
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_Merge(int arr[], int left, int mid, int right, long long& comp)
{
    //Khoi tao
    int numLeft = mid - left + 1;
    int numRight = right - mid;

    int* arrLeft = new int[numLeft];
    int* arrRight = new int[numRight];

    //Chep gia tri ra mang phu da sap xep de gop
    for (int i = 0; ++comp, i < numLeft; i++)
        arrLeft[i] = arr[left + i];
    for (int i = 0; ++comp, i < numRight; i++)
        arrRight[i] = arr[mid + i + 1];

    int pos1 = 0, pos2 = 0, posA = left;

    //Gop hai mang trai phai lai
    while ((++comp && pos1 < numLeft) && (++comp && pos2 < numRight))
    {
        if (++comp && arrLeft[pos1] <= arrRight[pos2])
        {
            arr[posA] = arrLeft[pos1];
            pos1++;
        }
        else {
            arr[posA] = arrRight[pos2];
            pos2++;
        }
        posA++;
    }

    //TH: Neu 1 trong 2 mang trai hay mang phai da hoan thanh xong truoc mang con lai
    while (++comp && pos1 < numLeft) {
        arr[posA] = arrLeft[pos1];
        pos1++; posA++;
    }
    while (++comp && pos2 < numRight) {
        arr[posA] = arrRight[pos2];
        pos2++; posA++;
    }
}

void Count_MergeSort(int arr[], int left, int right, long long& comp)
{
    if (++comp && left < right) {
        int mid = (left + right) / 2;
        Count_MergeSort(arr, left, mid, comp);
        Count_MergeSort(arr, mid + 1, right, comp);
        Count_Merge(arr, left, mid, right, comp);
    }
}




//------------------------ QUICK SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
int Patrition(int arr[], int first, int last)
{
    int pivot = first;
    int lasts1 = first;
    int firstUnknown = first + 1;

    while (firstUnknown <= last)
    {
        if (arr[firstUnknown] < arr[pivot])
        {
            swap(arr[firstUnknown], arr[lasts1 + 1]); // swap firstUk voi ptu dau s2
            lasts1++;
        }
        firstUnknown++;
    }
    swap(arr[pivot], arr[lasts1]);
    pivot = lasts1;
    return pivot;
}

void QuickSort(int arr[], int first, int last, double& time_used)
{
    clock_t start = clock();

    if (first < last)
    {
        swap(arr[first], arr[Median(arr, first, last)]);
        int pivotIndex = Patrition(arr, first, last);
        QuickSort(arr, first, pivotIndex - 1, time_used);
        QuickSort(arr, pivotIndex + 1, last, time_used);
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
int Count_Patrition(int arr[], int first, int last, long long& comp)
{
    int pivot = first;
    int lasts1 = first;
    int firstUnknown = first + 1;

    while (++comp && firstUnknown <= last)
    {
        if (++comp && arr[firstUnknown] < arr[pivot])
        {
            swap(arr[firstUnknown], arr[lasts1 + 1]); // swap firstUk voi ptu dau s2
            lasts1++;
        }
        firstUnknown++;
    }
    swap(arr[pivot], arr[lasts1]);
    pivot = lasts1;
    return pivot;
}

void Count_QuickSort(int arr[], int first, int last, long long& comp)
{
    if (++comp && first < last)
    {
        swap(arr[first], arr[countMedian(arr, first, last, comp)]);
        int pivotIndex = Count_Patrition(arr, first, last, comp);
        Count_QuickSort(arr, first, pivotIndex - 1, comp);
        Count_QuickSort(arr, pivotIndex + 1, last, comp);
    }
}




//------------------------ RADIX SORT ------------------------
//------------------------------------------------------------

// Äá»‹nh nghÄ©a Node, List, Queue
struct NODE
{
    int data;
    NODE* pNext;
};

struct List
{
    NODE* pHead;
};

NODE* CreateNode(int value)
{
    NODE* p = new NODE;
    p->data = value;
    p->pNext = NULL;
    return p;
}

List* InitLinkedList()
{
    List* list = new List;
    list->pHead = NULL;
    return list;
}

struct Queue
{
    NODE* pHead, * pTail;
};

Queue createQueue()
{
    Queue Q; //= new Queue;
    Q.pHead = NULL;
    Q.pTail = NULL;
    return Q;
}

bool IsEmpty(Queue Q)
{
    return (Q.pHead == NULL);
}

// TÃ­nh thá»i gian
void AddLast(NODE*& pHead, NODE* p)
{
    if (pHead == NULL) {
        pHead = p;
        return;
    }
    AddLast(pHead->pNext, p);
}

void Enqueue(Queue& Q, NODE* p)
{
    if (Q.pHead == NULL)
        Q.pHead = Q.pTail = p;
    else
    {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}

int Dequeue(Queue& Q)
{
    NODE* p = Q.pHead;
    if (Q.pHead == Q.pTail)
        Q.pHead = Q.pTail = NULL;
    else if (Q.pHead != NULL)
    {
        Q.pHead = p->pNext;
        p->pNext = NULL;
    }
    int val = p->data;
    delete p;
    return val;
}

void RadixSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    int n_loop = log10(FindIndexofLargest(arr, n)) + 1;

    for (int i = 1; i <= n_loop; i++)
    {
        // Tao 10 queue 0->9
        Queue* Q = new Queue[10];
        for (int u = 0; u < 10; u++) {
            Q[u] = createQueue();
        }

        // Xet xem chu so o vi tri thu i la so may
        // Vd: 324 thi vong for1: temp = 4 || for2: temp = 2 || for3: temp = 3
        for (int j = 0; j < n; j++)
        {
            int temp = arr[j];
            int k = 1;
            while (k < i)
            {
                temp = temp / 10;
                k++;
            }
            temp = temp % 10;

            // Pick phan tu dau trong List bo vao Queue
            int val = arr[j];
            switch (temp)
            {
            case 0:
                Enqueue(Q[0], CreateNode(val));
                break;

            case 1:
                Enqueue(Q[1], CreateNode(val));
                break;

            case 2:
                Enqueue(Q[2], CreateNode(val));
                break;

            case 3:
                Enqueue(Q[3], CreateNode(val));
                break;

            case 4:
                Enqueue(Q[4], CreateNode(val));
                break;

            case 5:
                Enqueue(Q[5], CreateNode(val));
                break;

            case 6:
                Enqueue(Q[6], CreateNode(val));
                break;

            case 7:
                Enqueue(Q[7], CreateNode(val));
                break;

            case 8:
                Enqueue(Q[8], CreateNode(val));
                break;

            case 9:
                Enqueue(Q[9], CreateNode(val));
                break;
            }
        }

        // Lay cac phan tu ra khoi Queue va sap lai vao List
        int k = 0;
        for (int u = 0; u < 10; u++)
        {
            while (IsEmpty(Q[u]) != true) {
                arr[k] = Dequeue(Q[u]);
                k++;
            }
        }
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_AddLast(NODE*& pHead, NODE* p, long long& comp)
{
    if (++comp && pHead == NULL) {
        pHead = p;
        return;
    }
    AddLast(pHead->pNext, p);
}

void Count_Enqueue(Queue& Q, NODE* p, long long& comp)
{
    if (++comp && Q.pHead == NULL)
        Q.pHead = Q.pTail = p;
    else
    {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}

int Count_Dequeue(Queue& Q, long long& comp)
{
    NODE* p = Q.pHead;
    if (++comp && Q.pHead == Q.pTail)
        Q.pHead = Q.pTail = NULL;
    else if (++comp && Q.pHead != NULL)
    {
        Q.pHead = p->pNext;
        p->pNext = NULL;
    }
    int val = p->data;
    delete p;
    return val;
}

void Count_RadixSort(int arr[], int n, long long& comp)
{
    int n_loop = log10(Count_FindIndexofLargest(arr, n, comp)) + 1;

    for (int i = 1; ++comp, i <= n_loop; i++)
    {
        // Tao 10 queue 0->9
        Queue* Q = new Queue[10];
        for (int u = 0; ++comp, u < 10; u++) {
            Q[u] = createQueue();
        }

        // Xet xem chu so o vi tri thu i la so may
        // Vd: 324 thi vong for1: temp = 4 || for2: temp = 2 || for3: temp = 3
        for (int j = 0; ++comp, j < n; j++)
        {
            int temp = arr[j];
            int k = 1;
            while (++comp && k < i)
            {
                temp = temp / 10;
                k++;
            }
            temp = temp % 10;

            // Pick phan tu dau trong List bo vao Queue
            int val = arr[j];
            ++comp;
            switch (temp)
            {
            case 0:
                Count_Enqueue(Q[0], CreateNode(val), comp);
                break;

            case 1:
                Count_Enqueue(Q[1], CreateNode(val), comp);
                break;

            case 2:
                Count_Enqueue(Q[2], CreateNode(val), comp);
                break;

            case 3:
                Count_Enqueue(Q[3], CreateNode(val), comp);
                break;

            case 4:
                Count_Enqueue(Q[4], CreateNode(val), comp);
                break;

            case 5:
                Count_Enqueue(Q[5], CreateNode(val), comp);
                break;

            case 6:
                Count_Enqueue(Q[6], CreateNode(val), comp);
                break;

            case 7:
                Count_Enqueue(Q[7], CreateNode(val), comp);
                break;

            case 8:
                Count_Enqueue(Q[8], CreateNode(val), comp);
                break;

            case 9:
                Count_Enqueue(Q[9], CreateNode(val), comp);
                break;
            }
        }

        // Lay cac phan tu ra khoi Queue va sap lai vao List
        int k = 0;
        for (int u = 0; ++comp, u < 10; u++)
        {
            while (++comp && IsEmpty(Q[u]) != true) {
                arr[k] = Count_Dequeue(Q[u], comp);
                k++;
            }
        }
    }
}




//----------------------- SHAKER SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void ShakerSort(int arr[], int n, double& time_used)
{
    clock_t startClock = clock();

    bool checkSwap = true;
    int start = 0;
    int end = n - 1;

    while (checkSwap == true)
    {
        checkSwap = false;

        for (int i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                checkSwap = true;
            }
        }

        if (checkSwap == false) break;
        checkSwap = false;
        end--;

        for (int i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                checkSwap = true;
            }
        }

        start++;
    }

    clock_t endClock = clock();
    time_used = (double)(endClock - startClock) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_ShakerSort(int arr[], int n, long long& comp)
{
    bool checkSwap = true;
    int start = 0;
    int end = n - 1;

    while (++comp && checkSwap == true)
    {
        checkSwap = false;

        for (int i = start; ++comp, i < end; i++)
        {
            if (++comp && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                checkSwap = true;
            }
        }

        if (++comp && checkSwap == false) break;
        checkSwap = false;
        end--;

        for (int i = end - 1; ++comp, i >= start; i--)
        {
            if (++comp && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                checkSwap = true;
            }
        }

        start++;
    }
}




//------------------------ SHELL SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void ShellSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }

    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_ShellSort(int arr[], int n, long long& comp)
{
    for (int gap = n / 2; ++comp, gap > 0; gap = gap / 2)
    {
        for (int i = gap; ++comp, i < n; i++)
        {
            int temp = arr[i];

            int j;
            for (j = i; ++comp && j >= gap && ++comp && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}




//---------------------- COUNTING SORT -----------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian
void FindMaxMin(int arr[], int n, int& max, int& min)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
}

void CountingSort(int arr[], int n, double& time_used)
{
    clock_t start = clock();

    int* resultArray = new int[n];
    int max = 0, min = 0, k = 0;
    FindMaxMin(arr, n, max, min);
    int* count = new int [max - min + 1] {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < (max - min + 1); i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        int k = count[arr[i] - min] - 1;
        resultArray[k] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = resultArray[i];
    }


    clock_t end = clock();
    time_used = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_FindMaxMin(int arr[], int n, int& max, int& min, long long& comp)
{
    for (int i = 0; ++comp, i < n; i++)
    {
        if (++comp && arr[i] > max)
            max = arr[i];
        else if (++comp && arr[i] < min)
            min = arr[i];
    }
}

void Count_CountingSort(int arr[], int n, long long& comp)
{
    int* resultArray = new int[n];
    int max = 0, min = 0, k = 0;
    Count_FindMaxMin(arr, n, max, min, comp);
    int* count = new int [max - min + 1] {0};

    for (int i = 0; ++comp, i < n; i++)
    {
        count[arr[i] - min]++;
    }

    for (int i = 1; ++comp, i < (max - min + 1); i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; ++comp, i < n; i++)
    {
        int k = count[arr[i] - min] - 1;
        resultArray[k] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; ++comp, i < n; i++)
    {
        arr[i] = resultArray[i];
    }
}




//------------------------ FLASH SORT ------------------------
//------------------------------------------------------------

// TÃ­nh thá»i gian

void FlashSort(int arr[], int n, double& time_used)
{
    int minVal = arr[0], maxIdx = 0;
    int buckets = int(0.45 * n);
    int* l = new int[buckets];
    for (size_t i = 0; i < buckets; i++)
    {
        l[i] = 0;
    }
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    if (arr[maxIdx] == minVal) {
        delete[]l;
        return;
    }
    double c1 = (double)(buckets - 1) / (arr[maxIdx] - minVal);
    for (size_t i = 0; i < n; i++)
    {
        int bucketIdx = int(c1 * (arr[i] - minVal));
        l[bucketIdx]++;
    }
    for (size_t i = 1; i < buckets; i++)
    {
        l[i] += l[i - 1];
    }
    swap(arr[maxIdx], arr[0]);
    int nmove = 0;
    int j = 0;
    int k = buckets - 1;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - minVal));
        }
        flash = arr[j];
        if (k < 0) break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            --l[k];
            swap(flash, arr[l[k]]);
            ++nmove;
        }
    }
    delete[]l;
    InsertionSort(arr, n, time_used);
}

// Äáº¿m sá»‘ phÃ©p so sÃ¡nh
void Count_FlashSort(int arr[], int n, long long& comp)
{
    int minVal = arr[0], maxIdx = 0;
    int buckets = int(0.45 * n);
    int* l = new int[buckets];
    for (size_t i = 0; ++comp, i < buckets; i++)
    {
        l[i] = 0;
    }
    for (size_t i = 1; ++comp, i < n; i++)
    {
        if (++comp && arr[i] < minVal) minVal = arr[i];
        if (++comp && arr[i] > arr[maxIdx]) maxIdx = i;
    }
    if (++comp && arr[maxIdx] == minVal) {
        delete[]l;
        return;
    }
    double c1 = (double)(buckets - 1) / (arr[maxIdx] - minVal);
    for (size_t i = 0; ++comp, i < n; i++)
    {
        int bucketIdx = int(c1 * (arr[i] - minVal));
        l[bucketIdx]++;
    }
    for (size_t i = 1; ++comp, i < buckets; i++)
    {
        l[i] += l[i - 1];
    }
    swap(arr[maxIdx], arr[0]);
    int nmove = 0;
    int j = 0;
    int k = buckets - 1;
    int flash;
    while (++comp && nmove < n - 1)
    {
        while (++comp && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - minVal));
        }
        flash = arr[j];
        if (++comp && k < 0) break;
        while (++comp && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            --l[k];
            swap(flash, arr[l[k]]);
            ++nmove;
        }
    }
    delete[]l;
    Count_InsertionSort(arr, n, comp);
}




int* CreateNewArray(int* arr, int n)
{
    int* newArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}

template <class T>
void HoanVi(T& a, T& b)
{
    T x = a;
    a = b;
    b = x;
}

// HÃ m phÃ¡t sinh máº£ng dá»¯ liá»‡u ngáº«u nhiÃªn
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// HÃ m phÃ¡t sinh máº£ng dá»¯ liá»‡u cÃ³ thá»© tá»± tÄƒng dáº§n
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// HÃ m phÃ¡t sinh máº£ng dá»¯ liá»‡u cÃ³ thá»© tá»± ngÆ°á»£c (giáº£m dáº§n)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// HÃ m phÃ¡t sinh máº£ng dá»¯ liá»‡u gáº§n nhÆ° cÃ³ thá»© tá»±
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType, FILE* f)
{
    switch (dataType)
    {
    case 1:	// ngáº«u nhiÃªn
        fprintf(f, "Mang phat sinh ngau nhien.\n");
        GenerateRandomData(a, n);
        break;
    case 2:	// cÃ³ thá»© tá»±
        fprintf(f, "Mang phat sinh co tinh thu tu.\n");
        GenerateSortedData(a, n);
        break;
    case 3:	// cÃ³ thá»© tá»± ngÆ°á»£c
        fprintf(f, "Mang phat sinh co thu tu nguoc.\n");
        GenerateReverseData(a, n);
        break;
    case 4:	// gáº§n nhÆ° cÃ³ thá»© tá»±
        fprintf(f, "Mang phat sinh gan nhu co thu tu.\n");
        GenerateNearlySortedData(a, n);
        break;
    }
}


int main()
{
    FILE* f = NULL;
    f = fopen("result2.txt", "w");

    int dataOrder = 2, dataSize = 6;

    for (int order = 2; order <= dataOrder; order++)
    {
        for (int size = 1; size <= dataSize; size++)
        {
            int n, * array;
             switch (size)
             {
             case 1:
                 n = 10000;
                 break;

             case 2:
                 n = 30000;
                 break;

             case 3:
                 n = 50000;
                 break;

             case 4:
                 n = 100000;
                 break;

             case 5:
                 n = 300000;
                 break;

             case 6:
                 n = 500000;
                 break;
             }

            array = new int[n];
            GenerateData(array, n, order, f);
            fprintf(f, "N = %d\n", n);
            clock_t start, end;

            for (int algorithm = 1;algorithm <=11;algorithm++)
            {
                int* sort_Time = CreateNewArray(array, n);
                int* sort_Comp = CreateNewArray(array, n);
                double runTime = 0;
                long long comp = 0;

                switch (algorithm)
                {
                case 1: // Selection Sort
                    cout << "selection sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    SelectionSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_SelectionSort(sort_Comp, n, comp);
                    fprintf(f, "Selection sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 2: // Insertion Sort
                    cout << "insertion sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    InsertionSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_InsertionSort(sort_Comp, n, comp);
                    fprintf(f, "Insertion sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 3: // Bubble Sort
                    cout << "bubble sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    BubbleSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_BubbleSort(sort_Comp, n, comp);
                    fprintf(f, "Bubble sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 4: // Shaker Sort
                    cout << "shaker sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    ShakerSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_ShakerSort(sort_Comp, n, comp);
                    fprintf(f, "Shaker sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 5: // Shell Sort
                    cout << "shell sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    ShellSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_ShellSort(sort_Comp, n, comp);
                    fprintf(f, "Shell sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 6: // Heap Sort
                    cout << "heap sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    HeapSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_HeapSort(sort_Comp, n, comp);
                    fprintf(f, "Heap sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 7: // Merge Sort
                    cout << "merge sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    MergeSort(sort_Time, 0, n - 1, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_MergeSort(sort_Time, 0, n - 1, comp);
                    fprintf(f, "Merge sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 8: // Quick Sort
                    cout << "quick sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    QuickSort(sort_Time, 0, n - 1, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_QuickSort(sort_Comp, 0, n - 1, comp);
                    fprintf(f, "Quick sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 9: // Counting Sort
                    cout << "counting sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    CountingSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_CountingSort(sort_Comp, n, comp);
                    fprintf(f, "Counting sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 10: // Radix Sort
                    cout << "radix sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    RadixSort(sort_Time, n, runTime);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    Count_RadixSort(sort_Comp, n, comp);
                    fprintf(f, "Radix sort: %lf \t %llu\n", runTime, comp);
                    break;

                case 11: // Flash Sort
                    cout << "flash sort\n";
                    cout << "Data order: " << order << endl;
                    cout << "Data size: " << n << endl;
                    cout << "--------------\n";
                    start = clock();
                    FlashSort(sort_Time, n, runTime);
                    Count_FlashSort(sort_Comp, n, comp);
                    end = clock();
                    runTime = (end - start) / (CLOCKS_PER_SEC / 1000);
                    fprintf(f, "Flash sort: %lf \t %llu\n", runTime, comp);
                    break;
                }
            }

            fprintf(f, "\n-------------------------------------------\n\n");
        }
    }

    fclose(f);
    return 0;
}