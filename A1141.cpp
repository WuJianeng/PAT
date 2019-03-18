#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 100005;
map<string, int> mp;
set<string> s[maxn];
string tran(string name){
	int len = name.size();
	for(int i = 0; i < len; ++i){
		if(name[i] <= 'Z' && name[i] >= 'A') 
			name[i] = name[i] - 'A' + 'a';
	}
	return name;
}
struct Ins{
	string sch;
	double tws;
	int ns;
}ins[maxn];
void fun(string id, double score, string school){
	 int num = mp[school];
	 ins[num].sch = school;
	 if(id[0] == 'B') score = score * 1.0 / 1.5;
	 else if(id[0] == 'T') score = score * 1.5;
	 id.erase(id.begin());
	 ins[num].tws += score;
	 if(s[num].find(id) == s[num].end()){
	 	s[num].insert(id);
	 	ins[num].ns++;
	 } 
}
bool cmp(Ins a, Ins b){
	if(a.tws != b.tws) return a.tws > b.tws;
	else if(a.ns != b.ns) return a.ns < b.ns;
	else return a.sch < b.sch;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < maxn; ++i){
		ins[i].ns = 0;
		ins[i].tws = 0;
	}
	int seq = 0;
	for(int i = 0; i < n; ++i){
		double score;
		string id, school;
		cin>>id>>score>>school;
		school = tran(school);
		if(mp.find(school) == mp.end()) mp[school] = seq++;
		fun(id, score, school);
	}
	for(int i = 0; i < maxn; ++i)
		ins[i].tws = int(ins[i].tws);
	sort(ins, ins + seq, cmp);
	cout<<seq<<endl;
	int rank = 1, tws = ins[0].tws;
	for(int i = 0; i < seq; ++i){
		if(ins[i].tws != tws){
			tws = ins[i].tws;
			rank = i  + 1;
		}
		cout<<rank<<" "<<ins[i].sch<<" "<<ins[i].tws<<" "<<ins[i].ns<<endl;
	}
	return 0;
} 
