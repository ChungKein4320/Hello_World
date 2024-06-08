#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *makeNode(int x) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushBack(node **head, int x) {
    node *newNode = makeNode(x);
    if (*head == NULL) {
        (*head) = newNode;
        return;
    }
    node *tmp = (*head);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void delete(node **head, int x) {

}

void deleteAll(node **head, int x) {
    while ((*head) != NULL && (*head)->data == x) {
        node *tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
    }
    node *tmp = (*head);
    node *prev = tmp;
    while (tmp != NULL) {
        if (tmp->data == x) {
            prev->next = tmp->next;
            free(tmp);
            tmp = prev->next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void Print(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    node *head = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        pushBack(&head, a);
    }

    deleteAll(&head, x);

    if (head == NULL) {
        printf("EMPTY");
    } else {
        Print(head);
    }

    return 0;
}