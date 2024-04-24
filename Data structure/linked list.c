#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;



Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}


Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = head;
    int i;
    for (i = 1; i < position-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}


Node* deleteFromEnd(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    }
    else {
        prev->next = NULL;
    }
    free(temp);
    return head;
}


Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is already empty\n");
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    if (prev == NULL) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}


Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void removeDuplicates(Node* head) {
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}


int main() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from end\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from any position\n");
        printf("7. Reverse list\n");
        printf("8. Print list\n");
        printf("9. Remove Duplicate\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                head = reverseList(head);
                break;
            case 8:
                printf("List: ");
                printList(head);
                break;
            case 9:
                printf("list: ");
                printList(head);

                removeDuplicates (head);

                printf("New list: ");
                printList(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

