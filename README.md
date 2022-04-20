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

```c

void	sort_push_b(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	max_value;
	int	max_value_index;
	int	next_max_value;

	while (stack_b->size > 0)
	{
		max_value = ref_array[stack_b->size - 1];
		max_value_index = get_index(*stack_b, max_value);
		next_max_value = ref_array[stack_b->size - 2];
		while (stack_b->top->content != max_value)
		{
			if (stack_b->top->content == next_max_value)
				p(stack_a, stack_b, TRUE, 'a');
			else
			{
				if (max_value_index <= stack_b->size / 2)
					r(stack_b, TRUE, 'b');
				else
					rr(stack_b, TRUE, 'b');
			}
		}
		p(stack_a, stack_b, TRUE, 'a');
		if (stack_a->size >= 2)
		{
			if (stack_a->top->content > stack_a->top->next->content)
				s(stack_a, TRUE, 'a');
		}
	}
}

```