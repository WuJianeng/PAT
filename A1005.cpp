#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h>
//2018.12.28  21:55
char trans[10][8] = {"zero","one", "two", "three", "four", "five", "six", 
"seven", "eight", "nine"}; 
int fun(int N){
	while(N >= 10) N = N / 10;
	return N;
}
int fun1(int N){
	int num = 0;
	while(N >= 10){
		N = N /10;
		num++;
	}
	return num;
}
int main(){
	char N[105];
	scanf("%s",N);
	int i = 0,sum = 0;
	//sum
	while(N[i]){
		sum += N[i] - '0';
		i++;
	}
	//sum is below 1000;
	if(sum >= 100) printf("%s ", trans[sum / 100]);
	if(sum >= 10) printf("%s ", trans[sum/10 % 10]);
	printf("%s\n",trans[sum % 10]);
	return 0;
}
