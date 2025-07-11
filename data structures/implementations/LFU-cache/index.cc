#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key,value,cnt;
    Node *next;
    Node *prev;
    Node(int _key,int _value) {
        key=_key;
        value=_value;
        cnt=1;
    }
};

class List {
public:
    int size;
    Node *head;
    Node *tail;
    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }


    void addfront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removenode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keynode;
    map<int, List*> freqlistmap;
    int maxsizecache;
    int minfreq;
    int cursize;
public:
    LFUCache(int capacity) {
        maxsizecache=capacity;
        minfreq=0;
        cursize=0;
    }
    void updatefreqlistmap(Node *node) {
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removenode(node);
        if(node->cnt==minfreq and freqlistmap[node->cnt]->size==0) {
            minfreq++;
        }
        List *nexthigherfreqlist=new List();
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end()) {
            nexthigherfreqlist=freqlistmap[node->cnt+1];
        }
        node->cnt+=1;
        nexthigherfreqlist->addfront(node);
        freqlistmap[node->cnt]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()) {
            Node *node=keynode[key];
            int val=node->value;
            updatefreqlistmap(node);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxsizecache==0) return;
        if(keynode.find(key) != keynode.end()) {
            Node *node = keynode[key];
            node->value = value;
            updatefreqlistmap(node);
        } else {
            if(cursize==maxsizecache) {
                List *list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlistmap[minfreq]->removenode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List *listfreq=new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()) {
                listfreq=freqlistmap[minfreq];
            }
            Node *node=new Node(key,value);
            listfreq->addfront(node);
            keynode[key]=node;
            freqlistmap[minfreq]=listfreq;
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
