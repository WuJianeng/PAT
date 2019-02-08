//2019.2.8 21:18
#include<cstdio>
using namespace std;
int tag[1010] = {0};//coin
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int coin;
	for(int i = 0; i < n; ++i){
		scanf("%d", &coin);
		if(tag[coin] < 2) tag[ coin ] ++;
	}
	int flag = 0;
	for(int i = 1; i <= m / 2; i++){
		if(tag[i] && tag[m-i])
			if(i != m - i || ( i == m - i && tag[i] >= 2 ) ){
				flag = 1;
				printf("%d %d\n", i, m - i);
				break;
			}
	}
	if(flag == 0) printf("No Solution\n");
	return 0;
}
