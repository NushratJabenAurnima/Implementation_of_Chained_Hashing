<!DOCTYPE html>
<html>
<body>
<h2>Project Done by &copy; Nushrat Jaben Aurnima. All Rights Reserved .</h2>
</body>
</html>

#include<stdio.h>
#include<stdlib.h>
#define size 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *chain[size];

void initial()
{
    for(int i = 0; i <size; i++)
        chain[i] = NULL;
}

void insert(int data)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    int key = data % size;

    if(chain[key] == NULL)

        chain[key] = newnode;

    else
    {
        struct Node *curr = chain[key];

        while(curr->next!=NULL)

            curr = curr->next;

         curr->next = newnode;
    }
}

void Delete(int x)
{
    int key = x % size;
    struct Node *temp1 = chain[key];
    struct Node *temp2 = NULL;

    if (temp1 == NULL)
    {
        printf("The item is not present in Your Hash Table\n");
        return;
    }

    if (temp1->data == x)
    {
        chain[key] = temp1->next;
        free(temp1);
        return;
    }

    while (temp1 != NULL && temp1->data != x)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 != NULL)
    {
        temp2->next = temp1->next;
        free(temp1);
    }
    else
    {
        printf("The item is not present in Your Hash Table!!!\n");
    }
}

void search(int x)
{
    int key = x % size;
    struct Node *temp = chain[key];

    if (temp == NULL)
    {
        printf("Your Value Is Not Found!!!\n");
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("Your Value Is Found In The Hash Table.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Your Value Is Not Found!!!\n");
}

void display()
{
    for(int i=0;i<size;i++)
    {
        struct Node *curr = chain[i];
        printf("chain[%d] -> ",i);
        while(curr!=NULL)
        {
            printf("%d -> ",curr->data);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice,x;
    int n, val;

    initial();

    while (1)
    {
        printf("\n     Operation MENU    \n");
        printf("\n1:Create Hash Table");
        printf("\n2:Display The Hash Table");
        printf("\n3:Delete Data From The Hash Table");
        printf("\n4:Search Data From The Hash Table");
        printf("\n5:Exit\n");
        printf("\n\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:

            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter Your Hash table Value: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d",&val);
                insert(val);
            }
            break;

        case 2:

            printf("\n\nThis is Your Hash Table:\n\n" );
            display();
            break;


        case 3:

            printf("\nEnter the Value You Want to Delete From Hash Table: ");
            scanf("%d",&x);
            Delete(x);
            break;

        case 4:

            printf("\nEnter the value you want to search in the Hash Table: ");
            scanf("%d",&x);
            search(x);
            break;

        case 5:
            printf("\nYou have successfully exited the Program!!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid Choice! Try Again!!!\n");
        }
    }
}
