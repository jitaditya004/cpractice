#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct Node {
char name[max];
struct Node* prev=NULL;
struct Node* next = NULL;
}node;

node* head = NULL;

node* create(char* name)
{
node* new= (node*)malloc(sizeof(node));
if(new==NULL)
{
printf("err 1");
exit(1);
}
int i = 0;
while(name != '\0' && i<=max-1)//string copy
{
new->name[i]=name[i];
i++;
}
new->name[i]='\0';
return new;
}

void insertany(char* name,int pos)
{
node* new = create(name);

if(pos == 1)
{
new->next=head;
if(head != NULL)
{
head->prev=new;
}
head=new;
return;
}
else{
int i=0;
node* temp = head;
while(temp != NULL && i<pos)
{
temp=temp->next;
i++;
}
if(temp == NULL)
{
printf("position not found");
free(new);
return;
}
if(temp->next != NULL)
{
temp->next->prev=new;

}
new->next=temp->next;
temp->next=new;
new->prev=temp;
printf("inserted");
}
}

void delany(int pos)
{
if(head==NULL)
{
printf("list empty");
return;
}
if(pos == 1)
{
if(head->next != NULL){
head->next->prev = NULL;
}
head = head->next;
free(head);
head = NULL;
}else{
node* temp=head;
int i=0;
while(temp != NULL && i<pos)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("pos not found");
return;
}
node* del=temp->next;
del->next->prev=temp;
temp->next=del->next;
free(del);
}

void search(char* str)
{
int match=1;

node* temp=head;
while(temp != NULL)
{
int i=0;
while(temp->name[i] != NULL && str[i] != NULL)
{
if(temp->name[i] != str[i])
{
match=0;
break;
}
i++;
}

if (match && temp->name[i] == '\0' && str[i] != '\0')
{
printf("found");
return;
}
printf("not found");
}

void disp()
{
node* temp = head;
while(temp != NULL)
{
printf("%s -- ",temp->name);
temp=temp->next;
}
}



int main() 
{
int choice,pos;
char name[max];
printf("choice  ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{

printf("insert--name  enter, pos");
fgets(name,max,stdin);

int len=0;//use brackets, fgets null terminate if space aviable
if(name[len] != '\0')
{
len++;
}
if(len>0 && name[len-1] == '\n')
{
name[len-1] = '\0';
}



scanf("%d",&pos);
insertany(str,pos);

break;
}
case 2:{
break;
}

default:

}
return 0;
}

