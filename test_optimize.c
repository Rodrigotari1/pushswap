#include "../inc/push_swap.h"
#include <stdio.h>

// Helper function to print stack contents
static void print_stacks(t_stacks *data, char *msg)
{
    printf("\n%s\n", msg);
    printf("Stack A: ");
    for (int i = 0; i < data->a_size; i++)
        printf("%d ", data->a[i]);
    printf("\nStack B: ");
    for (int i = 0; i < data->b_size; i++)
        printf("%d ", data->b[i]);
    printf("\n");
}

// Test function
static void test_optimize_and_push(void)
{
    t_stacks *data = malloc(sizeof(t_stacks));
    
    // Test case 1: Element in first half
    int test1[] = {5, 2, 8, 1, 9, 3};
    data->a = malloc(sizeof(int) * 6);
    data->b = malloc(sizeof(int) * 6);
    data->a_size = 6;
    data->b_size = 0;
    memcpy(data->a, test1, sizeof(test1));
    
    print_stacks(data, "Before pushing element at position 2:");
    optimize_and_push_to_b(data, 2);
    print_stacks(data, "After pushing element at position 2:");

    // Test case 2: Element in second half
    int test2[] = {5, 2, 8, 1, 9, 3};
    data->a_size = 6;
    data->b_size = 0;
    memcpy(data->a, test2, sizeof(test2));
    
    print_stacks(data, "\nBefore pushing element at position 4:");
    optimize_and_push_to_b(data, 4);
    print_stacks(data, "After pushing element at position 4:");

    free(data->a);
    free(data->b);
    free(data);
}

int main(void)
{
    printf("Testing optimize_and_push_to_b function:\n");
    test_optimize_and_push();
    return 0;
} 