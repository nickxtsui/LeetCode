
#include <typeinfo>
#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node* insert(Node* root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node* cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    Node* lca(Node* root, int v1, int v2)
    {
        // Write your code here.
        Node* p = root;

        if (NULL == p)
            return NULL;
        else if (p->data > v1 && p->data > v2)      // if both input values are smaller than the current node value
            return lca(p->left, v1, v2);            // move the current node to its left node/branch
        else if (p->data < v1 && p->data < v2)      // else if both input values are larger than the current node value
            return lca(p->right, v1, v2);           // then move current node to its right node/branch
        else                                        // if the two input values are situated on different sides of the current node
            return p;                               // then their lca is current node
    }

}; //End of Solution



int main()
{

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    Node* ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}


// sample input
//6
//4 2 3 1 7 6
//1 7


////Sample Output
////
////[reference to node 4]
