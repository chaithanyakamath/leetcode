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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* itr = head;
        vector<int> store, criticalPoints;

        while(itr){
            store.push_back(itr->val);
            itr = itr->next;
        }

        int n = store.size();
        for(int i=1; i<n-1; i++){
            if((store[i-1] > store[i] && store[i] < store[i+1]) || 
            (store[i-1] < store[i] && store[i] > store[i+1])){
                criticalPoints.push_back(i);
            }
        }
        if(criticalPoints.size() < 2)   return {-1, -1};

        int minn = INT_MAX;
        int maxx = criticalPoints.back() - criticalPoints.front();
        for(int i=1; i<criticalPoints.size(); i++){
            minn = min(minn, criticalPoints[i]-criticalPoints[i-1]);
        }

        return {minn, maxx};
    }
};