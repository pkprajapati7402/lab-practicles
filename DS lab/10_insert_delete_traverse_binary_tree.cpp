// EXPERIMENT- 10
//  10. Implement, Insertion, deletion and traversals (Inorder, preorder and postorder) on a binary
//  search tree with the information in the tree about the details of an automobile (type, company,
//  year of make).
//  INPUT
#include <iostream>
#include <string>
using namespace std;
struct Automobile
{
    string type;
    string company;
    int year;
    Automobile *left;
    Automobile *right;
    Automobile(string t, string c, int y)
    {
        type = t;
        company = c;
        year = y;
        left = right = NULL;
    }
};
class BST
{
public:
    Automobile *root;
    BST()
    {
        root = NULL;
    }
    Automobile *insert(Automobile *node, string type, string company, int year)
    {
        if (node == NULL)
        {
            return new Automobile(type, company, year);
        }
        if (year < node->year)
        {
            node->left = insert(node->left, type, company, year);
        }
        else if (year > node->year)
        {
            node->right = insert(node->right, type, company, year);
        }
        return node;
    }
    // Helper function to find the minimum value node in the right subtree (used in deletion)
    Automobile *minValueNode(Automobile *node)
    {
        Automobile *current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    // Function to delete a node with a given year from the BST
    Automobile *deleteNode(Automobile *root, int year)
    {
        if (root == NULL)
        {
            return root;
        }
        // Traverse the tree to find the node to delete
        if (year < root->year)
        {
            root->left = deleteNode(root->left, year);
        }
        else if (year > root->year)
        {
            root->right = deleteNode(root->right, year);
        }
        else
        {
            // Node to be deleted found
            // Node with one or no children
            if (root->left == NULL)
            {
                Automobile *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Automobile *temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children: find the inorder successor (smallest in right subtree)
            Automobile *temp = minValueNode(root->right);
            root->year = temp->year;
            root->type = temp->type;
            root->company = temp->company;
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->year);
        }
        return root;
    }
    // Inorder Traversal: Left-> Root-> Right
    void inorder(Automobile *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->left);
        cout << "Type: " << node->type << ", Company: " << node->company << ", Year: " << node->year << endl;
        inorder(node->right);
    }
    // Preorder Traversal: Root-> Left-> Right
    void preorder(Automobile *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << "Type: " << node->type << ", Company: " << node->company << ", Year: " << node->year << endl;
        preorder(node->left);
        preorder(node->right);
    }
    // Postorder Traversal: Left-> Right-> Root
    void postorder(Automobile *node)
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << "Type: " << node->type << ", Company: " << node->company << ", Year: " << node->year << endl;
    }
};
int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, "SUV", "Toyota", 2015);
    tree.insert(tree.root, "Sedan", "Honda", 2018);
    tree.insert(tree.root, "Truck", "Ford", 2012);
    tree.insert(tree.root, "Coupe", "BMW", 2020);
    tree.insert(tree.root, "Hatchback", "Hyundai", 2016);
    cout << "Inorder Traversal (Sorted by Year):" << endl;
    tree.inorder(tree.root);
    cout << endl;
    cout << "Preorder Traversal:" << endl;
    tree.preorder(tree.root);
    cout << endl;
    cout << "Postorder Traversal:" << endl;
    tree.postorder(tree.root);
    cout << endl;
    cout << "Deleting the automobile with year 2016..." << endl;
    tree.root = tree.deleteNode(tree.root, 2016);
    cout << "Inorder Traversal after Deletion:" << endl;
    tree.inorder(tree.root);
    cout << endl;
    return 0;
}
