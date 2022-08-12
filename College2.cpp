#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedNode {
public:
    int value;
    SinglyLinkedNode* next;
};
SinglyLinkedNode *reverseList(SinglyLinkedNode *A,int B,int z) 
{
    
    SinglyLinkedNode *prev=NULL,*curr=A,*nxt;
    int cnt = 0;
    if(z==0)return prev;
    while(curr!=NULL && cnt<B)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    if(nxt!=NULL)A->next = reverseList(nxt,B,z-1);
    return prev;
}
int main()
{
   int n,m,t;
   cin>>n>>m; 
   t=n/m;
   SinglyLinkedNode *res,*cs;
   SinglyLinkedNode *l1 = NULL;
   SinglyLinkedNode **node = &l1;
   int i=1,z=0;

   while(i<=n)
   {
       
       int k;
       cin>>k;
       *node = new SinglyLinkedNode();
       (*node)->value = k;
       if(z==t)
       {
           cs = *node;
       }
       node = &(*node)->next;
       if(i%m==0)z++;
       i++;
   }
   res = reverseList(l1,m,t);

   while(l1!=NULL)
   {
       cout<<res->value<<" ";
       res = res->next;
   }
   while(cs!=NULL)
   {
       cout<<cs->value<<" ";
       cs = cs->next;
   }
 return 0;
}