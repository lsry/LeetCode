#include <vector>

class MyCircularDeque {
private:
    std::vector<int> qi;
    int front, tail;
    int sz;
public:
    MyCircularDeque(int k) : qi(k + 1), front(0), tail(0), sz(k + 1) {}
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            qi[tail] = value;
            tail = (tail + 1) % sz;
        } else {
            front = (front - 1 + sz) % sz;
            qi[front] = value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        qi[tail] = value;
        tail = (tail + 1) % sz;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % sz;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        tail = (tail - 1 + sz) % sz;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : qi[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : qi[(tail - 1 + sz) % sz];
    }
    
    bool isEmpty() {
        return tail == front;
    }
    
    bool isFull() {
        return (tail + 1) % sz == front;
    }
};