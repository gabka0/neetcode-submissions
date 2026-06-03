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
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        int rem = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 || cur2 || rem){
            int val1, val2;
            if(cur1) val1 = cur1->val;
            else val1 = 0;
            if(cur2) val2 = cur2->val;
            else val2 = 0;
            int val3 = val1 + val2 + rem;
            if(val3 >=10){
                rem = 1;
            }
            else{
                rem = 0;
            }
            val3 = val3 % 10;
            ans->next = new ListNode(val3);
            ans = ans->next;
            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 = cur2->next;

        }
        return dummy->next;
        
    }
};
