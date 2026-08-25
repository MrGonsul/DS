#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key,int &stp) {
    int left = 0, right = n - 1;

    while (left <= right) {
            stp++;
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

int interpolationSearch(int arr[], int n, int key,int &stp) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        stp ++;
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

int main() {
    int n,stepi=0,stepb=0;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr= new int[n];

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter number to search: ";
    cin >> key;

   int result = binarySearch(arr, n, key,stepb);
cout<<"\n The Binary search  \n";
    if (result != -1){
        cout << "Element found at index: " << result << endl;
        cout<< "After "<<stepb<<" steps"<<endl;
    }
    else
        cout << "Element not found" << endl;



     result = interpolationSearch(arr, n, key,stepi);
  cout<<"\n The interpolation search  \n";
    if (result != -1){
        cout << "Element found at index: " << result << endl;
        cout<< "After "<<stepi<<" steps"<<endl;
    }
    else
        cout << "Element not found" << endl;

    return 0;
}

