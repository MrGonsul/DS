#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Mastered By Mr.Gonsul



// Merge Sort Best Case O(n) Worst Case O(nlog n) 

void Merge(int a[], int i1, int i2, int j1, int j2) {

	// Note that i1 = Start , i2 = End
	vector<int> temp(j2 - i1 + 1);

	int i = i1;
	int j = j1;
	int k = 0;

	while (i <= i2 && j <= j2) {

		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	// لو فضل عناصر
	while (i <= i2)
		temp[k++] = a[i++];

	while (j <= j2)
		temp[k++] = a[j++];

	// Transfer back to original array
	for (i = i1, j = 0; i <= j2; i++, j++) {
		a[i] = temp[j];
	}
}

void MergeSort(int a[], int i, int j) {

	int mid;

	if (i < j) {

		mid = (i + j) / 2;

		// left recursion
		MergeSort(a, i, mid);

		// right recursion
		MergeSort(a, mid + 1, j);

		// merge
		Merge(a, i, mid, mid + 1, j);
	}
}


// Quick Sort Best Case O(n) Worst Case O(n²)
void QuickSort(int arr[], int low, int high) {

	if (low >= high)
		return;

	int pivot = arr[high]; 

	int i = low;

	for (int j = low; j < high; j++) {

		if (arr[j] < pivot) {

			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[high]);

	QuickSort(arr, low, i - 1);   
	QuickSort(arr, i + 1, high);  
}

// Selection Sort Best Case O(n²) Worst Case O(n²) - Very Bad
void SelectionSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

// Insertion Sort Best Case O(n) Worst Case O(n²)
void InsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		int key = arr[i]; // important to store the value of arr[i]

		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

// BubbleSort Best Case O(n²) Worst Case O(n²)
void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


// Linear Search
int linearSearch(int* arr, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;
}


// Binary Search Best Case O(log n) Worst Case O(n Or Higher) - Search And Must be Sorted!
int binarySearch(int arr[], int n, int key) {
	int left = 0, right = n - 1;

	while (left <= right) {
	
		int mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}


// Interpolitaion Best Case O(log n) Worst Case O(n) - Search

int interpolationSearch(int arr[], int n, int key) {
	int low = 0, high = n - 1;

	while (low <= high && key >= arr[low] && key <= arr[high]) {

		if (low == high) {
			if (arr[low] == key)
				return low;
			return -1;
		}

		int pos = low + ((key - arr[low]) * (high - low))
			/ (arr[high] - arr[low]);

		if (arr[pos] == key)
			return pos;

		if (arr[pos] < key)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return -1;
}



// -- Dynamic Array Syntax : 
// 1D ===> int* arr = new int[5];
// 2D ===> int** arr = new int*[5]; Need For Loop To Create Each Row Column
// 2D ===> int*** arr = new int**[5]; Need For Loop To Create Each Block Have Row And Column



int main() {

	int *arr = new int[5](1,2,5,4,6); 

	// ---- Sort ---------
	
	//	MergeSort(arr, 0, 4);

	//	QuickSort(arr, 0, 4);

	//	SelectionSort(arr, 5);

	//	InsertionSort(arr, 5);

	//	BubbleSort(arr,5);


	// ------ Search -------------

	//	binarySearch(arr, 5, 3);
	
	//	interpolationSearch(arr, 5, 3);

	//	linearSearch(arr, 5, 3);


	// Print 
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";

	return 0;
}