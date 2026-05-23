class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;
        ListNode* cur;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        if(list1->val <= list2->val){
            head = list1;
            cur = list1;
            p1 = p1->next;   
        }
        else{
            head = list2;
            cur = list2;
            p2 = p2->next;   
        }

        while(p1 && p2){
            if(p1->val <= p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if (p1) cur->next = p1;
        if (p2) cur->next = p2;

        return head;
    }
};