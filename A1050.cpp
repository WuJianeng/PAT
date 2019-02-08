//2019.2.8 20:58
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char str1[10010], str2[10010];
bool tag[500] = {false};
int main(){
	cin.getline(str1,10010);
	cin.getline(str2,10010);
	int ln1 = strlen(str1), ln2 = strlen(str2);
	for(int i = 0; i < ln2; ++i){
		tag[ str2[i] ] = true;
	}
	for(int i = 0; i < ln1; ++i){
		if(tag[ str1[i] ] == false) printf("%c", str1[i]);
	}
	return 0;
}
