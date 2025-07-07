#include <stdio.h>

struct num {
 int n1;
 int n2;
 };
 
 int sum(struct num n)
 {
  return n.n1+n.n2; 
  }
  
  int main()
  {
  struct num numss;
  
  printf("Enter two numbers\n");
  scanf("%d %d", &numss.n1, &numss.n2);
  
  int result= sum(numss);
  printf ("The result  %d",result);
  
  }