// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>


struct BstNode
{
    int data;
    BstNode* right;
    BstNode* left;
};


BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(root->data>=data)
    {
        root->left = Insert(root->left, data);
    }
    else if(root->data<data)
    {
        root->right = Insert(root->right, data);
    }

    return root;

}

bool isSubtreeGreater(BstNode* root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubtreeLesser(BstNode* root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}


struct BstNode* Delete(BstNode* root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    else if (value < root->data)
    {
        root->left=Delete(root->left, value);
    }
    else if(value>root->data)
    {
        root->right = Delete(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            root = NULL;
            return root;
        }
        if ((root->left == NULL))
        {
            BstNode* temp = root;
            root = root->right;
            delete(temp);
            return root;
        }
        if (root->right == NULL)
        {
            BstNode* temp = root;
            root = root->right;
            delete(temp);
            return root;
        }


    }
}

bool isBinarySearchTree(BstNode* root,int value)
{
    if (root == NULL)
    {
        return true;
    }

    if (isSubtreeLesser(root->left, value) && isSubtreeGreater(root->right, value)
        && isBinarySearchTree(root->left, value) && isBinarySearchTree(root->right, value))
    {
        return true;
    }
    return false;
}

BstNode* FindMin(BstNode* root)
{   

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL)
    {
        return root;
    }
    
    return FindMin(root->left);
}

int findMax(BstNode* root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}

bool Search(BstNode* root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data < data)
    {
        return Search(root->right, data);
    }
    else
    {
        return Search(root->left, data);
    }
}

int findHeight(BstNode* root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

void levelOrder(BstNode* root)
{
    if (root == NULL)
    {
        return;
    }
    std::queue<BstNode*> q;
    q.push(root);

    while (!q.empty())
    {
        BstNode* current = q.front();
        std::cout << current->data << " ";
        if (current->left != NULL)
        {   
            q.push(current->left);
        }
        if (current->right != NULL)
        {   
            q.push(current->right);
        }
        q.pop();
    }
}


int getSumOfAllNode(BstNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->data + getSumOfAllNode(root->left) + getSumOfAllNode(root->right);
    }

}


void preorder(BstNode* root)
{   

    if (root == NULL)
    {
        return;
    }
    else
    {
        std::cout << root->data << " ";
    }

    {
        preorder(root->left);
    }

    {
        preorder(root->right);  
    }
}


int getNumberOfLeafNodes(BstNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL&&root->right==NULL)
    {
        return 1;
    }
    return getNumberOfLeafNodes(root->left) + getNumberOfLeafNodes(root->right);
    
}



int getHeightOfTree(BstNode* root)
{

}


int getNumberOfNodes(BstNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getNumberOfNodes(root->left) + getNumberOfNodes(root->right);
    }
}




int main()
{

    BstNode* root = NULL;
    root = Insert(root, 9);
    root = Insert(root, 2);
    root = Insert(root, 67);
    root = Insert(root, 1);
    root = Insert(root, -4);
    root = Insert(root, 88);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 1);


    std::cout << getNumberOfLeafNodes(root);


}

