struct Node {
    int val;
    Node *prev, *next;

    Node(int val): val(val), prev(nullptr), next(nullptr) {}
};
class FrontMiddleBackQueue {
    Node *head, *middle;
    int len;

    void addNodeNext(Node *cur, Node *addNode) {
        cur->next->prev = addNode;
        addNode->next = cur->next;
        addNode->prev = cur;
        cur->next = addNode;
    }

    void addNodePrev(Node *cur, Node *addNode) {
        cur->prev->next = addNode;
        addNode->prev = cur->prev;
        addNode->next = cur;
        cur->prev = addNode;
    }

    void removePrev(Node *cur) {
        cur->prev->prev->next = cur;
        cur->prev = cur->prev->prev;
    }

    void removeNext(Node *cur) {
        cur->next->next->prev = cur;
        cur->next = cur->next->next;
    }
public:
    FrontMiddleBackQueue(): head(new Node(0)), len(0) {
        head->prev = head;
        head->next = head;
        middle = head;
    }
    
    void pushFront(int val) {
        Node *node = new Node(val);
        addNodeNext(head, node);
        if (len == 0) {
            middle = node;
        } else if (len % 2 == 1) {
            middle = middle->prev;
        }
        ++len;
    }
    
    void pushMiddle(int val) {
        Node *node = new Node(val);
        if (len % 2 == 0) {
            addNodeNext(middle, node);
        } else {
            addNodePrev(middle, node);
        }
        middle = node;
        ++len;
    }
    
    void pushBack(int val) {
        Node *node = new Node(val);
        addNodePrev(head, node);
        if (len == 0) {
            middle = node;
        } else if (len % 2 == 0) {
            middle = middle->next;
        }
        ++len;
    }
    
    int popFront() {
        if (len == 0) {
            return -1;
        }
        Node *node = head->next;
        if (len == 1) {
            middle = head;
        } else if (len % 2 == 0) {
            middle = middle->next;
        }
        removeNext(head);
        --len;
        int val = node->val;
        delete node;
        return val;
    }
    
    int popMiddle() {
        if (len == 0) {
            return -1;
        }
        Node *node = middle;
        if (len % 2 == 0) {
            middle = middle->next;
            removePrev(middle);
        } else {
            middle = middle->prev;
            removeNext(middle);
        }
        --len;
        int val = node->val;
        delete node;
        return val;
    }
    
    int popBack() {
        if (len == 0) {
            return -1;
        }
        if (len == 1) {
            middle = head;
        } else if (len % 2 == 1) {
            middle = middle->prev;
        }
        Node *node = head->prev;
        removePrev(head);
        int val = node->val;
        delete node;
        --len;
        return val;
    }
};