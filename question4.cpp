#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int length[100];//存路径
int key;
int cn;
bool f = 1;
struct BiNode
{
	int data;
	BiNode* lchild, * rchild;
};
class BiTree
{
public:
	BiTree() { cout << "请输入树结点:";  root = Creat(); }
	void isPerfectBiTree();
	void PreOrder() { PreOrder(root); }
private:
	BiNode* Creat();
	bool PreOrder(BiNode* bt);
	BiNode* root;
	int cnt = 0;
	BiNode* target;
};
BiNode* BiTree::Creat()
{

	BiNode* bt;
	char s;
	cin >> s;
	if (s == '#')bt = nullptr;
	else
	{
		cnt++;
		bt = new BiNode;
		bt->data = s-'0';
		bt->lchild = Creat();
		bt->rchild = Creat();
	}
	return bt;
}
//不是完美二叉树：
//1.只有右孩子
//2.是叶子结点或者只有左孩子后，所有结点不能有孩子
void BiTree::isPerfectBiTree()
{
	bool isone = 0;
	BiNode* Q[100], * q = nullptr;
	int front = -1, rear = -1;
	if (root == nullptr)return;
	Q[++rear] = root;
	while (front != rear)
	{
		bool isonlyright = 0;//是否只有右孩子
		bool isonlyleft = 0;//是否只有左孩子
		q = Q[++front];
		if (q->lchild != nullptr)
		{
			Q[++rear] = q->lchild;
			isonlyright = 1;
		}
		if (q->rchild != nullptr)
		{
			if (!isonlyright)
			{
				cout << "这棵树不是完全二叉树" << endl;
				return;
			}
			Q[++rear] = q->rchild;
			isonlyleft = 1;
		}

		//叶子结点判断
		if (q->lchild == nullptr && q->rchild == nullptr)
		{
			isone = 1;
		}
		//如果是叶子结点且之后有左孩子或有孩子
		if (!isonlyleft && isone)
		{
			cout << "这棵树不是完全二叉树" << endl;
			return;
		}
	}
	cout << "这棵树是完全二叉树" << endl;
}
bool BiTree::PreOrder(BiNode* bt)
{
	if (bt == nullptr)return false;
	if (bt->data == key)
	{
		length[cn++] = bt->data;
		return true;
	}
	if(PreOrder(bt->lchild)||PreOrder(bt->rchild))
	{
		length[cn++] = bt->data;
		return true;
	}
	return false;
}
void menu()
{
	cout << "/****************************************/" << endl;
	cout << "\t\t第四题：树的应用\t\t" << endl;
	cout << "/****************************************/" << endl;
}
int main()
{
	menu();
	BiTree T;
	T.isPerfectBiTree();
	cout << endl;
	cout << "请输入key：";
	cin >> key;
	T.PreOrder();
	cout << endl;
	cout << "路径：";
	for (int i = cn-1; i >= 0; i--)
	{
		cout << length[i] << " ";
	}
	return 0;
}

