#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct People
{
	int toward;
	char name[15];
	int ID;
}p[100000];
struct Cmd
{
	int turn;
	int step;
}c[100000];
int main()
{
	int n,m,i,j;
	int origin=0;
	cin>>n>>m;
	
	for(i=0;i<=n-1;i++)
	{
		cin>>p[i].toward;
		cin>>p[i].name;
		p[i].ID=i;
	}
	for(j=0;j<=m-1;j++)
	{
		cin>>c[j].turn;
		cin>>c[j].step;
	}
	for(int k=0;k<=m-1;k++)
	{
		switch(c[k].turn)
		{
			case 0:
				switch(p[origin].turn)
				{
					case 0:
						origin=origin-c[k].step;
						if(origin<0)
						{
							origin+=n;
						}
						break;
					case 1:
						origin=origin+c[k].step;
						if(origin>=n)
						{
							origin-=n;
						}
						break;
				}
				break;
			case 1:
				switch(p[origin].turn)
				{
					case 0:
						origin=origin+c[k].step;
						if(origin>=n)
						{
							origin-=n;
						}
						break;
					case 1:
						origin=origin-c[k].step;
						if(origin<0)
						{
							origin+=n;
						}
						break;
				}
				break;
		}
	}
	cout<<p[origin].name<<endl;
	system("pause");
    return 0;
} 
