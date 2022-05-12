#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct node{
    double info;
    node* next;
};

class Stack {
private:
    node *top;
public:
    Stack(){top = NULL;}
    bool isEmpty();
    void push(double);
    double pop();
    double peak();
};

//Class Functions
bool Stack::isEmpty(){return (top == NULL);}

void Stack::push(double item){
    node*p = new node;
    p->info = item;
    p->next = top;
    top = p;
}

double Stack::pop(){
    if(isEmpty()){
        cout<<"Underflow\n";
        return -1;
    }else {
        node *temp = top;
        double x = top->info;
        top = top->next;
        delete temp;
        return x;
        }
}

double Stack::peak(){
    if(isEmpty()){
        cout<<"is Empty \n";
        return -1;
    }
    else
        return top->info;
}

// End Of Class's Functions



double evaluation(double op1, double op2, char Operator);    // Operation 1: Calculate Two Values
void expression();                                          // Operation 2:  Evaluate  Postfix Expression


int main(){
    cout<<"This Program Will Evaluate  Postfix Expression \n\n";
    expression();
    return 0;
}

double evaluation(double op1, double op2, char Operator){
    double value = 0;

    switch(Operator){
        case '^':
            value = (double)pow(op1, op2); break;
        case '*':
            value = op1 * op2; break;
        case '/':
            value = op2 != 0 ? (op1 / op2) : throw runtime_error("Math error: Attempted to divide by Zero\n"); break;// to avoid devided by zero which is comman logic error
        case '%':
            value = (int)op1 % (int)op2; break;
        case '+':
            value = op1 + op2; break;
        case '-':
            value = op1 - op2; break;
    }
    return value;
}

void expression(){
    Stack s;
    char symbol ;
    string postfix;
    double value, opnd1 , opnd2;
    int count = 0 ;

    cout<<"Enter postfix expression : ";
    cin>> postfix;

    while( count < postfix.length() ){
        symbol = postfix[count];

        if( isdigit(symbol))
            s.push(symbol - '0'); // to convert char to int
        else{
            opnd2 = s.pop();
            opnd1 = s.pop();
            value = evaluation(opnd1 , opnd2, symbol);
            s.push(value);
        }
        count++;
    }
      cout<<"Evaluating a postfix expression : "<<s.pop()<<endl;
}





