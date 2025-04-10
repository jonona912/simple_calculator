#include "../includes/simple_calculator.h"

void free_tokens_lst(t_token* token)
{
    while (token != NULL)
	{
        t_token* next = token->next;
        free(token);
        token = next;
    }
}

void append_token(t_token** head, t_token* new_token) {
	if (*head == NULL)
	{
		*head = new_token;
	} else
	{
		t_token* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_token;
	}
}

t_token* create_token(token_type type, int value) {
	t_token* new_token = (t_token*)malloc(sizeof(t_token));
	if (!new_token) {
		perror("Failed to allocate memory for token");
		return (NULL);
	}
	new_token->type = type;
	new_token->value = value;
	new_token->next = NULL;
	return new_token;
}

t_token* tokenize(const char* input)
{
	t_token* head = NULL;
	int pos = 0;

	if (!input)
		return NULL;

	while (input[pos] != '\0') {
		while (isspace(input[pos]))
			pos++;
		if (input[pos] == '\0')
			break;

		t_token* new_token = NULL;

		if (isdigit(input[pos]))
		{
			int value = 0;
			while (isdigit(input[pos]))
			{
				value = value * 10 + (input[pos] - '0');
				pos++;
			}
			new_token = create_token(TOKEN_NUMBER, value);
		} else if (input[pos] == '+')
		{
			new_token = create_token(TOKEN_PLUS, 0);
			pos++;
		}
		else if (input[pos] == '-')
		{
			new_token = create_token(TOKEN_MINUS, 0);
			pos++;
		}
		else if (input[pos] == '*')
		{
			new_token = create_token(TOKEN_TIMES, 0);
			pos++;
		}
		else if (input[pos] == '/')
		{
			new_token = create_token(TOKEN_DIVIDE, 0);
			pos++;
		}
		else if (input[pos] == '(')
		{
			new_token = create_token(TOKEN_LPAREN, 0);
			pos++;
		}
		else if (input[pos] == ')')
		{
			new_token = create_token(TOKEN_RPAREN, 0);
			pos++;
		}
		else if (input[pos] == '^')
		{
			new_token = create_token(TOKEN_POWER, 0);
			pos++;
		}  
		else
		{
			printf("Invalid character: %c\n", input[pos]);
			free_tokens_lst(head);
			exit(1);
		}
		if (!new_token)
		{
			free_tokens_lst(head);
			exit(1);
		}
		append_token(&head, new_token);
	}

	// Add EOF token
	t_token* eof = create_token(TOKEN_EOF, 0);
	if (!eof) {
		free_tokens_lst(head);
		exit(1);
	}
	append_token(&head, eof);

	return head;
}
