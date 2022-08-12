#include <iostream>
using namespace std;

class CircleList;

typedef string Elem;				// element type
class CNode {					    // circularly linked list node
private:
    Elem elem;					    // linked list element value
    CNode* next;				    // next item in the list
    friend class CircleList;		// provide CircleList access
};

class CircleList {				    // a circularly linked list
public:
    CircleList();				    // constructor
    ~CircleList();				    // destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;		// element at cursor
    const Elem& back() const;		// element following cursor
    void advance();				    // advance cursor
    void add(const Elem& e);		// add after cursor
    void remove();				    // remove node after cursor
    void traverse();                // traverse the list
private:
    CNode* cursor;				    // the cursor 
};

CircleList::CircleList()			// constructor
    : cursor(NULL) { }
CircleList::~CircleList()			// destructor
    { while (!empty()) remove(); }

bool CircleList::empty() const		        // is list empty?
    { return cursor == NULL; }
const Elem& CircleList::back() const		// element at cursor
    { return cursor->elem; }
const Elem& CircleList::front() const		// element following cursor
    { return cursor->next->elem; }
void CircleList::advance()			        // advance cursor
    { cursor = cursor->next; }
    
void CircleList::add(const Elem& e) {		// add after cursor
    CNode* v = new CNode;			        // create a new node
    v->elem = e;
    if (cursor == NULL) {			        // list is empty?
        v->next = v;				        // v points to itself
        cursor = v;				            // cursor points to v
    }
    else {					                // list is nonempty?
        v->next = cursor->next;			    // link in v after cursor
        cursor->next = v;
    }
}

void CircleList::remove() {			        // remove node after cursor
    CNode* old = cursor->next;			    // the node being removed
    if (old == cursor) 				        // removing the only node?
        cursor = NULL;				        // list is now empty
    else 
        cursor->next = old->next;			// link out the old node 
    delete old;					            // delete the old node
}

void CircleList::traverse(){
    CNode *temp = cursor->next;
    while(temp != cursor){
        cout<<temp->elem<<" ";
        temp = temp->next;
    }
    cout<<temp->elem;
    cout<<endl;
}

void printChoices(){
    cout<<"Please enter one of the following choices:\n";
    cout<<"1 : Add\n";
    cout<<"2 : Get front element\n";
    cout<<"3 : Get back element\n";
    cout<<"4 : Advance cursor\n";
    cout<<"5 : Remove element pointed by cursor\n";
    cout<<"6 : Check if list is empty\n";
    cout<<"7 : Traverse the list\n";
    cout<<"8 : Exit\n";
}

int main(){
    CircleList cl;
    int choice = 0;
    printChoices();
    while(choice != 8){
        cin>>choice;
        switch(choice){
            case 1:{
                string elem;
                cin>>elem;
                cout<<"Adding the following element : "<<elem<<endl;
                cl.add(elem);
                break;
            }
            case 2:{
                cout<<"Front element is : "<<cl.front()<<endl;
                break;
            }
            case 3:{
                cout<<"Back element is : "<<cl.back()<<endl;
                break;
            }
            case 4:{
                cout<<"Advancing the cursor\n";
                cl.advance();
                break;
            }
            case 5:{
                cout<<"Removing element pointed by the cursor\n";
                cl.remove();
                break;
            }
            case 6:{
                cout<<"List is "<<(cl.empty()?"":"not")<<" empty\n";
                break;
            }
            case 7:{
                cout<<"Traversing the list : ";
                cl.traverse();
                break;
            }
            case 8:{
                //Remove the linked list and Free the Memory.
                while(!cl.empty())
                {
                    cl.remove();
                }
                cout<<"Exiting\n";
                break;
            }
            default:{
                cout<<"Not a valid entry!\n";
                break;
            }
        }
    }
    return 0;
}