#include <iostream>
#include "Queue.h"
using namespace std;
class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    };
    void createTree();
    void preorder(node *);
    void preorder() //Even if root is private and we can call the preorder fun by using thid dummy fun
    {
        preorder(root);
    }
    void inorder(node *);
    void postorder(node *);
    void levelorder(node *);
    void height(node *);
};

int main()
{
    tree t;
    t.createTree();
    cout << "Preorder is:- ";
    t.preorder();

    cout << endl
         << "Inorder is:- ";
    t.inorder(t.root);

    cout << endl
         << "Postorder is:- ";
    t.postorder(t.root);

    return 0;
}

void tree::createTree()
{
    cout << "Enter the Root data:- ";
    root = new node;
    cin >> root->data;
    root->lc = root->rc = NULL;
    queue q(100);
    q.enQueue(root);

    node *p, *temp;
    int x;
    while (!q.isEmpty())
    {
        p = q.deQueue();

        cout << "Enter the left child of " << p->data << ":- ";
        cin >> x;
        if (x != -1)
        {
            temp = new node;
            temp->data =x;
            temp->lc = temp->rc = NULL;
            p->lc = temp;
            q.enQueue(temp);
        }

        cout << "Enter the right child of " << p->data << ":- ";
        cin >> x;
        if (x != -1)
        {

            temp = new node;
            temp->data =x;
            temp->lc = temp->rc = NULL;
            p->rc = temp;
            q.enQueue(temp);
        }
    }
}

void tree::preorder(node *p)
{
    if (p)
    {
        cout << p->data << ", ";
        preorder(p->lc);
        preorder(p->rc);
    }
}

void tree::inorder(node *p)
{
    if (p)
    {
        inorder(p->lc);
        cout << p->data << ", ";
        inorder(p->rc);
    }
}

void tree::postorder(node *p)
{
    if (p)
    {
        postorder(p->lc);
        postorder(p->rc);
        cout << p->data << ", ";
    }
}
