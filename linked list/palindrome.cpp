class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       stack<int>st;
       Node* t=head;
       while(t!=NULL){
           st.push(t->data);
           t=t->next;
       }
       t=head;
       int f=0;
       while(t!=NULL){
           int curr=st.top();
           st.pop();
           if(curr!=t->data){
               return false;
           }
           t=t->next;
       }

       return true;

    }
};
