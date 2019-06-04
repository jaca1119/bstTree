#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct node* sear(struct node *Node, int key)
{
    if (Node == NULL || Node->key == key)
        return Node;

    if (Node->key < key)
        return sear(Node->right, key);

    return sear(Node->left, key);
}


void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

struct node* inse(struct node* Node, int key)
{
    if (Node == NULL)
        return newNode(key);

    if (key < Node->key)
        Node->left = inse(Node->left ,key);
    else if (key > Node->key)
        Node->right = inse(Node->right ,key);

    return Node;
}


int main()
{
    struct node *parent = NULL;

    srand(time(NULL));

    parent = inse(parent, 60);
    inse(parent, 50);
    inse(parent, 40);

    inorder(parent);

    printf("\n%d", sear(parent, 50)->key);

    return 0;
}
