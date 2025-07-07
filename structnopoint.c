#include<stdio.h>
#include<stdlib.h>

struct student{
char* name;
float cgpa;
int roll;
};



struct student acc(struct student s)
{
s.name = (char*)calloc(100,sizeof(char));
printf("name \n");
//char buffer[100];
int i=0;
char ch;
while((ch=getchar()) != '\n')
{
    s.name[i] = ch;
i++;
}
s.name[i] = '\0';
if(s.name == NULL)
{
printf("fail");
}


printf("roll\n");
scanf("%d",&s.roll);
printf("\n");
scanf("%f",&s.cgpa);

return s;
}

void dis(struct student s)
{
printf("%-12s %-10s %-10s\n","name", "roll", "cgpa");
printf("%-12s %-10d %-10f\n",s.name, s.roll, s.cgpa);
}

int main()
{
struct student s = acc(s);

dis(s);
free(s.name);
return 0;
}