#ifndef Queue_h
#define Queue_h

struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
};



struct Queue
{
    int size;
    int front, rear;
    struct TreeNode **q;
};

void create(struct Queue *Q, int size)
{
    Q->size = size;
    Q->front = Q->rear = 0;
    *Q->q = new TreeNode();
}

void enqueue(struct Queue *Q, struct TreeNode *x)
{
    if((Q->rear+1)%Q->size == Q->front)
    {
        return;
    }
    else{
        Q->rear = (Q->rear+1)%Q->size;
        Q->q[Q->rear] = x;
    }
}

TreeNode * dequeue(struct Queue *Q)
{
    struct TreeNode *x;
    if(Q->front == Q->rear)
    {
        return x;
    }
    else {
        
        Q->front = (Q->rear+1)%Q->size;
        x = Q->q[Q->front];
    }

    return x;
}

bool isEmpty(struct Queue Q)
{
    return Q.front == Q.rear;
}

#endif /* Queue_h */