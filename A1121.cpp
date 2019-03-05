//2019/3/5 19:45
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
const int maxn = 100050;
int couple[maxn];
int main(){
	int n, m;
	scanf("%d", &n);
	fill(couple, couple + maxn, -1);
	for(int i = 0; i < n; ++i){
		int idA, idB;
		scanf("%d %d", &idA, &idB);
		couple[idA] = idB;
		couple[idB] = idA;
	}
	scanf("%d", &m);
	set<int> st;
	for(int i = 0; i < m; ++i){
		int id;
		scanf("%d", &id);
		st.insert(id);
	}
	vector<int> v;
	while(!st.empty()){
		set<int>::iterator it = st.begin();
		int id = *it;
		if(couple[id] == -1)
			v.push_back(id);
		else{
			int idB = couple[id];
			if(st.find(idB) == st.end())
				v.push_back(id);
			else st.erase(st.find(idB));
		}
		st.erase(it);
	}
	printf("%d\n", (int)v.size());
	for(int i = 0; i < (int)v.size(); ++i){
		if(i) printf(" ");
		printf("%05d", v[i]);
	}
	return 0;
}
