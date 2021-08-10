/**
 * Program to find sliding window maximum
 * Compilation : gcc sliding_window.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 09/8/2021
 * Ques 2. Assignment_4 - Stacks and Queues.
 *
 */

#include<stdio.h>
#include <stdlib.h>
int total_size=3;//total memory allocated to stack ,it increases when buffer is full
int call=0;//just a record of how many times push is called used to allocate memory to stack
int *stack;//our dynamic stack
int size=0;//current size of stack



 void allocate_memory_to_stack()
 {
    if(call==0)//call==0 means it is first time when push is called so stack is having no memory till now
     {
       stack = (int *)calloc(total_size , sizeof(int) );
       //now stack got some memory
       return ;
     }
    total_size*=2;//doubling the total size of stack
    int *temp;
    //tempory array to restore all the elements which were in stack and it is double the size of previous stack
    temp=(int *)calloc(total_size ,sizeof(int));
    for(int i=0;i<size;++i)
    temp[i]=stack[i];
    stack=temp;
    //now our stack has double size

 }



 // Adds a new element to the stack
void push(int value)
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
int pop()
{
    if(!size)
    return -1;
    int top_value= stack[size];//top value of stack
    size--;
    return top_value;
}


// Return but not remove the element at the top of the stack.
int peek()
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
int maximum(int a, int b )
{
    return ( (a > b) ? a : b);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    //to control undefined behavior of stack 
    size=0;
    call=0;
    total_size=3;
    //our answer array which contains all the maximum in all the windows
    int *answer=(int *) calloc(sizeof(int) , numsSize);
    int mx=0;
    
    int size=0;
    for(int i = 0 ; i <= numsSize-k ; ++i)
    {
        mx=-1e9;//maximum in current window
        for(int j = i ; j <  i + k ; ++j)
        {
            push(nums[j]);
        }
        while(!is_empty())
        {
            mx = maximum(mx , peek());//check for max
            pop();
        }
        answer[size] = mx;//put this max in answer array
        size++;
    
    }
    *returnSize = size; 
    return answer ;
    
}
