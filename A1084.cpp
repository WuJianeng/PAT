//2019.2.8 19:30
#include<iostream>
#include<cstring>
int tag[400] ={0};
using namespace std;
int main(){
	char test_in[100],test_out[100];
	scanf("%s\n%s", test_in, test_out);
	int ln1 = strlen(test_in);
	int ln2 = strlen(test_out);
	for(int i = 0; i < 400; ++i)
		tag[i] = 0;
	int s1, s2 = 0;
	for(s1 = 0; s1 < ln1; s1++){
		if(test_in[s1] <= 'z' && test_in[s1] >= 'a') test_in[s1] += 'A' - 'a';
		if(test_out[s2] <= 'z' && test_out[s2] >= 'a') test_out[s2] += 'A' - 'a';
		if(test_in[s1] == test_out[s2]) s2++;
		else{
			unsigned int num = (unsigned int)test_in[s1];
			if(tag[num] == 0){
				tag[num] = 1;
				printf("%c", test_in[s1]);
			}
		}
	}
	printf("\n");
	return 0;
}
