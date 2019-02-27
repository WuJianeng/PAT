#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>

//2018.12.17 19:57
struct People{
	char Name[15];
	char gender;
	char ID[15];
	int grade;
	bool tag = false;
}male,female,temp;
int main()
{
	int N;
	scanf("%d",&N);
	male.grade = 100;
	female.grade = 0;
	for(int i = 0; i < N; ++i)
	{
		scanf("%s %c %s %d",temp.Name,&temp.gender,temp.ID,&temp.grade);
		if(temp.gender == 'M')
		{
			if(temp.grade <= male.grade)
			{
				male = temp;
				male.tag = true;
			}
		}
		else if(temp.gender == 'F')
		{
			if(temp.grade >= female.grade)
			{
				female = temp;
				female.tag = true;
			}
		}
	}
	if(male.tag&&female.tag)
		printf("%s %s\n%s %s\n%d\n",female.Name,female.ID,male.Name,male.ID,(female.grade - male.grade));
	else if(male.tag)
	{
		printf("Absent\n%s %s\nNA\n",male.Name,male.ID);
	}
	else if(female.tag)
	{
		printf("%s %s\nAbsent\nNA\n",female.Name,female.ID);
	}
	else printf("Absent\nAbsent\nNA\n");
}

