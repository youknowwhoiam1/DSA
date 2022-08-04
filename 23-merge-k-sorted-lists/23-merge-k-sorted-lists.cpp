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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int n = list.size();
        while(1){
            int idx = -1;
            int mn = INT_MAX;
            for(int i = 0; i < n; i++){
                if(list[i]){
                    if(list[i]->val < mn){
                        mn = list[i]->val;
                        idx = i;
                    }
                }
            }
            if(idx == -1){break;}
            else{
                int data = list[idx]->val;
                ListNode* tmp = new ListNode(data);
                curr->next = tmp;
                curr = curr->next;
                list[idx] = list[idx]->next;
            }
        }
        return ans->next;
    }
};