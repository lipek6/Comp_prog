#include <bits/stdc++.h>

struct node
{
    int val;
    struct node *next;

};

int listSize (node *head)
{
    node *cur = head;
    size_t i = 0;
    while(cur->next != nullptr)
    {
        i++;
        cur = cur->next;
    }
    return i;
}

int listAt(node *head, size_t pos)
{
    if (pos >= listSize(head))
    {
        printf("ERROR, OUT OF RANGE\n");
        return -1;
    }
    node *cur = head;
    size_t i = 0;
    while(i < pos && cur->next != nullptr)
    {
        cur = cur->next;
        i++;
    }
    return cur->next->val;
}

int listFind(node *head, int value)
{
    node *cur = head;
    size_t i = 0;
    
    while(cur->next != nullptr)
    {
        if (cur->next->val == value)
        {
            return i;
        }
        cur = cur->next;
        i++;
    }

    return -1;
}


void listInsert(node *head, size_t pos, int value)
{
    node *cur = head;
    size_t i = 0;
    while(i < pos && cur->next != nullptr)
    {
        cur = cur->next;
        i++;
    }
    node *new_node = new node;
    new_node->val  = value;
    new_node->next = cur->next;
    cur->next = new_node; 
}

node *listNew()
{
    node *head = new node;
    head->next = nullptr;
    return head;
}
int main (void)
{
    
    node *HEAD = listNew();
    for (int v = 0; v < 100; v+= 10)
    {
        listInsert(HEAD, v/10, v);
    }
    
    node *CURRENT = HEAD;
    
    while(CURRENT->next != nullptr)
    {
        printf("%i\n", CURRENT->next->val);
        CURRENT = CURRENT->next;
    }
}