/* Merge K sorted linked lists  */
#include <stdio.h>

struct Node{
    int data;
    Node *next;
};

void printList(Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* newNode(int val)
{
    struct Node* node = new Node;
    node->data = val;
    node->next = NULL;
    return node;
}

Node *mergeTwoSortedLists(Node *list1, Node* list2)
{
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    if(list1->data > list2->data)
    {
        list2->next = mergeTwoSortedLists(list1, list2->next);
        return list2;
    }
    else
    {
        list1->next = mergeTwoSortedLists(list1->next, list2);
        return list1;
    }

}

Node *mergeKLists(Node *arr[], int num)
{
    if(num == 0)
        return NULL;

    while(num > 1)
    {
        for(int i = 0; i < num / 2; i++)
        {
            arr[i] = mergeTwoSortedLists(arr[i], arr[num - 1 - i]);
        }
        num = (num + 1) /2;
    }

    return arr[0];
}

int main()
{
    printf("Merge K sorted linked lists\n");

    int k = 3;

    int n = 4;

    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(5);
    arr[0]->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(11);

    Node *head = mergeKLists(arr, k);

    printList(head);

    return 0;
}