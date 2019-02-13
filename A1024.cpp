//2019 2.13 16:07
#include<cstdio>
#include<cstring>
using namespace std;
void change(char *s, int *a, int len){
	for(int i = 0; i < len; ++i)
		a[i] = s[i] - '0';
}
bool verify(int *a, int len){
	for(int i = 0; i < len / 2; ++i)
		if(a[i] != a[len - i - 1]) return false;
	return true;
}
void reverse(int *a, int *b, int len){
	for(int i = 0; i < len; ++i)
		b[len - i - 1] = a[i];
}
void sum(int *a, int *b, int &len){
	int flag = 0;
	for(int i = len - 1; i >= 0; --i){
		a[i] += b[i] + flag;
		if(a[i] >= 10){
			flag = 1;
			a[i] -= 10;
		}
		else flag = 0;
	}
	if(flag == 0) return ;
	else{
		for(int i = len; i > 0; --i)
			a[i] = a[i - 1];
		a[0] = 1;
		len++;
		return ;
	}
}
int main(){
	char s[105];
	int a[105], b[105], n, count = 0;
	scanf("%s %d", s, &n);
	int len = strlen(s);
	change(s, a, len);
	while(n--){
		if( verify(a, len) ) break;
		count++;
		reverse(a, b, len);
		sum(a, b, len);
		if(verify(a, len)) break;
	}
	for(int i = 0; i < len; ++i)
		printf("%d", a[i]);
	printf("\n%d\n", count);
	return 0;
}
