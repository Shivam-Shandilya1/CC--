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

template<typename DT> 
 class SinglyLinkedNode { 
 public: 
 // data items in the node 
 DT dataItem; 
 SinglyLinkedNode<DT> *next; 
 
 // constructor 
 SinglyLinkedNode(DT nodeValue, SinglyLinkedNode<DT> *nextPointer);
 }; 
 
 template<typename DT> 
 SinglyLinkedNode<DT>::SinglyLinkedNode(DT nodeValue, SinglyLinkedNode *nextPointer) {  dataItem = nodeValue; 
 next = nextPointer; 
 } 

 template<typename DT> 
 class SinglyLinkedList { 
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
 public: 
 // Constructor 
 SinglyLinkedList(); 
 
 void insertEnd(const DT &newDataItem); 
 void insertBeginning(const DT &newDataItem); 
 void deleteBeginning(); 
 void deleteEnd(); 
 void printForward(); 
 void printBackward(); 
 DT getHead();
 
 }; 
 
 template<typename DT> 
 SinglyLinkedList<DT>::SinglyLinkedList() { 
head = NULL; 
 numberOfItems=0; 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::insertBeginning(const DT &newDataItem) { 
 if(numberOfItems==0) { 
 head = new SinglyLinkedNode<DT>(newDataItem, NULL); 
 } 
 
 else { 
 SinglyLinkedNode<DT>* temp = new SinglyLinkedNode<DT>(newDataItem, head); 
 head = temp; 
 } 
 numberOfItems++; 
 };
 
 template<typename DT> 
 void SinglyLinkedList<DT>::insertEnd(const DT &newDataItem) { 
 insertEndRecursive(newDataItem, head); 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::insertEndRecursive(const DT &newDataItem, SinglyLinkedNode<DT> *current) {  if(numberOfItems==0) { 
 head = new SinglyLinkedNode<DT>(newDataItem, NULL); 

 numberOfItems++; 
 } 
 
 else if(current->next==NULL) { 
 current->next = new SinglyLinkedNode<DT>(newDataItem, NULL); 
 
 numberOfItems++; 
 } 
 else { 
 insertEndRecursive(newDataItem, current->next); 
 } 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::deleteBeginning() { 
 SinglyLinkedNode<DT>* temp = head->next; 
 delete head; 
 head = temp; 
 numberOfItems--; 
 } 
 

template<typename DT> 
 void SinglyLinkedList<DT>::deleteEnd() { 
 deleteEndRecursive(head); 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::deleteEndRecursive(SinglyLinkedNode<DT> *current) {  if(numberOfItems==1) { 
 delete head; 
 head = NULL; 

 numberOfItems--; 
 }  
 else if(current->next->next==NULL) { 
 delete current->next; 
 current->next = NULL; 
 
 numberOfItems--; 
 } 
 
 else { 
 deleteEndRecursive(current->next); 
 } 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::printForward() { 
 printForwardRecursive(head); 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::printForwardRecursive(SinglyLinkedNode<DT> *current) {  if(current==NULL) return; 
 
 std::cout<<current->dataItem<<" "; 
 printForwardRecursive(current->next); 
 if(current==head) std::cout<<std::endl; 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::printBackward() { 
 printBackwardRecursive(head); 
 } 
 
 template<typename DT> 
 void SinglyLinkedList<DT>::printBackwardRecursive(SinglyLinkedNode<DT> *current) {  if(current==NULL) return; 

 printBackwardRecursive(current->next); 
 std::cout<<current->dataItem<<" "; 
 if(current==head) std::cout<<std::endl; 
 } 
 
 template<typename DT> 
 DT SinglyLinkedList<DT>::getHead() { 
 return head->dataItem; 
}

template<typename DT>
class Stack {
private:
int numberOfItems;
SinglyLinkedList<DT> stackList;

public:
Stack();
void push(const DT &newDataItem);
DT pop();
bool isEmpty();
DT getTop();
};

// template<typename DT>
bool evaluateBracketSequence(const std::string &sequence)
{
    Stack<char> s;
    int n=sequence.size();
    int emp=0;
    for(int i=0;i<n;i++)
    {
        if(sequence[i]=='(')
        {
            s.push(sequence[i]);
        }
        else
        {
            if(s.isEmpty())
            {
                emp=1;
                break;
            }
            else
            s.pop();
        }
    }
    if(emp)
    return false;
    else if(s.isEmpty())
    return true;
    else return false;
}

template<typename DT>
Stack<DT>::Stack() {
numberOfItems=0;
}

template<typename DT>
void Stack<DT>::push(const DT &newDataItem) {
stackList.insertBeginning(newDataItem);
numberOfItems++;
}
template<typename DT>
DT Stack<DT>::pop() {
DT return_val = stackList.getHead();
stackList.deleteBeginning();
numberOfItems--;
return return_val;
}
template<typename DT>
DT Stack<DT>::getTop()
{
    DT return_val = stackList.getHead();
    return return_val;
}
template<typename DT>
bool Stack<DT>::isEmpty() {
return numberOfItems==0;
}
int main()
{
    cout<<evaluateBracketSequence("()()()")<<std::endl;
    cout<<evaluateBracketSequence("(())()")<<std::endl;
    cout<<evaluateBracketSequence(")(")<<std::endl;
    cout<<evaluateBracketSequence("((())(()))")<<std::endl;
    cout<<evaluateBracketSequence("((())(())(")<<std::endl;

    return 0;
}