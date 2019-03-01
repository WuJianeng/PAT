//2019/3/1 16:50
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 100500;
int n, m;
vector<int> inc[maxn], list;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		int good1, good2;
		scanf("%d %d", &good1, &good2);
		inc[good1].push_back(good2);
		inc[good2].push_back(good1);
	}
	for(int i = 0; i < m; ++i){
		int k;
		scanf("%d", &k);
		list.clear();
		for(int i = 0; i < k; ++i){
			int temp;
			scanf("%d", &temp);
			list.push_back(temp);
		}
		int flag = true;
		for(int i = 0; i < list.size(); ++i){
			for(int j = i + 1; j < list.size(); ++j){
				int st = list[i], end = list[j];
				for(int t = 0; t < inc[st].size(); ++t){
					if(inc[st][t] == end){
						flag = false;
						break;
					}
				}
				if(flag == false) break;
			}
			if(flag == false) break;
		}
		if(flag == false) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
