#include<bits/stdc++.h>

using namespace std;

class TreeNode
{

    public:
    int data;
    TreeNode *leftChild, *rightChild;

    TreeNode(int data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    // Insertion

    void Insert(int data)
    {
        
        if(data == this->data){
            return;
        }

        if(data < this->data) {
            if(leftChild == NULL) {
                leftChild = new TreeNode(data);
            } else {
                leftChild->Insert(data);
            }
        } else {
            if(rightChild == NULL) {
                rightChild = new TreeNode(data);
            } else {
                rightChild->Insert(data);
            }
        }
    }

    // Deletion
    
    
    // Traversals

    void InorderTraverse(){

        // left -> root -> right

        if(leftChild != NULL) {
            leftChild->InorderTraverse();
        }
        cout << data << " ";
        if(rightChild != NULL){
            rightChild->InorderTraverse();
        }
    }

    void Preorder(){

        // root -> left -> right

        cout << data << " ";
        if(leftChild != NULL){
            leftChild->Preorder();
        }
        if(rightChild != NULL){
            rightChild->Preorder();
        }
    }

    void Postorder(){

        // left -> right -> root
        if(leftChild != NULL) {
            leftChild->Postorder();
        }
        if(rightChild != NULL){
            rightChild->Postorder();
        }
        cout << data << " ";
    }

    void Levelorder(TreeNode *node){
        queue<TreeNode*> q;
        cout << node->data << " ";
        q.push(node);
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            if(node->leftChild){
                cout << node->leftChild->data << " ";
                q.push(node->leftChild);
            }
            if(node->rightChild){
                cout << node->rightChild->data << " ";
                q.push(node->rightChild);
            }
        }
         
    }

    // Searching

    TreeNode *Search(int key){
        if(key == this->data) {
            return this;
        }

        if(key < this->data) {
            if(leftChild != NULL) {
                return leftChild->Search(key);
            }

        } else {
            if(rightChild != NULL) {
                return rightChild->Search(key);
            }
        }

        return NULL;
    }

    int getMinimum(){
        if(leftChild == NULL) {
            return this->data;
        } else {
            return leftChild->getMinimum();
        }
    }

    int getMaximum(){
        if(rightChild == NULL) {
            return this->data;
        } else {
            return rightChild->getMaximum();
        }
    }

    

    

};

class Tree
{
    private:
    TreeNode *root = NULL;

    public:
    
    void Insert(int data){
        if(root == NULL){
            root = new TreeNode(data);
        } else {
            root->Insert(data);
        }
    }

    void InorderTraverse(){
        if(root != NULL) {
            root->InorderTraverse();
        }
        cout << "\n";
    }

    void PreorderTraverse(){
        if(root != NULL) {
            root->Preorder();
        }
        cout << "\n";
    }

    void PostorderTraverse() {
        if(root != NULL) {
            root->Postorder();
        }
        cout << "\n";
    }

    void LevelorderTraverse() {
        if(root != NULL) {
            root->Levelorder(root);
        }
        cout << "\n";
    }
    
    TreeNode *Search(int key){
        if (root != NULL) {
            return root->Search(key);
        } else {
            return NULL;
        }
    }

    int getMinimum(){
        if(root != NULL) {
            return root->getMinimum();
        }
    }

    int getMaximum() {
        if(root != NULL) {
            return root->getMaximum();
        }
    }

};

int main()
{
    Tree BST = Tree();

    BST.Insert(30);
    BST.Insert(20);
    BST.Insert(40);
    BST.Insert(10);
    BST.Insert(25);
    BST.Insert(35);
    BST.Insert(50);

    BST.InorderTraverse();
    BST.PreorderTraverse();
    BST.PostorderTraverse();
    BST.LevelorderTraverse();

    cout << BST.Search(50) << endl;
    cout << BST.getMinimum() << endl;
    cout << BST.getMaximum() << endl;

    
}