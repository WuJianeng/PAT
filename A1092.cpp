//2019.2.8 20:00
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char owner[1010],eva[1010];
int main(){
	scanf("%s\n%s", owner, eva);
	int ln1 = strlen(owner);
	int ln2 = strlen(eva);
	map<char, int> mp1;
	map<char, int> mp2;
	map<char, int>::iterator it;
	for(int i = 0; i < ln1; ++i){
		if(mp1.find( owner[i]) == mp1.end()) mp1[ owner[i] ] = 1;
		else mp1[ owner[i] ] ++;
	}
	for(int i = 0; i < ln2; ++i){
		if(mp2.find( eva[i]) == mp2.end()) mp2[ eva[i] ] = 1;
		else mp2[ eva[i] ] ++;
	}
	int count = 0, tag = 1;
	//judge "Yse" or "No"
	for(it = mp2.begin(); it != mp2.end(); ++it){
		if(it->second > mp1[ it ->first ] ){
			tag = 0;
			break;
		} 
		else mp1[ it->first] = mp1[ it->first ] - it->second;
	}
	if(tag == 0){
		for(it = mp2.begin(); it != mp2.end(); ++it){
			if(it->second > mp1[ it ->first ] ){
				count += it->second - mp1[ it ->first ];
			}
		}
		printf("No %d", count);
	}
	else{
		count = ln1 - ln2;
		printf("Yes %d", count);
	}
	return 0;
}
