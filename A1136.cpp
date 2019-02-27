//2019/2/27 16:25
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1010;
char n[maxn];
int s[maxn], r[maxn];
void intToString(char n[], int s[]){
	for(int i = 0; i < strlen(n); ++i)
		s[i] = n[i] - '0';
}
void rever(int len){
	for(int i = 0; i < len; ++i)
		r[len - 1 - i] = s[i];
}
void add(int &len){
	int tag = 0;
	for(int i = len - 1; i >= 0; --i){
		s[i] += r[i] + tag;
		if(s[i] > 9){
			tag = 1;
			s[i] -= 10;
		}
		else tag = 0;
	}
	if(tag){
		for(int i = len; i >= 1; --i)
			s[i] = s[i - 1];
		s[0] = 1;
		len++;
	}
}
bool verify(int len){
	for(int i = 0; i <= len / 2; ++i)
		if(s[i] != s[len - i - 1])
			return false;	
	return true;	
}
void print(int num[], int len){
	for(int i = 0; i < len; ++i)
			printf("%d", num[i]);
}
int main(){
	scanf("%s", n);
	int len = strlen(n);
	intToString(n, s);
	int count = 0;
	bool flag = false;
	while(flag == false || count == 0){
		flag = verify(len);
		if(flag == true){
			print(s, len);
			printf(" is a palindromic number.\n");
			break;
		}
		else if(count == 10){
			printf("Not found in 10 iterations.\n");
			break;
		}
		count++;
		rever(len);
		print(s, len);
		printf(" + ");
		print(r, len);
		printf(" = ");
		add(len);
		print(s, len);
		printf("\n");
	}
	return 0;
}
