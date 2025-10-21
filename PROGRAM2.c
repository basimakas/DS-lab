#include<stdio.h>
#include<stdlib.h>
int myfunction(int x, int y)
{
int c;
c=x+y;
return(c);
}
int main()
{
int a,b;
printf("enter two numbers");
scanf("%d%d",&a,&b);
int result=myfunction(a,b);
printf("result is%d",result);
return 0;
}

