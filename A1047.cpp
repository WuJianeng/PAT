//2019 2.13 20:30
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int stu = 40100;
char name[stu][8];
vector<int> course[2510];
bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
}
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%s %d", name[i], &temp);
		for(int j = 0; j < temp; j++){
			int temp1;
			scanf("%d", &temp1);
			course[temp1].push_back(i);
		}
	}
	for(int i = 1; i <= k; i++){
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++)
			printf("%s\n", name[ course[i][j] ]);	
	}
	return 0;
}
