#include <iostream>
using namespace std;
#ifndef Queue
#define Queue
class node
{
public:
    node *lc, *rc;
    int data;
};

class queue
{
    int size;
    int f;
    int b;
    node **arr;

public:
    queue();
    queue(int size);
    bool isEmpty();
    bool isFull();
    void enQueue(node *);
    node *deQueue();
    void display();
};

queue::queue()
{
    f = b = -1;
    size = 10;
    arr = new node *[size];
}

queue::queue(int size)
{
    f = b = -1;
    this->size = size;
    arr = new node *[size];
}

bool queue::isEmpty()
{
    return b == -1;
}



bool queue::isFull()
{
    return (b + 1) % size == f;
}

void queue::enQueue(node *temp)
{
    if (b == -1)
    {
        f = b = 0;
    }
    else if (!isFull())
    {
        b = (b + 1) % size;
    }
    arr[b] = temp;
}

node *queue::deQueue()
{
    node *temp = arr[f];
    if (f == b)
    {
        f = b = -1;
    }
    else if (!isEmpty())
    {
        f = (f + 1) % size;
    }
    return temp;
}

void queue::display()
{
    cout << "The Queue is:- ";
    for (int i = f; i <= b; i = (i + 1) % size)
    {
        cout << arr[i] << " ";
    }
}

#endif