#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MaxVertex = 105;//最大村庄数
ll maxnum = 100005;//一个较大的数字
bool isvisited[MaxVertex];//是否已经被连通村庄
int len[MaxVertex][MaxVertex];//交通图
int cnt = 0;//存轮数
struct school
{
	int v;
	int length;
}sc[MaxVertex];
bool cmp(school a, school b)
{
	return a.length < b.length;
}
class Village
{
public:
	Village();
	void getschool();
	void Dijkstra(int v);
	int findvillage(int dist[],int a);
private:
	int vexnum;
};
Village::Village()
{
	for (int i = 0; i < MaxVertex; i++)
	{
		for (int j = 0; j < MaxVertex; j++)
		{
			len[i][j] = maxnum;
		}
	}
	int n, q;
	cout << "请输入村庄的数目：";
	cin >> vexnum;
	//输入边距
	cout << "请输入要录入交通图信息个数:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cout << "请输入三个整数分别代表i村庄到j村庄的距离:";
		cin >> a >> b >> c;
		if (a<0 || a>vexnum || b<0 || b>vexnum)
		{
			cout << "非法输入，请重新输入……" << endl;
			return;
		}
		len[a][b] = c;
		len[b][a] = c;
	}
	for(int i=1;i<=vexnum;i++)
		Dijkstra(i);
}
int Village::findvillage(int dist[],int a)
{
	int index_min = 0;
	ll min = maxnum;
	for (int i = 1; i <= vexnum; i++)
	{
		if (dist[i] < min and !isvisited[i])
		{
			min = dist[i];
			index_min = i;
		}
	}
	return index_min;
}

void Village::Dijkstra(int v)
{
	int dist[MaxVertex];
	memset(dist, 10005, sizeof(dist));
	isvisited[v] = 1;
	//记录结点到其余村庄的距离
	for (int i = 1; i <= vexnum; i++)
	{
		if (i != v)
		{
			dist[i] = len[v][i];
		}
	}
	int k,min = v;
	for (int num = 1; num < vexnum; num++)
	{
		k = findvillage(dist,min);
		isvisited[k] = 1;
		for (int i = 1; i <= vexnum; i++)
		{
			if (dist[i] > len[k][i] && !isvisited[i])
			{
				dist[i] = len[k][i] + len[min][i];
			}
		}
		k = min;
	}
	
	int sum = 0;
	for (int i = 1; i <= vexnum; i++)
	{
		if (i!=v)
		{
			sum += dist[i];
		}
	}
	sc[cnt].v = v;
	sc[cnt].length = sum;
	cnt++;
}
void Village::getschool()
{
	sort(sc, sc + cnt, cmp);
	cout << "选择在 v" << sc[0].v << " 村庄建一所学校，该选址能使得所有村庄到学校路程最小" << endl;
}

void menu()
{
	cout << "/****************************************/" << endl;
	cout << "\t\t第二题：学校选址\t\t" << endl;
	cout << "/****************************************/" << endl;
}
int main()
{
	Village v;
	v.getschool();

	return 0;
}

