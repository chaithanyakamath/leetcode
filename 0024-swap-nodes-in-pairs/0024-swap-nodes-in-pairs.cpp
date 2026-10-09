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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* cur = head;
        vector<ListNode*> store;

        while(cur){
            store.push_back(cur);
            cur = cur->next;
        }

        ListNode* ans = new ListNode(0);
        ListNode* ptr = ans;

        int n = store.size();
        for(int i=1; i<n; i=i+2){
            ptr->next = store[i];
            ptr = ptr->next;
            ptr->next = store[i-1];
            ptr = ptr->next;
        } 
        if(n%2 != 0){   
            ptr->next = store[n-1];
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        return ans->next;
    }
};