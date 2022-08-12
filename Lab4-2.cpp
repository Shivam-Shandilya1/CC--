#include <bits/stdc++.h>
using namespace std;


// Solved
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
SinglyLinkedNode<DT>::SinglyLinkedNode(DT nodeValue, SinglyLinkedNode<DT> *nextPointer)
{
    dataItem = nodeValue;
    next = nextPointer;
}

template <typename DT>
class SinglyLinkedList
{
    // We declare these members protected because we will inherit this class later
protected:
    // Data Members
    SinglyLinkedNode<DT> *head;
    SinglyLinkedNode<DT> *cursor;
    int numberOfItems;

public:
    // Constructor
    SinglyLinkedList();

    void insert(const DT &newDataItem);
    void remove();
    void replace(const DT &newDataItem);
    void clear();
    bool isEmpty();
    void gotoBeginning();
    void gotoEnd();
    bool gotoNext();
    bool gotoPrior();
    DT getCursor();
    void showStructure();
};

template <typename DT>
SinglyLinkedList<DT>::SinglyLinkedList()
{
    head = NULL;
    cursor = NULL;
    numberOfItems = 0;
}

template <typename DT>
void SinglyLinkedList<DT>::insert(const DT &newDataItem)
{
    if (numberOfItems == 0)
    {
        head = new SinglyLinkedNode<DT>(newDataItem, NULL);

        cursor = head;
    }

    else
    {
        SinglyLinkedNode<DT> *new_node = new SinglyLinkedNode<DT>(newDataItem, cursor->next);
        cursor->next = new_node;
        cursor = cursor->next;
    }
    numberOfItems++;
}

template <typename DT>
void SinglyLinkedList<DT>::remove()
{
    if (cursor == head)
    {
        head = head->next;
        delete cursor;
        cursor = head;
        numberOfItems--;
        return;
    }

    SinglyLinkedNode<DT> *prev_node = head;
    while (prev_node->next != cursor)
    {
        prev_node = prev_node->next;
    }

    if (cursor->next == NULL)
    {
        prev_node->next = NULL;
        delete cursor;
        cursor = head;
    }

    else
    {
        prev_node->next = cursor->next;
        delete cursor;
        cursor = prev_node->next;
    }

    numberOfItems--;
}

template <typename DT>
void SinglyLinkedList<DT>::replace(const DT &newDataItem)
{
    cursor->dataItem = newDataItem;
}

template <typename DT>
void SinglyLinkedList<DT>::clear()
{

    cursor = head;
    while (cursor->next != NULL)
    {
        SinglyLinkedNode<DT> *nextNode = cursor->next;
        delete cursor;
        cursor = nextNode;
    }

    numberOfItems = 0;
    head = NULL;
    cursor = NULL;
}

template <typename DT>
bool SinglyLinkedList<DT>::isEmpty()
{
    return numberOfItems == 0;
}

template <typename DT>
void SinglyLinkedList<DT>::gotoBeginning()
{
    cursor = head;
}

template <typename DT>
void SinglyLinkedList<DT>::gotoEnd()
{
    while (cursor->next != NULL)
        cursor = cursor->next;
}

template <typename DT>
bool SinglyLinkedList<DT>::gotoNext()
{
    if (cursor->next == NULL)
        return false;
    else
    {
        cursor = cursor->next;
        return true;
    }
}

template <typename DT>
bool SinglyLinkedList<DT>::gotoPrior()
{
    if (cursor == head)
        return false;
    else
    {
        SinglyLinkedNode<DT> *prev_node = head;
        while (prev_node->next != cursor)
            prev_node = prev_node->next;
        cursor = prev_node;
        return true;
    }
}
template <typename DT>

DT SinglyLinkedList<DT>::getCursor()
{
    return cursor->dataItem;
}

template <typename DT>
void SinglyLinkedList<DT>::showStructure()
{
    if (numberOfItems == 0)
    {
        cout << "Empty list" << endl;
        return;
    }

    SinglyLinkedNode<DT> *temp_node = head;
    while (temp_node != NULL)
    {
        cout << temp_node->dataItem << " ";
        temp_node = temp_node->next;
    }
    cout << endl;
}

template <typename DT>
class DoublyLinkedNode : public SinglyLinkedNode<DT>
{
public:
    DoublyLinkedNode<DT> *next;
    DoublyLinkedNode<DT> *prev;
    using SinglyLinkedNode<DT>::dataItem;

    // constructor
    DoublyLinkedNode(DT nodeValue, DoublyLinkedNode<DT> *nextPointer, DoublyLinkedNode<DT> *prevPointer);
};

template <typename DT>
DoublyLinkedNode<DT>::DoublyLinkedNode(DT nodeValue, DoublyLinkedNode<DT> *nextPointer, DoublyLinkedNode<DT> *prevPointer) : SinglyLinkedNode<DT>(nodeValue, nextPointer)
{
    prev = prevPointer;
}

template <typename DT>
class DoublyLinkedList : public SinglyLinkedList<DT>
{
public:
    DoublyLinkedNode<DT> *head;
    DoublyLinkedNode<DT> *cursor;
    using SinglyLinkedList<DT>::numberOfItems;

public:
    DoublyLinkedList();
    void insert(const DT &newDataItem);
    DT getCursor();
    bool isEmpty();

    void clear();
    void remove();
    void replace(const DT &newDataItem);
    bool gotoPrior();
    void showStructure();
    void gotoBeginning();
    void gotoEnd();
    bool gotoNext();
};

