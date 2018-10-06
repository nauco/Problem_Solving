#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class node
{
public:
	int x;
	int y;
	int num;
	node* parent;
	node* left;
	node* right;
	node() {};
	node(int x, int y, int n) :x(x), y(y), num(n) {
		parent = NULL;
		left = NULL;
		right = NULL;
	};
};


bool cmp1(const node &a, const node &b) {
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	return a.y > b.y;
}

class tree
{
public:
	queue<node*> q;
	int idx = 0;
	vector<node> v;
	vector<vector<int>> answer;
	vector<int> tmp;
	node* root;

	void preorder(node* n)
	{
		tmp.push_back(n->num);
		if (n->left != NULL)
			preorder(n->left);
		if (n->right != NULL)
			preorder(n->right);
	};

	void postorder(node* n)
	{
		if (n->left != NULL)
			postorder(n->left);
		if (n->right != NULL)
			postorder(n->right);

		tmp.push_back(n->num);
	}
	void push(int n, int s)
	{
		int i;
		int lev = v[n].y;
		int k = 0;
		while (lev == v[n].y)
		{
			k++;
			lev = v[n + k].y;
		}

		for ( i = n+1; i < s; i++)
		{
			if (lev != v[i].y)
				continue;

			if (v[i].parent != NULL)
				continue;

			if (v[i].x < v[n].x && v[i].y < v[n].y)
			{
				if (v[n].parent==NULL)
				{
					v[n].left = &v[i];
					v[i].parent = &v[n];
					i++;
					break;
				}
				else
				{
					//내가 부모의 right면
					if (v[n].parent->right == &v[n])
					{
						if (v[n].parent->x < v[i].x)
						{
							v[n].left = &v[i];
							v[i].parent = &v[n];
							i++;
							break;
						}
					}
					else
					{
						//내가 부모의 left면
						if (v[n].parent->x < v[i].x)
						{
							v[n].left = &v[i];
							v[i].parent = &v[n];
							i++;
							break;
						}
					}
				}
			}
			break;
		}
		for (; i < s; i++)
		{
			if (lev != v[i].y)
				continue;

			if (v[i].parent != NULL)
				continue;

			if (v[i].x > v[n].x && v[i].y < v[n].y)
			{
				if (v[n].parent == NULL)
				{
					v[n].right = &v[i];
					v[i].parent = &v[n];
					return;
				}
				else
				{
					//내가 부모의 right면
					if (v[n].parent->right == &v[n])
					{
						if (v[n].parent->x > v[i].x)
						{
							v[n].right = &v[i];
							v[i].parent = &v[n];
							return;
						}
					}
					else
					{
						//내가 부모의 left면
						if (v[n].parent->x > v[i].x)
						{
							v[n].right = &v[i];
							v[i].parent = &v[n];
							return;
						}
					}
				}
			}
		}
	}
	tree(vector<vector<int>> nodeinfo)
	{
		for (auto& i : nodeinfo)
			v.push_back(node(i[0], i[1], ++idx));

		sort(v.begin(), v.end(), cmp1);

		int s = size(v);
		root = &v[0];
		for (int i = 0; i < s-1; i++)
		{
			push(i, s);
		}

	}

};


vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{

	tree T = tree(nodeinfo);

	T.preorder(T.root);
	T.answer.push_back(T.tmp);
	T.tmp.clear();
	T.postorder(T.root);
	T.answer.push_back(T.tmp);

	return T.answer;
}


int main()
{
	solution({ { 5, 3 },{ 11, 5 },{ 13, 3 },{ 3, 5 },{ 6, 1 },{ 1, 3 },{ 8, 6 },{ 7, 2 },{ 2, 2 } });

	cout << "gi" << endl;

	return 0;
}