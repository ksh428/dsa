//CODE GIVING ERROR RECHEK IT
#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op=='*'){
        return 1;
    }else if(op=='/') return 1;
    else if(op=='-') return 2;
    else return 2;
}
int operation(int a,int b,char op){
    if(op=='*') return a*b;
    else if(op=='/') return a/b;
    else if(op=='+') return a+b;
    else return a-b;
}
int evaluate(string s){
    stack<int>operands;
    stack<char>operators;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='('){
            operators.push(ch);
        }else if(isdigit(ch)){
           operands.push(ch-'0');
        }else if(ch==')'){
            while(operators.top()!=')') {
                //1 pop in operator = 2  pop in operands
                char op=operators.top();
                int v2=operands.top();
                operands.pop();
                int v1=operands.top();
                operands.pop();
                int val=operation(v1,v2,op);
                operands.push(val);
                operators.pop();
            }
            operators.pop();//pop the opening bracket

        }else if(ch=='+' or ch=='/' or ch=='-' or ch=='*'){
            while(!operators.empty() and operators.top()!='(' and precedence(operators.top())>=precedence(ch) ){

                 char op=operators.top();
                int v2=operands.top();
                operands.pop();
                int v1=operands.top();
                operands.pop();
                int val=operation(v1,v2,op);
                operands.push(val);
                operators.pop();
            }
            operators.push(ch);
        }
    }
     while(!operators.empty()) {
        //1 pop in operator = 2  pop in operands
        char op=operators.top();
        int v2=operands.top();
        operands.pop();
        int v1=operands.top();
        operands.pop();
        int val=operation(v1,v2,op);
        operands.push(val);
        operators.pop();
    }
    return operands.top();
}

int main() {
	cout << evaluate("10 + 2 * 6") << "\n";
	cout << evaluate("100 * 2 + 12") << "\n";
	cout << evaluate("100 * ( 2 + 12 )") << "\n";
	cout << evaluate("100 * ( 2 + 12 ) / 14");
	return 0;
}



