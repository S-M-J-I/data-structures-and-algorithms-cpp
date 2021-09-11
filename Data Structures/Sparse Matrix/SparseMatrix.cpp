#include<bits/stdc++.h>

using namespace std;

// declare a struct element: it is the contents of the element 
struct Element
{
    // has i:row; j:column; x:element value
    int i,j,x;
};

// sparse matrix details
struct Sparse
{
    // has m:no. of rows; n:no. of columns ; num: the number of non-zero elements 
    int m,n,num;
    // declare a dynamic array e
    struct Element *e;
};

void create(struct Sparse *s)
{
    
    printf("Enter row and column :");
    // enter row and column
    scanf("%d%d", &s->m, &s->n);
    printf("Enter number of non-zero elements: ");
    // enter the number of non-zero elements
    scanf("%d", &s->num);
    // create a new array: with size num of non-zero elements
    s->e = new Element[s->num];

    printf("Enter elements : \n");
    for(int i=0; i<s->num; i++)
    {
        // take input row, column and elements
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }

}

void display(struct Sparse s)
{
    int k = 0; // for non-zero
    //from 1 -> m
    for(int i=1; i<=s.m; i++)
    {
        // from 1 -> n
        for(int j=1; j<=s.n; j++)
        {
            // if index is equal to the index of element of sparse index 
            if(i==s.e[k].i && j==s.e[k].j)
            {
                printf("\033[0;31m");
                printf("%d ", s.e[k++].x); //print then increase the index of non-zero elements
                printf("\033[0m");
            }
            else
            {
                // print 0 if else
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse * add(struct Sparse *s1, struct Sparse *s2)
{
    if(s1->m!=s2->m && s1->n!=s2->n)
    {
        return NULL;
    }

    struct Sparse *sum;
    sum->e = new Element[s1->num + s2->num];
    int i,j,k;
    i = j = k = 0;

    while(i<s1->num && j<s2->num)
    {
        if(s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            if(s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].x = s2->e[j++].x;
            }
        }
    }

    for(;i<s1->num; i++)
    {
        sum->e[k++] = s1->e[i];
    }
    for(;j<s2->num; j++)
    {
        sum->e[k++] = s2->e[j];
    }

    return sum;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct Sparse s1, s2, *s3;
    // put & because we need to change
    create(&s1);
    create(&s2);

    s3 = add(&s1,&s2);

    display(*s3);
}