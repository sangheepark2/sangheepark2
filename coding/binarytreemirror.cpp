#include <stdio.h>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    int data;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode *root;
public:
    BinaryTree()
    {
        root = NULL;
    }

    void insertAsBST(int val)
    {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return;
        }

        TreeNode *cur = root;
        TreeNode *parent = NULL;
        while(cur != NULL)
        {
            parent = cur;
            if(val < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }

        cur = new TreeNode(val);
        if(val < parent->data)
            parent->left = cur;
        else
            parent->right = cur;
    }

    void recLevel(vector<vector<int>> &ret, int depth, TreeNode *node)
    {
        if(node == NULL)
            return;
        if(ret.size() <= depth)
            ret.push_back(vector<int>{});

        ret[depth].push_back(node->data);

        recLevel(ret, depth + 1, node->left);
        recLevel(ret, depth + 1, node->right);
    }

    vector<vector<int>> displayAsLevel()
    {
        vector<vector<int>> ret;

        recLevel(ret, 0, root);

        return ret;
    }

    void treeMirror()
    {
        treeMirror(root);
    }

    void treeMirror(TreeNode *node)
    {
        if(node == NULL)
            return;
        treeMirror(node->left);
        treeMirror(node->right);

        TreeNode *tmp = node->left;

        node->left = node->right;
        node->right = tmp;
        
    }

};

int main()
{
    printf("Binary Tree Mirror\n");
    BinaryTree bst;
    vector<int> data = {20, 50, 200, 75, 25, 300, 5, 100, 150, 210, 220, 4, 1, 3, 6};
    for(int i = 0; i < data.size(); i++)
    {
        bst.insertAsBST(data[i]);
    }

    vector<vector<int>> ret = bst.displayAsLevel();
    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
            printf("%d ", ret[i][j]);
        printf("\n");
    }

    printf( "=====================\n\n");
    bst.treeMirror();
    ret = bst.displayAsLevel();
    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
            printf("%d ", ret[i][j]);
        printf("\n");
    }
    return 0;
}