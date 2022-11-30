#pragma one
#include "function.h"

void writeFile(const char fileInput[], int a[], int n);

// Hàm hoán vị giá trị hai biến
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}



//--------------------- SELECTION SORT -----------------------
//------------------------------------------------------------

// Tính thời gian
int FindIndexofLargest (int arr[], int size)
{
    int largest = 0;
    for (int i = 1; i <= size; i++)
    {
        if(arr[i] > arr[largest]) {largest = i;} 
    }
    return largest;
}

void SelectionSort (int arr[], int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        int largest = FindIndexofLargest(arr, i); 
        swap(arr[i], arr[largest]);
    }
}

// Đếm số phép so sánh
int Count_FindIndexofLargest (int arr[], int size, long long &comp)
{
    int largest = 0;
    for (int i = 1; ++comp, i <= size; i++)
    {
        if(++comp && arr[i] > arr[largest]) {largest = i;} 
    }
    return largest;
}

void Count_SelectionSort (int arr[], int n, long long &comp)
{
    for(int i = n - 1; ++comp, i > 0; i--)
    {
        int largest = Count_FindIndexofLargest(arr, i, comp); 
        swap(arr[i], arr[largest]);
    }
}




//--------------------- INSERTION SORT -----------------------
//------------------------------------------------------------

// Tính thời gian
void InsertionSort (int arr[], int n)
{
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
}

// Đếm số phép so sánh
void Count_InsertionSort (int arr[], int n, long long &comp)
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

