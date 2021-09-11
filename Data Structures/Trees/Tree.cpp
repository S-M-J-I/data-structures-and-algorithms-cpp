#include<bits/stdc++.h>

using namespace std;

// There was a problem with the Queue.h file, so i used the STL queue<>

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
};

struct TreeNode *root = NULL;

void createTree()
{
    struct TreeNode *p, *t;
    int x;
    queue<TreeNode*> q;

    printf("Enter root : ");
    scanf("%d", &x);
    root = new TreeNode();
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        printf("Enter %d's left child : ", p->data);
        scanf("%d", &x);
        if( x != -1 )
        {
            t = new TreeNode();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter %d's right child : ", p->data);
        scanf("%d", &x);
        if(x != -1) 
        {
            t = new TreeNode();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }

}

void Inorder(struct TreeNode *node)
{
    if(node)
    {
        Inorder(node->lchild);
        cout << node->data << " ";
        Inorder(node->rchild);
    }
}


void Preorder(struct TreeNode *node)
{
    if(node)
    {
        cout << node->data << " ";
        Preorder(node->lchild);
        Preorder(node->rchild);
    }
}

void Postorder(struct TreeNode *node)
{
    if(node)
    {
        Postorder(node->lchild);
        Postorder(node->rchild);
        cout << node->data << " ";
    }
}

void Levelorder(struct TreeNode *node)
{
    queue<TreeNode*> q;
    cout << node->data << " ";
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if(node->lchild)
        {
            cout << node->lchild->data << " ";
            q.push(node->lchild);
        }

        if(node->rchild)
        {
            cout << node->rchild->data << " ";
            q.push(node->rchild);
        }
    }
}

int count(struct TreeNode *node)
{
    int x, y;
    if(node)
    {
        x = count(node->lchild);
        y= count(node->rchild);

        return x+y+1;
    }

    return 0;
}

int main()
{
    createTree();
    Inorder(root);
    cout << "\n";
    Preorder(root);
    cout << "\n";
    Postorder(root);
    cout << "\n";
    Levelorder(root);
    cout << "\n";

    cout << "Max Height Possible: " << count(root) - 1 << endl;
}