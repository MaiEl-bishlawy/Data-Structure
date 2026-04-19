#include <algorithm>
#include <iostream>

using namespace std;
const long long N = 1e6 + 6;
const long long mod = 1e9 + 7;

void Go() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Queue Implementation in C++

This project includes two implementations of Queue:

1. Dynamic Array Queue
2. Linked List Queue

Features:
- Enqueue
- Dequeue
- Peek (front element)
- Get rear element
- Display
- Search
- Count elements
- Clear queue

Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

Purpose:
Learning Queue (FIFO) data structure using array and linked list implementations.
*/

class node {
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = NULL;
    }
};
class DynamicQueue {
    int rear, front;
    int size;
    int *arr;
    public:
    DynamicQueue(int s) {
        front = rear = -1;
        size = s;
        arr=new int[size];
    }
    bool isempty() {
        return front == -1||front > rear;
    }
    bool isFull() {
        return (rear==size-1) ;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout<<"queue is full"<<endl;
            return;
        }
        if (isempty()) {
            front = rear = 0;
            arr[rear] = val;
            return;
        }
        rear++;
        arr[rear] = val;
    }
    void dequeue() {
        if (isempty()) {
            cout<<"queue is empty"<<endl;
            return ;
        }
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void display() {
        if (isempty()) {
            cout<<"queue is empty"<<endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~DynamicQueue() {
        delete[] arr;
    }

};
class LinkedQueue {
    node *front, *rear;
    public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }
    bool isempty() {
        return front == NULL;
    }
    void enqueue(int val) {
        node *newnode=new node(val);
        if (isempty()) {
            front = newnode;
            rear = newnode;
            return;
        }
        rear->next = newnode;
        rear =newnode;
    }
    void dequeue() {
        if (isempty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
            return;
        }
        node*temp=front;
        front = front->next;
        delete temp;

    }
    void display() {
        node *temp=front;
        if (isempty()) {
            cout<<"Empty Queue"<<endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int peek() {
        if (isempty()) {
            return -1;
        }
        return front->data;
    }
    int getrear() {
        if (isempty()) {
            return -1;
        }
        return rear->data;
    }
    void clear() {
        while (!isempty()) {
            dequeue();
        }
    }
    bool search(int val) {
        if (isempty()) {
            return false;
        }
        node *temp=front;
        while (temp != NULL&&temp->data != val) {
           temp = temp->next;
        }
        if (temp == NULL) {
            return false;
        }
        return true;
    }
    int count () {
        int cnt=0;
        node *temp=front;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }


};
signed main() {
    Go();
    DynamicQueue d(5);
    d.enqueue(1);
    d.enqueue(2);
    d.enqueue(3);
    d.enqueue(4);
    d.display();
    d.dequeue();
    d.dequeue();
    d.display();
    int n;
    cin>>n;
    LinkedQueue q;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cout <<q.count()<<endl;
    q.display();
    q.dequeue();
    cout <<q.count()<<endl;
    q.display();
    bool flag=q.search(5);
    if(flag) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

    cout <<q.peek()<<endl;
    cout <<q.getrear()<<endl;
    q.clear();
    q.display();
    return 0;
}