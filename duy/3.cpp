#pragma once
#include "string.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

//-------------------------------------------------
const int GENERATION_NUM = 4;
const char* INPUT_ORDER[] = { "-rand", "-nsorted" , "-sorted", "-rev" };

//Hàm lấy kiểu tạo mảng 0 --> 3, trả về false nếu đầu vào sai
bool GetGenerationType(char* input_order, int& type) {
	for (int i = 0; i < GENERATION_NUM; i++)
		if (strcmp(input_order, INPUT_ORDER[i]) == 0) {
			type = i;
			return 1;
		}

	return false;
}

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int*& a, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int*& a, int n)
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
		swap(a[r1], a[r2]);
	}
}

// Hàm phát sinh dữ liệu theo dataType
void GenerateData(int*& a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 2:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 3:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 1:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}