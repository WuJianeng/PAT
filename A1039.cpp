//2019 2.13 19:50
//不需要每次都排序，只需要在插入结束之后排序依次即可。 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> stu[maxn];
int getID(char *name){
	int id = 0;
	for(int i = 0; i < 3; ++i)
		id  = id * 26 + name[i] - 'A';
	id = id * 10 + name[3] - '0';
	return id;
}
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; ++i){
		int index, num;
		char name[8];
		scanf("%d %d", &index, &num);
		for(int j = 0; j < num; ++j){
			scanf("%s", name);
			int id = getID(name);
			stu[id].push_back(index);
		}
	}
	for(int i = 0; i < n; ++i){
		char name[8];
		scanf("%s", name);
		int id = getID(name);
		printf("%s %d", name, stu[id].size());
		sort(stu[id].begin(), stu[id].end());
		vector<int>::iterator it;
		for(it = stu[id].begin(); it != stu[id].end(); ++it)
			printf(" %d", *it);
		printf("\n");
	}
	return 0;
}
