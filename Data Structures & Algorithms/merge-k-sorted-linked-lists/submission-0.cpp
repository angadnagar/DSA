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

    ListNode* mergeTwoLinkedList(ListNode* node1,ListNode* node2){
        if(node1==NULL)
        return node2;

        if(node2==NULL)
        return node1;

        ListNode* first = node1;
        ListNode* second = node2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(first!=NULL && second!=NULL){
            if(first->val < second->val){
                curr->next=first;
                first=first->next;
            }

            else{
                 curr->next=second;
                 second=second->next;
            }
            curr=curr->next;
        }

        if(first!=NULL){
            curr->next=first;
        }

        if(second!=NULL){
            curr->next=second;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0)
        return NULL;
        
        int n = lists.size();

        for(int i=1;i<n;i++){
            lists[i]=mergeTwoLinkedList(lists[i],lists[i-1]);
        }

        return lists[n-1];
    }
};
