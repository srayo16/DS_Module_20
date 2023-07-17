#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inputTree()
{
    int val;
    cin >> val;
    Node *root;

    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *lc, *rc;
        if (l == -1)
            lc = NULL;
        else
            lc = new Node(l);
        if (r == -1)
            rc = NULL;
        else
            rc = new Node(r);

        f->left = lc;
        f->right = rc;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

bool search(Node *root, int x)
{

    if (root == NULL)
        return false;
    if (root->val == x)
        return true;

    if (x < root->val)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int main()
{
    Node *root = inputTree();
    // levelOrder(root);
    if (search(root, 5))
        cout << "Yes, Found!" << endl;
    else
        cout << "No, Not Found!" << endl;

    return 0;
}