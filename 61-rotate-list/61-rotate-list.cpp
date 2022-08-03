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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr){return head;}
        int no_of_nodes = 0;
        ListNode* temp = head;
        while(temp){
            no_of_nodes++;
            temp = temp->next;
        }
        k = k % no_of_nodes;
        ListNode* newhead;
        int t = no_of_nodes-k;
        if(t == 0){return head;}
        else{
            temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = head;
            temp = head;
            int cnt = 1;
            while(temp){
                if(cnt == t){break;}
                cnt++;
                temp = temp->next;
            }
            newhead = temp->next;
            temp->next = nullptr;
        }
        return newhead;
    }
};