#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st){
    cout<<"enrer size";
    cin>>st->size;
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}
void display(Stack st)
{
    for(int i=st.top;i>=0;i--){
        cout<<st.S[i]<<" ";
    }
}
void push(Stack *st,int x)
{
    if(st->top==st->size-1)
        cout<<"full";
    else{
        st->top++;
        st->S[st->top]=x;
    }
}
int pop(Stack *st)
{
    int x=-1;
    if(st->top==-1) cout<<"empty";
    else{
        x=st->S[st->top--];
    }
    return x;
}
int peek(Stack *st,int index)
{

    int x=-1;
    if(st.top-index<0) cout<<"invalid ";
    else{
        x=st.S[st.top-index+1];
    }
    return x;

}

int main()
{
    Stack st;
    create(&st);
    push(&st,5);
    push(&st,10);
    display(st);
    cout<<endl;
    cout<<pop(&st);



}
