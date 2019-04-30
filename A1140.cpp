//2019 4/30 
#include<cstdio>
#include<vector>
using namespace std;
vector<int> fir, sec;
void change(){
	int pre = fir[0], num = 0;
	sec.clear();
	for(int i = 0; i <= fir.size(); ++i){
		if(i == fir.size()){
			sec.push_back(pre);
			sec.push_back(num);
			break;
		}
		if(fir[i] != pre) {
			sec.push_back(pre);
			sec.push_back(num);
			pre = fir[i];
			num = 0;
			i--;
		}
		else num++;
	}
	fir.clear();
	fir.assign(sec.begin(), sec.end());
}
int main(){
	int d, n;
	scanf("%d %d", &d, &n);
	fir.push_back(d);
	for(int i = 1; i < n; ++i){
		change();
	}
	for(int i = 0; i < fir.size(); ++i){
		printf("%d", fir[i]);
	}
	printf("\n");
	return 0;
}
