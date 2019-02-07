//2019.2.7 18:08
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu{
	char name[15],id[15];
	int grade;
}stu[1000000];
bool cmp(Stu a, Stu b){
	return a.grade > b.grade;
}
int main(){
	int n;
	scanf("%d",&n);
	char name[15],id[15];
	int grade;
	for(int i = 0; i < n; ++i){
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	sort(stu, stu + n, cmp);
	int low,high,tag = 0;
	scanf("%d %d", &low, &high);
	for(int i = 0; i < n; ++i){
		if(stu[i].grade <= high && stu[i].grade >= low){
			tag = 1;
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	if(tag == 0) printf("NONE\n");
	return 0;
}
