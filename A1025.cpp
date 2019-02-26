//2019/2/26 9:49
#include<cstdio>
#include<algorithm>
using namespace std;
struct Stu{
	long long id;
	int grade, loc, rank, locRank;
}stu[30500];
const int maxn = 105;
int n, k[maxn];
bool cmp(Stu a, Stu b){
	if(a.grade != b.grade) return a.grade > b.grade;
	else return a.id < b.id;
}
bool cmpLoc(Stu a, Stu b){
	if(a.loc != b.loc) return a.loc < b.loc;
	else return a.grade > b.grade;
}
int main(){
	scanf("%d", &n);
	int count = 0, num = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &k[i]);
		num += k[i];
		for(int j = 0; j < k[i]; ++j){
			scanf("%lld %d", &stu[count].id, &stu[count].grade);
			stu[count].loc = i;
			count++;
		}
	}
	sort(stu, stu + num, cmpLoc);
	stu[0].locRank = 1;
	int locNum = 0;
	for(int i = 1; i < num; ++i){
		if(stu[i].loc == stu[i - 1].loc){
			locNum++;
			if(stu[i].grade == stu[i - 1].grade) stu[i].locRank = stu[i - 1].locRank;
			else stu[i].locRank = locNum + 1;
		}
		else{
			locNum = 0;
			stu[i].locRank = 1;
		} 
	}
	sort(stu, stu + num,cmp);
	printf("%d\n", num);
	stu[0].rank = 1;
	for(int i = 1; i < num; ++i)
		if(stu[i].grade == stu[i - 1].grade) stu[i].rank = stu[i - 1].rank;
		else stu[i].rank = i + 1;
	for(int i = 0; i < num; ++i)
		printf("%lld %d %d %d\n", stu[i].id, stu[i].rank ,stu[i].loc, stu[i].locRank);
}
