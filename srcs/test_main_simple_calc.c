#include "../includes/simple_calculator.h"
#include <assert.h>
#include <stdio.h>

int return_result(char *input)
{
	t_token		*token_lst;
	t_ast_node	*ast;

	token_lst = tokenize(input);
	parse_expression(token_lst, &ast);
	free_tokens_lst(token_lst);
	int result = evaluate_ast(ast);
	// printf("returned: %d\n", result);
	free_ast(ast);
	return (result);
}

void test_simple_calculator()
{
	// Test 1: Simple addition
	char *input1 = "3 + 4";
	int expected1 = 7;
	int result1 = return_result(input1);
	assert(result1 == expected1);
	printf("Test 1 passed: %s = %d\n", input1, result1);

	// Test 2: Subtraction and multiplication
	char *input2 = "10 - 2 * 5";
	int expected2 = 0;
	int result2 = return_result(input2);
	assert(result2 == expected2);
	printf("Test 2 passed: %s = %d\n", input2, result2);

	// Test 3: Parentheses with addition and subtraction
	char *input3 = "(1 + 2) * (3 - 4)";
	int expected3 = -3;
	int result3 = return_result(input3);
	assert(result3 == expected3);
	printf("Test 3 passed: %s = %d\n", input3, result3);

	// Test 4: Division with parentheses
	char *input4 = "5 / (2 + 3)";
	int expected4 = 1;
	int result4 = return_result(input4);
	assert(result4 == expected4);
	printf("Test 4 passed: %s = %d\n", input4, result4);

	// Test 5: Complex expression
	char *input5 = "8 * (2 + 3) - 4 / 2";
	int expected5 = 38;
	int result5 = return_result(input5);
	assert(result5 == expected5);
	printf("Test 5 passed: %s = %d\n", input5, result5);

	// Test 6: Longer expression
	char *input6 = "10 + 2 * (3 + 4) - 4 / (1 + 1)";
	int expected6 = 22;
	int result6 = return_result(input6);
	assert(result6 == expected6);
	printf("Test 6 passed: %s = %d\n", input6, result6);

	// Test 7: Nested parentheses
	char *input7 = "((2 + 3) * (4 - 1)) / (1 + 1)";
	int expected7 = 7;
	int result7 = return_result(input7);
	assert(result7 == expected7);
	printf("Test 7 passed: %s = %d\n", input7, result7);

	// Test 8: Complex nested expression
	char *input8 = "((10 - 2) * (3 + 5)) / (2 + (1 * 2))";
	int expected8 = 16;
	int result8 = return_result(input8);
	assert(result8 == expected8);
	printf("Test 8 passed: %s = %d\n", input8, result8);

	// Test 9: Single number
	char *input9 = "42";
	int expected9 = 42;
	int result9 = return_result(input9);
	assert(result9 == expected9);
	printf("Test 9 passed: %s = %d\n", input9, result9);

	// Test 10: Expression with all operators
	char *input10 = "1 + 2 * 3 - 4 / 2";
	int expected10 = 5;
	int result10 = return_result(input10);
	assert(result10 == expected10);
	printf("Test 10 passed: %s = %d\n", input10, result10);
}

int main(void)
{
	test_simple_calculator();
	printf("All tests passed successfully.\n");
	return 0;
}