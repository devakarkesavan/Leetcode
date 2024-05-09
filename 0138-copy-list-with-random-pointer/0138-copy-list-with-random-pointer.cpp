/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        // cloning the linked list
        while(temp!=NULL){
		Node* copyNode = new Node(temp->val);
		copyNode->next = temp->next;
		temp->next = copyNode;
		temp = temp->next->next;
	}
        // mark the random pointers
        temp = head;
        while(temp!=NULL){
            Node* cloneNode = temp->next;
            if(temp->random){
            cloneNode->random = temp->random->next;
            }
            else{
                cloneNode->random = NULL;
            }
            temp = temp->next->next;
        }
        // mark the next pointers and creating the copy
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};