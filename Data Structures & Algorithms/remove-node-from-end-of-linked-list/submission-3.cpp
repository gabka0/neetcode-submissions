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
        int length = 0;
        ListNode* cur = head;
        while(cur){
            length+=1;
            cur = cur->next;
        }
        int order = length - n;
        if (order == 0) {
            ListNode* newHead = head->next;
            return newHead;
        }
        cur = head;
        for(int i=0; i<order-1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
        
        
    }
};
