/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* result;
        int carryOver = 0;
        int sum = 0;
        
        while(temp1 != nullptr && temp2 != nullptr){
            sum = temp1->val + temp2->val + carryOver;
            if(sum > 9){
                sum = sum%10;
                carryOver = 1;
            }else{
                carryOver = 0;
            }
            ListNode* newNode = new ListNode(sum);
            if(tail == nullptr){
                result = newNode;
                tail = result;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(temp2 != nullptr){
            while(temp2 != nullptr){
                sum = temp2->val + carryOver;
                if(sum > 9){
                    sum = sum%10;
                    carryOver = 1;
                }else{
                    carryOver = 0;
                }
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = newNode;
                temp2 = temp2->next;
            }
        }   
        if(temp1 != nullptr){
            while(temp1 != nullptr){
                sum = temp1->val + carryOver;
                if(sum > 9){
                    sum = sum%10;
                    carryOver = 1;
                }else{
                    carryOver = 0;
                }
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = newNode;
                temp1 = temp1->next;
            }
        }
        if(temp1 == nullptr && temp2 == nullptr && carryOver == 1){
            ListNode* newNode = new ListNode(carryOver);
            tail->next = newNode;
            tail = newNode;
        }
        return result;
    }
private:
    ListNode *tail;
};