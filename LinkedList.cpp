#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ; //point to previous first node
    list = newNode ; //set list to point to newnode as this is now the first node
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
}


struct listNode * searchItem(int item)
{
    struct listNode * temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int insertLast(int item)
{
    struct listNode *newNode;
    newNode=(struct listNode*)malloc(sizeof (struct listNode));
    newNode->item=item;
    newNode->next=0;
    struct listNode *temp, *prev;
    prev=0;
    temp=list;
    while (temp!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    if (list!=0)
    {
        prev->next=newNode;
    }
    else
        list=newNode;
}

int insertAfter(int oldItem, int newItem)
{
    struct listNode *newNode;
    newNode=(struct listNode*)malloc(sizeof (struct listNode));
    newNode->item=newItem;
    struct listNode *temp, *prev;
    prev=0;
    temp=searchItem(oldItem);
    if (temp!=0)
    {
        newNode->next=temp->next;
        prev=temp;
        prev->next=newNode;


    }
    return SUCCESS_VALUE;

}
int deleteLast()
{
    struct listNode *temp, *prev ;
    temp = list ;
    while (temp != 0)
    {
        if (temp->next == 0) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list =0;
        free(temp) ;
    }
    else
    {
        prev->next =0 ;
        free(temp);
    }
    return SUCCESS_VALUE ;
}


int deleteFirst()
{
    struct listNode *temp;
    temp=list;
    if (temp==0) return NULL_VALUE;
    else
    {
        temp=list;
        list=list->next;
        free(temp);
        return SUCCESS_VALUE;
    }
    return 0;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. 4. insert last \n");
        printf("5. insert after. 6. Print. 7. exit. 8. delete last 9. delete 1st\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==6)
        {
            printList();
        }
        else if(ch==7)
        {
            break;
        }
        else if (ch==4)
        {
            int item;
            scanf("%d",&item);
            insertLast(item);
        }
        else if (ch==5)
        {
            int oldItem,newItem;
            scanf ("%d %d", & oldItem ,& newItem);
            insertAfter(oldItem, newItem);
        }
        else if(ch==8)
        {
            deleteLast();
        }
        else if (ch==9)
        {
            deleteFirst();
        }
    }

}
