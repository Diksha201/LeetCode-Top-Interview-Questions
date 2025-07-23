class Solution {
public:
   int getLength(ListNode* head){
        ListNode* temp=head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
       if(head==NULL) {
           return head;
       }
           if(head->next==NULL) {
               return head;
           }
           //ek case main solve karunga

           ListNode* prev = NULL;
           ListNode* curr=head;
           ListNode* nextNode=curr->next;
           int pos=0;
           
           int len = getLength(head);
           
           if(len<k){
               return head;
           }
           while(pos<k){
               
               nextNode=curr->next;
               curr->next=prev;
               prev=curr;
               curr=nextNode;
               pos++;
           }
           ListNode* recursionKaAns=NULL;
        if(nextNode != NULL){
            recursionKaAns=reverseKGroup(nextNode,k);
            head->next=recursionKaAns;
        }
        return prev;
       }
    
};