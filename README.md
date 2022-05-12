# Evaluation of Arithmetic Expressions By Using Stack

## What do you mean by Stack?
A Stack is a widely used linear data structure in modern computers in which insertions and deletions of an element can occur only at one end, i.e., top of the Stack. It is used in all those applications in which data must be stored and retrieved in the last.

## Following is the various Applications of Stack in Data Structure:
* Evaluation of Arithmetic Expressions
* Backtracking
* Delimiter Checking
* Reverse a Data
* Processing Function Calls

## Evaluation of Arithmetic Expressions
This Repository covers Coding Implementation Evaluation of Arithmetic Expressions base on the following [algorithem](https://github.com/wesamhamad/Stack_Application/blob/main/Stack%20Applications.pdf).

This program has separated [Convert Infix To Postfix](https://github.com/wesamhamad/Stack_Application/blob/main/src/main.cpp) **and** [Evaluate Postfix Expression](https://github.com/wesamhamad/Stack_Application/blob/main/src/Evaluate.

## Stack Using Array vs linked List.

**Singly-linked list:** costs to push or pop into a linked-list-backed stack
is O(1) worst-case.

**Stack using a dynamic array:** pushing onto the stack can be implemented by appending a new element to the dynamic array, which takes amortized O(1) time and worst-case O(n) time. Popping from the stack can be implemented by just removing the last element, which runs in worst-case O(1).

**So I Use Singly-Linked List To Implemented The Stack In My Code.**



## OutPut Samples:
#### CASE1:
```c++
This Program Will Convert Infix To Postfix 

Enter the infix expression:
9^2-(5+5)*2+(3*2)
92^55+2*-32*+
Program ended with exit code: 0

```
```c++
This Program Will Evaluate  Postfix Expression 

Enter postfix expression : 92^55+2*-32*+
Evaluating a postfix expression : 67
Program ended with exit code: 0

```
#### CASE2:
```c++
This Program Will Convert Infix To Postfix        

Enter the infix expression:
2^2^3
223^^
Program ended with exit code: 0

```

```c++
This Program Will Evaluate  Postfix Expression 

Enter postfix expression : 223^^
Evaluating a postfix expression : 256
Program ended with exit code: 0
  
```

