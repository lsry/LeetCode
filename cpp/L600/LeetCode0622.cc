#include <vector>

class MyCircularQueue {
private:
    std::vector<int> vq;
    int front, rear;
    int sz;
public:
    MyCircularQueue(int k): vq(k + 1), front(0), rear(0), sz(k + 1) {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vq[rear] = value;
        rear = (rear + 1) % sz;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % sz;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : vq[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : vq[(rear - 1 + sz) % sz];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % sz == front;
    }
};