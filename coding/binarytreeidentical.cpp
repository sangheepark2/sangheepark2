/* binary treee -> binary search tree, check identical */
#include <vector>
#include <stdio.h>

using namespace std;

struct BinaryTreeNode {
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    int data;
    BinaryTreeNode(int item)
    {
        data = item;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    BinaryTreeNode *root;

public:
    BST()
    {
        root = NULL;
    }

    int isEmpty()
    {
        return root == NULL;
    }

    void insert(int item)
    {
        BinaryTreeNode *node = new BinaryTreeNode(item);
        //printf("new item: %d\n", item);

        if(isEmpty())
            root = node;
        else
        {
            BinaryTreeNode *cur;
            BinaryTreeNode *parent;
            cur = root;
            while(cur != NULL)
            {
                parent = cur;
                if(item < cur->data)
                    cur = cur->left;
                else
                    cur = cur->right;
            }

            if(item < parent->data)
                parent->left = node;
            else
                parent->right = node;
        }
    }

    vector<int> traverse()
    {
        vector<int> ret;
        traverse(root, ret);

        return ret;
    }

    void traverse(BinaryTreeNode *node, vector<int> &trav)
    {
        if(node != NULL)
        {
            traverse(node->left, trav);
            trav.push_back(node->data);
            traverse(node->right, trav);
        }
    }
};

int main()
{
    BST bst1, bst2;
    vector<int> v1 = {20, 10, 5, 15, 40, 45, 30};
    vector<int> v2 = {20, 10, 5, 15, 40, 45, 30};

    printf( "before inserti v1.size(): %d\n", v1.size());
    for(int i = 0; i < v1.size(); i++)
        bst1.insert(v1[i]);

    for(int i = 0; i < v2.size(); i++)
        bst2.insert(v2[i]);
    printf("end of insert\n");
    vector<int> ret1, ret2;
    ret1 = bst1.traverse();
    ret2 = bst2.traverse();

    printf( "ret1.size(): %d\n", ret1.size());
    for(int i = 0; i < ret1.size(); i++)
        printf( "%d ", ret1[i]);
    printf("\n");

    for(int i = 0; i < ret2.size(); i++)
        printf( "%d ", ret2[i]);
    printf("\n");

    printf("ret1 and ret2: %d\n", ret1 == ret2);
    return 0;
}