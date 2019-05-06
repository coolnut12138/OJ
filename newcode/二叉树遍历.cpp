//牛客、根据前序遍历，构建出二叉树，并且输出二叉树的中序遍历
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char val;
	struct Node* left;
	struct Node* right;
} Node;

//这个结构体用来保存每次递归结束的根节点，以及使用了的结点数
typedef struct Result{
	Node* node;    //创建好的根节点
	int used;      //使用了的结点个数
} Result;

Result Create(char pre[], int size)
{
	if (size <= 0){
		Result result;
		result.node = NULL;
		result.used = 0;
		return result;
	}

	if (pre[0] == '#'){
		Result result;
		result.node = NULL;
		result.used = 1;
		return result;
	}

	//存储根结点
	Node *root = (Node*)malloc(sizeof(Node));
	root->val = pre[0];
	//创建左子树
	Result left = Create(pre + 1, size - 1);
	//创建右子树
	Result right = Create(pre + 1 + left.used, size - 1 - left.used);

	//让根结点与左右结点产生关系
	root->left = left.node;
	root->right = right.node;

	//返回总的根结点以及使用了的结点个数，以便下次遍历用
	Result result;
	result.node = root;
	result.used = 1 + left.used + right.used;
	return result;
}

void InorderTravelsal(Node* root){
	if (root == NULL){
		return;
	}
	InorderTravelsal(root->left);
	printf("%c ", root->val);
	InorderTravelsal(root->right);
}

char pre[1024] = { 0 };
int main()
{
	while (gets(pre)){
		Result root = Create(pre, strlen(pre));
		InorderTravelsal(root.node);
	}
	return 0;
}