// Tính thời gian
void BubbleSort (int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Đếm số phép so sánh
void Count_BubbleSort (int arr[], int n, long long &comp)
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

// Tính thời gian
void HeapRebuild (int pos, int arr[], int n)
{
    int k = pos;
    bool isHeap = false;
    while (isHeap == false && ((2*k+1) < n))
    {
        int j = 2*k+1;
        if(j < n-1)
            if(arr[j] < arr[j + 1])
                j = j + 1;

        if(arr[k] >= arr[j])
            isHeap = true;
        else{
            swap(arr[j], arr[k]);
            k = j;
        }
    }
}

void HeapConstruction (int arr[], int n)
{
    int pos = n/2;
    while (pos >= 0)
    {
        HeapRebuild(pos, arr, n);
        pos = pos - 1;
    }
}

void HeapSort (int arr[], int n)
{
    HeapConstruction(arr, n);
    int r = n - 1;
    while (r > 0)
    {
        swap(arr[0], arr[r]);
        HeapRebuild(0, arr, r); 
        r = r - 1;
    }
}

// Đếm số phép so sánh
void Count_HeapRebuild (int pos, int arr[], int n, long long &comp)
{
    int k = pos;
    bool isHeap = false;
    while ((++comp && isHeap == false) && (++comp && ((2*k+1) < n)))
    {
        int j = 2*k+1;
        if(++comp && j < n-1)
            if(++comp && arr[j] < arr[j + 1])
                j = j + 1;

        if(++comp && arr[k] >= arr[j])
            isHeap = true;
        else{
            swap(arr[j], arr[k]);
            k = j;
        }
    }
}

void Count_HeapConstruction (int arr[], int n, long long &comp)
{
    int pos = n/2;
    while (++comp && pos >= 0)
    {
        Count_HeapRebuild(pos, arr, n, comp);
        pos = pos - 1;
    }
}

void Count_HeapSort (int arr[], int n, long long &comp)
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

// Tính thời gian
void Merge (int arr[], int left, int mid, int right)
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

void MergeSort (int arr[], int left, int right)
{
    if (left < right) {
        int mid = (left + right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

// Đếm số phép so sánh
void Count_Merge (int arr[], int left, int mid, int right, long long &comp)
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

void Count_MergeSort (int arr[], int left, int right, long long &comp)
{
    if (++comp && left < right) {
        int mid = (left + right)/2;
        Count_MergeSort(arr, left, mid, comp);
        Count_MergeSort(arr, mid + 1, right, comp);
        Count_Merge (arr, left, mid, right, comp);
    }
}




//------------------------ QUICK SORT ------------------------
//------------------------------------------------------------

// Tính thời gian
int Partition (int arr[], int first, int last)
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

void QuickSort (int arr[], int first, int last)
{
	if (first < last)
	{
		int pivotIndex = Partition(arr, first, last);
		QuickSort(arr, first, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, last);
	}
}

// Đếm số phép so sánh
int Count_Partition (int arr[], int first, int last, long long &comp)
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

void Count_QuickSort (int arr[], int first, int last, long long &comp)
{
	if (++comp && first < last)
	{
		int pivotIndex = Count_Partition(arr, first, last, comp);
		Count_QuickSort(arr, first, pivotIndex - 1, comp);
		Count_QuickSort(arr, pivotIndex + 1, last, comp);
	}
}




//------------------------ RADIX SORT ------------------------
//------------------------------------------------------------

// Định nghĩa Node, List, Queue


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

// Tính thời gian
void AddLast(NODE* &pHead, NODE *p)
{
    if (pHead == NULL) {
       pHead = p;
       return;
    }
    AddLast(pHead->pNext, p);
}

void Enqueue(Queue &Q, NODE *p)
{
   if (Q.pHead == NULL)
       Q.pHead = Q.pTail = p;
   else
   {
       Q.pTail->pNext = p;
       Q.pTail = p;
   }
}

int Dequeue(Queue &Q)
{
   NODE *p = Q.pHead;
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

void RadixSort (int arr[], int n)
{
    int n_loop = log10(FindIndexofLargest(arr, n)) + 1; 

    for (int i = 1; i <= n_loop; i++)
    {
        // Tao 10 queue 0->9
        Queue* Q = new Queue[10];
        for (int u = 0; u < 10; u++){
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
            while (IsEmpty(Q[u]) != true){
                arr[k] = Dequeue(Q[u]);
                k++;
            }
        }
    }
}

// Đếm số phép so sánh
void Count_AddLast(NODE* &pHead, NODE *p, long long &comp)
{
    if (++comp && pHead == NULL) {
       pHead = p;
       return;
    }
    AddLast(pHead->pNext, p);
}

void Count_Enqueue(Queue &Q, NODE *p, long long &comp)
{
   if (++comp && Q.pHead == NULL)
       Q.pHead = Q.pTail = p;
   else
   {
       Q.pTail->pNext = p;
       Q.pTail = p;
   }
}

int Count_Dequeue(Queue &Q, long long &comp)
{
   NODE *p = Q.pHead;
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

void Count_RadixSort (int arr[], int n, long long &comp)
{
	int n_loop = log10(Count_FindIndexofLargest(arr, n, comp)) + 1; 

    for (int i = 1; ++comp, i <= n_loop; i++)
    {
        // Tao 10 queue 0->9
        Queue* Q = new Queue[10];
        for (int u = 0; ++comp, u < 10; u++){
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
            while (++comp && IsEmpty(Q[u]) != true){
                arr[k] = Count_Dequeue(Q[u], comp);
                k++;
            }
        }
    }
}




//----------------------- SHAKER SORT ------------------------
//------------------------------------------------------------

// Tính thời gian
void ShakerSort (int arr[], int n)
{
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
}

// Đếm số phép so sánh
void Count_ShakerSort (int arr[], int n, long long &comp)
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

// Tính thời gian
void ShellSort (int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap = gap / 2)
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
}

// Đếm số phép so sánh
void Count_ShellSort (int arr[], int n, long long &comp)
{
    for (int gap = n/2; ++comp, gap > 0; gap = gap / 2)
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

// Tính thời gian
void FindMaxMin (int arr[], int n, int &max, int &min)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
}

void CountingSort (int arr[], int n)
{
    int* resultArray = new int [n];
    int max = 0, min = 0, k = 0;
    FindMaxMin(arr, n, max, min);
    int* count = new int [max - min + 1]{0};
    
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
}

// Đếm số phép so sánh
void Count_FindMaxMin (int arr[], int n, int &max, int &min, long long &comp)
{
    for (int i = 1; ++comp, i < n; i++)
    {
        if (++comp && arr[i] > max)
            max = arr[i];
        else if (++comp && arr[i] < min)
            min = arr[i];
    }
}

void Count_CountingSort (int arr[], int n, long long &comp)
{
    int* resultArray = new int [n];
    int max = 0, min = 0, k = 0;
    Count_FindMaxMin(arr, n, max, min, comp);
    int* count = new int [max - min + 1]{0};
    
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

    delete[] resultArray;
}




//------------------------ FLASH SORT ------------------------
//------------------------------------------------------------

// Tính thời gian
void FlashSort (int arr[], int n)
{
    int nBucket = 0.45 * n;
    int* bucket = new int [nBucket]{0};

    int max = 0, min = 0;
    FindMaxMin(arr, n, max, min);

    for (int i = 0; i < n; i++)
    {
        int k = (nBucket - 1) * (arr[i] - min) / (max - min);
        bucket[k] += 1;
    }

    for (int i = 1; i < nBucket; i++) {
        bucket[i] = bucket[i] + bucket[i - 1];
    }

    int temp = arr[0];
    int move = 0, flash = 0, k = 0, t = 0, j = 0;

    while (move < n - 1) {

        while (j > (bucket[k] - 1))
        {
            j++;
            k = (nBucket - 1) * (arr[j] - min) / (max - min);
        }


        flash = arr[j];

        while (j != bucket[k]) 
        {
            k = (nBucket - 1) * (arr[j] - min) / (max - min);
            t = --bucket[k];
            temp = arr[t];
            arr[t] = temp;
            flash = temp;
            move++;
        }
    }

    InsertionSort(arr, n);
}

// Đếm số phép so sánh
void Count_FlashSort (int arr[], int n, long long &comp)
{
    int nBucket = 0.45 * n;
    int* bucket = new int [nBucket]{0};

    int max = 0, min = 0;
    Count_FindMaxMin(arr, n, max, min, comp);

    for (int i = 0; ++comp, i < n; i++)
    {
        int k = (nBucket - 1) * (arr[i] - min) / (max - min);
        bucket[k] += 1;
    }

    for (int i = 1; ++comp, i < nBucket; i++) {
        bucket[i] = bucket[i] + bucket[i - 1];
    }

    int temp = arr[0];
    int move = 0, flash = 0, k = 0, t = 0, j = 0;

    while (++comp && move < n - 1) {

        while (++comp && j > (bucket[k] - 1))
        {
            j++;
            k = (nBucket - 1) * (arr[j] - min) / (max - min);
        }


        flash = arr[j];

        while (++comp && j != bucket[k]) 
        {
            k = (nBucket - 1) * (arr[j] - min) / (max - min);
            t = --bucket[k];
            temp = arr[t];
            arr[t] = temp;
            flash = temp;
            move++;
        }
    }

    Count_InsertionSort(arr, n, comp);
}





//----------------------- READ INPUT -------------------------
//------------------------------------------------------------

// Hàm đọc chuỗi số
int ReadSize (const char* stringOfNum)
{
	int num = 0;
	for(int i = 0; i < strlen(stringOfNum); i++) {
		num = num * 10 + (stringOfNum[i] - '0');
	}
	return num;	
}

// Hàm đọc tên thuật toán khi cout ra kết quả
string ReadNameForCout (char* stringOfName)
{
	string fullName;
	if (strcmp(stringOfName, "selection-sort") == 0) //1
		fullName = "Selection Sort";
	else if (strcmp(stringOfName, "insertion-sort") == 0) //2
		fullName = "Insertion Sort";
	else if (strcmp(stringOfName, "bubble-sort") == 0)  //3
		fullName = "Bubble Sort";
	else if (strcmp(stringOfName, "shaker-sort") == 0) //4
		fullName = "Shaker Sort";
	else if (strcmp(stringOfName, "shell-sort") == 0)   //5
		fullName = "Shell Sort";
	else if (strcmp(stringOfName, "heap-sort") == 0)   //6
		fullName = "Heap Sort";
	else if (strcmp(stringOfName, "merge-sort") == 0) //7
		fullName = "Merge Sort";
	else if (strcmp(stringOfName, "counting -sort") == 0)  //8
		fullName = "Counting Sort";
	else if (strcmp(stringOfName, "radix-sort") == 0)   //9
		fullName = "Radix Sort";
	else if (strcmp(stringOfName, "flash-sort") == 0) // 10
		fullName = "Flash Sort";
    else if (strcmp(stringOfName, "quick-sort") == 0) // 11
		fullName = "Quick Sort";
	else return fullName;
	return fullName;
}

// Hàm đọc tên loại mảng đầu vào khi cout ra kết quả
string ReadOrderForCout (char* stringOfOrder)
{
	string fullName;
	if (strcmp(stringOfOrder, "-rand") == 0)
		fullName = "Randomize";
	else if (strcmp(stringOfOrder, "-nsorted") == 0)
		fullName = "Nearly Sorted";
	else if (strcmp(stringOfOrder, "-sorted") == 0)
		fullName = "Sorted";
	else if (strcmp(stringOfOrder, "-rev") == 0)
		fullName = "Reversed";
	else return fullName;
	return fullName;
}




//----------------------- CREATE ARRAY -----------------------
//------------------------------------------------------------

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData (int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

// Hàm đọc và khởi tạo mảng đầu vào
bool ReadOrder (char * order, int *&arr, int n)
{
    arr = new int [n];
	if (strcmp(order, "-rand") == 0) {
		// ngau nhien
		GenerateRandomData(arr, n);
		return true;
	}
	else if (strcmp(order, "-nsorted") == 0) {
		// co tinh thu tu
		GenerateSortedData(arr, n);
		return true;
	}
	else if (strcmp(order, "-sorted") == 0) {
		// gan nhu co tinh thu tu
		GenerateNearlySortedData(arr, n);
		return true;
	}
	else if (strcmp(order, "-rev") == 0) {
		// co thu tu nguoc
		GenerateReverseData(arr, n);
		return true;
	}
	else {
        delete[] arr;
        return false;
    }
}




//--------------- RUNNING TIME AND COMPARISONS ---------------
//------------------------------------------------------------

// Hàm khởi tạo và sao chép giá trị để chạy Sort
void CreateNewArray (int* arr, int n, int * &newArr)
{
    newArr = new int [n];
	for (int i = 0; i < n; i++)
	{
		newArr[i] = arr[i];
	}
}

// Hàm chạy tính toán thời gian
double RunningTimeFunction (char* name, int arr[], int n)
{
	// int* new_arr = NULL;
    // CreateNewArray(arr, n, new_arr);
	double runTime = 0;
    clock_t start, end;

	if (strcmp(name, "selection-sort") == 0) {
        start = clock();
		SelectionSort(arr, n);
	}
	else if (strcmp(name, "insertion-sort") == 0) {
        start = clock();
		InsertionSort(arr, n);
	}
	else if (strcmp(name, "bubble-sort") == 0) {
        start = clock();
		BubbleSort(arr, n);
	}
	else if (strcmp(name, "shaker-sort") == 0) {
        start = clock();
		ShakerSort(arr, n);
	}
	else if (strcmp(name, "shell-sort") == 0) {
        start = clock();
		ShellSort(arr, n);
	}
	else if (strcmp(name, "heap-sort") == 0) {
        start = clock();
		HeapSort(arr, n);
	}
	else if (strcmp(name, "merge-sort") == 0) {
        start = clock();
		MergeSort(arr, 0, n - 1);
	}
	else if (strcmp(name, "quick-sort") == 0) {
        start = clock();
		QuickSort(arr, 0, n - 1);
	}
	else if (strcmp(name, "counting-sort") == 0) {
        start = clock();
		CountingSort(arr, n);
	}
	else if (strcmp(name, "radix-sort") == 0) {
        start = clock();
		RadixSort(arr, n);
	}
	else if (strcmp(name, "flash-sort") == 0) {
        start = clock();
		FlashSort(arr, n);
	}
	else return -1;
	
    end = clock();
    runTime = (double)(end - start) / (CLOCKS_PER_SEC/1000);
	return runTime;
}

// Hàm chạy tính toán phép so sánh
long long ComparisonsFunction (char* name, int arr[], int n)
{
	//int* new_arr = NULL;
    //CreateNewArray(arr, n, new_arr);
	long long comp = 0;

	if (strcmp(name, "selection-sort") == 0) {
		Count_SelectionSort(arr, n, comp);
	}
	else if (strcmp(name, "insertion-sort") == 0) {
		Count_InsertionSort(arr, n, comp);
	}
	else if (strcmp(name, "bubble-sort") == 0) {
		Count_BubbleSort(arr, n, comp);
	}
	else if (strcmp(name, "shaker-sort") == 0) {
		Count_ShakerSort(arr, n, comp);
	}
	else if (strcmp(name, "shell-sort") == 0) {
		Count_ShellSort(arr, n, comp);
	}
	else if (strcmp(name, "heap-sort") == 0) {
		Count_HeapSort(arr, n, comp);
	}
	else if (strcmp(name, "merge-sort") == 0) {
		Count_MergeSort(arr, 0, n - 1, comp);
	}
	else if (strcmp(name, "quick-sort") == 0) {
		Count_QuickSort(arr, 0, n - 1, comp);
	}
	else if (strcmp(name, "counting-sort") == 0) {
		Count_CountingSort(arr, n, comp);
	}
	else if (strcmp(name, "radix-sort") == 0) {
		Count_RadixSort(arr, n, comp);
	}
	else if (strcmp(name, "flash-sort") == 0) {
		Count_FlashSort(arr, n, comp);
	}
	else return -1;

	return comp;
}




//------------------------ READ MODE -------------------------
//------------------------------------------------------------

// Hàm thực hiện command line 1
void AlgorithmMode_1 (char* argv[])
{
	// command 1 : a.exe -a heap-sort input.txt -both
	// ----------------------------------------------
	// Declaration 
	int n_size, *arr;
    double time = 0;
    long long comp = 0;
	const char* inFile = argv[3];

	// Read file
	FILE* f = NULL;
	f = fopen(inFile, "rt");
	if (f == NULL) return;

	fscanf(f, "%d\n", &n_size);
	arr = new int [n_size];

	for (int i = 0; i < n_size; i++)
	{
		fscanf(f, "%d ", &arr[i]);
	}
	fclose(f);

	// Print information
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << ReadNameForCout(argv[2]) << endl;
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << n_size << endl;
	cout << "------------------------------\n";
	if (strcmp(argv[4], "-time") == 0){
		time = RunningTimeFunction(argv[2], arr, n_size);
        writeFile("file//file//output.txt", arr, n_size);
		if (time != -1) {
			cout << "Running time: " << time << endl;
                

			return;
		}
	}
	else if (strcmp(argv[4], "-comp") == 0) {
        int* new_arr = NULL;
        CreateNewArray(arr, n_size, new_arr);
		comp = ComparisonsFunction(argv[2], new_arr, n_size);
                writeFile("file//output.txt", new_arr, n_size);
		if (time != -1) {
			cout << "Comparisions: " << comp << endl;

			return;
		}
	}
	else if (strcmp(argv[4], "-both") == 0)
	{   
        int* new_arr = NULL;
        CreateNewArray(arr, n_size, new_arr);
		time = RunningTimeFunction(argv[2], arr, n_size);
		comp = ComparisonsFunction(argv[2], new_arr, n_size);
                writeFile("file//output.txt", arr, n_size);
		if (time != -1 && comp != 1) {
			cout << "Running time: " << time << endl;
			cout << "Comparisions: " << comp << endl;

			return;
		}
	}
	cout << "Input syntax error!\n";
   
}

// Hàm thực hiện command line 2
void AlgorithmMode_2 (char* argv[]){
	// command 2 : a.exe -a heap-sort 50 -rand -time
	// ----------------------------------------------
	// Declaration 
	int n_size, *arr = NULL;
    double time = 0;
    long long comp = 0;

	// Input
	n_size = ReadSize(argv[3]);
	if (ReadOrder(argv[4], arr, n_size) == false) {
		cout << "Input syntax error!\n";
		return;
	}
    writeFile("file//input.txt", arr, n_size);

	// Print information
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << ReadNameForCout(argv[2]) << endl;
	cout << "Input size: " << n_size << endl;
	cout << "Input order: " << ReadOrderForCout(argv[4]) << endl;
	cout << "------------------------------\n";
	if (strcmp(argv[5], "-time") == 0){
		time = RunningTimeFunction(argv[2], arr, n_size);
        
        writeFile("file//output.txt", arr, n_size);
        

		if (time != -1) {
			cout << "Running time: " << time << endl;
			return;
		}
	}
	else if (strcmp(argv[5], "-comp") == 0) {
        int* new_arr = NULL;
        CreateNewArray(arr, n_size, new_arr);
		comp = ComparisonsFunction(argv[2], new_arr, n_size);
        writeFile("file//output.txt", new_arr, n_size);
		if (time != -1) {
			cout << "Comparisions: " << comp << endl;
            
			return;
		}
	}
	else if (strcmp(argv[5], "-both") == 0)
	{   
        int* new_arr = NULL;
        CreateNewArray(arr, n_size, new_arr);
		time = RunningTimeFunction(argv[2], arr, n_size);
		comp = ComparisonsFunction(argv[2], new_arr, n_size);
            writeFile("file//file//output.txt", arr, n_size);
		if (time != -1 && comp != 1) {
			cout << "Running time: " << time << endl;
			cout << "Comparisions: " << comp << endl;
			return;
		}
        
	}
	cout << "Input syntax error!\n";


}

// Hàm thực hiện command line 3
void AlgorithmMode_3 (char* argv[])
{
	// command 3 : a.exe -a heap-sort 700 -comp
	// -----------------------------------------
	// Declaration 
	int n_size, *arr_rand, *arr_sort, *arr_nsort, *arr_rev;

	// Input
	n_size = ReadSize(argv[3]);
	arr_rand = new int [n_size]; 
	arr_sort = new int [n_size]; 
	arr_nsort = new int [n_size];
	arr_rev = new int [n_size];

    int* new_arr_rand = NULL;
        CreateNewArray(arr_rand, n_size, new_arr_rand); 
    int* new_arr_sort = NULL;
        CreateNewArray(arr_rand, n_size, new_arr_sort); 
    int* new_arr_nsort = NULL;
        CreateNewArray(arr_rand, n_size, new_arr_nsort); 
    int* new_arr_rev = NULL;
        CreateNewArray(arr_rand, n_size, new_arr_rev); 

	GenerateRandomData(arr_rand, n_size);
            writeFile("file//input_1.txt", arr_rand, n_size);
        
	GenerateNearlySortedData(arr_nsort, n_size);
            writeFile("file//input_2.txt", arr_nsort, n_size);

	GenerateSortedData(arr_sort, n_size);
            writeFile("file//input_3.txt", arr_sort, n_size);


	GenerateReverseData(arr_rev, n_size);
            writeFile("file//input_4.txt", arr_rev, n_size);

	
	// Print information
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << ReadNameForCout(argv[2]) << endl;
	cout << "Input size: " << n_size << endl << endl;
	
	if (strcmp(argv[4], "-time") == 0){
		// Ngau nhien
		cout << "Input order: Randomize\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_rand, n_size) << endl << endl;

		// Gan nhu co tinh thu tu
		cout << "Input order: Nearly Sorted\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_nsort, n_size) << endl << endl;

		// Co tinh thu tu
		cout << "Input order: Sorted\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_sort, n_size) << endl << endl;

		// Co thu tu nguoc
		cout << "Input order: Reversed\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_rev, n_size) << endl << endl;
		return;

	}
	else if (strcmp(argv[4], "-comp") == 0) {
		
		// Ngau nhien
		cout << "Input order: Randomize\n";
		cout << "------------------------------\n";
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_rand, n_size) << endl << endl;

		// Gan nhu co tinh thu tu
		cout << "Input order: Nearly Sorted\n";
		cout << "------------------------------\n";
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_nsort, n_size) << endl << endl;

		// Co tinh thu tu
		cout << "Input order: Sorted\n";
		cout << "------------------------------\n";
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_sort, n_size) << endl << endl;

		// Co thu tu nguoc
		cout << "Input order: Reversed\n";
		cout << "------------------------------\n";
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_rev, n_size) << endl << endl;
		return;

	}
	else if (strcmp(argv[4], "-both") == 0) {
		
		// Ngau nhien
		cout << "Input order: Randomize\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_rand, n_size) << endl;
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_rand, n_size) << endl << endl;

		// Gan nhu co tinh thu tu
		cout << "Input order: Nearly Sorted\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_nsort, n_size) << endl;
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_nsort, n_size) << endl << endl;

		// Co tinh thu tu
		cout << "Input order: Sorted\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_sort, n_size) << endl;
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_sort, n_size) << endl << endl;

		// Co thu tu nguoc
		cout << "Input order: Reversed\n";
		cout << "------------------------------\n";
		cout << "Running time: " << RunningTimeFunction(argv[2], arr_rev, n_size) << endl;
		cout << "Comparisions: " << ComparisonsFunction(argv[2], new_arr_rev, n_size) << endl << endl;
		return;

	}
	cout << "Input syntax error!\n";
}

