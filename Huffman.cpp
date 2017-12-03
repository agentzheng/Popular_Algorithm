#include<iostream>
using namespace std;
#define MAXVALUE  10000

struct HNodeType
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char value;
} ;        /* 结点结构体 */

HNodeType * Creat(int n)
{
	int length = 2 * n - 1;
	HNodeType* tree = new HNodeType[length];
	for (int i = 0; i < n; i++)
	{
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		cout << "请输入第" << i << "个元素的权值和值,输入元素顺序无影响" << endl;
		cin >> tree[i].weight >> tree[i].value;
	}
	for (int i = n; i < length; i++)
	{
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = MAXVALUE;
		tree[i].value = '\0';
	}

	return tree;
}



 bool picktwosmall(HNodeType * tree,int n)
{
	 int minweight = MAXVALUE;
	 int minid = -1;
	 int subminweight = MAXVALUE;
	 int subminid = -1;

	 for (int i = 0; i < n; i++)
	 {
		 if (tree[i].parent != -1)
			 continue;
		 
		if (tree[i].weight < minweight)
		{
			minweight = tree[i].weight;
			minid = i;
		}
		if(minweight<=tree[i].weight&&tree[i].weight<subminweight&&i!=minid)
		{
			subminweight = tree[i].weight;
			subminid = i;
		}
	 }
	
	 if (subminid == -1)
		 return true;
	 tree[minid].parent = tree[subminid].parent = n;
	 tree[n].weight = subminweight + minweight;
	 tree[n].lchild = minid;
	 tree[n].rchild = subminid;

	 return false ;
}
void HuffmanTree(HNodeType * tree,int n)
{	
	
	int t = n;
	while (!picktwosmall(tree, t))
	{
		t++;
	}

	for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << i << '\t' << tree[i].parent <<"\t"<< tree[i].weight <<"\t"<< tree[i].value << endl;
	}

}



int main()
{
	int n = 4;
	HNodeType* tree = Creat(n);
	HuffmanTree(tree, n);
	system("pause");
}
