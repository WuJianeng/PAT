//并查集，还不会 
//2019/3/5 15:00
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10500;
int n;
vector<int> v[maxn];
int estate[maxn][2];
int min[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int id, father, mother, k;
		scanf("%d %d %d %d", &id, &father, &mother, &k);
		if(father != -1) v[id].push_back(father);
		if(mother != -1) v[id].push_back(mother);
		for(int j = 0; j < k; ++j){
			int child;
			scanf("%d", &child);
			v[id].push_back(child);
		}
		scanf("%d %d", &estate[id][0], &estate[id][1]);
	}
	for(int i = 0; i < maxn; ++i)
		min[maxn] = i;
	for(int i = 0; i < n; ++i){
		
	}
	return 0;
}
