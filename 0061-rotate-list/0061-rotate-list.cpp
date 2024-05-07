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
    ListNode* findkthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* tail = head;
        int len = 1;
        while(tail->next!=NULL){
            tail = tail->next;
            len++;
        }
        if(k%len==0){
            return head;
        }
        k = k%len;
        ListNode* kthNode = findkthNode(head,len-k);
        tail->next= head;
        head = kthNode->next;
        kthNode->next= NULL;
        return head;
        
    }
};