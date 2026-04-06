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

        Node* secondHead = head->next;
        first = head;

        while(first!=NULL){
            if(first->random!=NULL){
                first->next->random = first->random->next;
            }
            first=first->next->next;
        }

        first = head;

        while(first!=NULL){
            Node* forward = first->next;
            first->next=forward->next;

            if(forward->next!=NULL){
                forward->next=forward->next->next;
            }

            first=first->next;
        }

        return secondHead;
    }
};
