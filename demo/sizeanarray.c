#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Memory for numbers
    int *numbers = NULL;
    int capacity = 0;

    // Prompt for numbers (until EOF)
    int size = 0;
    while (true)
    {
        // Prompt for number
        int number = get_int("Number: ");

        // Check for EOF
        if (number == INT_MAX)
        {
            break;
        }

        // Check whether enough space for number
        if (size == capacity)
        {
            // Allocate space for number
            int *tmp = realloc(numbers, sizeof(int) * (size + 1));
            if (!tmp)
            {
                if (numbers)
                {
                    free(numbers);
                }
                return 1;
            }
            numbers = tmp;
            capacity++;
        }

        // Add number to list
        numbers[size] = number;
        size++;
    }

    // Print numbers
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }

    // Free memory
    if (numbers)
    {
        free(numbers);
    }
}