#include <iostream>

using namespace std;
int binarySearch(int array[], int low, int high, int keyfind) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (keyfind == array[mid]){
            return mid;
        }

        if (keyfind > array[mid]){
            low = mid + 1;
        }

        if (number_to_search_for < array[mid]){
            high = mid - 1;
        }

    }

  return -1;
}
int main()
{
     int r;
    cout<<"Enter Row Value : ";
    cin >> r ;  // Row


    int Arr[r]; // Column = 3 Because Bounds -_-

    // Create Array + Insert Element Value
   for(int i=0;i<r;i++){
            cout<<"Enter Value Of Row :";
            cin>>Arr[i];
        }

       int result = binarySearch(Arr,0,r-1,8); // 8 is Element that we need To find
       if(result == -1)
       cout<< "Not Found "<<endl;
       else{
       cout << "found !" <<endl;
       cout << "Result = " <<  result <<endl;
       }

    return 0;
}
