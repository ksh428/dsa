
#define ll long long
#define mod 1000000007
long long  multiplyTwoLists (Node* l1, Node* l2)
{
   ll a=0;
   ll b=0;
   Node* t=l1;
   while(t!=NULL){
       a=(a*10+t->data)%mod;
       t=t->next;
   }
   t=l2;
   while(t!=NULL){
       b=(b*10+t->data)%mod;
       t=t->next;
   }
   return (a*b)%mod;
}
