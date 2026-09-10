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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i=0; i<(left-1); i++)   prev = prev->next;
        ListNode* cur = prev->next;

        int count = (right-left);
        for(int i=0; i<(right-left); i++){
            ListNode* nxtNode = cur->next;
            cur->next = nxtNode->next;
            nxtNode->next = prev->next;
            prev->next = nxtNode;
        }
        return dummy->next;
    }
};