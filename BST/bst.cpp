#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// Find node with min value
struct node *minValueNode(struct node *node){
    struct node *temp = node;
    while(temp -> left != nullptr){
        temp = node -> left;
    }
    return temp;
}   

// Inorder traversal
void traverseInOrder(struct node *root)
{
    if (root != NULL)
    {
        traverseInOrder(root -> left);
        cout << root -> key << " ";
        traverseInOrder(root -> right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key)
{
    if(node == nullptr){
        // create new node and point to *node
        struct node *newNode = new struct node;
        newNode -> key = key;
        newNode -> left = nullptr;
        newNode -> right = nullptr;
        return newNode;
    }
    else if(key <= node -> key){
        // insert to left sub tree
        node -> left = insertNode(node -> left, key); 
    }
    else if(key > node -> key){
        // insert to right sub tree
        node -> right = insertNode(node -> right, key);
    }

    // return root
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if(root == nullptr){
        // no node to delete
        delete root;
        root = NULL;
        return root;
    }
    else if(key < root -> key){
        struct node *temp = root;
        root = root -> right;
        delete temp;
    }
    else if(key > root -> key){
        struct node *temp = root;
        root = root -> left;
        delete temp;
    }
    else{
        // node to delete found
        if(root -> left == nullptr){
            // new root of the sub tree will be the node on the right of the deleted node
            return root -> right;   
        }
        else if(root -> right == nullptr){
            // new root of the sub tree will be the node on the left of the deleted node
            return root -> left;
        }
        struct node *temp = minValueNode(root -> right);
        root -> key = temp -> key;
        root -> right = deleteNode(root -> right, temp -> key);
    }

    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1)
    {
        switch (operation)
        {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}