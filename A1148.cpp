//2019/3/1 15:20
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 105;
int judge[maxn];
int n;

bool verify(int i, int j){
	bool isWolf[maxn] = {false};
	for(int k = 1; k <= n; ++k){
		if(k != i && k != j && judge[k] < 0){
			int id = -judge[k];
			isWolf[id] = true;
		}
		if(k == i || k== j && judge[k] > 0) isWolf[judge[k]] = true;	
	}
	int iIsWolf = false, jIsWolf = false, wolfNum = 0;
	for(int k = 1; k <= n; ++k){
		if(isWolf[k] == true){
			if(k == i) iIsWolf = true;
			else if(k == j) jIsWolf = true;
			wolfNum++;
		}
	}
	if(wolfNum == 2 && (iIsWolf + jIsWolf == 1) )
		return true;
	else return false;
}
void fun(){
	for(int i = 1;i <= n; ++i)
		for(int j = i + 1; j <= n; ++j){
			bool flag = verify(i, j);
			if(flag == true){
				printf("%d %d\n", i, j);
				return ;
			}
		}
	printf("No Solution\n");
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &judge[i]);
	}
	fun();
	return 0;
}
