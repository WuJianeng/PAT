#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h>
//2018.12.28 09:11
char trans[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main()
{
	int color[3];
	char res[3];
	scanf("%d %d %d",&color[0],&color[1],&color[2]);
	printf("#");
	for(int  i = 0; i < 3; i++)
	{
		res[0] = trans[color[i] / 13];
		res[1] = trans[color[i] % 13];
		res[2] = '\0';
		printf("%s",res);
	}
	return 0;
}
