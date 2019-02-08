//2019.2.8 21:42
#include<cstdio>
#include<algorithm>
using namespace std;
struct Mooncake{
	double price, All_price,sto;
}moon[1010];
bool cmp(Mooncake a, Mooncake b){
	return a.price > b.price;
}
int main(){
	int n;
	double need;
	scanf("%d %lf", &n, &need);
	for(int i = 0; i < n; ++i)
		scanf("%lf", &moon[i].sto);		
	for(int i = 0; i < n; ++i){
		scanf("%lf", &moon[i].All_price);
		moon[i].price = moon[i].All_price / moon[i].sto;
	}
	sort(moon, moon + n, cmp);
	double profit = 0;//save 2 decimal digits
	for(int i = 0; need > 0 && i < n; i++)
		if(moon[i].sto <= need) {
			profit += moon[i].All_price;
			need -= moon[i].sto;
		}
		else {
			profit += need * moon[i].price;
			need = 0;
		}
	printf("%.2f\n", profit);
	return 0;	
}
