#include <iostream>
using namespace std;

//构建一个二叉树
int same;
typedef struct SearchBTree
{
	int val;
	struct SearchBTree *left, *right;
}SearchBTree, *sTree;

void init_tree(sTree &root);
void creat_Tree(sTree &root, int NVal);
void checksame(sTree &NTree, sTree &LTree);

int main() {
	int N, L,NVal;
	sTree NTree;
	sTree LTree;
	while (true)
	{
		cin >> N;
		if (N == 0) { break; }//如果发现是0就退出循环
		cin >> L;
		//读取第一行并存储在NTree中
		init_tree(NTree);
		for (int i = 0; i < N; i++) {
			cin >> NVal;
			creat_Tree(NTree,NVal);
		}
		//逐行读取并存储在LTree中
		for (int i = 0; i < L; i++) {
			init_tree(LTree);
			for (int i = 0; i < N; i++) {
				cin >> NVal;
				creat_Tree(LTree,NVal);
			}
			same = 1;
			checksame(NTree, LTree);
			if (same) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
void init_tree(sTree &root) {
	root = NULL;
}

void creat_Tree(sTree &root,int NVal) {
	if (root == NULL) {
		root = (sTree)malloc(sizeof(SearchBTree));
		root->val = NVal;
		root->left = NULL;
		root->left = NULL;
	}
	else {
		if (NVal<root->val) {
			creat_Tree(root->left, NVal);
		}
		if (NVal>root->val) {
			creat_Tree(root->right, NVal);
		}
	}
}

void checksame(sTree &NTree, sTree &LTree) {
	if (NTree->val == LTree->val)
	{
		if (NTree->left != NULL && LTree->left != NULL) {
			checksame(NTree->left, LTree->left);
		}
		if (NTree->left != NULL && LTree->left == NULL) {
			same = 0;
		}
		if (NTree->left == NULL && LTree->left != NULL) {
			same = 0;
		}
		if (NTree->right != NULL && LTree->right != NULL) {
			checksame(NTree->right, LTree->right);
		}
	}
	else { same = 0; }
}
