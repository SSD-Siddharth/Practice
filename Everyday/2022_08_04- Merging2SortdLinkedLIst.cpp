/*
Merging two sorted lists(ll)
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/



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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)  //Checking if any 1 of the list is empty,then return the other list
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1 == NULL && list2 == NULL)
            return list2;  //or, return list1
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while((list1!=NULL) && (list2!=NULL)){
            //When element of list1 is greater
            if(list1->val > list2->val)
            {
                if(head == NULL){ 
                    head = list2;
                    tail = list2;
                    list2 = list2->next;  //going to next element of list2
                }
                else{
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }
            //When element of list2 is greater
            else
            {
                if(head == NULL){  
                    head = list1;
                    tail = list1;
                    list1 = list1->next;
                }
                else{
                    tail->next = list1;
                    tail = list1;
                    list1 = list1->next;
                }
            }
            
        }
        //Adding the remaining items
        while(list1 != NULL){
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }

        while(list2 != NULL){
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }

        return head;

    }
};