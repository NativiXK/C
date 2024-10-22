#include <stdio.h>
#include <stdlib.h>

typedef struct stNode
{
    int value;
    struct stNode* next;
} stNode;

typedef struct stQueue
{
    stNode* first;
    stNode* last;
    int length;
} stQueue;

// Functions prototypes
stQueue* new_queue ();

int enqueue (stQueue* queue, int value);
stNode* dequeue (stQueue* queue);
stNode* peekFirst (stQueue* queue);
stNode* peekLast (stQueue* queue);

void print_queue(stQueue* queue);
void print_node(stNode* node);

void free_queue(stQueue* queue);
void free_node(stNode* node);

int main()
{
    stQueue* queue = (stQueue*) new_queue(); // FIFO
    
    if (queue == NULL) return 1;
    
    enqueue(queue, 5); // 1°
    enqueue(queue, 10);// 2°
    enqueue(queue, 0); // 3°
    enqueue(queue, 25);// 4°
    enqueue(queue, 52);// 5°
    
    print_queue(queue);//5 - 10 - 0 - 25 - 52
    
    stNode* node = NULL;
    
    node = dequeue(queue); // remove 5
    
    print_queue(queue); //10 - 0 - 25 - 52
    
    enqueue(queue, node->value);
    
    print_queue(queue);//10 - 0 - 25 - 52 - 5
    
    free_queue(queue);

    return 0;
}

stQueue* new_queue () {
    stQueue* queue = (stQueue*) malloc(sizeof(stQueue));
    
    if (queue != NULL) {
        queue->first = NULL;
        queue->last = NULL;
        queue->length = 0;
        
        return queue;
    }
    
    return NULL;
}

int enqueue (stQueue* queue, int value) {
    stNode* new = (stNode*) malloc(sizeof(stNode));
    
    if (new == NULL) return 1;
    
    new->value = value;
    new->next = NULL;
    
    // First insertion
    if ((queue->last == NULL) && (queue->first == NULL)) {
        
        queue->first = new;
        queue->last = new;
        
        queue->length++;
        
        return 0;
    }
    
    //Normal insertion
    queue->last->next = new;
    queue->last = new;
    
    return 0;
}

stNode* dequeue (stQueue* queue) {
    if (queue->first == NULL) return NULL;
    
    stNode* node = queue->first;
    queue->first = node->next;
    node->next = NULL;
    return node;
}

stNode* peekFirst (stQueue* queue) {
    if (queue->first == NULL) return NULL;
    
    return queue->first;
}

stNode* peekLast (stQueue* queue) {
    if (queue->last == NULL) return NULL;
    
    return queue->last;
}

void print_queue(stQueue* queue) {
    if (queue->first == NULL) return;
    print_node(queue->first);
    printf("\n");
}

void print_node(stNode* node) {
    printf("%d", node->value);
    
    if (node->next != NULL) {
        printf(" - ");
        return print_node(node->next);
    }
    
}

void free_queue(stQueue* queue) {
    if (queue->first != NULL) return free_node(queue->first);
    free(queue);
}

void free_node(stNode* node) {
    if (node->next != NULL) return free_node(node->next);
    free(node);
}
