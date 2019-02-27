#include<cstdio>
#include<cstring>
#include<iostream>

// 2019.1.29 10:47;
const int maxn = 100000000;
int tag[maxn][2] = {0};

int main(){
	int num,count = 0,p = -1;
	scanf("%d",&num);
	if(num != 1) printf("%d=",num);
	else printf("1=1");
	for(int i = 2; i <= num ; i++){
		if(num % i == 0) tag[p+1][0] = i;
		while(num % i == 0){
			num = num / i;
			if(count == 0){
				tag[++p][1]++;
				count++;
			} 
			else tag[p][1]++;
		}
		count = 0;
	}
	
	//print
	for(int i = 0; i <= p; i++){
		if(i != 0) printf("*");
		if(tag[i][1] == 1) printf("%d",tag[i][0]);
		else printf("%d^%d",tag[i][0],tag[i][1]);
	}
	return 0;
}
