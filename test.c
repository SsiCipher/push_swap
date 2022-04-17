#include "push_swap.h"

void	concat_op(char **ops_str, char *new_op)
{
	char	*tmp;

	tmp = *ops_str;
	*ops_str = ft_strjoin(*ops_str, new_op);
	free(tmp);
}

void	print_merged_ops(char *ops_str)
{
	int		i;
	char	**ops;

	i = 0;
	ops = ft_split(ops_str, '\n');
	while (ops[i])
	{
		if (
			(!ft_strcmp(ops[i], "rb") && !ft_strcmp(ops[i + 1], "ra"))
			|| (!ft_strcmp(ops[i], "ra") && !ft_strcmp(ops[i + 1], "rb"))
		)
		{
			write(1, "rr\n", 3);
			i += 2;
		}
		else
		{
			write(1, ops[i], ft_strlen(ops[i]));
			write(1, "\n", 1);
			i++;
		}
	}
}

int main()
{
	char *ops_str = NULL;

	concat_op(&ops_str, "ra\n");
	concat_op(&ops_str, "rb\n");
	concat_op(&ops_str, "pa\n");
	concat_op(&ops_str, "rb\n");
	concat_op(&ops_str, "rb\n");
	concat_op(&ops_str, "ra\n");
	concat_op(&ops_str, "ra\n");
	concat_op(&ops_str, "ra\n");
	concat_op(&ops_str, "ra\n");

	print_merged_ops(ops_str);

	return (0);
}
	