#include <iostream>
using namespace std;

class Queue {

    int Rear;
    int Front;
    int sArray;
    int *arr;

public:

    Queue(int val) {  // Constructor
        Rear = Front = -1;
        sArray = val;
        arr = new int[sArray];
    }

    // Add
    void Enqueue(int item) {

        if (Rear != sArray - 1) {

            // Empty
            if (Front == -1) {
                Front = 0;
                Rear = 0;
                arr[Rear] = item;
            }
            else {
                arr[++Rear] = item;
            }

        }
        else {
            cout << "The Queue Is Full..." << endl;
        }
    }

    void Dequeue() {

        if (Front != -1 && Front <= Rear) {

            Front++;


            if (Front > Rear) {
                Front = Rear = -1;
            }

        }
        else {
            cout << "Queue Is Empty..." << endl;
        }
    }

    int getFront() {
        if (Front != -1 && Front <= Rear) {
            return arr[Front];
        }
        else {
            cout << "Queue Is Empty..." << endl;
            return -1;
        }
    }

    int getRear() {
        if (Front != -1 && Front <= Rear) {
            return arr[Rear];
        }
        else {
            cout << "Queue Is Empty..." << endl;
            return -1;
        }
    }

    void display() {

        if (Front != -1 && Front <= Rear) {
            for (int i = Front; i <= Rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Queue Is Empty..." << endl;
        }
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

int main() {

    Queue Q(10);

    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);

    Q.display();

    cout << "===========" << endl;

    Q.Dequeue();
    Q.display();

    cout << "Front: " << Q.getFront() << endl;
    cout << "Rear: " << Q.getRear() << endl;

    return 0;
}
