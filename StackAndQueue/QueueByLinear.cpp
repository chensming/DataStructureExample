/*
课堂笔记：

/*
队头指针进1 :front = (front + 1) % maxSize
队尾指针进1 : rear = (rear + 1) % maxSize
队列初始化 : front = rear = 0
队空条件 : front == rear
队满条件 : (rear + 1) % maxSize == front
*/
#include <assert.h>
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    Queue(int sz = 10);
    ~Queue() { delete[] elements; }
    bool EnQueue(const T &x);
    bool DeQueue(T &x);
    bool getFront(T &x);
    void makeEmpty()
    {
        front = rear = 0;
    }
    bool IsEmpty() const
    {
        return (front == rear) ? true : false;
    }
    bool IsFull() const
    {
        return ((rear + 1) % maxSize == front) ? true : false;
    }
    int getSize() const { return (rear - front + maxSize) % maxSize; }
    // friend ostream &operator<<(ostream &output, Queue<T> &Q);
    void ShowStack();

private:
    int rear, front;
    T *elements;
    int maxSize;
};

template <class T>
Queue<T>::Queue(int sz) : front(0), rear(0), maxSize(sz)
{
    elements = new T[maxSize];
    assert(elements != 0);
}

template <class T>
bool Queue<T>::EnQueue(const T &x)
{
    if (IsFull())
        return false;
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

template <class T>
bool Queue<T>::DeQueue(T &x)
{
    if (IsEmpty())
        return false;
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

template <class T>
bool Queue<T>::getFront(T &x)
{
    if (IsEmpty())
        return false;
    x = elements[front];
    return true;
}

template <class T>
void Queue<T>::ShowStack()
{
    cout << "front = " << front << ",rear = ";
    cout << rear << endl;
    for (int i = front; i != rear; i = (i + 1) % maxSize)
        cout << i << ":" << elements[i] << endl;
}

// template <class T>
// ostream &operator<<(ostream &output, Queue<T> &Q)
// {
//     output << "front = " << Q.front << ",rear = ";
//     output << Q.rear << endl;
//     for (int i = Q.front; i != Q.rear; i = (i + 1) % Q.maxSize)
//         output << i << ":" << Q.elements[i] << endl;
//     return output;
// }

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