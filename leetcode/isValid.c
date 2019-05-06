#define _CRT_SECURE_NO_WARNINGS 1

//�Լ�ʵ��һ��ջ
//��������
typedef char SDataType;

//���þ�̬˳���ʵ��ջ
#define MAX_LEN 1000000

typedef struct Stack{
	SDataType array[MAX_LEN];
	int top;
}   Stack;

void StackInit(Stack *stack)
{
	stack->top = 0;
}

void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, int val)
{
	assert(stack);
	assert(stack->top < MAX_LEN);
	stack->array[stack->top] = val;
	stack->top++;
}
//ע�ⷵ��ֵ�����в���������ɱ���ü���const
int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}

SDataType StackTop(Stack *stack)
{
	assert(stack);
	assert(stack->top > 0);
	return stack->array[stack->top - 1];    //�ڲ���������ʵ�ֵģ�����ȡԪ��Ҫ�±� - 1
}

void StackPop(Stack *stack)
{
	assert(stack);
	assert(stack->top > 0);
	stack->top--;
}

bool isValid(char* s) {
	char* p = s;
	Stack stack;
	StackInit(&stack);
	while (*p != '\0'){
		switch (*p){
		case '{':
		case '[':
		case '(':
			//�����������Ŷ�ѹջ
			StackPush(&stack, *p);
			break;
		case '}':
		case ']':
		case ')':
		{
					//���ж�ջ����û�����ţ����û����֤�������ű���������
					if (StackEmpty(&stack)){
						return false;
					}
					//�����ж�ջ��Ԫ���Ƿ�ƥ��
					char left = StackTop(&stack);
					StackPop(&stack);
					if (!((left == '{' && *p == '}')
						|| (left == '[' && *p == ']')
						|| (left == '(' && *p == ')'))){
						return false;
					}
		}
			break;
		}
		p++;
	}
	//�ж�ջ���Ƿ������ݣ������������һ�ֻ������ݣ���֤�������ű������Ŷࡣ
	if (!StackEmpty(&stack)){
		return false;
	}
	return true;
}