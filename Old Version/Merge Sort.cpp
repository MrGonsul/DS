#include <iostream>
using namespace std;

// ===== Merge =====
void merge(int arr[], int l, int m, int r) {

   // Create Temp Array So We Can Merge 2 Array Togather  - >  Temp [k++];
    int temp[100];
    int k = 0;      // l = Left Low First Index & M = Mid Index & R = Right High Last Index
    int i = l;
    int j = m + 1;

    for (; i <= m && j <= r; k++) { // for (int i=l; i <= m && j <= r; k++)
        if (arr[i] <= arr[j]) // if item in first array is small insert into new array
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++]; // if item in second is small insert insto new array
    }

    for (; i <= m; i++, k++) // if big item in first array is smaller then mid insert !
        temp[k] = arr[i];

    for (; j <= r; j++, k++) // if big item in second array is smaller then mid insert !
        temp[k] = arr[j];

    for (i = l, k = 0; i <= r; i++, k++) // all Merge Item Insert IT INTO First Array
        arr[i] = temp[k];
}

// ===== Merge Sort =====
void mergeSort(int arr[], int l, int r) {
    if (l < r) { // low smaller then high  ---- left smaller the right
        int m = (l + r) / 2; // Rule
        mergeSort(arr, l, m); // sort recersive From low[first] into Mid
        mergeSort(arr, m + 1, r); // sort recersive From Mid + 1  Into Last[right] or high
        merge(arr, l, m, r); // Merge  all
    }
}

// ===== 1D =====
void case1D() {
    int n;
    cout << "Enter size of 1D array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted 1D:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ===== 2D =====
void case2D() {
    int r, c;
    cout << "Enter Value Of Rows : ";
    cin >> r ;
    cout << "Enter Value Of Columns : ";
    cin >> c;

    int arr[r][c];

    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    int temp[r*c]; // New Temp Array with new Index
    int k = 0;

    for (int i = 0; i < r; i++) // Transform 2D Into 1D
        for (int j = 0; j < c; j++)
            temp[k++] = arr[i][j];

    mergeSort(temp, 0, k - 1);

    k = 0; // Transform 1D Into 2D
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = temp[k++];

    cout << "Sorted 2D:\n"; // Traversal
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// ===== 3D =====
void case3D() {
    int x, y, z;

    cout << "Enter Value Of SubArray X : ";
    cin >> x ;

    cout << "Enter Value Of Row Y : ";
    cin >> y;

    cout << "Enter Value Of Columns Z : ";
    cin >> z;

    int arr[x][y][z]; //temp

    cout << "Enter elements:\n"; // insert
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                cin >> arr[i][j][k];

    int temp[x*y*z]; // total array temp
    int k = 0;

    for (int i = 0; i < x; i++) // 3D To 1D
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                temp[k++] = arr[i][j][l];

    mergeSort(temp, 0, k - 1);

    k = 0; // 1D INTO 3D
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                arr[i][j][l] = temp[k++];

    cout << "Sorted 3D:\n"; // traversal
    for (int i = 0; i < x; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < y; j++) {
            for (int l = 0; l < z; l++)
                cout << arr[i][j][l] << " ";
            cout << endl;
        }
    }
}

// ===== MAIN MENU =====
int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. 1D Merge Sort\n";
        cout << "2. 2D Merge Sort\n";
        cout << "3. 3D Merge Sort\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: case1D(); break;
            case 2: case2D(); break;
            case 3: case3D(); break;
            case 4: cout << "Exit...\n"; break;
            default: cout << "Wrong choice!\n";
        }

    } while (choice != 4);

    return 0;
}
