//ţ�͡�����ǰ�������������������������������������������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char val;
	struct Node* left;
	struct Node* right;
} Node;

//����ṹ����������ÿ�εݹ�����ĸ��ڵ㣬�Լ�ʹ���˵Ľ����
typedef struct Result{
	Node* node;    //�����õĸ��ڵ�
	int used;      //ʹ���˵Ľ�����
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

	//�洢�����
	Node *root = (Node*)malloc(sizeof(Node));
	root->val = pre[0];
	//����������
	Result left = Create(pre + 1, size - 1);
	//����������
	Result right = Create(pre + 1 + left.used, size - 1 - left.used);

	//�ø���������ҽ�������ϵ
	root->left = left.node;
	root->right = right.node;

	//�����ܵĸ�����Լ�ʹ���˵Ľ��������Ա��´α�����
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