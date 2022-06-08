#include "push_swap.h"

void push_front(t_stack ** head_ref, int num)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
 
    new_node->num = num;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}

void insertAfter(t_stack *prev_node, int num)
{
    t_stack *new_node;
    if (prev_node == NULL)
        return;
 
    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->num = num;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(t_stack **head_ref, int num)
{
    t_stack *new_node;
    t_stack *last;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    last = *head_ref;
    new_node->num = num;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

void deleteNode(t_stack ** head_ref, t_stack* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
 
    if (*head_ref == del)
        *head_ref = del->next;
 
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
    return;
}