    #include <bits/stdc++.h>

    struct node
    {
        int val;
        struct node *next;

    };

    int main (void)
    {
        node HEAD;
        node *CURRENT;
        node first;
        node second;
        node third;
        node fourth;
        node fifth;

        HEAD.next     = &first;
        CURRENT       = &HEAD;

        first.next  = &second;
        second.next = &third;
        third.next  = &fourth;
        fourth.next = &fifth;
        fifth.next  = nullptr;

        first.val  = 5;
        second.val = 10;
        third.val  = 15;
        fourth.val = 20;
        fifth.val  = 25;

        while(CURRENT->next != nullptr)
        {
            CURRENT = CURRENT->next;
            printf("%i\n", CURRENT->val);
        }
    }