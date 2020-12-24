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
    ListNode* removeZeroSumSublists(ListNode* head) {
     
        ListNode *temp,*cur;
        cur=head;
        int sum=0;
        while(cur!=NULL)
        {
            sum+=cur->val;
            if(sum==0)
            {
                head=cur->next;
                cur=cur->next;
                continue;
            }
            temp=head;
            int cnt=0;
            while(temp and temp!=cur)
            {
                cnt+=(temp->val);
                if(cnt==sum)
                {
                    temp->next=cur->next;
                    break;
                }
                temp=temp->next;
            }
            cur=cur->next;
        }
        return head;
        
    }
};
