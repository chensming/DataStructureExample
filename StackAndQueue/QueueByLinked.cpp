#include <iostream>
using namespace std;

template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *next;
    // LinkNode(LinkNode<T> *ptr = 0)
    // {
    //     next = ptr;
    // }
    LinkNode(const T &item)
    {
        data = item;
        next = 0;
    }
    // LinkNode(const T &item, LinkNode<T> *ptr = 0)
    // {
    //     data = item;
    //     next = ptr;
    // }
};

template <class T>
class Queue
{
public:
    Queue() : rear(0), front(0) {}
    ~Queue() { makeEmpty(); }
    bool EnQueue(const T &x);
    bool DeQueue(T &x);
    bool getFront(T &x) const;
    void makeEmpty();
    bool IsEmpty() const
    {
        return (front == 0) ? true : false;
    }
    int getSize() const;
    void ShowStack();

private : 
    LinkNode<T> *front;
    LinkNode<T> *rear;
};

template <class T>
void Queue<T>::makeEmpty()
{
    LinkNode<T> *p;
    while (front != 0)
    {
        p = front;
        front = front->next;
        delete p;
    }
}

template <class T>
bool Queue<T>::EnQueue(const T &x)
{
    if (front == 0)
    {
        front = rear = new LinkNode<T>(x);
        if (front == 0)
            return false;
    }
    else
    {
        rear->next = new LinkNode<T>(x);
        if (rear->next == 0)
            return false;
        rear = rear->next;
    }
    return true;
}

template <class T>
bool Queue<T>::DeQueue(T &x)
{
    if (IsEmpty())
        return false;
    LinkNode<T> *p = front;
    x = front->data;
    if (front == rear)
        rear = 0;
    front = front->next;
    delete p;
    return true;
}

template <class T>
bool Queue<T>::getFront(T &x) const
{
    if (IsEmpty())
        return false;
    x = front->data;
    return true;
}

template <class T>
int Queue<T>::getSize() const
{
    LinkNode<T> *p = front;
    int k = 0;
    while (p != 0)
    {
        p = p->next;
        k++;
    }
    return k;
}

template <class T>
void Queue<T>::ShowStack()
{
    LinkNode<T> *p = front;
    int i = 0;
    while (p != 0)
    {
        cout << ++i << ":" << p->data << endl;
        p = p->next;
    }
}

int main()
{
    Queue<int> Q;
    int x;
    Q.EnQueue(1);
    Q.EnQueue(2);
    Q.EnQueue(3);
    // cout << Q << endl;
    Q.ShowStack();
    Q.EnQueue(4);
    Q.EnQueue(5);
    Q.EnQueue(6);
    // cout << Q << endl;
    Q.ShowStack();
    Q.getFront(x);
    cout << "Q.getFront = " << x << endl;
    Q.getSize();
    Q.DeQueue(x);
    Q.DeQueue(x);
    cout << "Q.DeQueue = " << x << endl;
    Q.DeQueue(x);
    Q.DeQueue(x);
    // cout << Q << endl;
    Q.ShowStack();
    Q.DeQueue(x);
    cout << "Q.DeQueue = " << x << endl;
    Q.DeQueue(x);
    Q.DeQueue(x);
    cout << "IsEmpty?" << Q.IsEmpty() << endl;
    system("pause");
}
