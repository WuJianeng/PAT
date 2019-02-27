#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h>
//2018.12.17 20:42

int main()
{
	int N,k,n2;
	char temp[100];
	scanf("%s",temp);
	N = strlen(temp);
	n2 = (N + 2) % 3 == 0? (N + 2) / 3: (N + 2) / 3 + (N + 2) % 3;
	k = (N  - n2) / 2 ;
	for(int i = 0; i < k; ++i)
	{
		printf("%c",temp[i]);
		for(int j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n",temp[N-1-i]);
	}
	for(int i = 0; i < n2; i++)
	{
		printf("%c",temp[k + i]);
	}
	printf("\n");
	return 0;
}



