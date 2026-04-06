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

    int getLength(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head=head->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);

        int m = len - n;

        if(head->next==NULL && m==0)
        return NULL;

        if(m==0){
            ListNode* newHead = head->next;
            head->next=NULL;
            return newHead;
        }

        int count = 1;
        ListNode* first = head;

        while(count < m){
            first = first->next;
            count++;
        }

        first->next=first->next->next;

        return head;
    }
};
