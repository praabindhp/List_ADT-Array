#include<stdio.h>
#include<alloca.h>
#include<stdlib.h>
struct list
{
int capacity;
int size;
int *array;
};
typedef struct list *ptrToNode;
typedef ptrToNode LIST;
typedef int POSITION;
int Isempty(LIST L)
{
return L->size==0;
}
void MakeEmpty(LIST L)
{
if(Isempty(L))
printf("\n LIST is already Empty");
else
{
L->size=0;
printf("\n Now List becomes Empty");
}
}
LIST Createlist(int max)
{
LIST L;
L=(struct list*)malloc(sizeof(struct list));
if(L==NULL)
printf("\n Fatal Error");
else
{
L->capacity=max;
L->array=(int*)malloc(sizeof(int)*max);
if(L->array==NULL)
printf("\n Fatal Error");
else
{
L->size=0;
printf("\n List is Created successfully");
}
}return L;}
int Isfull(LIST L)
{
return L->size==L->capacity;
}
void Insert(int x,LIST L,POSITION P)
{
int i;
if(Isfull(L))
printf("\n List is Full");
else{
for(i=L->size-1;i>=P;i--)
L->array[i+1]=L->array[i];
L->size++;
L->array[P]=x;
}}
POSITION Findprevious(int x,LIST L)
{
POSITION P;
P=-1;
while(P!=L->size&&L->array[P+1]!=x)
{
P++;
}
return P;
}
POSITION Find(int x,LIST L)
{
POSITION P;
P=0;
while(P!=L->size&&L->array[P]!=x)
{
P++;
}
return P;
}
void Delete(int x,LIST L)
{
int i;
POSITION P;
P=Find(x,L);
if(P==L->size)
printf("\n Element not found in the list");
else
{for(i=P;i<L->size;i++)
L->array[i]=L->array[i+1];
L->size--;
}}
LIST Deletelist(LIST L)
{
MakeEmpty(L);
free(L);
L=NULL;
return L;
}
void Display(LIST L)
{int i;
for(i=0;i<L->size;i++)
printf("\n %d",L->array[i]);
}
void main()
{
LIST L=NULL;
POSITION P;
int a,choice,ch,element;
printf("\n\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.MakeEmpty\n6.Find\n7.IsEmpty\n8.IsFull\n9.Deletelist\n10.Exit\n");
A:
printf("\nEnter Your Option:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
if(L==NULL)
L=Createlist(5);
else
printf("\nList is already created");
break;
case 2:
if(L==NULL)
printf("\nList is not yet created");
else
{
printf("\nEnter the Element to insert:\t");
scanf("%d",&element);
if(L->size==0)
Insert(element,L,0);

else
{
printf("\n where u want to insert?\t1:Front\t2:Back\t3:middle\t::: ");
scanf("%d",&ch);
if(ch==1)
Insert(element,L,0);
else
if(ch==2)
Insert(element,L,L->size);
else
if(ch==3)
{
printf("\nWhere you want to insert:\t");
scanf("%d",&a);
P=Find(a,L);
if(P<L->size)
Insert(element,L,P);
else
printf("\nElement is not in the list");
}
else
printf("\n Ur choice is not available");
}
}
break;
case 3:
if(L==NULL)
printf("\nList is not yet created");
if(Isempty(L))
printf("\nList is empty");
else
{
printf("\nEnter the element to delete:\t");
scanf("%d",&a);
Delete(a,L);
}
break;
case 4:
if(L==NULL)
printf("\nList is not yet created");
else
if(Isempty(L))
printf("\nList is empty");
else
{
printf("\nElements present in the list are:");
Display(L);
}
break;
case 5:
if(L==NULL)
printf("\n List is not yet created ");

else
MakeEmpty(L);
break;
case 6:
if(L==NULL)
printf("\n Not yet created");
else
if(Isempty(L))
printf("\n List is empty");
else
{
printf("\n which element is to find:\t");
scanf("%d",&a);
P=Find(a,L);
printf("\n Element is at %d\t[0 to 4 means present]\t[5 means not present]",P);
}
break;
case 7:
if(L==NULL)
printf("\n Not yet created");
else
if(Isempty(L))
printf("\n List is empty");
else
printf("\n List is not empty");
break;
case 8:
if(L==NULL)
printf("\n Not yet created");
else
if(Isfull(L))
printf("\n List is FULL");
else
printf("\n List is not FULL");
break;
case 9:
if(L==NULL)
printf("\n Not yet created");
else
{
L=Deletelist(L);
printf("\n List is Deleted");
}
break;
case 10:
exit (0);
break;
default:
printf("\n\n *******WRONG ENTRY*******");
break;
}
goto A;
}
