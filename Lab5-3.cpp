#include <bits/stdc++.h>
using namespace std;

// Done but iterative Solution and Not Recursive One

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
    void moveNode(int a,int b);
    void reorderList();
};



template<typename T>
void SinglyLinkedList<T>::reorderList()
{
    SinglyLinkedNode<T>* curr=head;
    // rearrange(&curr,head);
    stack<SinglyLinkedNode<T>*>s;
    while (curr)
    {
        s.push(curr);
        curr=curr->next;
    }
    curr=head;
    int n=s.size();
    if(n<=2)
    {
        return ;
    }

    SinglyLinkedNode<T>* next;
    for(int i=0;i<n/2;i++)
    {
        next=curr->next;
        curr->next=s.top();
        s.pop();
        curr=curr->next;
        curr->next=next;
        curr=curr->next;
        // cout<<"curr and Next"<<curr->dataItem<<next->dataItem<<endl;

    }
    curr->next=NULL;
   
    


}

// template<typename T>
// void rearrange( SinglyLinkedNode<T>** head,  SinglyLinkedNode<T>* last)
// {
 
//     if (!last)
//         return;
 
//     // Recursive call
//     rearrange(head, last->next);
 
//     // (*head)->next will be set to NULL
//     // after rearrangement.
//     // Need not do any operation further
//     // Just return here to come out of recursion
//     if (!(*head)->next)
//         return;
 
//     // Rearrange the list until both head
//     // and last meet or next to each other.
//     if ((*head) != last && (*head)->next != last) {
//         struct Node* tmp = (*head)->next;
//         (*head)->next = last;
//         last->next = tmp;
//         *head = tmp;
//     }
//     else {
//         if ((*head) != last)
//             *head = (*head)->next;
//         (*head)->next = NULL;
//     }
// }


template<typename T>
void SinglyLinkedList<T>::moveNode(int a,int b)
{
    SinglyLinkedNode<T>* temp=head;
    SinglyLinkedNode<T>* to_delete;
    while(temp!=NULL)
    {
        if(temp->next->dataItem==a)
        {
            to_delete=temp->next;

            temp->next=temp->next->next;
            
            break;
        }

        temp=temp->next;
        
        
    }
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        if(i==b-1)
        {
            
            
            to_delete->next=temp->next;
            temp->next=to_delete;
            break;
        }
        
      

        temp=temp->next;

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

    std::cout << current->dataItem << " ";
    printForwardRecursive(current->next);
    if (current == head)
        std::cout << std::endl;
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
    std::cout << current->dataItem << " ";
    if (current == head)
        std::cout << std::endl;
}

int main()
{
    SinglyLinkedList<int> list;
    for(int i=0;i<10;i++) list.insertEnd(i+1);
    list.printForward();
    list.reorderList();
    list.printForward();

}