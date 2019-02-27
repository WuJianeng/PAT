#include<iostream>
using namespace std;
#include<cstdio>

struct Poly{
	int exp;
	double cof;
}poly[2001];

double _cof[2001];
int main(){
	int n,i,j,num,count = 0;
	scanf("%d",&n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	}
	for(i = 0; i < 2001; ++i)
		_cof[i] = 0;
	int exp;
	double cof;
	scanf("%d",&num);
	for(i = 0; i < num; ++i)
	{
		scanf("%d %lf",&exp,&cof);
		for(j = 0; j < n; ++j)
		{
			_cof[exp + poly[j].exp] += cof * poly[j].cof;
		}
	}
	for(i = 0; i < 2001; i++)
	{
		if(_cof[i] != 0) count++;
	}
	printf("%d",count);
	for(i = 2000; i >= 0; i--)
	{
		if(_cof[i] != 0) printf(" %d %.1f", i, _cof[i]);
	}
	
	return 0;
}
