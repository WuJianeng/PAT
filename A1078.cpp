//2019.2.13 14:14
#include<cstdio>
using namespace std;
bool a[10010] = {false};
bool isPrime(int n){
	if(n == 1) return false;
	for(int i = 2; i< n; ++i)
		if(n % i == 0) return false;
	return true;
}
int insert(int temp, bool a[], int max){
	int key = temp % max;
	for(int i = 1; i <= max && key < max; ++i){
		if(a[key] == false){
			a[key] = true;
			return key;
		}
		key = (temp + i * i) % max;
	}
	return -1;
}
int main(){
	int n, Msize;
	scanf("%d %d", &Msize, &n);
	while(isPrime(Msize) == false) Msize++;
	//insert
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		if(i != 0) printf(" ");
		temp = insert(temp, a, Msize);
		if(temp == -1) printf("-");
		else printf("%d", temp);
	}
	printf("\n");
	return 0;
}
