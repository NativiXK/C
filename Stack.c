#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct stNode
{
	int value;
	struct stNode *next;
} stNode;

// Stack structure
typedef struct stStack
{
	stNode* first;
	int length;

} stStack;

stStack *stack = NULL;

// Functions
void free_stack(stStack* stack);
void free_node(stNode* node);

void push(stStack* stack, int value);
int pop(stStack* stack);
int peek(stStack* stack);

void print_stack(stNode* firstNode);

void free_stack(stStack* stack);
void free_node(stNode* node);

int main()
{
	stack = (stStack*) malloc(sizeof(stStack));
  stack->first = NULL;
  stack->length = 0;

	push(stack, 5);
	push(stack, 25);
	push(stack, 10);
	push(stack, 15);

  print_stack(stack->first); // 15 - 10 - 25 - 5
  printf("\nLength: %d\n", stack->length); // 4

  printf("\nPop -> %d\n", pop(stack)); // 15
  printf("Pop -> %d\n", pop(stack)); // 10
  printf("\nLength: %d\n", stack->length); // 2

  print_stack(stack->first); // 25 - 5
  
  printf("\nPeek -> %d\n", peek(stack)); // 25
  
  print_stack(stack->first); // 25 - 5
  free_stack(stack); // Free system memory
  
	return 0;
}

void push(stStack* stack, int value) {
	stNode* new = (stNode*) malloc(sizeof(stNode));
	
	new->value = value;
	new->next = stack->first;
	stack->first = new;

    stack->length++;
}

int pop(stStack* stack) {
    if (stack->first == NULL) return -1;
    
    int res = stack->first->value;
    
    stack->first = stack->first->next;
    stack->length--;
    
    return res;
}

int peek(stStack* stack) {
    if (stack->first == NULL) return -1;
    return stack->first->value;
}

void print_stack(stNode* firstNode) {
    printf("%d", firstNode->value);
    if (firstNode->next != NULL) {
        printf(" - ");
        print_stack(firstNode->next);
    }
}

void free_stack(stStack* stack) {
	if (stack->first->next != NULL) free_node(stack->first);
	free(stack);
}

void free_node(stNode* node) {
    if (node->next != NULL) free_node(node->next);
    free(node);
}
