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
    ListNode* removeElements(ListNode* head, int val) {
        // set a dummy node
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        // remove the target element
        while(cur->next != NULL){
            if(cur->next->val != val){
                cur = cur->next;
            }else{
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
        
    }
};