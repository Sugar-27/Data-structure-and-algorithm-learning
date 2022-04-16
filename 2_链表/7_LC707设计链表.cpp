class MyLinkedList {
public:
    MyLinkedList() {
        protect = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if (index > size - 1 || index < 0) return -1;
        Node* head = protect->next;
        while (index--) {
            head = head->next;
        }
        return head->val;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        tmp->next = protect->next;
        protect->next = tmp;
        ++size;
    }
    
    void addAtTail(int val) {
        Node* tmp = new Node(val);
        Node* cur = protect;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tmp;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index == size) {
            addAtTail(val);
            return;
        } else if (index <= 0) {
            addAtHead(val);
            return;
        } else if (index > size) return;
        else {
            Node* tmp = new Node(val);
            Node* cur = protect;
            while (index--) {
                cur = cur->next;
            }
            tmp->next = cur->next;
            cur->next = tmp;
            ++size;
        } 
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index > size - 1) return;
        Node* cur = protect;
        while (index--) {
            cur = cur->next;
        }
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        --size;
    }
private:
    struct Node {
        Node(int val, Node* next) : val(val), next(next) {}
        Node(int val) : val(val), next(nullptr) {}
        int val;
        Node* next;
    };
    Node* protect;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */