#include <iostream>
using namespace std;

/*
===========================================================
        Circular Queue Implementation (Array Based)
         ‰›Ì– «·ÿ«»Ê— «·œ«∆—Ì »«” Œœ«„ «·„’›Ê›…
===========================================================

EN:
- Circular Queue is a queue where the last position
  is connected to the first position.
- We use modulo (%) to make the queue circular.

AR:
- «·ÿ«»Ê— «·œ«∆—Ì ÂÊ ÿ«»Ê— ¬Œ—Â „ ’· »√Ê·Â.
- ‰” Œœ„ (%) ⁄·‘«‰ ‰·› œ«Œ· «·„’›Ê›….
*/

class QueueCircular {

    /* ===================== VARIABLES ===================== */

    int front;   // EN: Index of first element
                 // AR: „ƒ‘— √Ê· ⁄‰’— ›Ì «·ÿ«»Ê—

    int rear;    // EN: Index of last element
                 // AR: „ƒ‘— ¬Œ— ⁄‰’— ›Ì «·ÿ«»Ê—

    int sizer;   // EN: Maximum size of the queue
                 // AR: «·ÕÃ„ «·√ﬁ’Ï ··ÿ«»Ê—

    int* arr;    // EN: Dynamic array to store elements
                 // AR: „’›Ê›… œÌ‰«„ÌﬂÌ… · Œ“Ì‰ «·⁄‰«’—

public:

    /* ===================== CONSTRUCTOR ===================== */

    QueueCircular(int size) {

        // EN: Save the size of the queue
        // AR: Õ›Ÿ ÕÃ„ «·ÿ«»Ê—
        sizer = size;

        // EN: -1 means the queue is empty
        // AR: -1 Ì⁄‰Ì «·ÿ«»Ê— ›«÷Ì
        front = rear = -1;

        // EN: Create dynamic array
        // AR: ≈‰‘«¡ «·„’›Ê›… «·œÌ‰«„ÌﬂÌ…
        arr = new int[sizer];
    }

    /* ===================== IS EMPTY ===================== */

    bool isEmpty() {

        // EN: Queue is empty if front == -1
        // AR: «·ÿ«»Ê— ›«÷Ì ≈–« ﬂ«‰ front = -1
        return front == -1;
    }

    /* ===================== IS FULL ===================== */

    bool isFull() {

        /*
        EN:
        Queue is full if next position of rear
        (circularly) equals front.

        AR:
        «·ÿ«»Ê— „„ ·∆ ≈–« «·„ﬂ«‰ «· «·Ì ·‹ rear
        (»‘ﬂ· œ«∆—Ì) Ì”«ÊÌ front
        */

        return (rear + 1) % sizer == front;
    }

    /* ===================== ENQUEUE ===================== */

    void Enqueue(int value) {

        // EN: Check if queue is full
        // AR: ›Õ’ ≈–« «·ÿ«»Ê— „„ ·∆
        if (isFull()) {
            cout << "Queue Is Full" << endl;
            return;
        }

        // EN: If queue is empty (first insertion)
        // AR: ≈–« ﬂ«‰  √Ê· ≈÷«›…
        if (isEmpty()) {
            front = 0;
        }

        // EN: Move rear forward circularly
        // AR:  Õ—Ìﬂ rear ··√„«„ »‘ﬂ· œ«∆—Ì
        rear = (rear + 1) % sizer;

        // EN: Insert the value
        // AR: ≈œŒ«· «·ﬁÌ„…
        arr[rear] = value;
    }

    /* ===================== DEQUEUE ===================== */

    void Dequeue() {

        // EN: Check if queue is empty
        // AR: ›Õ’ ≈–« «·ÿ«»Ê— ›«÷Ì
        if (isEmpty()) {
            cout << "Queue Is Empty" << endl;
            return;
        }

        /*
        EN:
        If only one element exists,
        reset the queue.

        AR:
        ≈–« ﬂ«‰ ⁄‰’— Ê«Õœ ›ﬁÿ°
        ‰—Ã¯⁄ «·ÿ«»Ê— ›«÷Ì
        */
        if (front == rear) {
            front = rear = -1;
        }
        else {
            // EN: Move front forward circularly
            // AR:  Õ—Ìﬂ front ··√„«„ »‘ﬂ· œ«∆—Ì
            front = (front + 1) % sizer;
        }
    }

    /* ===================== DISPLAY ===================== */

    void Display() {

        // EN: If queue is empty
        // AR: ≈–« «·ÿ«»Ê— ›«÷Ì
        if (isEmpty()) {
            cout << "Queue Is Empty" << endl;
            return;
        }

        /*
        EN:
        Start from front and move until rear
        using circular movement.

        AR:
        ‰»œ√ „‰ front Ê‰·› ·Õœ rear
        »«” Œœ«„ «·Õ—ﬂ… «·œ«∆—Ì…
        */

        for (int i = front; i != (rear + 1) % sizer; i = (i + 1) % sizer) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    /* ===================== GET FRONT ===================== */

    int getFront() {

        // EN: Return front element if exists
        // AR: ≈—Ã«⁄ √Ê· ⁄‰’— ≈–« „ÊÃÊœ
        if (!isEmpty())
            return arr[front];

        cout << "Queue Is Empty" << endl;
        return -1;
    }

    /* ===================== GET REAR ===================== */

    int getRear() {

        // EN: Return rear element if exists
        // AR: ≈—Ã«⁄ ¬Œ— ⁄‰’— ≈–« „ÊÃÊœ
        if (!isEmpty())
            return arr[rear];

        cout << "Queue Is Empty" << endl;
        return -1;
    }
};

/* ===================== MAIN FUNCTION ===================== */

int main() {

    // EN: Create Circular Queue of size 5
    // AR: ≈‰‘«¡ ÿ«»Ê— œ«∆—Ì »ÕÃ„ 5
    QueueCircular q(5);

    // EN: Insert elements
    // AR: ≈÷«›… ⁄‰«’—
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);

    // EN: Display elements
    // AR: ⁄—÷ «·⁄‰«’—
    q.Display();

    // EN: Remove one element
    // AR: Õ–› ⁄‰’—
    q.Dequeue();

    // EN: Display again
    // AR: ⁄—÷ „—… √Œ—Ï
    q.Display();

    return 0;
}
