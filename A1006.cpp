#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
//2018.12.17 19:25
struct Sign{
	char ID[20];
	int in_h,in_m,in_s;
	int out_h,out_m,out_s;
}temp,early,last;
int main()
{
	int N;
	scanf("%d",&N);
	early.in_h = 25;
	early.in_m = 00;
	early.in_s = 00;
	last.out_h = 0;
	last.out_m = 0;
	last.out_s = 0;
	//Input and Caculate
	for(int i = 0; i < N; ++i)
	{
		scanf("%s %d:%d:%d %d:%d:%d",temp.ID,&temp.in_h,&temp.in_m,&temp.in_s,&temp.out_h,&temp.out_m,&temp.out_s);
		if(temp.in_h * 10000 + temp.in_m * 100 + temp.in_s  <= early.in_h *10000 + early.in_m * 100 +early.in_s)
		{
			early = temp;
		}
		if(temp.out_h * 10000 + temp.out_m * 100 + temp.out_s  >= early.out_h *10000 + early.out_m * 100 +early.out_s)
		{
			last = temp;
		}
	}
	printf("%s %s\n",early.ID,last.ID);
	return 0;
}
