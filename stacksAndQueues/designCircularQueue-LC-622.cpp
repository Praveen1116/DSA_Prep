/* Problem:
   Design a Circular Queue that supports enqueue, dequeue, front, rear,
   isEmpty, and isFull operations in O(1) time.
*/

/* Intuition:
   In a normal queue implemented using an array, once the rear reaches the
   last index, no more elements can be inserted even if there are empty
   positions at the beginning due to previous deletions. This wastes space.

   A Circular Queue solves this problem by treating the array as circular.
   When the rear reaches the last index, it wraps around to the beginning of
   the array (if space is available). Similarly, the front also moves in a
   circular manner after every dequeue.

   We use modulo (%) to achieve this circular movement and maintain a count
   variable to easily determine whether the queue is empty or full.
*/

/* Approach:
   1. Initialize an array of size k along with:
      - front = -1
      - rear = -1
      - count = 0

   2. Enqueue:
      - If the queue is full, return false.
      - If the queue is empty, initialize front = 0.
      - Move rear circularly using:
            rear = (rear + 1) % size
      - Insert the value and increment count.

   3. Dequeue:
      - If the queue is empty, return false.
      - Decrement count.
      - If the queue becomes empty after deletion, reset both front and rear
        to -1.
      - Otherwise, move front circularly using:
            front = (front + 1) % size

   4. Front():
      - Return the element at front.
      - If the queue is empty, return -1.

   5. Rear():
      - Return the element at rear.
      - If the queue is empty, return -1.

   6. isEmpty():
      - Return true if count == 0.

   7. isFull():
      - Return true if count == size.

   Time Complexity:
   - MyCircularQueue(k) : O(k) (initializing the vector of size k) 
   - Enqueue : O(1)
   - Dequeue : O(1)
   - Front   : O(1)
   - Rear    : O(1)
   - isEmpty : O(1)
   - isFull  : O(1)

   Space Complexity: O(k)
*/

Question Link: https://leetcode.com/problems/design-circular-queue/

// Code:

class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int rear;
    int count;
    int size;

    MyCircularQueue(int k) {
        size = k;
        front = -1;
        rear = -1;
        count = 0;
        arr = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        if(isEmpty()) front = 0;

        rear = (rear+1)%size;
        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        count--;
        if (count == 0) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */