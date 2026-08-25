#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main()
{
	int row, column, Copy; // Copy like Layer Or block whatever

	cout << "Enter Size Of Copy : ";
	cin >> Copy;

	cout << "Enter Size Of Row : ";
	cin >> row;

	cout << "Enter Size Of Column : ";
	cin >> column;

	// identifiy Array Row Of Pointer That Point To Row From Stack RAM
	int*** arr = new int** [Copy];

	// Insert Each Row with column Pointer

	//   arr[Copy][row][column]
	for (int i = 0; i < Copy; i++) {
		arr[i] = new int* [row];

		for (int j = 0; j < row; j++){
			arr[i][j] = new int[column];
	}
}




	// arr[Copy][row][column]

	cout << "3D Array Dynamic Insertion : " << endl;

	// Insert 
	for (int i = 0; i < Copy; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < column; k++) {
				cin >> arr[i][j][k];
			}
		}
	}


	


	cout << "3D Array Dynamic : " << endl;

	// Print 
	for (int i = 0; i < Copy; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < column; k++) {
				cout << arr[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}








	// Delete - free memory
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
