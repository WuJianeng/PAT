//2019 2.9 16:45 forked from QingShenNotes
#include<cstdio>
#include<algorithm>
int seq[100010] = {0};
using namespace std;
int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq, seq + n);
	int count = 1;
	for(int i = 0; i < n; ++i){
		int j = upper_bound(seq + i + 1, seq + n, (long long)seq[i] * p ) - seq;
		count = max(count, j - i);
	}	
	printf("%d\n", count);
	return 0;
}
