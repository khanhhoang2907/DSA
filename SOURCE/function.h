#pragma one

#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include <math.h>
#include <string>
using namespace std;
struct NODE
{
   int data;
   NODE* pNext;
};

struct List
{
   NODE* pHead;
};
struct Queue
{
   NODE *pHead, *pTail;
};

// Hàm hoán vị giá trị hai biến
void swap(int &a, int &b);
//--------------------- SELECTION SORT -----------------------
//------------------------------------------------------------
// Tính thời gian
int FindIndexofLargest (int arr[], int size);
void SelectionSort (int arr[], int n);
// Đếm số phép so sánh
int Count_FindIndexofLargest (int arr[], int size, long long &comp);
void Count_SelectionSort (int arr[], int n, long long &comp);
//--------------------- INSERTION SORT -----------------------
//------------------------------------------------------------
// Tính thời gian
void InsertionSort (int arr[], int n);
// Đếm số phép so sánh
void Count_InsertionSort (int arr[], int n, long long &comp);
//----------------------- BUBBLE SORT -----------------------;-
//------------------------------------------------------------
// Tính thời gian
void BubbleSort (int arr[], int n);
// Đếm số phép so sánh;
void Count_BubbleSort (int arr[], int n, long long &comp);


//------------------------ HEAP SORT -------------------------
//------------------------------------------------------------
// Tính thời gian
void HeapRebuild (int pos, int arr[], int n);
void HeapConstruction (int arr[], int n);
void HeapSort (int arr[], int n);
// Đếm số phép so sánh
void Count_HeapRebuild (int pos, int arr[], int n, long long &comp);
void Count_HeapConstruction (int arr[], int n, long long &comp);
void Count_HeapSort (int arr[], int n, long long &comp);


//------------------------ MERGE SORT ------------------------
//------------------------------------------------------------
// Tính thời gian
void Merge (int arr[], int left, int mid, int right);
void MergeSort (int arr[], int left, int right);
// Đếm số phép so sánh
void Count_Merge (int arr[], int left, int mid, int right, long long &comp);
void Count_MergeSort (int arr[], int left, int right, long long &comp);

//------------------------ QUICK SORT ------------------------
//------------------------------------------------------------
// Tính thời gian
int Patrition (int arr[], int first, int last);
void QuickSort (int arr[], int first, int last);
// Đếm số phép so sánh
int Count_Patrition (int arr[], int first, int last, long long &comp);
void Count_QuickSort (int arr[], int first, int last, long long &comp);

//------------------------ RADIX SORT ------------------------
//------------------------------------------------------------
// Định nghĩa Node, List, Queue
void Enqueue(Queue &Q, NODE *p);
Queue createQueue();
NODE* CreateNode(int value);
List* InitLinkedList();

bool IsEmpty(Queue Q);
// Tính thời gian
void AddLast(NODE* &pHead, NODE *p);
void Enqueue(Queue &Q, NODE *p);
int Dequeue(Queue &Q);
void RadixSort (int arr[], int n);
// Đếm số phép so sánh
void Count_AddLast(NODE* &pHead, NODE *p, long long &comp);
void Count_Enqueue(Queue &Q, NODE *p, long long &comp);
int Count_Dequeue(Queue &Q, long long &comp);
void Count_RadixSort (int arr[], int n, long long &comp);


//----------------------- SHAKER SORT ------------------------
//------------------------------------------------------------
// Tính thời gian
void ShakerSort (int arr[], int n);
// Đếm số phép so sánh
void Count_ShakerSort (int arr[], int n, long long &comp);
//------------------------ SHELL SORT ------------------------
//------------------------------------------------------------
// Tính thời gian
void ShellSort (int arr[], int n);
// Đếm số phép so sánh
void Count_ShellSort (int arr[], int n, long long &comp);


//---------------------- COUNTING SORT -----------------------
//------------------------------------------------------------
// Tính thời gian
void FindMaxMin (int arr[], int n, int &max, int &min);
void CountingSort (int arr[], int n);
// Đếm số phép so sánh
void Count_FindMaxMin (int arr[], int n, int &max, int &min, long long &comp);
void Count_CountingSort (int arr[], int n, long long &comp);


//------------------------ FLASH SORT ------------------------
//------------------------------------------------------------
// Tính thời gian
void FlashSort (int arr[], int n);
// Đếm số phép so sánh
void Count_FlashSort (int arr[], int n, long long &comp);

//----------------------- READ INPUT -------------------------
//------------------------------------------------------------
// Hàm đọc chuỗi số
int ReadSize (const char* stringOfNum);
// Hàm đọc tên thuật toán khi cout ra kết quả
string ReadNameForCout (char* stringOfName);
// Hàm đọc tên loại mảng đầu vào khi cout ra kết quả
string ReadOrderForCout (char* stringOfOrder);


//----------------------- CREATE ARRAY -----------------------
//------------------------------------------------------------

template <class T>
void HoanVi(T &a, T &b);
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData (int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData (int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData (int a[], int n);
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData (int a[], int n);
// Hàm đọc và khởi tạo mảng đầu vào
bool ReadOrder (char * order, int *&arr, int n);


//--------------- RUNNING TIME AND COMPARISONS ---------------
//------------------------------------------------------------
// Hàm khởi tạo và sao chép giá trị để chạy Sort
void CreateNewArray (int* arr, int n, int * &newArr);

// Hàm chạy tính toán thời gian
double RunningTimeFunction (char* name, int arr[], int n);
// Hàm chạy tính toán phép so sánh
long long ComparisonsFunction (char* name, int arr[], int n);


//------------------------ READ MODE -------------------------
//------------------------------------------------------------
// Hàm thực hiện command line 1
void AlgorithmMode_1 (char* argv[]);

// Hàm thực hiện command line 2
void AlgorithmMode_2 (char* argv[]) ;                
// Hàm thực hiện command line 3
void AlgorithmMode_3 (char* argv[]);
// Hàm thực hiện command line 4
void CompareMode_4 (char* argv[]);
// Hàm thực hiện command line 5
void CompareMode_5 (char* argv[]);
//writeFile
void writeFile(const char fileInput[], int a[], int n);


