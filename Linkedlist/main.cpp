#include <iostream>
#include <vector>

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
Singly Linked List Implementation in C++

Features:
- Insert (begin, end, by value, by index)
- Delete (begin, end, by value, by index)
- Update (by value / index)
- Search
- Count nodes
- Reverse
- Traverse (returns vector)

Time Complexity:
- Insert at beginning: O(1)
- Insert at end: O(n)
- Insert at position: O(n)
- Delete at beginning: O(1)
- Delete at end: O(n)
- Search: O(n)
- Access by index: O(n)

Purpose:
Understanding basic Linked List operations and pointer manipulation.
*/

class Node {
public :
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    bool IsEmpty() {
        return (head == NULL);
    }

    void insertAtBegin(int val) {
        Node *newnode = new Node(val);
        if (IsEmpty()) {
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtEnd(int val) {
        if (IsEmpty()) {
            insertAtBegin(val);
        } else {
            Node *newnode = new Node(val);
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void insertAtPositem(int val,int item) {
        //insert after
        Node *newnode = new Node(val);
        Node *temp = head;
        //insert after
        while (temp != NULL && temp->data != item) {
            temp = temp->next;
        }
        //insert before
        /*
        while (temp->next!=NULL&&temp->next->data!=item) {
                temp=temp->next;
            }
         */
        if (temp == NULL) {
            cout << "Error" << endl;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void insertAtPosidx(int val,int idx) {
        if (idx <= 0) {
            cout << "Error" << endl;
            return;
        }
        if (idx == 1) {
            insertAtBegin(val);
            return;
        } else {
            Node *newnode = new Node(val);
            int cnt = 1;
            Node *temp = head;
            while (temp != NULL && cnt < idx - 1) {
                temp = temp->next;
                cnt++;
            }
            if (temp == NULL) {
                cout << "Error" << endl;
                return;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void deleteatbegin() {
        if (IsEmpty()) {
            cout << "Error" << endl;
            return;
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteatend() {
        if (IsEmpty()) {
            cout << "Error" << endl;
            return;
        }
        if (head->next == NULL) {
            deleteatbegin();
            return;
        } else {
            Node *temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    void deleteatposval(int item) {
        if (IsEmpty()) {
            cout << "Error" << endl;
            return;
        }
        if (head->data == item) {
            deleteatbegin();
            return;
        } else {
            Node *temp = head;
            Node *prev = NULL;
            while (temp != NULL && temp->data != item) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Error" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    void deleteatposidx(int idx) {
        if (IsEmpty() || idx <= 0) {
            cout << "Error" << endl;
            return;
        }
        if (idx == 1) {
            deleteatbegin();
            return;
        } else {
            Node *temp = head;
            Node *prev = NULL;
            int cnt = 1;
            while (temp != NULL && cnt < idx) {
                prev = temp;
                temp = temp->next;
                cnt++;
            }
            if (temp == NULL) {
                cout << "Error" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (IsEmpty()) {
            cout << "Empty" << endl;
        } else {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void updatevalue(int oldValue,int newValue) {
        if (IsEmpty()) {
            cout << "Empty" << endl;
        } else {
            Node *temp = head;
            while (temp != NULL && temp->data != oldValue) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Error" << endl;
            } else {
                temp->data = newValue;
            }
        }
    }

    void updatevaluepos(int idx,int newValue) {
        if (IsEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        if (idx <= 0) {
            cout << "Error" << endl;
            return;
        } else if (idx == 1) {
            head->data = newValue;
            return;
        } else {
            Node *temp = head;
            int cnt = 1;
            while (temp != NULL && cnt < idx) {
                temp = temp->next;
                cnt++;
            }
            if (temp == NULL) {
                cout << "Error" << endl;
                return;
            }
            temp->data = newValue;
        }
    }

    bool search(int val) {
        if (IsEmpty()) {
            return false;
        } else {
            Node *temp = head;
            while (temp != NULL && temp->data != val) {
                temp = temp->next;
            }
            if (temp == NULL) {
               return false;
            } else {
               return true;
            }
        }
    }

    int size() {
        if (IsEmpty()) {
            return 0;
        } else {
            Node *temp = head;
            int cnt = 0;
            while (temp != NULL) {
                temp = temp->next;
                cnt++;
            }
            return cnt;
        }
    }
    //to optimize
    vector<int> traverse() {
        vector<int> vtemp;
        if (IsEmpty()) {
            return vtemp;
        } else {
            Node *temp = head;
            while (temp != NULL) {
                vtemp.push_back(temp->data);
                temp = temp->next;
            }
            return vtemp;
        }
    }

    void reverse() {
        if (IsEmpty()) {
            cout << "Empty" << endl;
            return;
        } else {
            Node *curr = head;
            Node *prev = NULL;
            Node *next = NULL;
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
    }

    ~LinkedList() {
        Node *temp = head;
        while (temp != NULL) {
                Node *next = temp->next;
                delete temp;
                temp = next;
        }
    }
};

int main() {
    Go();
    LinkedList s1;
    s1.insertAtBegin(5);
    s1.insertAtEnd(8);
    s1.insertAtPositem(7, 8);
    s1.insertAtPosidx(6, 2);
    s1.display();
    s1.updatevalue(8, 7);
    s1.updatevaluepos(4, 8);
    s1.display();
    cout << s1.size() << endl;
    s1.reverse();
    s1.display();
    s1.deleteatbegin(); //7 6 5
    s1.deleteatend(); //7 6
    s1.deleteatposval(7); //6
    s1.insertAtBegin(5); //5 6
    s1.insertAtEnd(7); //5 6 7
    s1.deleteatposidx(2); //5 7
    s1.display();
    s1.search(8);
    s1.reverse();
    s1.display();
    s1.updatevalue(7, 6);
    cout << s1.size() << endl;
    s1.display();
    return 0;
}
