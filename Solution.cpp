struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int nodeCount(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
  
    int intersectPoint(Node* head1, Node* head2) {
        int l1= nodeCount(head1);
        int l2= nodeCount(head2);
        Node* temp1=head1;
        Node* temp2=head2;
        
        if(l1>l2){
            int diff= l1-l2;
            while(diff--){
                temp1=temp1->next;
            }
        }
        else{
            int diff=l2-l1;
            while(diff--){
                temp2= temp2->next;
            }
        }
        
        while(temp1!=NULL && temp2!= NULL){
            if(temp1==temp2){
                return temp1->data;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return -1;
    }
};
