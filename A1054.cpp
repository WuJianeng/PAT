//2019 2.13 22:57
#include<cstdio>
#include<map>
using namespace std;
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	map<int, int> mp;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			int temp;
			scanf("%d", &temp);
			if(mp.find(temp) == mp.end()) mp[temp] = 1;
			else mp[temp]++;
		}
	int s = m * n / 2;
	map<int, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
		if(it->second > s) printf("%d\n", it->first);
	return 0;
}
