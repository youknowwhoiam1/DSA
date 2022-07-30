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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* root = nullptr;
        int carry = 0;
        while(temp1 and temp2){
            if(temp1 == nullptr or temp2 == nullptr){
                break;
            }
            if(root == nullptr){
                ListNode* temp = new ListNode;
                int data = temp1->val+temp2->val+carry;
                temp->val = data%10;
                data/=10;
                carry = data%10;
                temp->next = nullptr;
                root = temp;
            }else{
                ListNode* temp = new ListNode;
                int data = temp1->val+temp2->val+carry;
                temp->val = data%10;
                data/=10;
                carry = data%10;
                temp->next = nullptr;
                ListNode* ptr = root;
                while (ptr->next != nullptr)
                    ptr = ptr->next;
                ptr->next = temp;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1 != nullptr){
            while(temp1){
                if(root == nullptr){
                    ListNode* temp = new ListNode;
                    int data = temp1->val+carry;
                    temp->val = data%10;
                    data/=10;
                    carry = data%10;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp1->val+carry;
                    temp->val = data%10;
                    data/=10;
                    carry = data%10;
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
                    int data = temp2->val+carry;
                    temp->val = data%10;
                    data/=10;
                    carry = data%10;
                    temp->next = nullptr;
                    root = temp;
                }else{
                    ListNode* temp = new ListNode;
                    int data = temp2->val+carry;
                    temp->val = data%10;
                    data/=10;
                    carry = data%10;
                    temp->next = nullptr;
                    ListNode* ptr = root;
                    while (ptr->next != nullptr)
                        ptr = ptr->next;
                    ptr->next = temp;
                }
                temp2=temp2->next;
            }
        }
        if(carry > 0){
            if(root == nullptr){
                ListNode* temp = new ListNode;
                int data = carry;
                temp->val = data%10;
                data/=10;
                carry = data%10;
                temp->next = nullptr;
                root = temp;
            }else{
                ListNode* temp = new ListNode;
                int data = carry;
                temp->val = data%10;
                data/=10;
                carry = data%10;
                temp->next = nullptr;
                ListNode* ptr = root;
                while (ptr->next != nullptr)
                    ptr = ptr->next;
                ptr->next = temp;
            }
        }
        return root;
    }
};