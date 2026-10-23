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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        auto cmp = [](ListNode* a, ListNode* b) {return a -> val > b -> val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(auto list : lists){
            if(list != NULL) minHeap.push(list);
        }
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        while(!minHeap.empty()){
            auto node = minHeap.top();
            minHeap.pop();
            curr -> next = node;
            curr = node;
            if(node -> next != NULL) minHeap.push(node -> next);
        }
        return ans -> next;
    }
};
