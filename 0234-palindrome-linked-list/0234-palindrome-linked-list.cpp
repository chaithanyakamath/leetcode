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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* cur = slow;
        ListNode* prev = nullptr;

        while(cur){
            ListNode* NextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = NextNode;
        }

        ListNode* a = head;
        ListNode* b = prev;
        while(a && b){
            if(a->val != b->val) return false;
            else{
                a = a->next;
                b = b->next;
            }
        }
        return true;
    }
};