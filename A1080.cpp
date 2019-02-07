//2019.2.7 19:45
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct Stu{
	int ge, gi,id;
	double ga;
	int sch[5];
}stu[40010];
bool cmp(Stu a, Stu b){
	if(a.ga != b.ga) return a.ga > b.ga;
	else return a.ge > b.ge;
}
int main(){
	int n, m, k;//appplication: n  Schools: m  Choice: k
	scanf("%d %d %d", &n, &m, &k);
	int quota[105],Score_e[105];
	double Score_a[105];
	for(int i = 0; i < m; ++i){
		scanf("%d", &quota[i]);
		Score_a[i] = 0;
		Score_e[i] = 0;
	}
	for(int i = 0; i < n; ++i){
		stu[i].id = i;
		scanf("%d %d", &stu[i].ge, &stu[i].gi);
		stu[i].ga = (stu[i].gi + stu[i].ge ) / 2.0; 
		for(int j = 0; j < k; ++j){
			scanf("%d", &stu[i].sch[j]);
		}
	}
	//sort
	sort(stu, stu + n, cmp);
	set<int>  s[105];
	set<int>::iterator it;
	
	//chose student
	int temp = stu[0].sch[0];
	s[temp].insert(stu[0].id);
	Score_a[temp] = stu[0].ga;
	Score_e[temp] = stu[0].ge;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < k; j++){
			int sch = stu[i].sch[j];
			if(s[sch].size() < quota[sch]) {
				Score_a[sch] = stu[i].ga;
				Score_e[sch] = stu[i].ge;
				s[sch].insert(stu[i].id);
				break;
			}
			else if(stu[i].ga == Score_a[sch] && stu[i].ge == Score_e[sch]){
				s[sch].insert(stu[i].id);
				break;
			}	
		}
	}
	//output
	for(int i = 0; i < m; ++i){
		if(s[i].size()){
			for(it = s[i].begin(); it != s[i].end(); it++){
				if(it != s[i].begin()) printf(" ");
				printf("%d", *it);
			}
		}
		printf("\n");
	}
	return 0;
}
