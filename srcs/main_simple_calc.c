#include "../includes/simple_calculator.h"

void print_ast(t_ast_node *node, int depth);
void print_tokens(t_token *token_lst);

int	return_result(char *input)
{
	t_token		*token_lst;
	t_ast_node	*ast;

	token_lst = tokenize(input);
	print_tokens(token_lst);
	parse_expression(token_lst, &ast);
	free_tokens_lst(token_lst);
	print_ast(ast, 0);

	int result = evaluate_ast(ast);
	printf("result: %d\n", result);
	free_ast(ast);
	return (result);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: simple math expression can include as second arg: digits + - * / ( )\n");
		return (1);
	}
	return_result(argv[1]);
	return (0);
}

void print_tokens(t_token *token_lst)
{
	t_token *current = token_lst;

	while (current)
	{
		switch (current->type)
		{
			case TOKEN_NUMBER:
				printf("NUMBER(%d)\n", current->value);
				break;
			case TOKEN_PLUS:
				printf("PLUS(+)\n");
				break;
			case TOKEN_MINUS:
				printf("MINUS(-)\n");
				break;
			case TOKEN_TIMES:
				printf("TIMES(*)\n");
				break;
			case TOKEN_DIVIDE:
				printf("DIVIDE(/)\n");
				break;
			case TOKEN_LPAREN:
				printf("LPAREN(()\n");
				break;
			case TOKEN_RPAREN:
				printf("RPAREN())\n");
				break;
			case TOKEN_EOF:
				printf("EOF\n");
				break;
			case TOKEN_POWER:
				printf("POWER(^)\n");
				break;
			default:
				printf("UNKNOWN\n");
				break;
		}
		current = current->next;
	}
}

void print_ast(t_ast_node *node, int depth)
{
	if (!node)
		return;

	for (int i = 0; i < depth; i++)
		printf("  "); // Indentation for better visualization

	if (node->type == NODE_OPERATOR)
	{
		switch (node->data.binary_op.operation)
		{
			case TOKEN_PLUS:
				printf("PLUS(+)\n");
				break;
			case TOKEN_MINUS:
				printf("MINUS(-)\n");
				break;
			case TOKEN_TIMES:
				printf("TIMES(*)\n");
				break;
			case TOKEN_DIVIDE:
				printf("DIVIDE(/)\n");
				break;
			case TOKEN_POWER:
				printf("POWER(^)\n");
				break;
			default:
				printf("UNKNOWN\n");
				break;
		}
		print_ast(node->data.binary_op.left, depth + 1);
		print_ast(node->data.binary_op.right, depth + 1);
	}
	else if (node->type == NODE_NUMBER)
	{
		printf("Number: %d\n", node->data.value);
	}
}