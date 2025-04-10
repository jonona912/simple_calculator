#ifndef SIMPLE_CALCULATOR_H
#define SIMPLE_CALCULATOR_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// t_token types
typedef enum {
    TOKEN_NUMBER,   // e.g., 2, 3, 4
    TOKEN_PLUS,     // +
    TOKEN_MINUS,    // -
    TOKEN_TIMES,    // *
    TOKEN_DIVIDE,   // /
    TOKEN_LPAREN,   // (
    TOKEN_RPAREN,   // )
	TOKEN_POWER,    // ^
    TOKEN_EOF       // End of input
} token_type;

// t_token structure (linked list)
typedef struct t_token {
	token_type		type;
	int				value;          // For TOKEN_NUMBER
	struct t_token*	next;
}	t_token;

typedef enum node_type
{
	NODE_NUMBER,
	NODE_OPERATOR,
} node_type;

typedef struct s_ast_node
{
	node_type type;
	union
	{
		int	value;
		struct {
			token_type			operation;
			struct s_ast_node	*left;
			struct s_ast_node	*right;
		} binary_op;
	} data;
} t_ast_node;

// evaluate.c
int	evaluate_ast(t_ast_node *node);

t_token* tokenize(const char* input);
void free_tokens_lst(t_token* token);

// parser_functions.c
void free_ast(t_ast_node *node);
t_ast_node *create_ast_number_node(int value);
t_ast_node *create_ast_operator_node(token_type operation, t_ast_node *left, t_ast_node *right);

// parser.c
t_token	*parse_expression(t_token *token_lst, t_ast_node **head);

#endif
