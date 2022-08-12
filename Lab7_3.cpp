#include <bits/stdc++.h>
#define en "\n"
#define ll long long
#define mini INT64_MIN
#define maxi INT64_MAX
#define sz size()
#define ss second
#define ff first
#define pb push_back
#define ceil(x) ceil((double)x)
using namespace std;
#define forl(i, a, b) for (ll i = a; i < b; i++)

class DLinkedList;

typedef char DataType; // list element type
class DNode
{ // doubly linked list node
private:
    DataType elem;            // node element value
    DNode *prev;              // previous node in list
    DNode *next;              // next node in list
    friend class DLinkedList; // allow DLinkedList access
};

class DLinkedList
{ // doubly linked list
public:
    DLinkedList();                    // constructor
    ~DLinkedList();                   // destructor
    bool empty() const;               // is list empty?
    const DataType &front() const;    // get front element
    const DataType &back() const;     // get back element
    void addFront(const DataType &e); // add to front of list
    void addBack(const DataType &e);  // add to back of list
    void removeFront();               // remove from front
    void removeBack();                // remove from back
    void listReverse();               // reverse the list
private:                              // local type definitions
    DNode *header;                    // list sentinels
    DNode *trailer;

protected:                                 // local utilities
    void add(DNode *v, const DataType &e); // insert new node before v
    void remove(DNode *v);                 // remove node v
};

DLinkedList::DLinkedList()
{                       // constructor
    header = new DNode; // create sentinels
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}

DLinkedList::~DLinkedList()
{ // destructor
    while (!empty())
        removeFront(); // remove all but sentinels
    delete header;     // remove the sentinels
    delete trailer;
}

bool DLinkedList::empty() const // is list empty?
{
    return (header->next == trailer);
}

const DataType &DLinkedList::front() const // get front element
{
    return header->next->elem;
}

const DataType &DLinkedList::back() const // get back element
{
    return trailer->prev->elem;
}

void DLinkedList::add(DNode *v, const DataType &e)
{ // insert new node before v
    DNode *u = new DNode;
    u->elem = e;       // create a new node for e
    u->next = v->next; // link u in between v
    u->prev = v;
    v->next->prev = u;
    v->next = u;
}

void DLinkedList::addFront(const DataType &e) // add to front of list
{
    add(header, e);
}

void DLinkedList::addBack(const DataType &e) // add to back of list
{
    add(trailer->prev, e);
}

void DLinkedList::remove(DNode *v)
{                       // remove node v
    DNode *u = v->prev; // predecessor
    DNode *w = v->next; // successor
    u->next = w;        // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() // remove from font
{
    remove(header->next);
}

void DLinkedList::removeBack() // remove from back
{
    remove(trailer->prev);
}

void DLinkedList::listReverse()
{                  // reverse a list
    DLinkedList T; // temporary list
    while (!this->empty())
    { // reverse L into T
        int s = this->front();
        this->removeFront();
        T.addFront(s);
    }
    while (!T.empty())
    { // copy T back to L
        int s = T.front();
        T.removeFront();
        this->addBack(s);
    }
}

typedef char DataType; // deque element type
class LinkedDeque
{ // deque as doubly linked list
public:
    LinkedDeque();                       // constructor
    int size() const;                    // number of items in the deque
    bool empty() const;                  // is the deque empty?
    const DataType &front();             // the first element
    const DataType &back();              // the last element
    void insertFront(const DataType &e); // insert new first element
    void insertBack(const DataType &e);  // insert new last element
    void removeFront();                  // remove first element
    void removeBack();                   // remove last element
private:                                 // member data
    DLinkedList D;                       // linked list of elements
    int n;                               // number of elements
};

// Another way to initialize values in a constructor. The brackets next to the variable
// signify the value that it gets initialized to.
LinkedDeque::LinkedDeque() : D(), n(0) {}

void LinkedDeque::insertFront(const DataType &e)
{
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const DataType &e)
{ // insert new last element
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront()
{ // remove first element
    if (empty())
        cout << "removeFront of empty deque\n";
    else
    {
        D.removeFront();
        n--;
    }
}

void LinkedDeque::removeBack()
{ // remove last element
    if (empty())
        cout << "removeBack of empty deque\n";
    else
    {
        D.removeBack();
        n--;
    }
}

int LinkedDeque::size() const
{
    return n;
}

bool LinkedDeque::empty() const
{
    return n == 0;
}

const DataType &LinkedDeque::front()
{ // get the front element
    if (empty())
        cout << "front of empty queue\n";
    return D.front(); // list front is queue front
}

const DataType &LinkedDeque::back()
{ // get the back element
    if (empty())
        cout << "back of empty queue\n";
    return D.back(); // list front is queue front
}

int checkPalindrome(string str)
{
    LinkedDeque q;
    ll n=str.sz;
    forl(i,0,n)
    q.insertBack(str[i]);
    ll flag=0;
    while(true)
    {
        if(q.size()==1)
        {
            flag =1;
            break;
        }
        char c1=q.front();
        q.removeFront();
        char c2=q.back();
        q.removeBack();
        if(c1==c2)
        flag=1;
        else
        {
            flag=0;break;
        }

    }
    return flag;
}

int main()
{
    cout<<checkPalindrome("abcba")<<endl;
    cout<<checkPalindrome("abcbb")<<endl;
    cout<<checkPalindrome("datastructures")<<endl;
    cout<<checkPalindrome("datastructureserutcurtsatad")<<endl;
    return 0;
}