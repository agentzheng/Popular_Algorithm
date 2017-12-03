#include<iostream>
using namespace std;

struct BiNode
{
	char data;
	BiNode * left_child;
	BiNode * right_child;
};

void CreatTree(BiNode*& T,int depth)//������ķ�ʽ���������
{
	char c;
	cin >> c;
	if (c == '#')
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = c;
		cout << "����������" << depth << endl;
		CreatTree(T->left_child,depth+1);
		cout << "����������" << depth << endl;
		CreatTree(T->right_child,depth+1);
	}
}


void PreOrder(BiNode* T)//�������
{
	if (!T)
		return;
	cout << T->data;
	PreOrder(T->left_child);
	PreOrder(T->right_child);
}


void InOrder(BiNode* T)//�������
{
	if (!T)
		return;
	InOrder(T->left_child);
	cout << T->data;
	InOrder(T->right_child);
}


void PostOrder(BiNode* T)//�������
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