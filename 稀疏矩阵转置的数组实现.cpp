#include<iostream>
using namespace std;
template <class T>
class Sparse
{
private:
	int rows, cols;
	bool transable;
	struct Triple {
		int row;
		int col;
		T data;
	};
	int count;
	Triple * matrix;
	int * count_per_col;
	int * first_per_col;//每列第一个元素的行号

	void get_info()
	{
		count_per_col = new int[cols];
		first_per_col = new int[cols];
		//暂时没想到更好的初始化方法
		for (int i = 0; i < cols; i++)
		{
			count_per_col[i] = 0;
			first_per_col[i] = 0;//-1表示这行没有第一个;因为根本就没有元素
		}
		for (int i = 0; i < count; i++)
		{
			count_per_col[matrix[i].col]++;
		}
		for(int i=1;i<cols;i++)
		{
				first_per_col[i] += first_per_col[i - 1] + count_per_col[i - 1];
		 }
	}

	Sparse()
	{
		transable = false;
	}

public:
	
	Sparse(int layer,int n):rows(layer),cols(layer),transable(false),count(n)
	{
		if (rows == cols)
		{
			cout << "非常棒，你的矩阵是可以转置的" << endl;
			transable = true;
		}
			
		matrix = new Triple[count];
		for (int i = 0; i < count; i++)
		{
			cout << "请按照行优先顺序输入,矩阵下标从0，开始稀疏矩阵的第" << i+1  << "个元素 行 列 值" << endl;
			cin >> matrix[i].row >> matrix[i].col >> matrix[i].data;
		}
		get_info();
	}

	Sparse(Sparse&& other)
	{
		rows = other.rows;
		cols = other.cols;
		transable = other.transable;
		matrix = other.matrix;
		other.matrix = NULL;
		count = other.count;
		first_per_col = other.first_per_col;
		other.first_per_col = NULL;
		count_per_col = other.count_per_col;
		other.count_per_col = NULL;
	}

	void print()
	{
		cout << "开始输出矩阵" << endl;
		for (int i = 0; i < count; i++)
		{
			Triple triple = matrix[i];
			cout << "<" << triple.row <<"," << triple.col << "," << triple.data <<">"<< endl;
		}
		cout << "矩阵输出结束" << endl;
	}


	Sparse transpose()
	{
		Sparse transposed;
		transposed.cols = cols;
		transposed.rows = rows;
		transposed.transable = transable;
		transposed.count = count;
		transposed.matrix = new Triple[count];
		for (int i = 0; i < count; i++)
		{
			int index = first_per_col[matrix[i].col];
			transposed.matrix[index].data = matrix[i].data;
			transposed.matrix[index].col = matrix[i].row;
			transposed.matrix[index].row = matrix[i].col;
			first_per_col[matrix[i].col]++;
		}
		get_info();
		return transposed;
	}

	friend ostream& operator<<(ostream& os,Sparse& sparse)
	{
		sparse.print();
		return os;
	}
};

int main()
{
	int layer = 0, n = 0;
	cout << "请输入阶数和非零元素个数" << endl;
	while (layer <= 0 || n >= layer*layer)
	{
		cin >> layer >> n;
	}
	Sparse<int> sparse(layer, n);
	Sparse<int> transposed = sparse.transpose();
	cout << sparse << transposed << endl;
	system("pause");
}