// Hàm thực hiện command line 4
void CompareMode_4 (char* argv[])
{
	// command 4 : a.exe -c heap-sort merge-sort input.txt
	// ---------------------------------------------------
	// Declaration 
	int n_size, *arr;
    double time1 = 0, time2 = 0;
    long long comp1 = 0, comp2 = 0;
	const char* inFile = argv[4];
    int* new_arr = NULL;
        CreateNewArray(arr, n_size, new_arr);

	// Read file
	FILE* f = NULL;
	f = fopen(inFile, "rt");
	if (f == NULL) return;
    
	fscanf(f, "%d\n", &n_size);
	arr = new int [n_size];
    
	for (int i = 0; i < n_size; i++)
	{
		fscanf(f, "%d ", &arr[i]);
	}
	fclose(f);
     
	// Print information
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << ReadNameForCout(argv[2]) << " | " << ReadNameForCout(argv[3]) << endl;
	cout << "Input file: " << argv[4] << endl;
	cout << "Input size: " << n_size << endl;
	cout << "------------------------------\n";
	time1 = RunningTimeFunction(argv[2], arr, n_size);
	time2 = RunningTimeFunction(argv[3], arr, n_size);

	comp1 = ComparisonsFunction(argv[2], new_arr, n_size);
	comp2 = ComparisonsFunction(argv[3], new_arr, n_size);

	if (time1 != -1 && comp1 != 1 && time2 != -1 && comp2 != -1) {
		cout << "Running time: " << time1 << " | " << time2 << endl;
		cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
		return;
	}

	cout << "Input syntax error!\n";
}

