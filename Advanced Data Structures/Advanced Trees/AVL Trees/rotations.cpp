#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right, *left;
    int height;

    Node(int data, int height) {
        this->data = data;
        this->left = this->right = NULL;
        this->height = height;
    }

} * root = NULL;

int NodeHeight(Node *node) {
    int hLeft, hRight;
    hLeft = (node && node->left ? node->left->height : 0);
    hRight = (node && node->right ? node->right->height : 0);

    return hLeft > hRight ? hLeft+1 : hRight+1;
}

int BalanceFactor(Node *node) {

    int hLeft, hRight;
    hLeft = (node && node->left ? node->left->height : 0);
    hRight = (node && node->right ? node->right->height : 0);

    return hLeft - hRight;
}


Node * LLRotation(Node *node) {
    Node *rChild = node->right;
    Node *lChild = node->left;

    rChild->right = node;
    node->left = lChild;
    node->height = NodeHeight(node);
    lChild->height = NodeHeight(lChild);

    if(node == root) {
        root = lChild;
    }

    return lChild;
}

Node * RRRotation(Node *node) {
    Node *rChild = node->right;
    Node *lChild = node->left;

    lChild->left = node;
    node->right = rChild;
    node->height = NodeHeight(node);
    rChild->height = NodeHeight(rChild);

    if(node == root) {
        root = rChild;
    }

    return rChild;
}


// TODO : Implement LR & RL

Node * LRRotation(Node *node) {
    return NULL;
}

Node * RLRotation(Node *node) {
    return NULL;
}




Node * Insert(Node *curr, int key) {
    Node *temp = NULL;

    if(curr == nullptr) {
        temp = new Node(key, 1);
        return temp;
    }

    if(key < curr->data) {
        curr->left = Insert(curr->left, key);
    }

    else if (key > curr->data) {
        curr->right = Insert(curr->right, key);
    }

    curr->height = NodeHeight(curr);

    // if imbalanced on left hand side, perform LL rotation
    if(BalanceFactor(curr) == 2 && BalanceFactor(curr->left) == 1) {
        return LLRotation(curr);
    }
    else if(BalanceFactor(curr) == 2 && BalanceFactor(curr->left) == -1) {
        return LRRotation(curr);
    }
    else if(BalanceFactor(curr) == -2 && BalanceFactor(curr->right) == -1) {
        return RRRotation(curr);
    }
    else if(BalanceFactor(curr) == -2 && BalanceFactor(curr->left) == 1) {
        return RLRotation(curr);
    }


    return curr;
}


int main() {

}