//2019.2.11 15:05
#include<cstdio>
#include<algorithm>
int s[400050];
using namespace std;
int main(){
	int n, n1, n2, i;
	scanf("%d", &n1);
	for(i = 0; i < n1; ++i)
		scanf("%d", &s[i]);
	scanf("%d", &n2);
	n = n1 + n2;
	for(; i < n; ++i)
		scanf("%d", &s[i]);
	sort(s, s + n);
	int mid = (n + 1) / 2;
	printf("%d\n", s[mid - 1]);
	return 0;	
}