template <typename DT>
void DoublyLinkedList<DT>::showStructure()
{
    if (numberOfItems == 0)
    {
        cout << "Empty List\n";
        return;
    }

    DoublyLinkedNode<DT> *temp = head;
    while (temp != NULL)
    {
        cout << (temp)->dataItem << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename DT>
DoublyLinkedList<DT>::DoublyLinkedList()
{
    head = NULL;
    cursor = head;
    numberOfItems = 0;
}

template <typename DT>
void DoublyLinkedList<DT>::insert(const DT &neww)
{
    if (numberOfItems == 0)
    {
        head = new DoublyLinkedNode<DT>(neww, NULL, NULL);
        cursor = head;
    }
    else
    {
        DoublyLinkedNode<DT> *new_node = new DoublyLinkedNode<DT>(neww, cursor->next, cursor);
        cursor->next = new_node;
        cursor->next->prev = new_node;
        
        cursor = new_node;
    }

    numberOfItems++;
}

template <typename T>
void DoublyLinkedList<T>::remove()
{
    if (cursor == head)
    {
        head = head->next;
        delete cursor;
        cursor = head;
        numberOfItems--;
        return;
    }

    DoublyLinkedNode<T> *prev_node = head;
    while (prev_node->next != cursor)
    {
        prev_node = prev_node->next;
    }

    if (cursor->next == NULL)
    {
        prev_node->next = NULL;
        delete cursor;
        cursor = head;
    }
    else
    {
        prev_node->next = cursor->next;
        delete cursor;
        cursor = prev_node->next;
    }

    numberOfItems--;
}

template <typename T>
bool DoublyLinkedList<T>::gotoNext()
{
    if (!cursor->next)
    {
        return false;
    }
    else
    {
        cursor = cursor->next;
        return true;
    }
}

template <typename T>
void DoublyLinkedList<T>::replace(const T &x)
{
    cursor->dataItem = x;
}

template <typename T>
void DoublyLinkedList<T>::gotoBeginning()
{
    cursor = head;
}

template <typename T>
T DoublyLinkedList<T>::getCursor()
{
    return cursor->dataItem;
}

template <typename T>
void DoublyLinkedList<T>::gotoEnd()
{
    while (cursor->next != NULL)
    {
        cursor = cursor->next;
    }
}
template <typename T>
bool DoublyLinkedList<T>::gotoPrior()
{
    if (cursor == head)
    {
        return false;
    }
    else
    {
        DoublyLinkedNode<T> *ded = head;
        while (ded->next != cursor)
        {
            ded = ded->next;
        }

        cursor = ded;
        return true;
    }
}
template <typename T>
void DoublyLinkedList<T>::clear()
{
    cursor = head;
    while (cursor->next != NULL)
    {
        DoublyLinkedNode<T> *temp = cursor->next;
        delete cursor;
        cursor = temp;
    }
    delete cursor;
    numberOfItems = 0;
    head = NULL;
    cursor = NULL;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return numberOfItems == 0;
}

template <typename T>
class AnagramPuzzle
{
public:
    DoublyLinkedList<T> *ans;
    DoublyLinkedList<T> *init;

    AnagramPuzzle(string ans, string init);
    void shiftLeft();
    void shiftRight();
    void swapEnds();
    void display();
    bool solved();
};

template <typename T>
AnagramPuzzle<T>::AnagramPuzzle(string ans, string init)
{
    this->ans = new DoublyLinkedList<T>();
    this->init = new DoublyLinkedList<T>();
    for (int i = 0; i < ans.size(); i++)
    {
        this->ans->insert(ans[i]);
        this->init->insert(init[i]);
    }
}

template <typename T>
void AnagramPuzzle<T>::display()
{
    string s = "";
    init->gotoBeginning();
    // cout<<init->getCursor();
    s += init->getCursor();
    while (init->gotoNext())
    {
        s += init->getCursor();
        //  cout<<init->getCursor();
    }
    s += "\n";
    cout << s;

}

template <typename T>
void AnagramPuzzle<T>::shiftLeft()
{
    init->gotoEnd();
    T ded=init->getCursor();
    while (init->gotoPrior())
    {
        T temp=init->getCursor();
        init->replace(ded);
        ded=temp;
    }
    init->gotoEnd();
    init->replace(ded);
    
}

template <typename T>
void AnagramPuzzle<T>::swapEnds()
{
    init->gotoBeginning();
    T beg=init->getCursor();
    init->gotoEnd();
    T end=init->getCursor();
    init->replace(beg);
    init->gotoBeginning();
    init->replace(end);
    init->gotoBeginning();
    
}

template <typename T>
bool AnagramPuzzle<T>::solved()
{
    init->gotoBeginning();
    ans->gotoBeginning();
    if(init->getCursor() != ans->getCursor())
    {
        return false;
    }
    while (init->gotoNext() and ans->gotoNext())
    {
        if(init->getCursor() != ans->getCursor())
        {
            return false;
        }
    }
    return true;
    
    
}

int main()
{
    AnagramPuzzle<char> TestPuzzle("yes", "yse");
    TestPuzzle.display();
    TestPuzzle.shiftLeft();
    TestPuzzle.display();
    TestPuzzle.swapEnds();
    TestPuzzle.display();
    if(TestPuzzle.solved())
    {
        cout<<"Solved\n";
    }
    else
    {
        cout<<"Not Solved\n";
    }
}