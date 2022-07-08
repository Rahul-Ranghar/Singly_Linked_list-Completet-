#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert_beg();
void insert_end();
void insert_random();
void delete_beg();
void delete_end();
void delete_random();
void search();
void display();
int main()
{
    int ch=0;
    do
    {
    printf("\nPress\n1-Insert at starting\n2-Insert at ending\n3-Insert at any postion\n4-Delete from start\n5-Delete from last\n6-Delete from random place\n7-Display\n8-Search\n9-Exit\nEnter your choice.\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            insert_beg();
            break;
        }
        case 2:
        {
            insert_end();
            break;
        }
        case 3:
        {
            insert_random();
            break;
        }
        case 4:
        {
            delete_beg();
            break;
        }
        case 5:
        {
            delete_end();
            break;
        }
        case 6:
        {
            delete_random();
            break;
        }
        case 7:
        {
            display();
            break;
        }
        case 8:
        {
            search();
            break;
        }
        case 9:
        {
            exit(0);
            break;
        }
        default :
        {
            printf("Wrong choice.\n");
            break;
        }
    }
    }while(ch!=8);
    return 0;
}
void insert_beg()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the value.\n");
    scanf("%d",&n);
    temp->data=n;
    temp->next=head;
    head=temp;
    printf("Node inserted.\n");
}
void insert_end()
{
    struct node *ptr;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the value.\n");
    scanf("%d",&n);
    temp->data=n;
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
        printf("Node inserted.\n");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        printf("Node inserted.\n");
    }
}
void insert_random()
{
    struct node *ptr;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        int n,pos,i;
        printf("Enter the value\n");
        scanf("%d",&n);
        printf("Enter the position where you want to insert.\n");
        scanf("%d",&pos);
        temp->data=n;
        ptr=head;
        for(i=0;i<pos;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Can't inserted the value.\n");
            }
        }
            temp->next=ptr->next;
            ptr->next=temp;
            printf("Node inserted.\n");      
    }
}
void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Empty linked list.\n");
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void delete_beg()
{
    if(head==NULL)
    {
        printf("Empty linked list\n");
    }
    else
    {
       struct node *ptr;
       ptr=head;
       head=head->next;
       free(ptr);
       printf("Node deleted.\n"); 
    }
}
void delete_end()
{
    if(head==NULL)
    {
        printf("Empty linked list\n");
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
            printf("Node delete\n");
        }
        struct node *ptr, *ptr2;
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr2=ptr;
            ptr=ptr->next;
        }
        ptr2->next=NULL;
        free(ptr);
        printf("Node delete\n");
    }
}
void delete_random()
{
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        struct node *ptr,*ptr2;
        int pos,i;
        printf("Enter the postion where you want to clear\n");
        scanf("%d",&pos);
        ptr=head;
        for(i=0;i<pos;i++)
        {
            ptr2=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Can't delete.\n");
            }
        }
        ptr2->next=ptr->next;
        free(ptr);
    }
}
void search()
{
    if(head==NULL)
    {
        printf("Empty linked list\n");
    }
    else
    {
        int n,i=0;
        struct node *ptr;
        printf("Enter the value for find:\n");
        scanf("%d",&n);
        ptr=head;
        while(ptr->next!=NULL)
        {
            if(ptr->data==n)
            {
                printf("Item found at %d",i);
                break;
            }
            i++;
            ptr=ptr->next;
        }
    }
}