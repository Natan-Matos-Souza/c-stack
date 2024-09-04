#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
     int value;
     struct Node *next;
} Node;

typedef struct StackList {
    Node *head;
} StackList;

StackList* create_stack_list() {
    StackList *stack_list = (StackList*) malloc(sizeof(StackList));
    stack_list->head = NULL;
    return stack_list;
}

void insert_element(int number, StackList *stack_list) {
    Node *element = (Node*) malloc(sizeof(Node));
    element->value = number;
    
    if (stack_list->head == NULL) {
        stack_list->head = element;
        return;
    }
    
    Node *old_first_element = stack_list->head;
    stack_list->head = element;
    
    stack_list->head->next = old_first_element;
}

void pop(StackList* stack_list) {
    if (!stack_list->head->next) {
        free(stack_list->head);
        stack_list->head = NULL;
        return;
    }
    
    Node *second_element = stack_list->head->next;
    free(stack_list->head);
    stack_list->head = second_element;
}

void show_elements(StackList *stack_list) {
    Node *element = stack_list->head;
    
    while (element) {
        printf("%i\n", element->value);
        element = element->next;
    }
}

int main()
{
    StackList *stack_list = create_stack_list();
    insert_element(10, stack_list);
    insert_element(20, stack_list);
    insert_element(30, stack_list);
    pop(stack_list);
    pop(stack_list);
    pop(stack_list);
    pop(stack_list);
    show_elements(stack_list);
    return 0;
}
