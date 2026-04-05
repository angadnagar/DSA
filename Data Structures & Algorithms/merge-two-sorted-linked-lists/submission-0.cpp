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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* newNode = dummy;

        ListNode* l1=list1;
        ListNode* l2=list2;

        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                newNode->next=l1;
                l1=l1->next;
            }

            else{
                newNode->next=l2;
                l2=l2->next;
            }

            newNode=newNode->next;

        }

        while(l1!=NULL){
            newNode->next=l1;
            l1=l1->next;
            newNode=newNode->next;
        }

        while(l2!=NULL){
            newNode->next=l2;
            l2=l2->next;
            newNode=newNode->next;
        }

        return dummy->next;
    }
};
