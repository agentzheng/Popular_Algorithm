#include<iostream>
using namespace std;

struct BiNode
{
	char data;
	BiNode * left_child;
	BiNode * right_child;
};

void CreatTree(BiNode*& T,int depth)//以先序的方式构造二叉树
{
	char c;
	cin >> c;
	if (c == '#')
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = c;
		cout << "构造左子树" << depth << endl;
		CreatTree(T->left_child,depth+1);
		cout << "构造右子树" << depth << endl;
		CreatTree(T->right_child,depth+1);
	}
}


void PreOrder(BiNode* T)//先序遍历
{
	if (!T)
		return;
	cout << T->data;
	PreOrder(T->left_child);
	PreOrder(T->right_child);
}


void InOrder(BiNode* T)//中序遍历
{
	if (!T)
		return;
	InOrder(T->left_child);
	cout << T->data;
	InOrder(T->right_child);
}


void PostOrder(BiNode* T)//后序遍历
{
	if (!T)
		return;
	PostOrder(T->left_child);
	PostOrder(T->right_child);
	cout << T->data;
}


int main()
{
	BiNode * T = NULL;
	CreatTree(T,0);
	cout << endl;
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PostOrder(T);
	cout << endl;

	system("pause");

}