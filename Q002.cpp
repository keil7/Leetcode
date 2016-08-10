/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        while(1) {
            int r = p1->val+p2->val+carry;
            carry = r/10;
            p1->val = r%10;
            if(p1->next&&p2->next) {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
                break;
        }
        if(!p1->next) //The length of l2 is no less than the length of l1
            p1->next = p2->next;
        //consider carry
        while(carry) {
            if(!p1->next)//overflow, one more node needed
                p1->next = new ListNode(0);
            p1 = p1->next;
            carry = ++(p1->val)/10;
            p1->val %= 10;
        }
        
        return l1;
    }
};
