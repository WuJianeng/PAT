#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>

//2018.12.17 18:01

int main()
{
	char a[3] = {'W','T','L'};
	double sum = 1.0,temp,max;
	int tag;
	for(int i = 0; i < 3; i++)
	{
		max = 0.0; 
		for(int j = 0; j < 3; j++)
		{
			scanf("%lf",&temp);
			if(temp > max)
			{
				max = temp;
				tag = j;
			}
		}
		sum = sum * max;
		printf("%c ",a[tag] );
	}
	printf("%.2f",sum*1.30 - 2.00);
	return 0;
}


