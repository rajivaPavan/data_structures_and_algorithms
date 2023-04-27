#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
}; 

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
    if(node == NULL){
        // create new node and point to *node
        struct node *newNode = new struct node;
        newNode -> key = key;
        newNode -> left = NULL;
        newNode -> right = NULL;
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

// Find node with min value
struct node *minValueNode(struct node *node){
    struct node *temp = node;
    while(temp && temp -> left != NULL){
        temp = node -> left;
    }
    return temp;
}  

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if(root == NULL){
        // no node to delete
        return root;
    }
    else if(key < root -> key){
        root -> left = deleteNode(root -> left, key);
    }
    else if(key > root -> key){
        root -> right = deleteNode(root -> right, key);
    }
    else{
        // node has no child
        if (root->left == NULL && root->right == NULL)
            return NULL;
        // node to delete found
        else if(root -> left == NULL){
            // new root of the sub tree will be the node on the right of the deleted node
            struct node *temp = root -> right;
            free(root);
            return temp;   
        }
        else if(root -> right == NULL){
            // new root of the sub tree will be the node on the left of the deleted node
            struct node *temp = root -> left;
            free(root);
            return temp; 
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