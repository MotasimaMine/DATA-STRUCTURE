#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}
int getLength()
{
    return length;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
    if (listMaxSize==0)
        initializeList();
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}
int insertItemAt(int pos, int item)
{
    int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};
	list[length] = list[pos];
	list[pos]=item;
	length++ ;
	return SUCCESS_VALUE ;
}
int shrink()
{
    int *tempList;
    while (length<=listMaxSize/2)
    {
        if (listMaxSize==LIST_INIT_SIZE )
            break;
        else
        {
            listMaxSize =listMaxSize/2 ;
            tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
            int i;
            for( i = 0; i < length ; i++ )
            {
                tempList[i] = list[i] ; //copy all items from list to tempList
            }
            free(list) ; //free the memory allocated before
            list = tempList ;
        }
        if (length==listMaxSize) break;
        listMaxSize=listMaxSize/2;
    }
    return SUCCESS_VALUE;

}


int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position >= length ) return NULL_VALUE;
	list[position] = list[length-1] ;
	length-- ;
	shrink();
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	shrink();
	return SUCCESS_VALUE ;
}
int deleteLast()
{
    if(length==0)
        return NULL_VALUE;
    length--;
    shrink();
    return SUCCESS_VALUE;
}
int deleteALL()
{
    length=0;
    shrink();
    return SUCCESS_VALUE;
}
int clearALL()
{
    length=0;
    listMaxSize=0;
    free(list);
    return SUCCESS_VALUE;
}

void printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}
void postFix(char a[])
{
    int i,c, x,y;
    for(i=0; i < 100; i++){
        if(a[i]>='0' && a[i] <= '9')
        {
            c=a[i];
            x=c-48;
            insertItem(x);
        }
        if(a[i]=='+')
        {
           y=list[length-1]+list[length-2];
           deleteLast();
           deleteLast();
           insertItem(y);
        }
        if(a[i]=='-')
        {
            y=list[length-2]-list[length-1];
            deleteLast();
            deleteLast();
            insertItem(y);
        }
        if(a[i]=='*')
        {
            y=list[length-2]*list[length-1];
            deleteLast();
            deleteLast();
            insertItem(y);
        }
        if(a[i]=='/')
        {
            y=list[length-2]/list[length-1];
            deleteLast();
            deleteLast();
            insertItem(y);
        }
    }
    for(i=0; i < length; i++)
        printf("%d",list[i]);
}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. Insert Item At 5.Delete Last 6.Delete all 7.Clear\n");
        printf("8. Print. 9. exit.\n");

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
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==4)
        {
            int pos,item;
            scanf("%d %d",&pos,&item);
            insertItemAt(pos,item);
        }
        else if (ch==5)
        {
            deleteLast();
        }
        else if (ch==6)
        {
            deleteALL();
        }
        else if (ch==7)
        {
            clearALL();
        }
        else if(ch==8)
        {
            printList();
        }
        else if(ch==9)
        {
            break;
        }
    }

}*/
main()
{
    initializeList();
    char a[100];
    printf("Enter Expression: ");
    scanf("%s",a);
    postFix(a);
    clearALL();
}
