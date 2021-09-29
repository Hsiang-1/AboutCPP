#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct TreeNode {
	char data;
	TreeNode* leftchild;
	TreeNode* rightchild;
	TreeNode(char c): data(c), leftchild(NULL), rightchild(NULL) {}
};

TreeNode* Build( int & position, string str)
{
	char c = str[position++];
	if( c == '#')
		return NULL;
	
	TreeNode * root = new TreeNode(c);
	root -> leftchild = Build( position, str);
	root -> rightchild = Build ( position , str);
	return root;
}

void InOrder(TreeNode * root)
{
	if( root == NULL)
		return ;
	
	InOrder(root->leftchild);
	cout << root->data << " ";
	InOrder(root->rightchild);
	return ;
}


int main(void)
{
	string str;
	while( cin >> str)
	{
		int position = 0;
		TreeNode * root = Build(position, str);
		InOrder(root);
		cout << endl;
	}
	
	return 0;
}


