#include <iostream>
using namespace std;

// Binary Search Must Be The Array Sorted !!!!!

// ===== Bubble Sort =====
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

// ===== Binary Search =====
int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

// ===== 1D =====
void case1D() {
    int n, key;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    bubbleSort(arr, n);

    cout << binarySearch(arr, n, key);
}

// ===== 2D =====
void case2D() {
    int r, c, key;
    cout << "Enter Value Of Row : ";
    cin >> r ;

    cout << "Enter Value Of Column : ";
    cin >> c ;

    int arr[r][c];
    int temp[r * c];
    int k = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    cin >> key;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[k++] = arr[i][j];

    bubbleSort(temp, k);

    cout << binarySearch(temp, k, key);
}

// ===== 3D =====
void case3D() {
    int x, y, z, key;
    cout << "Enter Value Of SubArray : ";
    cin >> x ;


    cout << "Enter Value Of Row : ";
    cin >> y ;

    cout << "Enter Value Of Column : ";
    cin >> z ;

    int arr[x][y][z];
    int temp[x * y * z];
    int k = 0;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                cin >> arr[i][j][l];

    cin >> key;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                temp[k++] = arr[i][j][l];

    bubbleSort(temp, k);

    cout << binarySearch(temp, k, key);
}

// ===== MAIN =====
int main() {
    int choice;
    cin >> choice;

    if (choice == 1) case1D();
    if (choice == 2) case2D();
    if (choice == 3) case3D();

    return 0;
}
