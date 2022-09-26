#include <memory>
class MyLinkedList;
class MyNode {
private:
    int val;
    std::shared_ptr<MyNode> next;
public:
    friend class MyLinkedList;
    MyNode(int val, std::shared_ptr<MyNode> n) : val(val), next(n) {}
};

class MyLinkedList {
private:
    std::shared_ptr<MyNode> head;
    int size;

    void insertAtIndex(int index, int val) {
        std::shared_ptr<MyNode> node = head;
        for (int i = 0;i < index;++i) {
            node = node->next;
        }
        std::shared_ptr<MyNode> n{std::make_shared<MyNode>(val, node->next)};
        node->next = n;
        ++size;
    }
public:
    MyLinkedList(): size(0), head(std::make_shared<MyNode>(0, nullptr)) {}
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        std::shared_ptr<MyNode> node = head;
        for (int i = 0;i < index;++i) {
            node = node->next;
        }
        return node->next->val;
    }
    
    void addAtHead(int val) {
        std::shared_ptr<MyNode> node{std::make_shared<MyNode>(val, head->next)};
        head->next = node;
        ++size;
    }
    
    void addAtTail(int val) {
        insertAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        } else if (index < 0) {
            addAtHead(val);
        } else {
            insertAtIndex(index, val);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        std::shared_ptr<MyNode> node = head;
        for (int i = 0;i < index;++i) {
            node = node->next;
        }
        node->next = node->next->next;
        --size;
    }
};