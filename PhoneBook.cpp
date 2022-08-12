#include <bits/stdc++.h>
using namespace std;

// Phone Book Data
class Data
{
private:
    string name;
    string number;

public:
    Data()
    {
        name = "";
        number = "";
    }
    Data(string a, string b)
    {
        name = a;
        number = b;
    }
    string &getName()
    {
        return name;
    }
    string &getNumber()
    {
        return number;
    }
    void setName(string &a)
    {
        name = a;
    }
    void setNumber(string &a)
    {
        number = a;
    }
};

// Node
class Node
{   
private:
    Data elem; 
    Node *next;
    Node *prev;
    friend class DoubleLinkedList;
};

// Doubly Linked List
class DoubleLinkedList
{
public:
    void modifyByName(string name);
    void modifyByNumber(string number);
    Node *searchByName(string name);
    Node *searchByNumber(string number);

private:
    Node *header;
    Node *trailer;
};
Node* DoubleLinkedList::searchByName(string name)
{
    Node* listNode = new Node();
    listNode->elem = Data("Shivam","123");
    if(name!="Shivam")return nullptr;
    return listNode;
}
Node* DoubleLinkedList::searchByNumber(string number)
{
    Node* listNode = new Node();
    listNode->elem = Data("Shivam","123");
    if(number!="123")return nullptr;
    return listNode;
}
void DoubleLinkedList::modifyByName(string name)
{
    Node *cur = searchByName(name);
    if(cur!=nullptr)
    {
    string nm = cur->elem.getName();
    string num = cur->elem.getNumber();
    cout<<"Contact Found:- "<<endl;
    cout<<"Name: "<<nm<<endl;
    cout<<"Contact Number: "<<num<<endl;
    loop:
    cout<<"Modification:\nPlease Choose from the given Options:-"<<endl;
    cout<<"1) Update Name."<<endl;
    cout<<"2) Update Number."<<endl;
    int i;
    cin>>i;
    
    switch(i)
    {
        case 1:
        {
            cout<<"New Name: ";
            string value;
            cin.ignore();
            getline(cin,value);
            cur->elem.setName(value);
            break;
        }
        case 2:
        {
            cout<<"New Number: ";
            string value;
            cin.ignore();
            cin>>value;
            cur->elem.setNumber(value);
            break;
        }
        default:
        cout<<"You have Chosen the Wrong Option."<<endl;
        goto loop;
        break;
    }
    cout<<"Modified Contact Details:-"<<endl;
    cout<<"Name: "<<cur->elem.getName()<<endl;
    cout<<"Number: "<<cur->elem.getNumber()<<endl;
    }else
    {
        cout<<"Contact Not Found By Name.\nTry to Modify with Number.\nOtherwise, Add a new Contact."<<endl;
    }
    
}
void DoubleLinkedList::modifyByNumber(string number)
{
    Node *cur = searchByNumber(number);
    if(cur!=nullptr)
    {
    string nm = cur->elem.getName();
    string num = cur->elem.getNumber();
    cout<<"Contact Found:- "<<endl;
    cout<<"Name: "<<nm<<endl;
    cout<<"Contact Number: "<<num<<endl;
    loop:
    cout<<"Modification:\nPlease Choose from the given Options:-"<<endl;
    cout<<"1) Update Name."<<endl;
    cout<<"2) Update Number."<<endl;
    int i;
    cin>>i;
    
    switch(i)
    {
        case 1:
        {
            cout<<"New Name: ";
            string value;
            cin.ignore();
            getline(cin,value);
            cur->elem.setName(value);
            break;
        }
        case 2:
        {
            cout<<"New Number: ";
            string value;
            cin.ignore();
            cin>>value;
            cur->elem.setNumber(value);
            break;
        }
        default:
        cout<<"You have Chosen the Wrong Option."<<endl;
        goto loop;
        break;
    }
    cout<<"Modified Contact Details:-"<<endl;
    cout<<"Name: "<<cur->elem.getName()<<endl;
    cout<<"Number: "<<cur->elem.getNumber()<<endl;
    }else
    {
        cout<<"Contact Not Found By Number.\nTry to Modify with Name.\nOtherwise, Add a new Contact."<<endl;
    }
}
int main()
{
    DoubleLinkedList obj;
    cout<<"Choose Your Approach for Modification:-"<<endl;
    cout<<"1)By Name"<<endl;
    cout<<"2)By Number"<<endl;
    int i;
    cin>>i;
    switch(i)
    {
        case 1:{
    cout<<"Name to be Modified:"<<endl;
    string n;
    cin>>n;
    obj.modifyByName(n);
        }
        case 2:
        {
    cout<<"Number to be Modified:"<<endl;
    string n;
    cin>>n;
    obj.modifyByNumber(n);
        }
    }
    return 0;
}
