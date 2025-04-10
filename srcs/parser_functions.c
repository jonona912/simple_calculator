#include "../includes/simple_calculator.h"

t_ast_node *create_new_ast_node(node_type type, int value, token_type operation, t_ast_node *left, t_ast_node *right)
{
	t_ast_node *new_node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	if (type == NODE_NUMBER)
	{
		new_node->data.value = value;
	}
	else if (type == NODE_OPERATOR)
	{
		new_node->data.binary_op.operation = operation;
		new_node->data.binary_op.left = left;
		new_node->data.binary_op.right = right;
	}
	return (new_node);
}

void free_ast(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == NODE_OPERATOR)
	{
		free_ast(node->data.binary_op.left);
		free_ast(node->data.binary_op.right);
	}
	free(node);
}

t_ast_node *create_ast_number_node(int value)
{
	t_ast_node *new_node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!new_node)
		return (NULL);
	new_node->type = NODE_NUMBER;
	new_node->data.value = value;
	return (new_node);
}

t_ast_node *create_ast_operator_node(token_type operation, t_ast_node *left, t_ast_node *right)
{
	t_ast_node *new_node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!new_node)
		return (NULL);
	new_node->type = NODE_OPERATOR;
	new_node->data.binary_op.operation = operation;
	new_node->data.binary_op.left = left;
	new_node->data.binary_op.right = right;
	return (new_node);
}



// 3 =>     path::> pe, pt, pf (NM 3)
// 3 + 4 => path::> pe1, [[pt1, [pf1 (NM 3)] ] pt, pf (NM 4), (NBO) (/3  +  4\)]

// 3 + 4 * 5 