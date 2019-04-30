//2019 4/30 14:40
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int l, k;
const int len = 1005;
const long long maxn = 10000005;
char s[len];
bool isPrim[maxn];
long long tran(int place){
	long long ans = 0;
	for(int i = 0; i < k; ++i){
		ans = ans * 10 + s[place + i] - '0';
	}
	return ans;
}
int main(){
	scanf("%d %d", &l, &k);
	scanf("%s", s);
	fill(isPrim, isPrim + maxn, true);
	isPrim[0] = isPrim[1] = false;
	for(long long i = 2; i < maxn; ++i){
		if(isPrim[i] == false) continue;
		for(long long j = i * 2; j < maxn; j = j + i){
			isPrim[j] = false;
		}
	}
	int i;
	for(i = 0; i < l - k; ++i){
		long long num = tran(i);
		if(isPrim[num]){
			printf("%lld\n", num);
			break;
		}
	}
	if(i == l - k) printf("404\n");
	return 0;
}
