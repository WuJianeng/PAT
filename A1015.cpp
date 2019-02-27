#include<cstdio>
#include<iostream>
// 2019.1.18 11:08
using namespace std;
int temp[100];
bool IsPrime(int k){
	if(k <= 1) return false;
	if(k == 2) return true;
	for(int i = 2; i < k; ++i){
		if(k % i == 0) 
			return false;
	}
	return true;
}
int tran(int &k,int de){
	int i;
	for( i = 0; k > 0; i++){
		temp[i] = k % de;
		k = k / de;
	}
	for(int j = 0; j < i; j++){
		k = k * de + temp[j];
	}
}
int main(){
	int k,de;
	while(true){
		scanf("%d",&k);
		if(k < 0) return 0;
		scanf("%d",&de);
		if(!IsPrime(k)) {
			printf("No\n");
			continue;
		}
		//transfer
		tran(k,de);
		if(IsPrime(k))
			printf("Yes\n");
		else printf("No\n");	
	}
	return 0;
}
