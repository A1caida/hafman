#include <iostream>
#include <vector>
using namespace std;

struct Tree
{
	char n;
	bool f;
	Tree* left;
	Tree* right;
};

Tree* InsertNode(Tree* node, char q, bool k,int owo)
{
	if (node == NULL)
	{
		node = new (nothrow) Tree();
		if (node != NULL)
		{
			if (owo==1)
			{
				node->n = q;
				node->f = k;
				node->right = NULL;
			}
			else 
			{
				node->n = q;
				node->f = k;
				node->left = node->right = NULL;
			}
				
		}
		return node;
	}

	if (owo==2)
	{
		node->right = InsertNode(node->right, q, 1, owo);
	}
	else
	{
		if (q < node->n)
			node->left = InsertNode(node->left, q, 0, owo);
		else
			//if (node->right == NULL)
			node->right = InsertNode(node->right, q, 1, owo);
	}
	
	return node;
}

void print_Tree(Tree* node, int level)
{
	if (node)
	{
		print_Tree(node->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->n <<" " << node->f <<endl;
		print_Tree(node->left, level + 1);
	}
}

int main()
{
	string a, b;
	
	cin >> a;
	vector<int> count;
	vector<char> let;
	Tree* tree = NULL;
	while (a.length()!=0)
	{
		int temp = 1;
		for (size_t i = 1; i < a.length(); i++)
		{
			if (a[0] == a[i])
			{
				temp++;
			}
				
		}
		for (size_t i = 1; i < a.length(); i++)
		{
			if (a[0] == a[i])
			{
				a.erase(i,1);
			}

		}
		let.push_back(a[0]);
		a.erase(0, 1);
		count.push_back(temp);
	}

	int x; char y;
	for (int i = 0; i < count.size(); i++) 
	{            
		for (int j = count.size() - 1; j > i; j--) 
		{     
			if (count[j - 1] > count[j]) 
			{
				x = count[j - 1]; count[j - 1] = count[j]; count[j] = x;
				y = let[j - 1]; let[j - 1] = let[j]; let[j] = y;
			}
		}
	}
	for (size_t i = 0; i < count.size(); i++)
	{
		cout << let[i] << count[i] << endl;
	}
	int owo=1;
	while (count.size() != owo)
	{
		tree = InsertNode(tree, let[count.size() - owo], 0,owo);
		owo++;

	}
	print_Tree(tree, count.size()-1);
}

