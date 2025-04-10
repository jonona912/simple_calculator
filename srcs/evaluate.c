#include "../includes/simple_calculator.h"

int	evaluate_ast(t_ast_node *node)
{
	int right;
	int left;

	if (node->type == NODE_NUMBER)
		return (node->data.value);
	left = evaluate_ast(node->data.binary_op.left);
	right = evaluate_ast(node->data.binary_op.right);
	if (node->data.binary_op.operation == TOKEN_PLUS)
		return (left + right);
	else if (node->data.binary_op.operation == TOKEN_MINUS)
		return (left - right);
	else if (node->data.binary_op.operation == TOKEN_TIMES)
		return (left * right);
	else if (node->data.binary_op.operation == TOKEN_POWER)
	{
		int i = 1;
		int accum = left;
		while (i < right)
		{
			accum *= left;
			i++;
		}
		return (accum);
	}
	else if (node->data.binary_op.operation == TOKEN_DIVIDE)
	{
		if (right == 0)
		{
			printf("Error: Division by zero\n");
			exit(1);
		}
		return (left / right);
	}
	return (0);
}
