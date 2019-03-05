//2019/3/5 16:15 
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000000];
int main(){
	int n, e = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	while(a[e] > e + 1) e++;
	printf("%d\n", e);
	return 0;
}
