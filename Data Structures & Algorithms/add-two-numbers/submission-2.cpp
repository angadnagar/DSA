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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;

        int carry = 0;

        ListNode* head = NULL;
        ListNode* addNum = NULL;


        while(first!=NULL && second!=NULL){
           int val1=first->val;
           int val2=second->val;

           int sum = carry+val1+val2;
       
           ListNode* sumNode = new ListNode(sum%10);

           if(head==NULL){
            head=sumNode;
            addNum=head;
           }
           
           else{
           addNum->next=sumNode;
           addNum=addNum->next;
           }

           carry=sum/10;

           first=first->next;
           second=second->next;
           
           



        }



        while(first!=NULL){
           int val1=first->val;

           int sum = carry+val1;
       
           ListNode* sumNode = new ListNode(sum%10);

           if(head==NULL){
            head=sumNode;
            addNum=head;
           }

           else{
           addNum->next=sumNode;
           addNum=addNum->next;
           }
           
           carry=sum/10;

           first=first->next;

        }

        while(second!=NULL){
           int val2=second->val;

           int sum = carry+val2;
       
           ListNode* sumNode = new ListNode(sum%10);

           if(head==NULL){
            head=sumNode;
            addNum=head;
           }
           
           else{
           addNum->next=sumNode;
           addNum=addNum->next;
           }
           
           carry=sum/10;

           second=second->next;

        }

        if(carry>0){
            ListNode* node = new ListNode(carry);
            addNum->next=node;
        }

        return head;
    }
};
