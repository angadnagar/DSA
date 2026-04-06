/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL)
        return NULL;
        
        Node* first = head;

        while(first!=NULL){
            Node* newNode = new Node(first->val);
            Node* forward = first->next;
            first->next=newNode;
            newNode->next=forward;
            first=forward;
        }

        Node* second = head->next;
        first = head;

        while(first!=NULL){
            if(first->random == NULL){
                second->random = NULL;
            }
            else{
            second->random = first->random->next;
            }

            if(first->next == NULL){
                first = NULL;
            }

            else{
                first = first->next->next;
            }
            if(first == NULL){
                second = NULL;
            }
            else
            second = first->next;
        }

        first = head;
        Node* secondHead = first->next;

        while(first!=NULL){
            Node* forward = first->next;
            Node* originalForward = forward->next;

        if(forward->next==NULL){
            forward->next=NULL;
        }
        else{
            forward->next=forward->next->next;
        }
            first->next = originalForward;
            first=originalForward;
        }

        return secondHead;
    }
};
