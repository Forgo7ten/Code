#include "queue0.h"

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
bool Queue::enqueue(const Item& item)
{
    if (isfull())
        return false;
    items++;
    Node*add = new Node;
    add->next = nullptr;
    add->item = item;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = rear->next;
    
    return true;
}
bool Queue::dequeue(Item& item)
{
    if (isempty())
        return false;
    --items;
    item = front->item;
    Node* de = front;
    front = front->next;
    delete de;
    if (!items)
        rear = nullptr;
    return true;
}
Queue::~Queue()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}
bool Queue::isempty() const
{
    return !items;
}
bool Queue::isfull() const
{
    return items == qsize;
}
int Queue::queuecount() const
{
    return items;
}