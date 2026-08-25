#include <iostream>
using namespace std;

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

// ===== 1D =====
void case1D() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// ===== 2D =====
void case2D() {
    int r, c;

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

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[k++] = arr[i][j];

    bubbleSort(temp, k);

    k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << temp[k++] << " ";
        cout << endl;
    }
}

// ===== 3D =====
void case3D() {
    int x, y, z;
    cin >> x >> y >> z;

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

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int l = 0; l < z; l++)
                temp[k++] = arr[i][j][l];

    bubbleSort(temp, k);

    k = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int l = 0; l < z; l++)
                cout << temp[k++] << " ";
            cout << endl;
        }
    }
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
