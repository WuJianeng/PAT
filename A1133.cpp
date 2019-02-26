//2019/2/26 17:34
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 100500;
int n, k;
struct Node{
	int data, next;
}node[maxn];
vector<int> neg[3];
int main(){
	int st;
	scanf("%d %d %d", &st, &n, &k);
	for(int a = 0; a < n; ++a){
		int id;
		scanf("%d", &id);
		scanf("%d %d", &node[id].data, &node[id].next);
	}
	int id = st;
	while(id != -1){
		int data = node[id].data;
		if(data < 0) neg[0].push_back(id);
		else if(data <= k) neg[1].push_back(id);
		else neg[2].push_back(id);
		id = node[id].next;
	}
	for(int i = 0; i < neg[1].size(); ++i)
		neg[0].push_back(neg[1][i]);
	for(int i = 0; i < neg[2].size(); ++i)
		neg[0].push_back(neg[2][i]);
	for(int i = 0; i < neg[0].size(); ++i){
		id = neg[0][i];
		printf("%05d %d ", id, node[id].data);
		if(i == neg[0].size() - 1) printf("-1\n");
		else printf("%05d\n", neg[0][i + 1]);
	}
	return 0;
}
