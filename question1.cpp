#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int vertexnum = 5;
bool visit[6];
int adjlist[6][6];
int rudu[6];//入度数
string workname[6] = { "","XMedia","XMedia.Controllers","XMedia.Models","XMedia.Logics","XMdia.Commons" };
int cn = 0;//记录轮次
int que[6];//入度为0的队列
int ans[6];
bool f = 1;
class Work
{
public:
	Work();
	void TopSort();
};
Work::Work()
{
	//初始化入度数
	adjlist[1][1] = 3;
	adjlist[1][2] = 4;
	adjlist[1][3] = 5;
	adjlist[2][1] = 1;
	adjlist[2][2] = 2;
	adjlist[2][3] = 3;
	adjlist[2][4] = 4;
	adjlist[2][5] = 5;
	adjlist[4][1] = 3;
	adjlist[4][2] = 5;
}
void Work::TopSort()
{
	rudu[1] = 3;
	rudu[2] = 4;
	rudu[3] = 0;
	rudu[4] = 2;
	rudu[5] = 0;
	cn++;
	int ccnt = 1;
	int head=0, rear=0;//队列头尾指针
	int n = 0;
	memset(visit, false, sizeof(visit));
	while(n!= vertexnum)
	{
		n++;
		if (f)
		{
			for (int j = 1; j <= vertexnum; j++)
			{
				if (rudu[j] == 0 && !visit[j])
				{
					que[rear++] = j;
					visit[j] = true;
				}
			}
		}
		else
		{
			for (int j = vertexnum; j >=1; j--)
			{
				if (rudu[j] == 0 && !visit[j])
				{
					que[rear++] = j;
					visit[j] = true;
				}
			}
		}
		int p = que[head++];
		for (int k = 1; k <= vertexnum; k++)
		{
			for (int s = 1; s <= vertexnum; s++)
			{
				if (adjlist[k][s] == p)
				{
					rudu[k]--;
				}
				else if (adjlist[k][s] == 0)break;
			}
		}
	
	}
	cout << "The " << cn << " :";
	for (int i = 0; i < vertexnum; i++)
	{
		if (i == 0)cout << workname[que[i]];
		else cout << " -> " << workname[que[i]];
	}
	cout << endl;
	f = 0;
}
void menu()
{
	cout << "/****************************************/" << endl;
	cout << "\t\t第一题：项目编译次序\t\t" << endl;
	cout << "/****************************************/" << endl;
}
int main()
{
	menu();
	cout << endl;
	Work w;
	w.TopSort();
	cout << endl;
	w.TopSort();


	return 0;
}

