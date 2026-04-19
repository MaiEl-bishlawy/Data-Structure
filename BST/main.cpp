#include <algorithm>
#include <iostream>


using namespace std;

const long long N = 1e6 + 6;
const long long mod = 1e9 + 7;

void GO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
# Binary Search Tree (BST) Implementation in C++

This project implements a Binary Search Tree with full functionality.

## Features:
- Insert nodes
- Search for a value
- Delete nodes (leaf / one child / two children)
- Traversals:
  - Inorder
  - Preorder
  - Postorder
- Find:
  - Minimum value
  - Maximum value
- Tree statistics:
  - Total nodes
  - Leaf nodes
  - Parent (internal) nodes
  - Height of tree / node
  - Depth of a node

## Complexity:
- Insert: O(h)
- Search: O(h)
- Delete: O(h)
- Traversals: O(n)

Where h is the height of the tree.

## Purpose:
Understanding hierarchical data structure and recursive algorithms.
*/

class Node {
public :
    int data;
    Node *right;
    Node *left;

    Node(int n) {
        data = n;
        right = NULL;
        left = NULL;
    }
};

class BST {
    Node *root;

public:
    BST() {
        root = NULL;
    }

    Node *insert(Node *r,int n) {
        if (r == NULL)return new Node(n);
        else if (n < r->data)r->left = insert(r->left, n);
        else r->right = insert(r->right, n);
        return r;
    }

    void insert(int n) {
        root = insert(root, n);
    }

    Node *search(Node *r,int key) {
        if (r == NULL) return NULL;
        else if (key < r->data) return search(r->left, key);
        else if (key > r->data) return search(r->right, key);
        else return r;
    }

    bool search(int key) {
        Node *ans = search(root, key);
        if (ans == NULL) return false;
        else return true;
    }

    void preorder(Node *r) {
        if (r == NULL) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void postorder(Node *r) {
        if (r == NULL) return;
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
    void preorder() {
        preorder(root);cout << "\n";
    }
    void inorder() {
        inorder(root);cout << "\n";
    }
    void postorder() {
        postorder(root);cout << "\n";
    }
    Node *maxx(Node*r) {
        if (r==NULL) return NULL;
        else if (r->right==NULL) return r;
        else return maxx(r->right);
    }
    Node *mini(Node*r) {
        if (r==NULL) return NULL;
        else if (r->left==NULL) return r;
        else return mini(r->left);
    }
    int maxx() {
        Node*ans=maxx(root);
        if (ans==NULL)return -1;
        else return ans->data;
    }
    int mini() {
        Node *ans=mini(root);
        if (ans==NULL)return -1;
        else return ans->data;
    }
    Node *deleteNode(Node *r,int n){
    if (r==NULL) return NULL;
        if (n>r->data)r->right=deleteNode(r->right,n);
        else if (n<r->data)r->left=deleteNode(r->left,n);
        else {
          if (r->right==NULL&&r->left==NULL) {
              delete r;
              r=NULL;
          }
           else if (r->right==NULL&&r->left!=NULL) {
                Node*temp=r->left;
                delete r;
                return temp;
            }
            else if (r->right!=NULL&&r->left==NULL) {
               Node *temp=r->right;
                delete r;
                return temp;
            }
            else {
                Node *maxxx=maxx(r->left);
                r->data=maxxx->data;
                r->left=deleteNode(r->left,maxxx->data);
            }
        }
        return r;
    }
    void deleteNode(int n) {
        root=deleteNode(root,n);
    }
    int countnodes(Node *r) {
        if (r==NULL) return 0;
        return 1+countnodes(r->left)+countnodes(r->right);
    }
    int countparents(Node*r) {
        //count interior nodes
        if (r==NULL) return 0;
        if (r->left==NULL&&r->right==NULL) return 0;
        return 1+countparents(r->left)+countparents(r->right);
    }
    int countleaves(Node *r) {
        if (r==NULL) return 0;
        if (r->left==NULL&&r->right==NULL) return 1;
        return countleaves(r->left)+countleaves(r->right);
    }
    int countnode() { return countnodes(root); }
    int countleaves() { return countleaves(root); }
    int countparents() { return countparents(root); }

    Node *successor(Node *r) {
        if (r==NULL)return NULL;
        if (r->left==NULL) return r;
        return successor (r->left);
    }
    Node *predecessor(Node *r) {
        if (r==NULL)return NULL;
        if (r->right==NULL)return r;
        return predecessor(r->right);
    }
    int depth(Node*r,int n,int lvl) {
        if (r==NULL)return -1;
        if (n<r->data) return depth(r->left,n,lvl+1);
        if (n>r->data) return depth(r->right,n,lvl+1);
        else return lvl;
    }
    int height(Node *r) {
        if (r==NULL) return -1;
        return 1+max (height(r->left),height(r->right));
    }
    int height (Node *r,int n) {
        if (r==NULL) return -1;
        else if (n<r->data) return height(r->left,n);
        else if (n>r->data) return height(r->right,n);
        else return height(r);
    }
    void clear(Node* r) {
        if (r == nullptr) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }
    ~BST() {
        clear(root);
    }


};


signed main() {
    GO();

        BST tree;

        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        cout << "Inorder Traversal: ";
        tree.inorder();   // المفروض يطلع: 20 30 40 50 60 70 80

        cout << "Preorder Traversal: ";
        tree.preorder();  // المفروض يطلع: 50 30 20 40 70 60 80

        cout << "Postorder Traversal: ";
        tree.postorder(); // المفروض يطلع: 20 40 30 60 80 70 50

        // البحث
        cout << "Search 40: " << (tree.search(40) ? "Found\n" : "Not Found\n");
        cout << "Search 90: " << (tree.search(90) ? "Found\n" : "Not Found\n");

        // الحذف
        tree.deleteNode(20); // حذف leaf
        tree.deleteNode(30); // حذف عقدة 1 child
        tree.deleteNode(50); // حذف عقدة 2 child

        cout << "Inorder Traversal after deletions: ";
        tree.inorder();  // المفروض يطلع: 40 60 70 80

        // عدد NODES
        cout << "Total nodes: " << tree.countnode() << "\n";
        cout << "Leaf nodes: " << tree.countleaves() << "\n";
        cout << "Parent nodes: " << tree.countparents() << "\n";

        // MAX,MINI
        cout << "Maximum: " << tree.maxx() << "\n";
        cout << "Minimum: " << tree.mini() << "\n";

        return 0;
    }

