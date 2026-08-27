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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;

        while(second != NULL){
            ListNode* next = second->next;
            second->next = prev;

            prev = second;
            second = next;
        }

        ListNode* first = head;
        ListNode* sec = prev;
        while(sec != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;
            first->next = sec;
            sec->next = temp1;
            first = temp1;
            sec = temp2;
        }
    }
};
