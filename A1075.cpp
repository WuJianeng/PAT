//2019.02.07 16:20
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct User{
	int id;//5 digits
	int total_score;
	int s[6];//1 ~k
	int per;
	int tag;
}user[10005];
bool cmp(User a, User b){
	if(a.total_score != b.total_score) return a.total_score > b.total_score;
	else if(a.per != b.per) return a.per > b.per;
	else return a.id < b.id;
}
int main(){
	int n,k,m;
	scanf("%d %d %d", &n, &k, &m);
	int Score[6];
	for(int i = 1; i <= k; ++i){
		scanf("%d",&Score[i]);
	}
	int id, num, sco;
	for(int i = 1; i <= n; ++i){
		user[i].id = i;
		user[i].per = 0;
		user[i].total_score = 0;
		user[i].tag = 0;
		for(int j = 1; j <= k; j++){
			user[i].s[j] = -2;
		}
	}
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d", &id, &num, &sco);
		user[id].s[num] = user[id].s[num] < sco?sco: user[id].s[num];
		if(user[id].s[num] >= 0) user[id].tag = 1;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; j++){
			if(user[i].s[j] > 0)
				user[i].total_score += user[i].s[j];
			if(user[i].s[j] == Score[j]) user[i].per++;
		}
	}
	sort(user+1, user + n + 1, cmp);
	int rank = 1;
	printf("%d %05d %d", rank, user[1].id, user[1].total_score);
	for(int i = 1; i <= k; ++i){
		if(user[1].s[i] == -2) printf(" -");
		else if(user[1].s[i] <= 0) printf(" 0");
		else printf(" %d", user[1].s[i]);
	}
	printf("\n");
	for(int i = 2; i <= n; ++i){
		if(user[i].total_score == 0 && user[i].tag == 0) continue;
		if(user[i].total_score != user[i - 1].total_score)
			rank = i;
		printf("%d %05d %d", rank, user[i].id, user[i].total_score);
		for(int j = 1; j <= k; ++j){
			if(user[i].s[j] == -2) printf(" -");
			else if(user[i].s[j] <= 0) printf(" 0");
			else printf(" %d", user[i].s[j]);
		}
		printf("\n");
	}
	return 0;
}
