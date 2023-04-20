#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 10

void InitARR(int*& arr, int len) {
	arr = (int*)calloc(len, sizeof(int));

	for (int i = 0; i < len; i++) {
		if (arr)
			arr[i] = rand() % 100;
	}
}

void PrintARR(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(int& a, int& b) {
	int flag = a;
	a = b;
	b = flag;
}

int partition(int* arr, int low, int high) {
	int pivot = arr[low];
	while (low<high)
	{
		while (low<high && arr[high] >= pivot)//从后往前遍历，找到一个比pivot小的数
			high--;
		arr[low] = arr[high];

		while (low<high && arr[low] <= pivot)//从后往前遍历，找到一个比pivot小的数
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;//把pivot放回数组
	return low;      //返回pivot的位置
}

void QuickSort(int* arr, int low,int high) {
	if (low < high) {
		int pivot_pos = partition(arr, low, high);
		QuickSort(arr, low, pivot_pos - 1);
		QuickSort(arr, pivot_pos + 1, high);
	}


}

int main()
{
	srand((unsigned)time(NULL));
	int* ARR = NULL;
	int i = 0;
	InitARR(ARR, length);
	PrintARR(ARR, length);
	printf("\n\n-------QuickSort--------\n\n");
	QuickSort(ARR,0,length-1);
	PrintARR(ARR, length);

	return 0;
}