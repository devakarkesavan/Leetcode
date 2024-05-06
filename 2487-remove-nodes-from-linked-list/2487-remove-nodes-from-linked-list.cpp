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
    ListNode* removeNodes(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* ptr = head;
        deque<ListNode*> s;
        while(ptr != NULL){
            if(!s.empty()) {
                while(!s.empty() && s.back()->val < ptr->val) s.pop_back(); 
            }
            s.push_back(ptr);
            ptr = ptr->next;
        }
        if(s.empty() ) return NULL;
        head = s.front(); ptr = s.front(); s.pop_front();
        while(!s.empty()){
            ptr->next = s.front();
            ptr = ptr->next;
            s.pop_front();
        }
        ptr->next = NULL;
        return head;
    }
};