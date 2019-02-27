#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h>
//2018.12.28 09:11

int main()
{
	int N,base,num = 0,i  = 0;
	scanf("%d %d",&N,&base);
	int trans[35];
	while(N != 0){
		trans[i] = N % base;
		N = N / base;
		i++;
	}
	int j = 0, k = i - 1, tag = 1;
	for(; j < k ; j++, k--)
	{
		if(trans[j] != trans[k])
		{
			printf("No\n");
			tag = 0;
			break;
		}
	}
	if(tag == 1) printf("Yes\n");
	for(j = i - 1; j >= 0; --j)
	{
		if(j != i - 1) printf(" ");
		printf("%d",trans[j]);
	}
	return 0;
}
