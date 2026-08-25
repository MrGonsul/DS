#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ?
// Dynamic Array & Static

// 2D -> int** arr = new *int [row];
// 
// for(int i=0; i <row; i++){
//  arr[i] = new *int[column];
// }
//---------------------------------------------------------------------------------------------



// Example 1 Get 3 Top Maximum
void Ex1(int** arr, int row, int column) {

	int k = 0;
	int* temp = new int[row * column];

	int c = 3;

	for (int i = row - 1; i >= 0; i--) {
		for (int j = column - 1; j >= 0; j--) {

			if (c != 0) {
				temp[k++] = arr[i][j];
				c--;
			}
		}
	}

	cout << "The List Is :" << endl;
	for (int i = 0; i < k; i++) {
		cout << temp[i] << " ";

	}
	

}

// Example 2 Two Point Need To 1D Array
void Ex2(int arr [], int row, int column) {
	
	int i = 0, j=0; // = (sizer)-1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}


}

// Example 3 Sum All Matrix -> if u do 2D it must be Known the column
void Ex3(int arr [][3], int row, int column) {
	int sum = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			sum += arr[i][j];
		}
	}
	cout << "sum : " << sum << endl;
}

// Example 4 Sum Each Row
void Ex4 (int arr[][3], int row, int column) {

	for (int i = 0; i < row; i++) {

		int sum = 0;   // مهم داخل الحلقة

		for (int j = 0; j < column; j++) {
			sum += arr[i][j];
		}

		cout << "Row " << i << " = " << sum << endl;
	}
}

// Example 5 Sum Each Column
void Ex5(int arr[][3], int row, int column) {
	
	for (int j = 0; j < column; j++) {

		int sum = 0;   

		for (int i = 0; i < row; i++) {
			sum += arr[i][j];
		}

		cout << "Column " << j << " = " << sum << endl;
	}

}

// Example 6  Avg Matrix
void Ex6(int arr[][3], int row, int column) {

	int sum = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			sum += arr[i][j];
		}
	}

	double avg = (double)sum / (row * column);

	cout << "Average = " << avg << endl;
}


// Example 7  Avg Matrix
void Ex7(int arr[][3], int row, int column) {
	
	int temp[3][3];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {

			temp[j][i] = arr[i][j];
		}
	}

	// Print
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {

			cout << temp[i][j] << " ";
		}
		cout << endl;
	}

}
 
// Example 8  Transpose As 90 Degree [ Transe + Reverse Row ]
void Ex8(int arr[][3], int row, int column) {
		
	// Transepose
	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < column; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}

	// reverse
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column / 2; j++) {
			swap(arr[i][j], arr[i][column - 1 - j]);
		}
	}


	//
	cout << "\n-----------------------------------------\n";
	cout << "Transpoosed Matrix\n";
	cout << "-----------------------------------------\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";

	}
	

}


// Example 9  Transpose As 180 Degree [ Transe + Reverse Row ]
void Ex9(int arr[][3], int row, int column) {

	// step 1: reverse rows
	for (int i = 0; i < row / 2; i++) {
		for (int j = 0; j < column; j++) {
			swap(arr[i][j], arr[row - 1 - i][j]);
		}
	}

	// step 2: reverse each row
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column / 2; j++) {
			swap(arr[i][j], arr[i][column - 1 - j]);
		}
	}
}


// Example 10 Find 3 Max and Min With Their Avg
void Ex10(int arr[][3], int row, int column) {
	
	
	int temp[10];   
	int k = 0;

	// 2D To 1D
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			temp[k++] = arr[i][j];
		}
	}

	// sort
	sort(temp, temp + k);

	// smallest 3
	int sumSmall = temp[0] + temp[1] + temp[2];

	// largest 3
	int sumLarge = temp[k - 1] + temp[k - 2] + temp[k - 3];

	cout << "Avg Small = " << (double)sumSmall / 3 << endl;
	cout << "Avg Large = " << (double)sumLarge / 3 << endl;

}



// STAR 
// j<n−i -> مثلث العلوي يسار
// j<=i  -> مثلث السفلي
// if (j >= n - i - 1) مثلث يمني


int fibo(int n) {

	if (n == 1)
		return 1;

	return fibo(n - 1) + fibo(n - 2);


}




void QuickSort(int arr[], int low, int high);
int main()
{

	const int row = 3, column = 3; // Not Nessesary The Const

	// -- 2D Dynamic --
/*
	int** arr = new int*[row];

	for (int i = 0; i < row; i++) {
		arr[i] = new int[column];
	}
*/

	// -- 2D Static --
	int arr[row][column];

	// We have 2D Array

	// Insert
	
	cout << "Enter value : " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {

			cin >> arr[i][j];
	
		}

	}

	//-------------------------------------------------------------------------------
	
	//	Ex1(arr, row, column);
	//	int size = sizeof(arr) / sizeof(arr[0]);
    //  Ex2(arr, row,column);
    //  Ex3(arr, row, column);
	//	Ex4(arr, row, column);
	//  Ex5(arr, row, column);
	//  Ex6(arr, row, column);
	//  Ex7(arr, row, column);
	//  Ex8(arr, row, column);
	//  Ex9(arr, row, column);
	//  Ex10(arr, row, column);

	







	//----------------------------------------------------------------------------------
/*
	// Free Memory
	for (int i = 0; i < row; i++) 
			delete [] arr[i];


	// Delete Dynamic Array 
	delete[] arr;
*/
	return 0;
}
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
