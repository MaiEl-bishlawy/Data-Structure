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

class StaticStack {
    static const int s = 5;
    int top;
    int arr[s];

public:
    StaticStack() {
        top = -1;
    }

    void push(int val) {
        if (top == s - 1) {
            cout << "stack is full" << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

class DynamicStack {
    int size;
    int *arr;
    int top;

public:
    DynamicStack(int s) {
        size = s;
        arr = new int[s];
        top = -1;
    }

    ~DynamicStack() {
        delete[] arr;
    }

    void resize() {
        int *newarr = new int [size * 2];
        for (int i = 0; i <= top; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        size *= 2;
    }

    void push(int val) {
        if (top == size - 1) {
            resize();
        }
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    int sizeStack() {
        return top + 1;
    }

    void display() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class node {
public :
    int data;
    node *next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedStack {
    node *top;

public:
    LinkedStack() {
        top = NULL;
    }

    bool isempty() {
        return top == NULL;
    }

    void push(int val) {
        node *newnode = new node(val);
        if (isempty()) {
            top = newnode;
            return;
        } else {
            newnode->next = top;
            top = newnode;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }

    int popvalue() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        node *temp = top;
        int data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }
    void display() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return;
        }
        node *temp = top;
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    int peek() {
        if (isempty()) {
            return -1;
        }
        return top->data;
    }

    int size() {
        int cnt = 0;
        node *temp = top;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }


    void copy(LinkedStack &s) {
        int c = s.size();
        int arr[c];
        node *temp = s.top;
        int idx = c - 1;
        while (temp != NULL) {
            arr[idx--] = temp->data;
            temp = temp->next;
        }
        for (int i = 0; i < c; i++) {
            push(arr[i]);
        }
    }
};

signed main() {
    Go();
    StaticStack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    if (s1.peek() == -1) {
        cout << "stack is empty"<<endl;
    } else {
        cout << s1.peek() << endl;
    }
    s1.display();

    DynamicStack s2(2);
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.display();

    LinkedStack s3;
    int n;
    cin>>n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s3.push(x);
    }
    s3.display();
    s3.pop();
    s3.display();
    if (s3.peek() == -1) {
        cout << "stack is empty" << endl;
    } else {
        cout << s3.peek() << endl;
    }
    cout << s3.size() << endl;
    LinkedStack s4;
    s4.copy(s3);
    s4.display();

    return 0;
}
