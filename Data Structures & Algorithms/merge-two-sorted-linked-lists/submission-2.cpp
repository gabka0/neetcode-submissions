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
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode head = ListNode();
        ListNode* cur = &head;
        while(cur1 && cur2){
            if(cur1->val>=cur2->val){
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else{
                cur->next=cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }
        if(cur1==nullptr){
            cur->next = cur2;
        }
        else cur->next = cur1;
        return head.next;

        
    }
};
