#include <iostream>

using namespace std;



// Two Static Array Daimansion
// Declare Array Two Daimansion
void RowAvg(int Arr[][3], int r);
void ColumnSum(int Arr[][3], int r);
void SwapingElement(int Arr[][3], int r);
void Traversal (int Arr[][3] , int r);

int main()
{
    int r;
    cout<<"Enter Row Value : ";
    cin >> r ;  // Row


    int Arr[r][3]; // Column = 3 Because Bounds -_-

    // Create Array + Insert Element Value

   for(int i=0;i<r;i++)
        for(int j=0;j<3;j++){
            cout<<"Enter value of row["<<(i+1)<<"] column["<<(j+1)<<"] : ";
            cin>>Arr[i][j];
        }
//============================================================================================

system("cls");
// Operand Menu...
while (true){

    cout<<"1 - Each Row Average." <<endl;
    cout<<"2 - Each Column Sum." <<endl;
    cout<<"3 - Inverse main Row with Sub Row." <<endl;
    cout<<"4 - Traversal." <<endl;
    cout<<"Choose Between 1~4." <<endl;

    int choose;
    cin>>choose;
    switch(choose){

    case 1 : {  RowAvg(Arr,r); break; }
    case 2 : {  ColumnSum(Arr , r ); break; }
    case 3 : {  SwapingElement(Arr , r ); break; }
    case 4 : {  Traversal (Arr , r); break; }

        default:
        cout<<"Invalid Operand..."<<endl;
    }
}
//============================================================================================



    return 0;
}

// Method

void RowAvg(int Arr[][3] ,int r ){
 system("cls");
                 for(int i=0;i<r;i++){
                 float sj=0; // Sum + Sum(old);

                 for(int j=0;j<3;j++){
                 sj = sj + Arr[i][j];
            }

                float avg = sj/3.0;
                cout<<"Row["<<i<<"] avg = "<<avg<<endl;
        }

}

void SwapingElement(int Arr[][3] ,int r ){
 system("cls");

                for(int i=0;i<r;i++){
                int temp = Arr[i][i];
                Arr[i][i] = Arr[i][2-i];
                Arr[i][2-i] = temp;
}
        cout<<"Array after swap:"<<endl;

         for(int i=0;i<r;i++){
         for(int j=0;j<3;j++){
         cout<<Arr[i][j]<<" ";
    }
         cout<<endl;
}
}
void ColumnSum(int Arr[][3], int r){
    system("cls");

    int total = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < r; j++){
            total += Arr[j][i];
        }
    }

    cout << "Total Sum Of All Columns = " << total << endl;
}

void Traversal (int Arr[][3] , int r){

        // Traversal
        system("cls");
         cout<<"Value of Row [R] Column [C] : "<<endl;
         for(int i=0;i<r;i++){
        for(int j=0;j<3;j++){

            cout<<Arr[i][j]<< "\t";
        }
         cout<<endl;
         }
}
