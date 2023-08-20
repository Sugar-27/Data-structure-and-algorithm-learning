// 模板题，实现一个LRU

class LRUCache {
public:
  LRUCache(int capacity) : capacity(capacity) {
    head.next = &tail;
    tail.pre = &head;
  }

  int get(int key) {
    if (h.find(key) == h.end())
      return -1;
    Node *item = h[key];
    removeFromlist(item);
    insertToList(item);
    return item->value;
  }

  void put(int key, int value) {
    if (h.find(key) == h.end()) {
      Node *item = new Node();
      item->key = key, item->value = value;
      insertToList(item);
      h[key] = item;
    } else {
      Node *item = h[key];
      item->value = value;
      removeFromlist(item);
      insertToList(item);
    }
    if (h.size() > capacity) {
      Node *node = tail.pre;
      removeFromlist(node);
      h.erase(node->key);
      delete node;
    }
  }

private:
  struct Node {
    int key;
    int value;
    Node *pre;
    Node *next;
  };

  void removeFromlist(Node *node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
  }

  void insertToList(Node *node) {
    head.next->pre = node;
    node->next = head.next;
    head.next = node;
    node->pre = &head;
  }

  int capacity;
  unordered_map<int, Node *> h;
  Node head, tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */