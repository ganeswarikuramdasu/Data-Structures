 #include<stdio.h>
#include<ctype.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int val) {
    stack[top++]=val;
}
int pop(){
    return stack[top--];
}
int evaluatePostfix(char exp[]){
    for(int i=0;exp[i]!='\0';i++) {
        char ch=exp[i];
        if(isdigit(ch)) {
            push(ch-'0');
        }
        else {
            int b=pop();
            int a=pop();
            int result;
            switch(ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(result);
        }
    }
    return pop(); 
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression:\n");
    scanf("%s", exp);
    int result=evaluatePostfix(exp);
    printf("Result=%d\n", result);
    return 0;
}
