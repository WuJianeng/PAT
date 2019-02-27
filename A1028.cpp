//2019.2.6 21:50
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int flag = 0;
struct Student{
	char name[10];
	int id;
	int grade;
}stu[100005];
bool cmp(Student a,Student b){
	if(flag == 1)
		return a.id < b.id;
	else if(flag == 2){
		int f = strcmp(a.name, b.name);
		if(f != 0) return f < 0;
		else return a.id < b.id;
	}
	else{
		if(a.grade != b.grade) return a.grade < b.grade;
		else return a.id < b.id;
	}
}
int main(){
	int n;
	scanf("%d %d",&n,&flag);
	for(int i = 0; i < n; ++i){
		scanf("%d %s %d",&stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + n,cmp);
	for(int i = 0; i < n; ++i){
		printf("%06d %s %d\n",stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
