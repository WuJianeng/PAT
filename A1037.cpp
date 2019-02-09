//2019 2.9 14:40
#include<cstdio>
#include<algorithm>
using namespace std;
int list[2][100010];
bool cmp(int a, int b){
	return a > b;
}
bool cmp1(int a, int b){
	return a < b;
}
int main(){
	int n[2];
	for(int i = 0; i < 2; ++i){
		scanf("%d", &n[i]);
		for(int  j = 0; j < n[i]; ++j)
			scanf("%d", &list[i][j]);
	}
	for(int i = 0; i < 2; ++i)
		sort(list[i], list[i] + n[i], cmp);
	long long int amount = 0;
	//positive
	for(int i = 0; i < n[0] && i < n[1]; ++i){
		if(list[0][i] > 0 && list[1][i] > 0) amount += list[0][i] * list[1][i];
		else break;
	}
	for(int i = 0; i < 2; ++i)
		sort(list[i], list[i] + n[i], cmp1);
	//negative
	for(int i = 0; i < n[0] && i < n[1]; ++i){
		if(list[0][i] < 0 && list[1][i] < 0) amount += list[0][i] * list[1][i];
		else break;
	}	
	printf("%lld\n", amount);
	return 0;
}
