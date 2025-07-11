#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    class node {
    public:
        node* prev;
        node* next;
        int key, val;
        node(int k, int v){
            key = k;
            val = v;
        }
    };

    void deleteNode(node* n){
        node* prv = n->prev;
        node* nxt = n->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void addnode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    unordered_map<int, node*> mp;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            node * resnode = mp[key];
            int res = resnode -> val;
            mp.erase(key);
            deleteNode(resnode);
            addnode(resnode);
            mp[key] = head -> next;
            return res;
        }

        return -1;
    }

    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node * existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        if (mp.size() == capacity) {
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addnode(new node(key, value));
        mp[key] = head -> next;
    }
};

int main() {
    int capacity;
    cout << "Enter capacity of LRU Cache: ";
    cin >> capacity;

    LRUCache cache(capacity);

    cout << "\nCommands:\n";
    cout << "1 key value => put(key, value)\n";
    cout << "2 key       => get(key)\n";
    cout << "0           => exit\n\n";

    int command;
    while (true) {
        cout << "Enter command: ";
        cin >> command;

        if (command == 0) break;

        if (command == 1) {
            cout<<"enter key and value"<<endl;
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
            cout << "put(" << key << ", " << value << ") executed.\n";
        } else if (command == 2) {
            cout<<"enter key"<<endl;
            int key;
            cin >> key;
            int result = cache.get(key);
            cout << "get(" << key << ") = " << result << "\n";
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }

    cout << "Program exited.\n";
    return 0;
}
