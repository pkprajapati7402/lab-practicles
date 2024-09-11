// EXPERIMENT- 9
//  9. Create a Binary Tree and perform Tree traversals (Preorder, Postorder, Inorder) using the
//  concept of recursion.
//  INPUT
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }
    Node *createNode(int value)
    {
        return new Node(value);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
    }
    preorder(node->right);
    void inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};
int main()
{
    BinaryTree tree;
    tree.root = tree.createNode(1);
    tree.root->left = tree.createNode(2);
    tree.root->right = tree.createNode(3);
    tree.root->left->left = tree.createNode(4);
    tree.root->left->right = tree.createNode(5);
    tree.root->right->left = tree.createNode(6);
    tree.root->right->right = tree.createNode(7);
    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    return 0;
}
