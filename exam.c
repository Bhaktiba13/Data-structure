// 1. WAP to insert an element at the beginning of an array 

#include <stdio.h>

int main() {
    int a[100], n, i, x;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert at beginning: ");
    scanf("%d", &x);

    // Shift elements to right
    for(i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }

    // Insert element at first position
    a[0] = x;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;++
}

// 2. WAP to insert an element at the end of an array

#include <stdio.h>

int main() {
    int a[50], n, i, x;

    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to insert at end: ");
    scanf("%d", &x);

    a[n] = x;   
    n++;          

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// 3. WAP to delete an element at the beginning of an array

#include <stdio.h>

int main() {
    int a[50], n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Shift elements to left
    for(i = 0; i < n-1; i++)
        a[i] = a[i+1];

    n--;   

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


// 4. WAP to delete an element at the end of an array


#include <stdio.h>

int main() {
    int a[50], n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    n--;   

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


// 5. Stack PUSH,POP,DISPLAY

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(15);
    push(75);
    push(32);
    pop();
    push(14);
    push(16);
    display();
    pop();
    push(28);
    push(39);
    push(49);
    display();
    return 0;
}

// 6. Simple Queue 

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements:\n");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {

    enqueue(15);
    enqueue(75);
    enqueue(32);
    dequeue();
    enqueue(14);
    enqueue(16);
    display();
    dequeue();
    enqueue(28);
    enqueue(39);
    enqueue(46);
    display();

    return 0;
}

// 7. Circluar Queue

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1))
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = rear = 0;
        else if(rear == MAX-1)
            rear = 0;
        else
            rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front == -1)
        printf("Queue Underflow\n");
    else {
        printf("Deleted element: %d\n", queue[front]);
        if(front == rear)
            front = rear = -1;
        else if(front == MAX-1)
            front = 0;
        else
            front++;
    }
}

void display() {
    int i;
    if(front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements:\n");
        i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i+1) % MAX;
        }
        printf("\n");
    }
}

int main() {

    enqueue(15);
    enqueue(75);
    enqueue(32);
    dequeue();
    enqueue(14);
    enqueue(16);
    display();
    dequeue();
    enqueue(28);
    enqueue(39);
    enqueue(46);
    display();

    return 0;
}


// 8. Double Ended Queue 

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1))
        printf("Overflow\n");
    else {
        if(front == -1)
            front = rear = 0;
        else if(front == 0)
            front = MAX-1;
        else
            front--;
        deque[front] = x;
    }
}

void insertRear(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1))
        printf("Overflow\n");
    else {
        if(front == -1)
            front = rear = 0;
        else if(rear == MAX-1)
            rear = 0;
        else
            rear++;
        deque[rear] = x;
    }
}

void deleteFront() {
    if(front == -1)
        printf("Underflow\n");
    else {
        printf("Deleted from front: %d\n", deque[front]);
        if(front == rear)
            front = rear = -1;
        else if(front == MAX-1)
            front = 0;
        else
            front++;
    }
}

void deleteRear() {
    if(front == -1)
        printf("Underflow\n");
    else {
        printf("Deleted from rear: %d\n", deque[rear]);
        if(front == rear)
            front = rear = -1;
        else if(rear == 0)
            rear = MAX-1;
        else
            rear--;
    }
}

void display() {
    int i;
    if(front == -1)
        printf("Deque is empty\n");
    else {
        printf("Deque elements:\n");
        i = front;
        while(1) {
            printf("%d ", deque[i]);
            if(i == rear)
                break;
            i = (i+1) % MAX;
        }
        printf("\n");
    }
}

int main() {

    insertRear(20);
    insertRear(45);
    insertRear(67);
    deleteFront();
    insertFront(12);
    insertRear(89);
    display();
    deleteRear();
    insertFront(34);
    insertFront(56);
    display();

    return 0;
}