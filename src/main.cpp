#include <string>
#include<cstring> // for size_t
#include <iostream>

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

int Priority(char x);                                          // Operation 1: Check Priority
bool prcd(char symb1, char symb2);                            //  Operation 2: Decided Precedence Of Operations
void infix_to_postfix();                                     //   Operation 3: Convert Infix To Postfix

int main(){
    cout<<"This Program Will Convert Infix To Postfix \n\n";
    infix_to_postfix();

    return 0;
}

int Priority(char x){
    int n = 0;
    if (x == '^')
        n = 3;
    if(x == '*' || x == '/' || x == '%' )
        n = 2;
    if(x == '+' || x == '-' )
        n = 1;
    return n;
}

bool prcd(char symb1, char symb2){
    if(symb1 == '^' && symb2 == '^') // 2^2^3
        return false;
    if(symb1 == '(' || symb2 == '(')// open
        return false;
    else if(symb1 == ')')//to pop operations
        return true;
    else{
        if(Priority(symb1) >= Priority(symb2))
            return true;
        else
            return false;
    }
}

void infix_to_postfix(){
    Stack s;
    string infix;
    char symbol = '\0';
    int count1 = 0;// to accessing infix characters
    int count2 = 0;// to accessing postfix elements

    cout<<"Enter the infix expression:"<<endl;
    getline (cin,infix);

    size_t size = infix.length();

    string *postfix = new string[size];

    while (count1 < size) {
        symbol = infix[count1];
        if(isalpha(symbol) || isdigit(symbol)){
            postfix[count2] = symbol;
            count2++;
        }
        else{
            while (!s.isEmpty() && prcd(s.peak(), symbol)) {
                postfix[count2] = s.pop();
                count2++;
            }
            if(s.isEmpty() || symbol != ')')
                s.push(symbol);
            else
                s.pop();

        }
        count1++;
    }

    while(!s.isEmpty()){
        if( symbol == '(')
            s.pop();
        else{
            postfix[count2] = s.pop();
            count2++;
        }
    }

    for(int i=0; i<count2; i++)
        cout<< postfix[i];
    cout<<endl;

    delete [] postfix;
    postfix = NULL;

}

