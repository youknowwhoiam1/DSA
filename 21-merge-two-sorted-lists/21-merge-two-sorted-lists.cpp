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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* root = nullptr;
        while(temp1 and temp2){
            if(temp1 == nullptr or temp2 == nullptr){
                break;
            }
            if(temp1->val <= temp2->val){
                if(root == nullptr){
                    ListNode* temp = new ListNode;
                    int data = temp1->val;
                    temp->val = data;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp1->val;
                    temp->val = data;
                    temp->next = nullptr;
                    ListNode* ptr = root;
                    while (ptr->next != nullptr)
                        ptr = ptr->next;
                    ptr->next = temp;
                }
                temp1=temp1->next;
            }else{
                if(root == nullptr){
                    ListNode* temp = new ListNode;
                    int data = temp2->val;
                    temp->val = data;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp2->val;
                    temp->val = data;
                    temp->next = nullptr;
                    ListNode* ptr = root;
                    while (ptr->next != nullptr)
                        ptr = ptr->next;
                    ptr->next = temp;
                }
                temp2=temp2->next;
            }
        }
        // return root;
        if(temp1 != nullptr){
            while(temp1){
                if(root == nullptr){
                    ListNode* temp = new ListNode;
                    int data = temp1->val;
                    temp->val = data;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp1->val;
                    temp->val = data;
                    temp->next = nullptr;
                    ListNode* ptr = root;
                    while (ptr->next != nullptr)
                        ptr = ptr->next;
                    ptr->next = temp;
                }
                temp1=temp1->next;
            }
        }
        if(temp2 != nullptr){
            while(temp2){
                if(root == nullptr){
                    ListNode* temp = new ListNode;
                    int data = temp2->val;
                    temp->val = data;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp2->val;
                    temp->val = data;
                    temp->next = nullptr;
                    ListNode* ptr = root;
                    while (ptr->next != nullptr)
                        ptr = ptr->next;
                    ptr->next = temp;
                }
                temp2=temp2->next;
            }
        }
        return root;
    }
};