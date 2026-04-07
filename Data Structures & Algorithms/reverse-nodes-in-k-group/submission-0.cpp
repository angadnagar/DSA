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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev = dummy;
        
        while(true){
        ListNode* kth = getKth(groupPrev,k);

        if(!kth)
        break;

        ListNode* groupNext = kth->next;
        ListNode* prevNode = kth->next;
        ListNode* curr = groupPrev->next;

        while(curr!=groupNext){
          ListNode* nextN = curr->next;
          curr->next = prevNode;
          prevNode = curr;
          curr=nextN;

        }

        ListNode* nextN = groupPrev->next;
        groupPrev->next=kth;
        groupPrev=nextN;

        }

        return dummy->next;

        
    }

    ListNode* getKth(ListNode* curr,int k){
      while(curr && k>0){
        curr=curr->next;
        k--;
      }

      return curr;
    }
};
