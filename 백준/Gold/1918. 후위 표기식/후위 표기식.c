#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack {
	char data;
	struct stack *next;
}Stack;

typedef struct stackList {
	Stack *top;
}sList;

void initStack(sList *list) {
	list->top = NULL;
}

void push(sList *list, char data) {
	Stack *new = (Stack*)malloc(sizeof(Stack));
	new->data = data;
	new->next = list->top;
	list->top = new;
}

void pop(sList *list) {
	Stack *temp = list->top->next;
	free(list->top);
	list->top = temp;
}

bool isEmpty(sList *list) {
	if (list->top == NULL) return true;
	else return false;
}

char peek(sList *list) {
	if (isEmpty(list)) return NULL;
	else return list->top->data;
}

void freeStack(sList *list) {
	while (!isEmpty(list)) {
		pop(list);
	}
}

int getWeight(char k) {
	switch (k)
	{
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		return 0;
	case '(':
		return -1;
	default:
		return NULL;
	}
}

int main(void) {
	sList stack1; initStack(&stack1);
	char susick[60]; scanf("%s", susick);
	char back[60]; int k = 0;
	for (int i = 0; i < strlen(susick); i++) {
		if ('A' <= susick[i] && susick[i] <= 'Z') {
			back[k++] = susick[i];
		}
		else if (isEmpty(&stack1) || susick[i]=='(') {
			push(&stack1, susick[i]);
		}
		else if (susick[i] == ')') {
			while (peek(&stack1) != '(') {
				back[k++] = peek(&stack1);
				pop(&stack1);
			}
			pop(&stack1);
		}
		else {
			if (getWeight(peek(&stack1)) < getWeight(susick[i])) {
				push(&stack1, susick[i]);
			}
			else {
				while (!isEmpty(&stack1) && getWeight(peek(&stack1)) >= getWeight(susick[i])) {
					back[k++] = peek(&stack1);
					pop(&stack1);
				}
				push(&stack1, susick[i]);
			}
		}
	}
	while (!isEmpty(&stack1)) {
		back[k++] = peek(&stack1);
		pop(&stack1);
	}
	back[k] = '\0';

	printf("%s\n", back);

	return 0;
}