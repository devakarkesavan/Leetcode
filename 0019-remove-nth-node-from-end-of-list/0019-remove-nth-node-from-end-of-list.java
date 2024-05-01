/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getsize(ListNode head){
        ListNode temp = head;
        int cnt = 0;
        while(temp!=null){
            cnt++;
            temp = temp.next;
        }
        return cnt;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size = getsize(head);
        int s = size-n+1;
        int count = 0;
        if(s==1){
            head = head.next;
            return head;
        }
        ListNode temp=head,prev=null;
        while(temp!=null){
            count++;
            if(count==s){
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp=temp.next;
        }
        return head;
        
    }
}