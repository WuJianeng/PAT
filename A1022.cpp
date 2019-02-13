//2019 2.13 23:50
#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map<string, set<int> > &mp, string &str){
	if(mp.find(str) == mp.end()) printf("Not Found\n");
	else 
	for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
		printf("%07d\n", *it);
}
int main(){
	int n, m, id, type;
	string str;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		string str;
		scanf("%d", &id);
		getchar();
		getline(cin, str);
		title[str].insert(id);
		getline(cin, str);
		author[str].insert(id);
		while(true){
			cin>>str;
			char c = getchar();
			key[str].insert(id);
			if(c == '\n') break;
		}
		getline(cin, str);
		pub[str].insert(id);
		getline(cin, str);
		year[str].insert(id);		
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d: ", &type);
		getline(cin, str);
		cout<<type<<": "<<str<<endl;;
		if(type == 1) query(title, str);
		else if(type == 2) query(author, str);
		else if(type == 3) query(key, str);
		else if(type == 4) query(pub, str);
		else if(type == 5) query(year, str);
	}
	return 0;
}
