#define _CRT_SECURE_NO_WARNINGS 1

//自己实现一个栈
//数据类型
typedef char SDataType;

//利用静态顺序表实现栈
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
//注意返回值，还有参数如果不可变最好加上const
int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}

SDataType StackTop(Stack *stack)
{
	assert(stack);
	assert(stack->top > 0);
	return stack->array[stack->top - 1];    //内部是用数组实现的，所以取元素要下标 - 1
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
			//将所有左括号都压栈
			StackPush(&stack, *p);
			break;
		case '}':
		case ']':
		case ')':
		{
					//先判断栈内有没有括号，如果没有则证明左括号比右括号少
					if (StackEmpty(&stack)){
						return false;
					}
					//依次判断栈顶元素是否匹配
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
	//判断栈内是否还有数据，如果经过完整一轮还有数据，则证明左括号比右括号多。
	if (!StackEmpty(&stack)){
		return false;
	}
	return true;
}