//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        vector<int> v;
        Node *temp = head;
        while(temp != NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        
        reverse(v.begin(), v.end());
        
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->data = v[i]; i++;
            temp = temp->next;
        }
        
        // temp = head;
        // while(temp != NULL){
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
        
        int carry = 1;
        temp = head;
        while(temp != NULL){
            int val = temp->data + carry;
            if(val > 9){carry = 1;}
            else{carry = 0;}
            temp->data = (val)%10;
            temp = temp->next;
        }
        
        // temp = head;
        // while(temp != NULL){
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
        
        // cout << carry << endl;
        
        if(carry == 1){
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new Node(1);
        }
        
        // temp = head;
        // while(temp != NULL){
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
        
        v.clear();
        temp = head;
        while(temp != NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        reverse(v.begin(), v.end());
        temp = head;
        i = 0;
        while(temp != NULL){
            temp->data = v[i++];
            temp = temp->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends