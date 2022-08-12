#include <iostream>

using namespace std;

template<typename E>
class SLinkedList;                      //forward declare the class

template <typename E>
class SNode {					        // singly linked list node
private:
    E elem;					            // linked list element value
    SNode<E>* next;				        // next item in the list
    friend class SLinkedList<E>;		// provide SLinkedList access
};

template <typename E>
class SLinkedList {				        // a singly linked list
public:
    SLinkedList();				        // empty list constructor
    ~SLinkedList();				        // destructor
    bool empty() const;				    // is list empty?
    const E& front() const;			    // return front element
    void addFront(const E& e);			// add to front of list
    void removeFront();				    // remove front item list
    void traverse();                    // traverse the list
private:
    SNode<E>* head;				        // head of the list
};

template <typename E>
SLinkedList<E>::SLinkedList()			// constructor
    : head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const		// is list empty?
{ return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const	// return front element
{ return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{ while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) {		// add to front of list
    SNode<E>* v = new SNode<E>;				    // create new node
    v->elem = e;					            // store data
    v->next = head;					            // head now follows v
    head = v;						            // v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {			// remove front item
    SNode<E>* old = head;				        // save current head
    head = old->next;					        // skip over old head
    delete old;					        	    // delete the old head
}

template <typename E>
void SLinkedList<E>::traverse(){
    SNode<E> *temp = head;
    while(temp != NULL){
        cout<<temp->elem<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printChoices(){
    cout<<"Please enter one of the following choices:\n";
    cout<<"1 : Add at the front\n";
    cout<<"2 : Get frontmost element\n";
    cout<<"3 : Remove front element\n";
    cout<<"4 : Check if list is empty\n";
    cout<<"5 : Traverse the list\n";
    cout<<"6 : Exit\n";
}
int main(){
    SLinkedList<string> sl;
    int choice = 0;
    printChoices();
    while(choice != 6){
        cin>>choice;
        switch(choice){
            case 1:{
                string elem;
                cin>>elem;
                cout<<"Adding the following element to the front : "<<elem<<endl;
                sl.addFront(elem);
                break;
            }
            case 2:{
                cout<<"Frontmost element is : "<<sl.front()<<endl;
                break;
            }
            case 3:
                cout<<"Removing from the front\n";
                sl.removeFront();
                break;
            case 4:
                cout<<"List is "<<(sl.empty()?"":"not")<<" empty\n";
                break;
            case 5:
                cout<<"Traversing the list : ";
                sl.traverse();
                break;
            case 6:
            while(!sl.empty())
            {
                sl.removeFront();
            }
                cout<<"Exiting";
                break;
            default:
                cout<<"Not a valid entry!\n";
                break;
        }
    }
    return 0;
}