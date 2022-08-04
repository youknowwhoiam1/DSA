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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr or head->next == nullptr){
            return head;
        }
        ListNode* tmp = head;
        ListNode* curr = head;
        while(tmp->next){
            if(tmp->next->val == curr->val){
                tmp = tmp->next;
            }else{
                tmp = tmp->next;
                curr->next = tmp;
                curr=curr->next;
            }
        }
        curr->next = nullptr;
        return head;
    }
};