#include <iostream>
using namespace std;
/*全局变量代表对比的结果，每次对比开始之前会被重设为1；*/
int CheckResult;

/*定义一个结构体，作为二叉树的一个节点*/
typedef struct SearchBTree
{
	int val;
	struct SearchBTree *left, *right;
}SearchBTree, *sTree;

/*用于初始化二叉树*/
void TreeInit(sTree &root) {
	root = NULL;
}
/*将制定的NVal插入*/
void TreeInsert(sTree &root,int InsertValue) {
	if (root == NULL) {
		root = (sTree)malloc(sizeof(SearchBTree));
		root->val = InsertValue;
		root->left = NULL;
		root->left = NULL;
	}
	else {
		if (InsertValue<root->val) {
			TreeInsert(root->left, InsertValue);
		}
		if (InsertValue>root->val) {
			TreeInsert(root->right, InsertValue);
		}
	}
}
/*检查传入的的两个二叉树，如果有不同则把CheckResult设为1*/
void CheckSame(sTree &NTree, sTree &LTree) {
	if (NTree->val == LTree->val)
	{
		if (NTree->left != NULL && LTree->left != NULL) {
			CheckSame(NTree->left, LTree->left);
		}
		if (NTree->left != NULL && LTree->left == NULL) {
			CheckResult = 0;
		}
		if (NTree->left == NULL && LTree->left != NULL) {
			CheckResult = 0;
		}
		/*三种情况，两个都是NULL，两个都不是NULL，两个有一个NULL
		第一种是相同的，第二种继续递归查找，第三种不同直接设为0*/
		if (NTree->right != NULL && LTree->right != NULL) {
			CheckSame(NTree->right, LTree->right);
		}
		if (NTree->right != NULL && LTree->right == NULL) {
			CheckResult = 0;
		}
		if (NTree->right == NULL && LTree->right != NULL) {
			CheckResult = 0;
		}
	}
	else { CheckResult = 0; }
}

int main() {
	int N, L, NVal, LVal;
	sTree NTree;
	sTree LTree;
	while (true)
	{
		cin >> N;
		if (N == 0) { break; }
		cin >> L;
		/*初始化NTree用来接收被对比二叉树*/
		TreeInit(NTree);
		for (int i = 0; i < N; i++) {
			cin >> NVal;
			TreeInsert(NTree, NVal);
		}
		/*开始循环，每次循环做一次对比*/
		for (int i = 0; i < L; i++) {
			/*初始化LTree并接受二叉树*/
			TreeInit(LTree);
			for (int i = 0; i < N; i++) {
				cin >> LVal;
				TreeInsert(LTree, LVal);
			}
			/*对比*/
			CheckResult = 1;
			CheckSame(NTree, LTree);
			/*对比结果*/
			if (CheckResult) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
