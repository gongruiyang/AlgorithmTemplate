
const int M = 1e5 + 10;
int stk[M], top;

// ��ʼ��ջ�ṹ
void init(){ top = -1; }

// ��ջ
void push(int x){ stk[++top] = x; }

// ��ջ
void pop(){ --top; }

// �п�
bool empty(){ return top == -1; }

// ��ȡջ��Ԫ��
int query(){ return stk[top]; }
