//2019.2.8 20:43
#include<cstdio>
#include<cstring>
using namespace std;
int num[100010] = {0};
int tag[10010] = {0};
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		tag[ num[i] ]++;
	}
	int flag = 0;
	for(int i = 0; i < n; ++i){
		if(tag[ num[i] ] == 1) {
			printf("%d\n", num[i]);
			flag = 1;
			break;	
		}
	}
	if(flag == 0) printf("None\n");
	return 0;
}
