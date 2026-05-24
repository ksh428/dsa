class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       Node* curr=head;
       Node* prev=NULL;
       unordered_map<Node*,int>m;
       while(curr){
           if(!m[curr]){
               m[curr]=1;
               prev=curr;
               curr=curr->next;
           }else{
               prev->next=NULL;
               break;
           }
       }
    }
};
