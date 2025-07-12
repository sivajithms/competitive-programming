#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    class Node {
    public:
        int key, val, cnt;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k; val = v; cnt = 1;
        }
    };
    class List {
    public:
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* n){
            Node* temp = head->next;
            head->next = n;
            n->next = temp;
            temp->prev = n;
            n->prev = head;
            size++;
        }

        void removeNode(Node* n){
            Node* prv = n->prev;
            Node* nxt = n->next;
            prv->next = nxt;
            nxt->prev = prv;
            size--;
        }
    };

    int cap, minFreq, currSize;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;

public:
    LFUCache(int capacity) {
        cap = capacity; minFreq = 0; currSize = 0;
    }

    void updateFreq(Node* n){
        freqMap[n->cnt]->removeNode(n);
        if(n->cnt == minFreq && freqMap[n->cnt]->size == 0) {
            freqMap.erase(n->cnt);
            minFreq++;
        }
        n->cnt++;
        if(freqMap.find(n->cnt) != freqMap.end()) freqMap[n->cnt]->addFront(n);
        else {
            freqMap[n->cnt] = new List();
            freqMap[n->cnt]->addFront(n);
        }
        keyMap[n->key] = n;
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end()) return -1;
        updateFreq(keyMap[key]);
        return keyMap[key]->val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keyMap.find(key) != keyMap.end()){
            keyMap[key]->val = value;
            updateFreq(keyMap[key]);
        } else {
            if(currSize == cap) {
                List *list = freqMap[minFreq];
                keyMap.erase(list->tail->prev->key);
                freqMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            Node* n = new Node(key, value);
            keyMap[key] = n;
            if(freqMap.find(1) == freqMap.end()){
                freqMap[1] = new List();
            }
            freqMap[1]->addFront(n);
        }
    }
};

int main() {
    int capacity;
    cout << "Enter capacity of LRU Cache: ";
    cin >> capacity;

    LFUCache cache(capacity);

    int command;
    while (true) {
        cout << "\nCommands:\n";
        cout << "1 key value => put(key, value)\n";
        cout << "2 key       => get(key)\n";
        cout << "0           => exit\n\n";

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
