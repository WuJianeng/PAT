#include <iostream>
using namespace std;
#include<math.h>
typedef struct
{
	int pow;
	double f;
}Element;
int main() 
{
	int num1,num2,i,j;
	//Input
		
	scanf("%d",&num1);
	Element ele1[10];

	for(i = 0;i < num1; ++i)
	{
		scanf("%d %lf",&ele1[i].pow,&ele1[i].f);
	}
	
	scanf("%d",&num2);
	Element ele2[10];
	for(i = 0;i < num2; ++i)
	{
		scanf("%d %lf",&ele2[i].pow,&ele2[i].f);
	}
	i = 0; j = 0;
	
	//Caculate and Storage
	Element ele3[20];
	int num3 = 0;
	while(i < num1 && j < num2)
	{
		if(ele1[i].pow > ele2[j].pow) 
		{
			ele3[num3].pow = ele1[i].pow;
			ele3[num3].f = ele1[i].f;
			i++;
		}
		else if(ele1[i].pow < ele2[j].pow)
		{
			ele3[num3].pow = ele2[j].pow;
			ele3[num3].f = ele2[j].f;
			j++;
		}
		else if(ele1[i].f + ele2[j].f != 0)
		{
			ele3[num3].pow = ele2[j].pow;
			ele3[num3].f = ele1[i].f + ele2[j].f;
			i++;
			j++;
		}
		else {
			num3--;
			i++;
			j++;
		}
			
		num3++;
	}
	while(i < num1)
	{
		ele3[num3].pow = ele1[i].pow;
		ele3[num3].f = ele1[i].f;
		i++;
		num3++;
	}
	while(j < num2)
	{
		ele3[num3].pow = ele2[j].pow;
		ele3[num3].f = ele2[j].f;
		j++;
		num3++;
	}
	
	//Output
	printf("%d",num3);
	for(i = 0; i < num3; i++)
	{
		printf(" %d %.1lf",ele3[i].pow,ele3[i].f);
	}
	return 0;
}
