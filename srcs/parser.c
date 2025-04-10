#include "../includes/simple_calculator.h"

t_token	*parse_factor(t_token *token_lst, t_ast_node **num_node)
{

	if (!token_lst)
		return (printf("Null token\n"), NULL);
	if (token_lst->type == TOKEN_NUMBER)
	{
		*num_node = create_ast_number_node(token_lst->value);
		return (token_lst->next);
	}
	else if (token_lst->type == TOKEN_LPAREN)
	{
		token_lst = token_lst->next;
		token_lst = parse_expression(token_lst, num_node);
		if (token_lst->type != TOKEN_RPAREN)
		{
			printf("Error: Missing closing parenthesis\n");
			exit(1);
		}
		return (token_lst->next);
	}
	else
	{
		printf("Error: Unexpected token\n");
		exit(1);
	}
}

t_token	*parse_exponent(t_token *token_lst, t_ast_node **node)
{
	t_ast_node	*left;
	t_ast_node	*right;
	token_type	t_op;

	if (!token_lst)
		return (NULL);
	right = NULL;
	token_lst = parse_factor(token_lst, node);
	while (token_lst->type == TOKEN_POWER)
	{
		t_op = token_lst->type;
		token_lst = parse_factor(token_lst->next, &right);
		left = *node;
		*node = create_ast_operator_node(t_op, left, right);
	}
	return (token_lst);
}

t_token	*parse_term(t_token *token_lst, t_ast_node **node)
{
	t_ast_node	*left;
	t_ast_node	*right;
	token_type	t_op;

	if (!token_lst)
		return (NULL);
	right = NULL;
	token_lst = parse_exponent(token_lst, node);
	while (token_lst->type == TOKEN_TIMES || token_lst->type == TOKEN_DIVIDE)
	{
		t_op = token_lst->type;
		token_lst = parse_exponent(token_lst->next, &right);
		left = *node;
		*node = create_ast_operator_node(t_op, left, right);
	}
	return (token_lst);
}

t_token	*parse_expression(t_token *token_lst, t_ast_node **head)
{
	t_ast_node	*left;
	t_ast_node	*right;
	token_type	t_op;

	if (!token_lst)
		return (NULL);
	right = NULL;
	token_lst = parse_term(token_lst, head);
	while (token_lst->type == TOKEN_PLUS || token_lst->type == TOKEN_MINUS)
	{
		t_op = token_lst->type;
		token_lst = parse_term(token_lst->next, &right);
		left = *head;
		*head = create_ast_operator_node(t_op, left, right);
	}
	return (token_lst);
}
