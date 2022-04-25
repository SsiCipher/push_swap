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

if (stack_b->top->content == ref_array[max_index])
{
	p(stack_a, stack_b, TRUE, NULL);
	max_index -= 1;
	if (sort_2(stack_a, 1))
		max_index -= 1;
}
else if (stack_b->top->content == ref_array[max_index - 1])
	p(stack_a, stack_b, TRUE, NULL);
else
{
	if (down_c == 0 && stack_b->top->content < stack_tail(*stack_a))
	{
		p(stack_a, stack_b, TRUE, NULL);
		r(stack_a, TRUE, NULL);
		down_c += 1;
	}
	else
	{
		if (max_stack_index <= stack_b->size / 2)
			r(stack_b, TRUE, NULL);
		else
			rr(stack_b, TRUE, NULL);
	}
}

int	smart_rotate(t_stack *stack, int min, int max)
{
	int		start;
	int		end;
	t_node	*curr;

	start = 0;
	curr = stack->top;
	while (start < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->next;
		start++;
	}
	end = 0;
	curr = stack->top->prev;
	while (end < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->prev;
		end++;
	}
	return (start - end);
}

// void	push_to_a(t_stack *stacks[2], int *ref, int *max_index, int *down_c, char **ops)
// {
// 	int	max_stack_index;

// 	max_stack_index = get_index(*stacks[1], ref[*max_index]);
// 	if (max_stack_index == -1)
// 	{
// 		rr(stacks[0], FALSE, ops);
// 		*down_c -= 1;
// 		*max_index -= 1;
// 	}
// 	else if (!push_max(stacks, ref, max_index, ops))
// 	{
// 		if (*down_c == 0 && stacks[1]->top->content < stack_tail(*stacks[0]))
// 		{
// 			p(stacks[0], stacks[1], FALSE, ops);
// 			r(stacks[0], FALSE, ops);
// 			*down_c += 1;
// 		}
// 		else
// 		{
// 			if (max_stack_index <= stacks[1]->size / 2)
// 				r(stacks[1], FALSE, ops);
// 			else
// 				rr(stacks[1], FALSE, ops);
// 		}
// 	}
// }

```