// Hàm thực hiện command line 5
void CompareMode_5 (char* argv[])
{
	// command 5 : a.exe -c quick-sort merge-sort 1000 -nsorted
	// --------------------------------------------------------
	// Declaration 
	int n_size, *arr = NULL;
    double time1 = 0, time2 = 0;
    long long comp1 = 0, comp2 = 0;
	const char* inFile = argv[4];

	// Read file
	n_size = ReadSize(argv[4]);
	if (ReadOrder(argv[5], arr, n_size) == false) {
		cout << "Input syntax error!\n";
		return;
	}
    writeFile("file//input.txt", arr, n_size);

    int* new_arr_1 = NULL;
        CreateNewArray(arr, n_size, new_arr_1); 
        
    int* new_arr_2 = NULL;
        CreateNewArray(arr, n_size, new_arr_2); 
    int* new_arr_3 = NULL;
        CreateNewArray(arr, n_size, new_arr_3); 
	// Print information
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << ReadNameForCout(argv[2]) << " | " << ReadNameForCout(argv[3]) << endl;
	cout << "Input size: " << n_size << endl;
	cout << "Input order: " << ReadOrderForCout(argv[5]) << endl;
	cout << "------------------------------\n";
	time1 = RunningTimeFunction(argv[2], new_arr_3, n_size);
	time2 = RunningTimeFunction(argv[3], new_arr_3, n_size);

	comp1 = ComparisonsFunction(argv[2], new_arr_1, n_size);
	comp2 = ComparisonsFunction(argv[3], new_arr_2, n_size);

	if (time1 != -1 && comp1 != 1 && time2 != -1 && comp2 != -1) {
		cout << "Running time: " << time1 << " | " << time2 << endl;
		cout << "Comparisions: " << comp1 << " | " << comp2 << endl;
		return;
	}

	cout << "Input syntax error!\n";
}
//writeFile
void writeFile(const char fileInput[], int a[], int n)
{
	FILE* f = fopen(fileInput, "wt");
	if (f == NULL)
	{
		return;
	}

	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", a[i]);
	}
	fclose(f);
}

