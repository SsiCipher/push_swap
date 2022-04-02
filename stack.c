#include "push_swap.h"

void stack_push(t_stack stack, t_node *new_node)
{
    if (stack.stack_top == NULL)
        stack.stack_top = new_node;
    else
    {
        new_node->next = stack.stack_top;
        stack.stack_top = new_node;
    }
    
    stack.stack_size += 1;
}

int main() {
    t_stack a;

    t_node *curr = a.stack_top;
    while (curr)
        printf("Node content: %d", curr->content);

    return (0);
}