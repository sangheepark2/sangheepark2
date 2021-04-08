/* Add Two Numbers: https://leetcode.com/problems/add-two-numbers-ii/ */
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

#if 1
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    vector<int> n1;
    vector<int> n2;

    while(l1)
    {
        n1.push_back(l1->val);
        l1 = l1->next;
    }

    while(l2)
    {
        n2.push_back(l2->val);
        l2 = l2->next;
    }

    int sum = 0, carry = 0;
    ListNode *head = NULL, *tmp = NULL;

    int m = n1.size();
    int n = n2.size();

    for(int i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
    {
        sum = carry;
        if(i >= 0)
            sum += n1[i];

        if(j >= 0)
            sum += n2[j];

        carry = sum / 10;
        tmp = new ListNode(sum % 10);
        tmp->next = head;
        head = tmp;
    }

    if(carry != 0)
    {
        tmp = new ListNode(carry);
        tmp->next = head;
        head = tmp;
    }

    return head;
}
#else
// with stack
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> n1;
    stack<int> n2;;

    while(l1)
    {
        n1.push(l1->val);
        l1 = l1->next;
    }

    while(l2)
    {
        n2.push(l2->val);
        l2 = l2->next;
    }

    int sum = 0, carry = 0;
    ListNode *head = NULL, *tmp;

    while(!n1.empty() || !n2.empty())
    {
        sum = carry;
        
        if(!n1.empty())
        {
            sum += n1.top();
            n1.pop();
        }

        if(!n2.empty())
        {
            sum += n2.top();
            n2.pop();
        }

        carry = sum / 10;
        tmp = new ListNode(sum % 10);
        tmp->next = head;
        head = tmp;
    }

    if(carry != 0)
    {
        printf("carry: %d\n", carry);
        tmp = new ListNode(carry);
        tmp->next = head;
        head = tmp;
    }

    return head;
}
#endif

int main()
{
    printf("Add Two Numbers II\n");

    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode (4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *node = addTwoNumbers(l1, l2);

    while(node)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    
    return 0;
}