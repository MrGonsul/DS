#include <iostream>
using namespace std;

// ===== Partition =====
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;

    return i + 1;
}

// ===== Quick Sort =====
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ===== 1D =====
void case1D() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted 1D:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ===== 2D =====
void case2D() {
    int r, c;
    cout << "Enter Value Of Rows  : ";
    cin >> r ;
    cout << "Enter Value Of Column : ";
    cin >> c;

    int arr[r][c];

    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    int temp[r*c];
    int k = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[k++] = arr[i][j];

    quickSort(temp, 0, k - 1);

    k = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = temp[k++];

    cout << "Sorted 2D:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// ===== 3D =====
void case3D() {
    int x, y, z;
    cout << "Enter Value Of SubArray : ";
    cin >> x ;

    cout << "Enter Value Of Rows  : ";
    cin >> y ;

    cout << "Enter Value Of Column : ";
    cin >> z;

    int arr[x][y][z];

    cout << "Enter elements:\n";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                cin >> arr[i][j][k];

    int temp[x*y*z];
    int k = 0;

    // 3D -> 1D
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                temp[k++] = arr[i][j][l];

    quickSort(temp, 0, k - 1);

    // 1D -> 3D
    k = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                arr[i][j][l] = temp[k++];

    cout << "Sorted 3D:\n";
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
        cout << "1. 1D Quick Sort\n";
        cout << "2. 2D Quick Sort\n";
        cout << "3. 3D Quick Sort\n";
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
