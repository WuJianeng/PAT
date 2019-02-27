#include<cstdio>
#include<cstring>

// 2019.1.25 scanf("%d",N)输入应当注意加&,为此调试了十几分钟； 
using namespace std;
int num[10] = {0};
int Max(int ans)
{
	int count,n = 4;
	for(int i = 0; i < 10; ++i)
	{
		num[i] = 0;
	}
	while(ans > 0 )
	{
		count = ans % 10;
		ans = ans/10;
		num[count]++;
		n--;	
	}
	if(n > 0) num[0] += n;
	for(int i = 9; i >= 0; --i)
	{
		while(num[i] != 0)
		{
			ans = ans * 10 + i;
			num[i]--;
		}
	}
	return ans;
}

int Min(int ans)
{
	int count,n = 4;
	for(int i = 0; i < 10; ++i)
	{
		num[i] = 0;
	}
	while(ans > 0 )
	{
		count = ans % 10;
		ans = ans/10;
		num[count]++;
		n--;	
	}
	if(n > 0) num[0] += n;
	for(int i = 0; i < 10; ++i)
	{
		while(num[i] != 0)
		{
			ans = ans * 10 + i;
			num[i] --;
		}
	}
	return ans;
}
int main(){
	int N,min,max,ans;
	scanf("%d",&N);
	ans = N;
	while(true){
		min = Min(ans);
		max = Max(ans);
		ans = max -min;
		printf("%04d - %04d = %04d\n",max,min,ans);
		if(ans == 6174 || ans == 0) break;
	}
	return 0;
}
