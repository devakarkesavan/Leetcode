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
    ListNode* reverse(ListNode* temp){
        if(temp==NULL || temp->next==NULL){
            return temp;
        }
        ListNode* newNode = reverse(temp->next);
        ListNode* front  = temp->next;
        front->next = temp;
        temp->next = NULL;
        return newNode;
    }
    ListNode* findkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* kthNode = findkthnode(temp,k);
            if(kthNode==NULL){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};