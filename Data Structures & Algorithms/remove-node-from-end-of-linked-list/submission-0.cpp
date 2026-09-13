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
    int lengthOfLL(ListNode* head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = lengthOfLL(head);

        
        if(l == n){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        int TravelFromFront = l-n;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(TravelFromFront--){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete(temp);

        return head;
    }
};
