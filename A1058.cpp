#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
#include<math.h>
//2018.12.28 09:51
int main()
{
	int Ga1,Ga2,Si1,Si2,Kn1,Kn2;
	scanf("%d.%d.%d %d.%d.%d",&Ga1,&Si1,&Kn1,&Ga2,&Si2,&Kn2);
	if(Kn1 + Kn2 >= 29) Si1++;
	Kn1 = (Kn1 + Kn2) % 29;
	Ga1 += (Si1 + Si2) / 17;
	Si1 = (Si1 + Si2) % 17;
	Ga1 += Ga2;
	printf("%d.%d.%d\n", Ga1, Si1, Kn1);
	return 0;
}
