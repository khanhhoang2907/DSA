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
//Ðua ph?n t? nh? nh?t v? d?u, l?p l?i n l?n
void selectionSort(int a[], int n) {
    // Di chuy?n ranh gi?i c?a m?ng dã s?p x?p và chua s?p x?p
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        // Tìm ph?n t? nh? nh?t trong m?ng chua s?p x?p
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        // Ð?i ch? ph?n t? nh? nh?t v?i ph?n t? d?u tiên
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
//So sánh 2 ph?n t? liên ti?p t? d?u m?ng r?i d?i ch? chúng (n?u c?n), l?p l?i cho d?n khi du?c m?ng tang
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

//4. Shaker Sort (C?i ti?n c?a Buble Sort):
//So sánh 2 ph?n t? liên ti?p t? d?u m?ng và 2 ph?n t? liên ti?p cu?i m?ng r?i d?i ch? chúng (n?u c?n), l?p l?i cho d?n khi du?c m?ng tang
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
    // interval là bi?n kho?ng cách gi?a các ph?n t?
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
//6.a Hàm di?u ch?nh max heap
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

//6.b Hàm t?o max heap
void builMaxHeap(int a[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);
}

//6.c Hàm Heap Sort:
void heapSort(int a[], int N)
{
    //Ð?u tiên t?o max heap
    builMaxHeap(a, N);

    for (int i = N - 1; i >= 0; i--) {
        //Hoán d?i max trên d?u max heap v?i giá tr? cu?i m?ng
        //Sau dó l?i di?u ch?nh max heap l?i
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

//7. Merge sort:
//7.a Hàm Chia nh? và ghép các m?ng chia nh? dã dó (nhung dã du?c s?p x?p tang d?n) l?i
void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //T?o 2 m?ng con
    int* L = new int[n1];
    int* R = new int[n2];

    //Sao chép d? li?u t? m?ng g?c sang 2 m?ng con
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    //Ghép 2 m?ng con l?i r?i sao chép d? li?u dua cho m?ng g?c
    i = 0; //V? trí kh?i d?u c?a m?ng con L
    j = 0; //V? trí kh?i d?u c?a m?ng con R
    k = l; //V? trí kh?i d?u c?a m?ng g?c (du?c sao chép d? li?u dã s?p x?p tang d?n vào)
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

    //N?u m?ng con L v?n còn ph?n t? chua du?c sao chép thì sao chép v? chúng v? m?ng g?c
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    //N?u m?ng con R v?n còn ph?n t? chua du?c sao chép thì sao chép v? chúng v? m?ng g?c
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

//7.b Hàm Merge sort
//l = 0, r = n - 1, m là giá tr? ? gi?a;
void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        //Tính m th? này giúp tránh tràn s? n?u l ho?c r quá l?n
        int m = l + (r - l) / 2;
        //Chia nh? các m?ng ra r?i ghép t?ng th? l?i (Theo ki?u d? quy)
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}


//8. Quick sort:
//8.a Hàm tìm ph?n t? Pivot:
//start = 0; end = n - 1
int partition(int a[], int start, int end) {
    int pivot = a[(start + end) / 2];

    // S?p x?p m?ng bên trái và m?ng bên ph?i c?a ph?n t? Pivot
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

//8.b Hàm Quick sort
void quickSort(int a[], int start, int end) {
    //Ði?u ki?n d?ng d? quy (là khi m?ng dã du?c s?p x?p tang d?n hoàn toàn)
    if (start >= end)
        return;

    // Tao ph?n t? pivot
    int p = partition(a, start, end);

    // S?p x?p m?ng bên trái
    quickSort(a, start, p - 1);

    // S?p x?p m?ng bên ph?i
    quickSort(a, p + 1, end);
}

//9. Counting sort:
//LUU Ý: CH? S? D?NG CHO M?NG CÓ T?T C? PH?N T? KHÔNG ÂM
//S?p x?p b?ng d?m phân ph?i (s? l?n xu?t hi?n)
//Ý tu?ng có ph?n liên quan d?n b?ng bam
//C?n t?o 1 m?ng con có kích thu?c max - 0 - 1 ph?n t?, v?i v? trí t? 0 d?n max v?i max là giá tr? l?n nh?t trong m?ng g?c , m?i ph?n t? luu s? l?n xu?t hi?n c?a giá tr? ph?n t? tuong ?ng v?i v? trí c?a nó
//Giá tr? ban d?u c?a m?i ph?n t? trong m?ng con là 0
//Ð?m s? l?n xu?t hi?n c?a các ph?n t? trong m?ng g?c r?i dua vào m?ng con, sau dó th?c hi?n s?p x?p dãy d?a trên m?ng con

//9.c Hàm tìm giá tr? ph?n t? l?n nh?t
int findMaxValue(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

//9.b Counting sort
void countingSort(int a[], int n) {

    //T?o m?ng con d?m s? l?n xu?t hi?n c?a các giá tr?
    int maxValue = findMaxValue(a, n);
    int countArraySize = maxValue + 1;
    int* countArray = new int [countArraySize] {0};

    //Ð?m s? l?n xu?t hi?n c?a 1 ph?n t? trong m?ng g?c r?i luu s? l?n xu?t hi?n dó vào m?ng con
    for (int i = 0; i < n; i++)
        countArray[a[i]]++;

    //S?p x?p m?ng g?c b?ng cách l?y s? l?n xu?t hi?n c?a t?ng giá tr? trong m?ng con d?m vi?t thành dãy r?i sao chép vào m?ng g?c
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
//Dùng thùng ch?a, xét t? 0 d?n 9, s?p x?p m?ng theo ch? s? hàng don  v?, d?n hàng ch?c, d?n hàng tram, d?n ... m v?i m là s? ch? s? c?a s? l?n nh?t

//10.a Hàm s?p x?p m?ng d?a theo co s? exp truy?n vào
// exp = 1
void expSort(int a[], int n, int exp)
{
    //M?ng gi? k?t qu? sau khi s?p x?p
    int* budget = new int[n];
    //M?ng thùng ch?a theo co s?
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

//10.b Hàm Radix sort:
void radixSort(int a[], int n) {
    //Tìm só lu?ng ch? s? c?a s? l?n nh?t trong m?ng
    int maxValue = findMaxValue(a, n);

    //S?p x?p m?ng theo ch? s? hàng don v?, ch?c, tram, ....
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        expSort(a, n, exp);
    }
}

//11. Flash sort:
//11.a Hàm tìm giá tr? nh? nh?t trong m?ng
int findMinValue(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

//11.b Hàm Flash sort
void flashSort(int a[], int n) {
    int minVal = findMinValue(a, n);
    int maxVal = findMaxValue(a, n);

    //N?u m?ng ch? có 1 ph?n t? ho?c nhi?u ph?n t? nhung các ph?n t? d?u b?ng nhau thì không c?n s?p x?p
    if (minVal == maxVal)
        return;

    //Chia các l?p ra v?i di?u ki?n là b?t kì ph?n t? c?a l?p tru?c ph?i nh? hon b?t kì ph?n t? c?a l?p sau

    // Tính S? l?p chia ra. Thu?ng ngu?i ta s? chia là 0.45 x s? lu?ng ph?n t? c?a m?ng
    int nClass = int(0.45 * n);

    //M?ng classes v?i m?i ph?n t? là 1 l?p và d? li?u c?a nó là s? lu?ng ph?n t? n?m trong l?p dó
    int* classes = new int[nClass] {0};

    //Tính ph?n t? c1 d? xác d?nh l?p mà ph?n t? a[i] s? du?c thêm vào (công th?c du?c áp d?ng dã du?c ch?ng minh)
    double c1 = (double)((nClass - 1) / (maxVal - minVal));

    for (int i = 0; i < n; i++) {
        int k = int((a[i] - minVal) * c1);
        ++classes[k];
    }

    //Tính index cu?i cùng c?a t?ng l?p
    for (int i = 1; i < nClass; i++)
        classes[i] = classes[i] + classes[i - 1];

    //Sau khi có s? lu?ng ph?n t? t?ng l?p thì ti?n hành s?p x?p các ph?n t? trong l?p dó, r?i ghép các l?p v? thành 1 m?ng k?t qu
    //S? d?ng hoán v? cho các ph?n t? trong các sô, n?u thêm 1 ph?n t? vào l?p này thì ph?i d?y 1 ph?n t? sang xô kia
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
    // Di chuy?n ranh gi?i c?a m?ng dã s?p x?p và chua s?p x?p
    int min_idx;
    for (int i = 0; ++count && i < n - 1; i++) {
        // Tìm ph?n t? nh? nh?t trong m?ng chua s?p x?p
        min_idx = i;
        for (int j = i + 1; ++count && j < n; j++)
            if (++count && a[j] < a[min_idx])
                min_idx = j;

        // Ð?i ch? ph?n t? nh? nh?t v?i ph?n t? d?u tiên
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
    // interval là bi?n kho?ng cách gi?a các ph?n t?
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
    //Ð?u tiên t?o max heap
    builMaxHeap(a, N);

    for (int i = N - 1; count++ && i >= 0; i--) {
        //Hoán d?i max trên d?u max heap v?i giá tr? cu?i m?ng
        //Sau dó l?i di?u ch?nh max heap l?i
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void mergeSortCompare(int a[], int l, int r, long long& count)
{
    if (count++ && l < r) {
        //Tính m th? này giúp tránh tràn s? n?u l ho?c r quá l?n
        int m = l + (r - l) / 2;
        //Chia nh? các m?ng ra r?i ghép t?ng th? l?i (Theo ki?u d? quy)
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void quickSortCompare(int a[], int start, int end, long long& count) {
    //Ði?u ki?n d?ng d? quy (là khi m?ng dã du?c s?p x?p tang d?n hoàn toàn)
    if (count++ && start >= end)
        return;

    // Tao ph?n t? pivot
    int p = partition(a, start, end);

    // S?p x?p m?ng bên trái
    quickSort(a, start, p - 1);

    // S?p x?p m?ng bên ph?i
    quickSort(a, p + 1, end);
}

void countingSortCompare(int a[], int n, long long& count) {

    //T?o m?ng con d?m s? l?n xu?t hi?n c?a các giá tr?
    int maxValue = findMaxValue(a, n);
    int countArraySize = maxValue + 1;
    int* countArray = new int [countArraySize] {0};

    //Ð?m s? l?n xu?t hi?n c?a 1 ph?n t? trong m?ng g?c r?i luu s? l?n xu?t hi?n dó vào m?ng con
    for (int i = 0; count++ && i < n; i++)
        countArray[a[i]]++;

    //S?p x?p m?ng g?c b?ng cách l?y s? l?n xu?t hi?n c?a t?ng giá tr? trong m?ng con d?m vi?t thành dãy r?i sao chép vào m?ng g?c
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
    //Tìm só lu?ng ch? s? c?a s? l?n nh?t trong m?ng
    int maxValue = findMaxValue(a, n);

    //S?p x?p m?ng theo ch? s? hàng don v?, ch?c, tram, ....
    for (int exp = 1; count++ && maxValue / exp > 0; exp *= 10) {
        expSort(a, n, exp);
    }
}

void flashSortCompare(int a[], int n, long long& count) {
    int minVal = findMinValue(a, n);
    int maxVal = findMaxValue(a, n);

    //N?u m?ng ch? có 1 ph?n t? ho?c nhi?u ph?n t? nhung các ph?n t? d?u b?ng nhau thì không c?n s?p x?p
    if (count++ && minVal == maxVal)
        return;

    //Chia các l?p ra v?i di?u ki?n là b?t kì ph?n t? c?a l?p tru?c ph?i nh? hon b?t kì ph?n t? c?a l?p sau

    // Tính S? l?p chia ra. Thu?ng ngu?i ta s? chia là 0.45 x s? lu?ng ph?n t? c?a m?ng
    int nClass = int(0.45 * n);

    //M?ng classes v?i m?i ph?n t? là 1 l?p và d? li?u c?a nó là s? lu?ng ph?n t? n?m trong l?p dó
    int* classes = new int[nClass] {0};

    //Tính ph?n t? c1 d? xác d?nh l?p mà ph?n t? a[i] s? du?c thêm vào (công th?c du?c áp d?ng dã du?c ch?ng minh)
    double c1 = (double)((nClass - 1) / (maxVal - minVal));

    for (int i = 0; count++ && i < n; i++) {
        int k = int((a[i] - minVal) * c1);
        ++classes[k];
    }

    //Tính index cu?i cùng c?a t?ng l?p
    for (int i = 1; count++ && i < nClass; i++)
        classes[i] = classes[i] + classes[i - 1];

    //Sau khi có s? lu?ng ph?n t? t?ng l?p thì ti?n hành s?p x?p các ph?n t? trong l?p dó, r?i ghép các l?p v? thành 1 m?ng k?t qu
    //S? d?ng hoán v? cho các ph?n t? trong các sô, n?u thêm 1 ph?n t? vào l?p này thì ph?i d?y 1 ph?n t? sang xô kia
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


