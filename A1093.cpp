#include<cstdio>
#include<cstring>
// 2019.1.25 11:
using namespace std;
char str[100025];
int left_P[100025] = {0};
int right_T[100025] = {0};
int main(){
	scanf("%s",str);
	int N = strlen(str),count = 0;
	for(int i = 0; i < N; i ++){
		if(i > 0) left_P[i] = left_P[i-1];
		if(str[i] == 'P') left_P[i]++;
	}
	for(int i = N-1; i >= 0; i --){
		if(i < N-1) right_T[i] = right_T[i+1];
		if(str[i] == 'T') right_T[i]++;
	}
	for(int i = 0; i < N; i ++){
		if(str[i] == 'A') count = (count + left_P[i] * right_T[i])%1000000007;
	}
	printf("%d\n",count);
	return 0;
}
