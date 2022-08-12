#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *temp = NULL;
    while(head)
    {
        temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        if(head->prev==NULL)break;
        head = head->prev;
    }
    
    return head;
}

int main()
{
    Node *head = NULL,*temp = NULL;
     Node **n = &head;
    for(int i = 0;i< 8;i++)
    {
        *n = new Node(i);
        (*n)->prev = temp;
        temp = *n;
        n = &((*n)->next);
    }
    head = reverse(head);
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    
    return 0;
}