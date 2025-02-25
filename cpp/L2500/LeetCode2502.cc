struct MemoryNode {
    int left;
    int right;
    MemoryNode *prev, *next;
    int mId;
};

class Allocator {
    MemoryNode *head;

    int freeSingleNode(MemoryNode *cur) {
        MemoryNode *node = cur->next;
        int size = node->right - node->left + 1;
        cur->next = node->next;
        node->next->prev = cur;
        delete node;
        return size;
    }

public:
    Allocator(int n) {
        head = new MemoryNode();
        MemoryNode *tail = new MemoryNode();
        head->left = -1;
        head->right = -1;
        head->prev = nullptr;
        head->next = tail;
        head->mId = -100;
        tail->left = n;
        tail->right = n;
        tail->prev = head;
        tail->next = nullptr;
        tail->mId = -100;
    }
    
    int allocate(int size, int mID) {
        MemoryNode *cur = head;
        while (cur->next != nullptr) {
            if (cur->next->left - cur->right - 1 >= size) {
                break;
            }
            cur = cur->next;
        }
        if (cur->next == nullptr) {
            return -1;
        }
        MemoryNode *node = new MemoryNode();
        node->left = cur->right + 1;
        node->right = cur->right + size;
        node->mId = mID;
        node->prev = cur;
        node->next = cur->next;
        cur->next->prev = node;
        cur->next = node;
        return node->left;
    }
    
    int freeMemory(int mID) {
        MemoryNode *cur = head;
        int size{0};
        while (cur->next != nullptr) {
            if (cur->next->mId == mID) {
                size += freeSingleNode(cur);
            } else {
                cur = cur->next;
            }
        }
        return size;
    }
};

int main() {
    Allocator allocator(10);
    allocator.allocate(1, 1);
    allocator.allocate(1, 2);
    allocator.allocate(1, 3);
    allocator.freeMemory(2);
    allocator.allocate(3, 4);
    allocator.allocate(1, 1);
    allocator.allocate(1, 1);
    allocator.freeMemory(1);
    allocator.allocate(10, 2);
    allocator.freeMemory(7);
}