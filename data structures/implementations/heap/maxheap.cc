#include <bits/stdc++.h>
using namespace std;

class maxHeap {
public:
    int arr[100];
    int size;

    maxHeap () {
        size = 0;
    }

    void push(int num){
        int i = ++size;
        arr[i] = num;

        while(i > 1) {
            int parent = i / 2;
            if(arr[parent] < arr[i]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else return;
        }
    }

    void pop(){
        if(size == 0) {
            cout << "maxHeap is empty";
            return;
        }

        arr[1] = arr[size--];
        int idx = 1;

        while(idx <= size){
            int left = idx * 2;
            int right = idx * 2 + 1;
            int largest = idx;

            if(left <= size && arr[left] > arr[largest]) largest = left;
            if(right <= size && arr[right] > arr[largest]) largest = right;

            if(largest != idx) {
                swap(arr[idx], arr[largest]);
                idx = largest;
            } else {
                return;
            }
        }
    }


    void print() {for(int i = 0; i <= size; i++) cout<<arr[i]<<" "; cout<<endl;}
};


int main() {
    maxHeap* pq = new maxHeap();

    pq->push(5);
    pq->push(2);
    pq->push(6);
    pq->push(8);

    pq->print();


    pq->pop();

    pq->print();

    return 0;
}