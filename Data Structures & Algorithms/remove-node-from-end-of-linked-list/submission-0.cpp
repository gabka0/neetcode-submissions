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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr1 = dummy;
        ListNode* curr2 = dummy;
        for(int i=0;i<n;i++){
            curr2 = curr2->next;
        }
        while(curr2->next){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        curr1->next = curr1->next->next;
        return dummy->next;
        
    }
};
