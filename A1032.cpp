//2019/2/26 11:08
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100500;
struct Data{
	char data;
	int next;
	bool flag;
}data[maxn];
int main(){
	int st1, st2, n;
	scanf("%d %d %d", &st1, &st2, &n);
	for(int i = 0; i < n; ++i){
		int address;
		scanf("%d", &address);
		scanf(" %c %d", &data[address].data, &data[address].next);
	}
	for(int i = 0; i < maxn; ++i)
		data[i].flag = false;
	int id = st1;
	while(id != -1){
		data[id].flag = true;
		id = data[id].next;
	}
	id = st2;
	while(id != -1){
		if(data[id].flag == true) break;
		else id = data[id].next;
	}
	if(id == -1) printf("-1\n");
	else printf("%05d\n", id);
	return 0;
}
