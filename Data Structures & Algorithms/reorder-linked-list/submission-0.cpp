/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverseLL(ListNode* slow){
        ListNode* prev = NULL;

        while(slow!=NULL){
            ListNode* forward = slow->next;
            slow->next=prev;
            prev=slow;
            slow=forward;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevNode = NULL;

        while(fast!=NULL){
            prevNode=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
        }
        prevNode->next=NULL;

        ListNode* newHead = reverseLL(slow);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            ListNode* forward = first->next;
            ListNode* nextNode = second->next;
            first->next=second;
            second->next=forward;
            first=forward;
            second=nextNode;
        }



    }
};
