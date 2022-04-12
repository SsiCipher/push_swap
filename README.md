# push_swap

A Project to Discover the World of Algorithms and Complexity

## To test add

```c

// ----- TESTING ONLY
printf("---------------- PushSwap ----------------\n");
print_ops_count();
print_stacks(stack_a, stack_b);
interactive_tester(&stack_a, &stack_b);
// ----- TESTING ONLY

```

```c

int	min_index;
int	min_value;
int	next_min_value;
min_index = stack_min(stack_a, &min_value, &next_min_value);
printf("Min: [%d], Index: [%d], Next Min: [%d]\n", min_value, min_index, next_min_value);

```

```c

int		i = 0;
t_node	*curr = stack_a.stack_top;
while (i < stack_a.stack_size)
{
	printf("Item %d: %d => %d\n", i, curr->content, curr->index);
	curr = curr->next;
	i++;
}

```
