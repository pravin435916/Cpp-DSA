#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int isCommon(struct Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == data)
    {
        return 1;
    }
    return isCommon(root->left, data) || isCommon(root->right, data);
}

void findCommonMembers(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL)
    {
        return;
    }

    if (isCommon(root2, root1->data))
    {
        printf("%d ", root1->data);
    }

    findCommonMembers(root1->left, root2);
    findCommonMembers(root1->right, root2);
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{  
    printf ("Roll no. : 58\n");
    printf ("Name : Pravin Nandankar\n");
    printf ("Sem : 3rd\n");
    printf ("Batch : C4\n");
    struct Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    struct Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(6);
    root2->left->right = createNode(5);

    printf("Common members: ");
    findCommonMembers(root1, root2);

    return 0;
}

