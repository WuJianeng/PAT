#include <iostream>
using namespace std;
#include<math.h>
int main() 
{
	int A,B,sum;
	scanf("%d%d",&A,&B);
	sum = A + B;
	if(sum < 0) printf("-");
	sum = abs(sum);
	if(sum >= 1000000 ) 
		printf("%d,%03d,%03d",sum/1000000,sum%1000000/1000,sum%1000);
	else if(sum >= 1000)
			printf("%d,%03d",sum/1000,sum%1000);
		else 
			printf("%d",sum);
	return 0;
}
