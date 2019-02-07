//2019.2.6 22:19
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Man{
	char name[10];
	int age,worth;
}man[maxn];

bool cmp(Man a, Man b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else  return strcmp(a.name, b.name) < 0;
}


int main(){
	//input
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 0; i < m; ++i){
		scanf("%s %d %d", man[i].name, &man[i].age, &man[i].worth);
	}
	sort(man, man + m, cmp);
	for(int i = 0; i < n; ++i){
		int num, age_low, age_high;
		scanf("%d %d %d", &num, &age_low, &age_high);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for(int j = 0; j < m; j++){
			if(man[j].age >= age_low && man[j].age <= age_high && count < num){
				count++;
				printf("%s %d %d\n", man[j].name, man[j].age, man[j].worth);
			} 
		}
		if(count == 0) printf("None\n");
	}
	
	return 0;
}
