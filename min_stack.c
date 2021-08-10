/**
 * Program to implement Min Stack.
 * Compilation : gcc Min_stack.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 09/8/2021
 * Ques 5. Assignment_4 - Stacks and Queues.
 *
 */

//structure to contain value and minimum value 
typedef struct 
{
   
    int value;      
    int min_value;
    
} MinStack;



int size=0, idx=0;//size and index


//function to initialize stack 
MinStack* minStackCreate() 
{
  
    //dynamic allocation of memory
    MinStack *stk = (MinStack *)calloc(1000000 , sizeof(MinStack)); 
    idx=0;
    size=0;
    //return stack after creating
    return stk;
}


 
void minStackPush(MinStack* obj, int val)
{
    // now minimum value for 1st element is 1st element
    if(size == 0)
    {
        obj[idx].min_value = val;
    }
    
    else 
    {
        //checking for minimum value
        if(val >= minStackGetMin(obj))
        {
            
             obj[idx].min_value =  minStackGetMin(obj);
            
        }
        else
        {
             obj[idx].min_value = val;
            
        }
    }
    
    obj[idx].value = val;
    size++;
    idx++;
}


void minStackPop(MinStack* obj) 
{
    size--;
    idx--;
}


int minStackTop(MinStack* obj) 
{

        //return top of stack    
        return obj[idx-1].value; 
    
}



int minStackGetMin(MinStack* obj) 
{

        //returning minimum value
        return obj[idx - 1].min_value;
    
   
}



void minStackFree(MinStack* obj) 
{
    //clearing memory
    free(obj);
}

