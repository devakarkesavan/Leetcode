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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        small->next = NULL;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        large->next = NULL;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                small->next = temp;
                small = small->next;
            }
            else{
                large->next = temp;
                large = large->next;
            }
            temp = temp->next;
        }
        small->next = largeHead->next;
        large->next = NULL;
        return smallHead->next;
        
    }
};