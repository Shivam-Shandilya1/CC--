#include <bits/stdc++.h>
using namespace std;

// Done
template <typename DT>
class SinglyLinkedNode
{
public:
    // data items in the node
    DT dataItem;
    SinglyLinkedNode<DT> *next;

    // constructor
    SinglyLinkedNode(DT nodeValue, SinglyLinkedNode<DT> *nextPointer);
};

template <typename DT>
SinglyLinkedNode<DT>::SinglyLinkedNode(DT nodeValue, SinglyLinkedNode *nextPointer)
{
    dataItem = nodeValue;
    next = nextPointer;
}

template <typename DT>
class SinglyLinkedList
{
    // We declare these members protected because we will inherit this class later
private:
    // Data Members
    SinglyLinkedNode<DT> *head;
    int numberOfItems;

    // These are utility functions that the main functions will call
    void insertEndRecursive(const DT &newDataItem, SinglyLinkedNode<DT> *current);
    void deleteEndRecursive(SinglyLinkedNode<DT> *current);
    void printForwardRecursive(SinglyLinkedNode<DT> *current);
    void printBackwardRecursive(SinglyLinkedNode<DT> *current);
    void moveNodeRecursive(int oldPosition, int newPosition, int count, SinglyLinkedNode<DT> *current);

public:
    // Constructor
    SinglyLinkedList();

    void insertEnd(const DT &newDataItem);
    void deleteEnd();
    void printForward();
    void printBackward();
    void moveNode(int a, int b);
};

template <typename T>
void SinglyLinkedList<T>::moveNode(int a, int b)
{
    SinglyLinkedNode<T> *temp = head;
    SinglyLinkedNode<T> *to_delete;
    while (temp != NULL)
    {
        if (temp->next->dataItem == a)
        {
            to_delete = temp->next;

            temp->next = temp->next->next;

            break;
        }

        temp = temp->next;
    }
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (i == b - 1)
        {

            to_delete->next = temp->next;
            temp->next = to_delete;
            break;
        }

        temp = temp->next;
    }
}

template <typename DT>
SinglyLinkedList<DT>::SinglyLinkedList()
{
    head = NULL;
    numberOfItems = 0;
}

template <typename DT>
void SinglyLinkedList<DT>::insertEnd(const DT &newDataItem)
{
    insertEndRecursive(newDataItem, head);
}

template <typename DT>
void SinglyLinkedList<DT>::insertEndRecursive(const DT &newDataItem, SinglyLinkedNode<DT> *current)
{
    if (numberOfItems == 0)
    {
        head = new SinglyLinkedNode<DT>(newDataItem, NULL);
    }

    else if (current->next == NULL)
    {
        current->next = new SinglyLinkedNode<DT>(newDataItem, NULL);
    }
    else
    {
        insertEndRecursive(newDataItem, current->next);
    }

    numberOfItems++;
}

template <typename DT>
void SinglyLinkedList<DT>::deleteEnd()
{
    deleteEndRecursive(head);
}

template <typename DT>
void SinglyLinkedList<DT>::deleteEndRecursive(SinglyLinkedNode<DT> *current)
{
    if (numberOfItems == 1)
    {
        delete head;
        head = NULL;
    }

    else if (current->next->next == NULL)
    {
        delete current->next;
        current->next = NULL;
    }

    else
    {
        deleteEndRecursive(current->next);
    }

    numberOfItems--;
}

template <typename DT>
void SinglyLinkedList<DT>::printForward()
{
    printForwardRecursive(head);
}

template <typename DT>
void SinglyLinkedList<DT>::printForwardRecursive(SinglyLinkedNode<DT> *current)
{
    if (current == NULL)
        return;

    cout << current->dataItem << " ";
    printForwardRecursive(current->next);
    if (current == head)
        cout << endl;
}

template <typename DT>
void SinglyLinkedList<DT>::printBackward()
{
    printBackwardRecursive(head);
}

// Notice how we don't have to reverse the linked list or maintain any extra variables
// in order to print it backwards. We can just make use of the recursion stack.
template <typename DT>
void SinglyLinkedList<DT>::printBackwardRecursive(SinglyLinkedNode<DT> *current)
{
    if (current == NULL)
        return;

    printBackwardRecursive(current->next);
    cout << current->dataItem << " ";
    if (current == head)
        cout << endl;
}

class Timer
{
private:
    chrono::time_point<chrono::high_resolution_clock> m_StartTimepoint;

public:
    Timer();
    ~Timer();
    void Stop();
};
Timer::Timer()
{
    // Initialize start time with the constructor
    m_StartTimepoint = chrono::high_resolution_clock::now();
}
Timer::~Timer()
{
    Stop();
}
void Timer::Stop()
{
    // Get time of object destruction
    auto endTimepoint = chrono::high_resolution_clock::now();
    // Get start and end time in microseconds
    auto start = chrono::time_point_cast<chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
    auto end = chrono::time_point_cast<chrono::microseconds>(endTimepoint).time_since_epoch().count();
    // calculate time elapsed
    auto duration = end - start;
    double ms = duration * 0.001;
    cout << duration << " microseconds ( " << ms << " milliseconds)" << endl;
}
int main()
{
    SinglyLinkedList<int> list;
    {
        Timer timer;
        for (int i = 0; i < 10000; i++)
            list.insertEnd(i + 1);
    }
}