//1

/**
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

void push(int data) {
    if (is_full()) {
        printf("Stack overflow!\n");
        return;
    }

    top++;
    stack[top] = data;
}

void pop() {
    if (is_empty()) {
        printf("Stack underflow!\n");
        return;
    }

    int data = stack[top];
    top--;
    printf("%d is deleted from the stack.\n", data);
}

void display() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int option;

    do {
        printf("Enter your option:\n");
        printf("1. Push/insert data\n");
        printf("2. Print stack\n");
        printf("3. Pop\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1: {
                int data;
                printf("Enter the element to insert:\n");
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    } while(option != 4);

    return 0;
}

**/

/**
#include<stdio.h>
#include<stdlib.h>


#define Size 10

int Top=-1, arr[Size];
void Push();
void Pop();
void show();

int main()
{
	int choice;

	while(1)
	{

		printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			    Push();
                break;
			case 2:
			    Pop();
                break;
			case 3:
			    show();
                break;
			case 4:
			    exit(0);

			default: printf("\nWrong Input");
		}
	}
}

void Push()
{
	int x;

	if(Top==Size-1)
	{
		printf("\n Warning Overflow!!");
	}
	else
	{
		printf("\nPush Item:");
		scanf("%d",&x);
		Top=Top+1;
		arr[Top]=x;
		printf("Item Push Successfull\n");
	}
}

void Pop()
{
	if(Top==-1)
	{
		printf("\n Warning Underflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",arr[Top]);
		Top=Top-1;
		printf("Item Poped Successfull\n");
	}
}

void show()
{
    if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
	    int i = Top;
		printf("\n Elemenmts Are : \n");
		for(i;i>=0;--i)
			printf("%d\n",arr[i]);
	}
}
**/



/**
//2
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char a1) {
    if (top == MAX_SIZE-1) {
        return;
    }
    top++;
    stack[top] = a1;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    char a1 = stack[top];
    top--;
    return a1;
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') {
        return true;
    }
    return false;
}

void checkParentheses(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push('(');
        }
        else if (expression[i] == ')') {
            char a1 = pop();
            if (!isMatchingPair(a1, ')')) {
                printf("Closing parentheses not matched\n");
                return;
            }
        }
    }
    if (top != -1) {
        printf("Opening parentheses not closed\n");
        return;
    }
    printf("All parentheses are closed.\n");
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);
    checkParentheses(expression);
    return 0;
}
**/





#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return 1;
    return 0;
}

int check(char expr[]) {
    int len = strlen(expr), i;
    char temp;
    for (i = 0; i < len; i++) {
        switch (expr[i]) {
            case '(':
            case '[':
            case '{':
                push(expr[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (top == -1 || !match(pop(), expr[i]))
                    return 0;
                break;
            default:
                break;
        }
    }
    return (top == -1);
}

int main() {
    char expr[MAX_SIZE];
    int valid;

    printf("Enter parentheses : ");
    fgets(expr, MAX_SIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    valid = check(expr);
    if (valid)
        printf("The parentheses are valid\n");
    else
        printf("The parentheses are invalid\n");

    return 0;
}


/**

#include <stdio.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    int value = stack[top];
    top--;
    return value;
}

int is_empty() {
    return top == -1;
}

int decimal_to_binary(int decimal) {
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(remainder);
        decimal /= 2;
    }

    int binary = 0;
    while (!is_empty()) {
        int bit = pop();
        binary = binary * 10 + bit;
    }

    return binary;
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    int binary = decimal_to_binary(decimal);
    printf("Binary number: %d\n", binary);

    return 0;
}
**/

//5
/**
#include <stdio.h>

#define MAX_EXPRESSION_SIZE 100
#define MAX_RESULT_SIZE 100

char stack[MAX_EXPRESSION_SIZE];
int top = -1;

void push(char value) {
    stack[++top] = value;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

void infix_to_postfix(char* expression, char* result) {
    int i, j = 0;
    char c;
    for (i = 0; expression[i] != '\0'; i++) {
        c = expression[i];
        if (isdigit(c)) {
            result[j++] = c;
        } else if (is_operator(c)) {
            while (top != -1 && is_operator(peek()) && precedence(peek()) >= precedence(c)) {
                result[j++] = pop();
            }
            push(c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                result[j++] = pop();
            }
            pop();
        }
    }
    while (top != -1) {
        result[j++] = pop();
    }
    result[j] = '\0';
}

int main() {
    char expression[MAX_EXPRESSION_SIZE];
    char result[MAX_RESULT_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", expression);

    infix_to_postfix(expression, result);

    printf("Postfix expression: %s\n", result);

    return 0;
}
**/
