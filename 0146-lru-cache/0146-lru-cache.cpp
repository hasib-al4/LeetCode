class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key1, int val1) {
            key = key1;
            val = val1;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(node* newNode) {
        node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void delNode(node* oldNode) {
        node* delprev = oldNode -> prev;
        node* delnext = oldNode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            node* resNode = mpp[key];
            int res = resNode -> val;
            mpp.erase(key);
            delNode(resNode);
            addNode(resNode);
            mpp[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            node* existingNode = mpp[key];
            mpp.erase(key);
            delNode(existingNode);
        }
        else if(mpp.size() == cap) {
            mpp.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }
        addNode(new node(key, value));
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */