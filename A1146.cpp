//2019/3/1 14:18
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1005;
struct Node{
	vector<int> next;
	int pre, topSort;
}node[maxn];
int n, m;
int main(){
	//initial
	for(int i = 0; i <= maxn; ++i)
		node[i].pre = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int st, end;
		scanf("%d %d", &st, &end);
		node[st].next.push_back(end);
		node[end].pre++;
	}
	int k;
	scanf("%d", &k);
	int count = 0;
	vector<int> print;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j <= n; ++j){
			node[j].topSort = node[j].pre;

		}
		vector<int> sort;
		sort.clear();
		for(int j = 0; j < n; ++j){
			int temp;
			scanf("%d", &temp);
			sort.push_back(temp);
		}
		for(int j = 0; j < n; ++j){
			int temp = sort[j];
			if(node[temp].topSort != 0){
				print.push_back(i);
				break;
			}
			else{
				for(int v = 0; v < node[temp].next.size(); ++v){
					int id = node[temp].next[v];
					node[id].topSort--;
				}
			}
		}
	}
	for(int i = 0; i < print.size(); ++i){
		if(i != 0) printf(" ");
		printf("%d", print[i]);
	}
	printf("\n");
	return 0;
}
