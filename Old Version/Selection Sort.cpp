#include <iostream>
using namespace std;

// ===== Selection Sort =====
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}

// ===== 1D =====
void case1D() {
    int n;
    cout << "Enter Size Array :";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);

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

    selectionSort(temp, k);

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

    selectionSort(temp, k);

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
    cout << "Enter Choose 1 for 1D - 3 - 3D"<<endl;
    int choice;
    cin >> choice;

    if (choice == 1) case1D();
    if (choice == 2) case2D();
    if (choice == 3) case3D();

    return 0;
}
