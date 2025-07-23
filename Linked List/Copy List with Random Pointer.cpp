class Solution {
public:
   Node* copyRandomList(Node* head){
    if(!head) return 0;

    Node* it = head;
    while(it){
        Node* clonedNode=new Node(it->val);
        clonedNode->next=it->next;
        it->next=clonedNode;
        it=it->next->next;
    }

     it=head;
     while(it){
        Node* clonedNode=it->next;
        clonedNode->random=it->random?it->random->next:nullptr;
        it=it->next->next;
     }
     
     
     it=head;
    
     Node*clonedHead=it->next;
      while(it){
        Node*clonedNode=it->next;
        it->next=it->next->next;
        if(clonedNode->next){
           clonedNode->next=clonedNode->next->next; 
        }
        it=it->next;
     }
     return clonedHead;

   }

        
    
};