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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* curr = head;
        while(curr->next != NULL){
            int a = curr->val;
            int b = curr->next->val;
            int gcdVal = __gcd(a, b);
            ListNode* newNode = new ListNode(gcdVal, curr->next);
            curr->next = newNode;
            curr = newNode->next; 
        }
        return head;
    }
};