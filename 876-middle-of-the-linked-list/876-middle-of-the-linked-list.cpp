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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            ++cnt;
            if(temp->next == nullptr){break;}
            temp=temp->next;
        }
        temp = head;
        int k = cnt/2 +1;
        cnt = 0;
        while(temp){
            ++cnt;
            if(cnt == k){
                break;
            }
            temp=temp->next;
        }
        return temp;
    }
};