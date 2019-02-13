//2019 2.13 15:40
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool change(char *s, int* a){
	int len = strlen(s);
	for(int i = 0; i < len; ++i)
		a[i] = s[i] - '0';
	return true;
}
int main(){
	char s[21];
	scanf("%s", s);
	int a[21];
	change(s, a);
	int len = strlen(s);
	int tag[10] ={0};
	for(int i = 0; i < len; ++i)
		tag[ a[i] ]++;
	int flag = 0;
	for(int i = len - 1; i >= 0; --i){
		a[i] = a[i] * 2 + flag;
		if(a[i] >= 10){
			flag = 1;
			a[i] = a[i] - 10;
		}
		else flag = 0;
	}
	if(flag == 1){
		printf("No\n");
		printf("1");
		for(int i = 0; i < len; ++i)
			printf("%d", a[i]);
	}
	else{
		for(int i = 0; i < len; ++i)
			tag[ a[i] ]--;
		flag = 1;
		for(int i = 0; i < 10; ++i)
			if(tag[i] != 0){
				printf("No\n");
				flag = 0;
				break;
			}
		if(flag) printf("Yes\n");
		for(int i = 0; i < len; ++i)
		printf("%d", a[i]);
	}
	return 0;
}
