#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MaxVertex = 105;//最大村庄数
ll maxnum = 100005;//一个较大的数字
bool isvisited[MaxVertex];//是否已经被连通村庄
int lower[MaxVertex];//最短距离数组
int parent[MaxVertex][MaxVertex];//起点坐标
int shortans[MaxVertex];//每轮计算出的村庄
ll build_ans = 0;//需要修建长度
int cnt = 0;//存轮数
class Village
{
public:
	Village();
	void getshort();
	int findvillage(int a);
	void getline();
private:
	int len[MaxVertex][MaxVertex];
	int vexnum;
};
Village::Village()
{
	int n, q;
	cout << "请输入村庄的数目：";
	cin >> vexnum;
	//输入边距
	for (int i = 1; i <= vexnum * (vexnum - 1) / 2; i++)
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
	for (int i = 1; i <= vexnum; i++) { len[i][i] = 0; }

	//连通道路之间距离变为0
	cout << "请输入一个整数代表村庄已经修建了多少条路：";
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cout << "请输入两个整数代表村庄a和村庄b已经新建了路：";
		cin >> a >> b;
		if (a<0 || a>vexnum || b<0 || b>vexnum)
		{
			cout << "非法输入，请重新输入……" << endl;
			return;
		}
		len[a][b] = len[b][a] = 0;
	}
}
int Village::findvillage(int a)
{
	int index_min = 0;
	ll min = maxnum;
	for (int i = 1; i <= vexnum; i++)
	{
		if (lower[i] < min and !isvisited[i])
		{
			min = lower[i];
			index_min = i;
		}
	}
	return index_min;
}
void Village::getshort()
{
	//设以村庄1为起点
	isvisited[1] = true;
	parent[1][1] = 0;
	len[1][1] = 0;
	shortans[1] = 1;
	cnt++;
	for (int i = 2; i <= vexnum; ++i)
	{
		//把其余村庄与村庄1之间距离放入最短数组中
		//且父母结点均设置为1
		lower[i] = len[1][i];
		parent[cnt][i] = 1;
	}
	int min = 1;//遍历路径最小村庄数
	for (int i = 2; i <= vexnum; ++i)
	{
		min = findvillage(min);
		isvisited[min] = true;
		shortans[i] = min;//记录每轮得出的村庄
		cnt++;
		//更新lower[min]
		for (int j = 1; j <= vexnum; j++)
		{
			if (!isvisited[j] && lower[j] > len[min][j])
			{
				lower[j] = len[min][j];
				parent[cnt][j] = min;
			}
			else if (!isvisited[j])
			{
				parent[cnt][j] = parent[cnt - 1][j];
			}
		}

	}
	getline();
}
//根据parent判断到该村庄的距离是否为0，不为0则说明需要修路
void Village::getline()
{
	cout << endl;
	cout << "还需修建：" << endl;
	for (int i = vexnum-1; i >= 1; i--)
	{
		cnt--;
		if (len[shortans[i + 1]][parent[cnt][shortans[i + 1]]] > 0)
		{
			cout << shortans[i + 1] << "到" << parent[cnt][shortans[i + 1]] << "修建" << len[shortans[i + 1]][parent[cnt][shortans[i + 1]]] << endl;
			build_ans += len[shortans[i + 1]][parent[cnt][shortans[i + 1]]];
		}
	}
	cout << "需要修建总长" << build_ans << endl;
}
void menu()
{
	cout << "/****************************************/" << endl;
	cout << "\t\t第三题：修建道路\t\t" << endl;
	cout << "/****************************************/" << endl;
}
int main()
{
	Village v;
	v.getshort();

	return 0;
}
