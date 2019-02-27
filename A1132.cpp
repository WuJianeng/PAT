//2019/2/26 17:00
#include<cstdio>
#include<cmath>
using namespace std;
void judge(int z){
	int i;
	for(i = 1; i < 11; i++)
		if(z < (long long)pow(10, i)) break;
	i = i / 2;
	int low = z % (int)pow(10, i);
	int high = z / (int)pow(10, i);
	if(low == 0){
		printf("No\n");
		return ;
	}
	if(z % (low * high) == 0) printf("Yes\n");
	else printf("No\n");
}
int main(){
	int n, z;
	scanf("%d", &n);
	for(int j = 0; j < n; ++j){
		scanf("%d", &z);
		judge(z);
	}
	return 0;
}
