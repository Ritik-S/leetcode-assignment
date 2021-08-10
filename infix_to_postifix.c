/**
 * Program that converts an arithmetic expression from infix notation to postfix notation.
 * Compilation : gcc Infix_to_postifix.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 09/8/2021
 * Ques 2. Assignment_4 - Stacks and Queues.
 *
 */
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int total_size=3;//total memory allocated to stack ,it increases when buffer is full
int call=0;//just a record of how many times push is called used to allocate memory to stack
char *stack;//our dynamic stack
int size=0;//current size of stack
int maxN = 1e5; 


 void allocate_memory_to_stack()
 { 
    if(call==0)//call==0 means it is first time when push is called so stack is having no memory till now
     {
       stack = (char *)calloc(total_size , sizeof(char) );
       //now stack got some memory
       return ;
     }
    total_size*=2;//doubling the total size of stack
    char *temp;
    //tempory array to restore all the elements which were in stack and it is double the size of previous stack
    temp=(char *)calloc(total_size ,sizeof(char));
    for(int i=0;i<size;++i)
    temp[i]=stack[i];
    stack=temp;
    //now our stack has double size

 }



 // Adds a new element to the stack
void push(char value)
{
    if(!call||size==total_size-1)//if there is no memory in stack or there is only one block of memory left in our stack
    {
      allocate_memory_to_stack();
      //it will give memory to stack as well as double the memory of stack if required
    }
    stack[size]=value;//push the value in stack
    size++;
    call++;
}


// Remove and return the element from the stack.
char pop()
{
    if(!size)
    return -1;
    size--;
    char top_value= stack[size];//top value of stack
    //printf("%c\n",top_value); 
    return top_value;
}


// Return but not remove the element at the top of the stack.
char peek()
{
    if(size==0)
    return -1;// if empty return -1 because there is no peek element
    else
    return stack[size-1];//return top or peek element of stack
}


// Return 1 if the stack is empty, else return 0
int is_empty()
{
    if(size==0)
    return 1;
    else
    return 0;
}

int priority(char c) {
	
    if(c == '+' || c == '-')
	return 1;
    else if(c == '/' || c=='*')
	return 2;
    else
	return -1;
}
void infixToPostfix(char *s) {
    int sz=strlen(s);
    char answer[10000];
    int fsz=0;//final size
    for(int i = 0; i < sz; i++) 
    {
        char ch = s[i];

	// If character is an operand, add it to output string.
	if( ch >= '0' && ch <= '9')
	   answer[fsz++]=ch;
	else if(ch == '(')
           push('(');
        else if(ch == ')')
       	{
	    while(peek() != '(')
	    {
		char top_element=peek();
		answer[fsz++]=top_element;
		pop();
	    }
            //popping opening bracket
	    pop();
        }

		//if operator comes
	else 
	{
	    while(!is_empty() && priority(s[i]) <= priority(peek())) 
    	    {
	        answer[fsz++]=peek();
		pop();
	    }
	    push(ch);
	}

	}

	// Pop all the remaining elements from the stack
	while(!is_empty()) 
	{
            answer[fsz++]=peek();
	    pop();
	}
        answer[fsz]='\0';
        printf("%s",answer);
}

//Driver program to test above functions
int main() {
	char expression[10000];
	scanf("%s",expression);
	infixToPostfix(expression);
	return 0;
}

