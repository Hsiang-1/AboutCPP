#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct TreeNode{
	char data;
	TreeNode * lchild;
	TreeNode * rchild;
	TreeNode(char c): data(c), lchild(NULL), rchild(NULL) { }
};

void PostOrder( TreeNode * root)
{
	if(root == NULL)
		return ;
	
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->data << " ";
	return ;
}

TreeNode* Build( string str1, string str2)
{
	if(str1.size() == 0)
		return NULL;
	
	char c = str1[0];
	TreeNode * root = new TreeNode(c);
	int position = str2.find(c);
	root->lchild = Build(str1.substr(1, position), str2.substr(0, position));
	root->rchild = Build(str1.substr(position + 1), str2.substr(position + 1));
	return root;
}


int main (void)
{
	string str1, str2;
	while( cin >> str1 >> str2)
	{
		TreeNode * root = Build(str1, str2);
		PostOrder(root);
		cout << endl;
	}
	
	
	
	return 0;
}
