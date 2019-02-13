//2019 2.13 21:09
#include<cstdio>
#include<set>
using namespace std;
set<int> s[51];
void compare(int fir, int sec){
		int count_all = s[fir].size() + s[sec].size();
		int count_and = 0;
		set<int>::iterator it;
		for(it = s[fir].begin(); it != s[fir].end(); it++)
			if(s[sec].find(*it) != s[sec].end()) count_and++;
		double res = count_and * 1.0 / (count_all - count_and) ;
		res = res * 100;
		printf("%.1f\%\n", res);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			int temp;
			scanf("%d", &temp);
			s[i].insert(temp);
		}
	}	
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int fir, sec;
		scanf("%d %d", &fir, &sec);
		compare(fir, sec);
	}
	return 0;
}
