
/**
 * Program to implement Largest Rectangle.
 * Compilation : gcc Largest Rectangle.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 09/8/2021
 * Ques 5. Assignment_4 - Stacks and Queues.
 *
 */


#include<stdio.h>
#include <stdlib.h>
int total_size=1000000;//total memory allocated to stack ,it increases when buffer is full
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
    if(!call||size==total_size-1)//if there is no memory in stack or there is only one block of memory to_left in our stack
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
    size--;
    int top_value= stack[size];//top value of stack
    
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
int maximum(int a, int b)
{
return ( (a<=b) ? b : a );
}

int largestRectangleArea(int* heights, int total){
{
    //just to avoid undefined behaviour
    size=0;
    total_size=1e6;
    call=0;
    // to keep record of elements to the left and to the right
    int to_left[total+5] , to_right[total+5];
    //basic idea used is we fix min height equal to height of each tower and then check the maximum width we can form from this  
    for(int idx = 0 ; idx < total ; idx++ ) 
    {
         // it is ensure that all the heights to the left are greater or equal to current tower's height        
        while( !is_empty() && heights[peek()] >= heights[idx])
        pop();
        //empty means we can't move to left at all               
	if(!is_empty())
        {
            to_left[idx] = peek() + 1;
        }
        else
	{
            to_left[idx] = 0;

        }
        push(idx);
    }

        while(!is_empty())
            pop();

        for(int idx = total - 1 ; idx >= 0 ; idx--)
        {
            // it is ensure that all the heights to the right are greater or equal to current tower's height   
            while(!is_empty() && heights[peek()] >= heights[idx])
                pop();       
            //empty means we can't move right at all
            if(!is_empty())
                to_right[idx] = peek() - 1;
	    else
                to_right[idx] = total - 1;
            
            push(idx);
        }
        
        int answer=0;
        for(int i=0;i<total;i++)
        {
            //answer is simply the maximum extension to the right and left of the current tower multiplied by height of current tower
            answer=maximum(answer,  (int)(heights[i] * (to_right[i] -( to_left[i] - 1))));
          
        }
        return answer;
   
}
}

