
const int M = 1e5 + 10;
int stk[M], top;

// 初始化栈结构
void init(){ top = -1; }

// 入栈
void push(int x){ stk[++top] = x; }

// 出栈
void pop(){ --top; }

// 判空
bool empty(){ return top == -1; }

// 获取栈顶元素
int query(){ return stk[top]; }
