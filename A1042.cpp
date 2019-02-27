#include <iostream>
#include<stdio.h>


//Shuffing Machine

#define N 54

int main()
{
	
	char color[5] = {'S','H','C','D','J'};
	int First[N+1],End[N+1],next[N+1],i,times;
	
	for(i=1;i<=N;i++)
		First[i]=i;
	//Receive Input
	scanf("%d",&times);
	for(i = 1; i<= N; i++)
		scanf("%d",&next[i]);
	
	//Reverse
	for(int j = 0; j <times; ++j)
	{
		for(i = 1; i <= N; ++i)
		{
			End[next[i]] = First[i];
		}
		for(i = 1; i<= N; ++i)
		{
			First[i] = End[i];
		}
	}
	
	//Print 
	for(i = 1;i <= N; ++i )
	{
		if(i != 1) printf(" ");
		First[i]--;
		printf("%c",color[First[i]/13]);
		printf("%d",First[i]%13+1);
	}
	return 0;
}
