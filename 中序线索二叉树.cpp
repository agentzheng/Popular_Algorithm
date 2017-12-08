#include<iostream>
using namespace std;

//中序线索二叉树
enum Tag{child,thread};

struct BiNode
{
	char data;
	BiNode * lchild;
	BiNode * rchild;
	Tag rtag;
	Tag ltag;
};

BiNode* pre = NULL;

void CreatTree(BiNode*& T, int depth)//以先序的方式构造二叉树
{
	char c;
	cin >> c;
	if (c == '#')
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = c;
		T->rtag = T->ltag = child;;
		cout << "构造左子树" << depth << endl;
		CreatTree(T->lchild, depth + 1);
		if (!T->lchild)
			T->ltag = thread;
		cout << "构造右子树" << depth << endl;
		CreatTree(T->rchild, depth + 1);
		if (!T->rchild)
			T->rtag = thread;
	}
}



void InOrderForm(BiNode* T)//中序遍历构建二叉树
{
	
	if (!T)
		return;
	InOrderForm(T->lchild);
	if (T->ltag==thread)
	{
		T->lchild = pre;
	}
	//cout << T->data;
	if (pre->rtag==thread)
	{
		pre->rchild = T;
	}
	pre = T;
	InOrderForm(T->rchild);
}


void FormTree(BiNode*& head, BiNode* root)
{
	if (!root)
	{
		cout << "凉凉" << endl;
		return;
	}
	head = new BiNode;
	head->ltag = child;
	head->lchild = root;
	head->rtag = child;
	
	pre = head;
	InOrderForm(root);
	pre->rchild = head;
}



void InOrderVisit(BiNode* head)//中序遍历构建二叉树
{
	BiNode* root = head->lchild;
	BiNode* p = root;
	while (p != head)
	{
		while (p->ltag == child)
		{
			p = p->lchild;
		}
		//找到第一个节点
		while (p->rtag == thread)
		{
			cout << p->data;
			p = p->rchild;
		}
		if(p!=head)
		{
			cout << p->data;
			p = p->rchild;
		}
	}
	cout << endl;
}



int main()
{
	BiNode * Tree = NULL;
	CreatTree(Tree, 0);
	BiNode * head = NULL;
	FormTree(head, Tree);
	InOrderVisit(head);
	system("pause");

}