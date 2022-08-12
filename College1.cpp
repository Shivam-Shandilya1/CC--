#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedNode {
public:
    int value;
    SinglyLinkedNode* next;
};
long long addTwoNumbers(SinglyLinkedNode *l1,SinglyLinkedNode *l2)
{
    long long number=0,i=0;
    int carry = 0;
    long long sum = 0;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1!=NULL)
        {
            sum+=l1->value;
            l1 = l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->value;
            l2= l2->next;
        }
        if(carry==1)
        {
            sum++;
            carry = 0;
        }
        
        number+=((sum%10)*pow(10,i));
        i++;
        if(sum/10>=1)carry=1;
        sum = 0;
    }
    if(carry==1){
        number+=1*pow(10,i);
    }
    return number;
}

SinglyLinkedNode *reverseLinkedList(SinglyLinkedNode *l1)
{
    SinglyLinkedNode *temp = NULL, *temp2;
    while(l1!=NULL)
    {
        temp2 = l1->next;
        
        l1->next = temp;
        temp = l1;
        
        l1 = temp2;
    }
    l1=temp;
    return l1;
}

int main()
{
string s1,s2;
cin>>s1>>s2;

SinglyLinkedNode *l1 = NULL;
SinglyLinkedNode *l2 = NULL;
SinglyLinkedNode **node = &l1;
SinglyLinkedNode **node2 = &l2;

for(char c:s1){
    (*node) = new SinglyLinkedNode();
    (*node)->value = (c-'0');
    node = &(*node)->next;
}
for(char c:s2){
    (*node2) = new SinglyLinkedNode();
    (*node2)->value = (c-'0');
    node2 = &(*node2)->next;
}


SinglyLinkedNode *h1 = reverseLinkedList(l1);
SinglyLinkedNode *h2 = reverseLinkedList(l2);


long long k = addTwoNumbers(h1,h2);
cout<<k;
return 0;
}