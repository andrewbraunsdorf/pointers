#include <cs50.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // Memory for numbers
    node *numbers = NULL;

    // Prompt for numbers (until EOF)
    while (true)
    {
        // Prompt for number
        int number = get_int("number: ");

        // Check for EOF
        if (number == INT_MAX)
        {
            break;
        }
    }
     // Allocate space for number
     node *n = malloc(sizeof(node));
     if (!n)
     {
         return 1;
     }

     // Add number to list
     n->number = number;
     n->next = NULL;
     if (numbers)
     {
         for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
         {
             if (!ptr->next)
             {
                 ptr->next = n;
                 break;
             }
         }
     }
     else
     {
         numbers = n;
     }
}