#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
int top=-1;
char stack[MAX];
int isNull(){
    if(top==-1)
        return 1;
    return 0;
}
int isFull(){
    if(top==MAX-1)
        return 1;
    return 0;
}
void push(char value){
    if(isFull()==1)
        printf("Overflow");
    else
        stack[++top]=value;
}
char pop(){
    if(isNull()==1)
        printf("Underflow");
    else{
        top--;
        return stack[top+1];
    }
    return '\0';
}
void readInfix(char *ar){
    printf("Enter a Infix Exproision : ");
    scanf("%s",ar);
}
int presidance(char op){
    switch(op){
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default :return 0;
    }
}
int isOprator(char op){
    if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^')
        return 1;
    return 0;
}
void infixToPostfixConversion(char infix[],char postfix[]){
    int i,j,k;
    char temp;
    for(i=0,j=0;infix[i]!='\0'; ){
        if(isalnum(infix[i])>0){
            postfix[j++]=infix[i++];
        }
        else if(isOprator(infix[i])==0){
            if(infix[i]=='(')
                push(infix[i]);
            else if(infix[i]==')'){
                for(k=top;stack[k]!='(';k--)
                    postfix[j++]=pop();
               temp =pop();
            }
            i++;
        }
        else if(isOprator(infix[i])==1){
            if(presidance(infix[i])>presidance(stack[top])||isNull())
                push(infix[i++]);
            else if(presidance(infix[i])<presidance(stack[top]))
                postfix[j++]=pop();
            else{
                if(presidance(infix[i]==3))
                    push(infix[i++]);
                else{
                    postfix[j++]=pop();
                    push(infix[i++]);
                }
            }
        }
    }
    
    while(isNull()!=1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void main(){
    char Infix[10];
    char Postfix[10];
    readInfix(Infix);
    printf("\n infix Exprission is : %s" , Infix);
    infixToPostfixConversion(Infix,Postfix);
    printf("\nPostfix is :%s\n",Postfix);
}