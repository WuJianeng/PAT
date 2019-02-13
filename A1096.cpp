//2019 2.13 15:02
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int sqr = (int) sqrt(n) + 2;
	bool *tag = new bool [sqr];
	int *flag = new int [sqr];
	for(int i = 0; i <= sqr; ++i){
		tag[i] = false;
		flag[i] = 0;
	}
	for(int i = 1; i <= sqr; ++i)
		if(n % i == 0) tag[i] = true;
	for(int i = 2; i <= sqr; ++i){
		long long int res = 1;
		if(tag[i] == true)
			for(int j = i; j <= sqr; j++){
				res = res * j;
				if(n % res == 0) flag[i]++;
				else break;
			}
	}
	int count = 0, num;
	for(int i = 2; i <= sqr; i++)
		if(flag[i] > count){
			count = flag[i];
			num = i;
		}
	if(count == 0) printf("1\n%d\n", n);
	else{
		printf("%d\n", count);
		for(int i = 0; i < count; i++){
			if(i != 0) printf("*");
			printf("%d", num + i);
		}
	}
	return 0;	
}
