//2019/3/1 21:31
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 305;
int n, m, k;
struct Node{
	int a, b;
};
vector<int> rel[10050];
vector<Node> s;
bool cmp(Node a, Node b){
	if(a.a != b.a) return a.a < b.a;
	else return a.b < b.b; 
}
void print(int a, int b){
	s.clear();
	for(int i = 0; i < rel[abs(a)].size(); ++i){
		int aFri = rel[abs(a)][i];
		if(aFri * a < 0 || aFri == b) continue;
		for(int j = 0; j < rel[abs(b)].size(); ++j){
			int id = rel[abs(b)][j];
			if(b * id < 0 || id == a) continue;
			vector<int>::iterator it = find(rel[abs(aFri)].begin(), rel[abs(aFri)].end(), id);
			if(it != rel[abs(aFri)].end()){
				Node root;
				root.a = abs(aFri);
				root.b = abs(id);
				s.push_back(root);
			}	 
		}
	}
	sort(s.begin(), s.end(), cmp);
	printf("%d\n", s.size());
	for(int i = 0; i < s.size(); ++i)
		printf("%d %d\n", s[i].a, s[i].b);
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int pair1, pair2;
		scanf("%d %d", &pair1, &pair2);
		rel[abs(pair1)].push_back(pair2);
		rel[abs(pair2)].push_back(pair1);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++k){
		int pair1, pair2;
		scanf("%d %d", &pair1, &pair2);
		print(pair1, pair2);
	}
	return 0;
}
