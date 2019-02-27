#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
// 2019.1.16 10:50
using namespace std;
struct student{
	char ID[10];
	int de,cai,sum;
	int flag;
}stu[100005];
bool cmp(student A,student B){
	if(A.flag != B.flag){
		return A.flag < B.flag;
	}
	else if(A.sum != B.sum)
			return A.sum > B.sum;
		else if(A.de != B.de)
				return A.de > B.de;
			else return strcmp(A.ID,B.ID) < 0;
}
int main(){
	int N,L,H;
	scanf("%d%d%d",&N,&L,&H);
	int count = N;
	for(int i = 0; i < N; ++i){
		scanf("%s%d%d",stu[i].ID,&stu[i].de,&stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if(stu[i].de < L || stu[i].cai < L){
			stu[i].flag = 5;
			count--;
		}
			
		else if(stu[i].de >= H && stu[i].cai >= H)
			stu[i].flag = 1;
		else if(stu[i].de >= H )
			stu[i].flag = 2;
		else if(stu[i].de >= stu[i].cai)
			stu[i].flag = 3;
		else stu[i].flag = 4;
	}
	sort(stu,stu+N,cmp);
	printf("%d\n",count);
	for(int i = 0;i < count; i++)
	{
			printf("%s %d %d\n",stu[i].ID,stu[i].de,stu[i].cai);
	}
	return 0;
}
