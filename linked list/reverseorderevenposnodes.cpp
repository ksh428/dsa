/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //INTERVIEWBIT
 // CAN ALSO BE SOLVED USING STACK. STORE THE DATA OF EVEN POS NODES AND REPLCE THE DATA WHILE TRAVERSING AGAN FROM HEAD

 //SEE COPY FOR EXP
ListNode* Solution::solve(ListNode* head) {
    ListNode* odd=head;
     if(!head or head->next==NULL or head->next->next==NULL) return head;
     ListNode* even=NULL;
     while(!odd and odd->next!=NULL){
         ListNode* t=odd->next;
         odd->next=t->next;
         t->next=even;
         even=t;
         odd=odd->next;
     }
     odd=head;
     while(even){
         ListNode* t=even->next;
         even->next=odd->next;
         odd->next=even;
         odd=odd->next->next;

         even=t;
     }
     return head;
}

