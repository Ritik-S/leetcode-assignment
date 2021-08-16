/**
 * Program to Implement Stack using Queues.
 * Compilation : gcc queue_stack.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 09/8/2021
 * Ques 2. Assignment_4 - Stacks and Queues.
 *
 */

int maxN=1e6;
int end=0;
int front =0;
typedef struct {
    int value;

} MyStack;//it is our main queue



MyStack* myStackCreate() {//creating and allocating memory to our main queue
     end=0;
     front =0;
     MyStack *stack_using_queue = (MyStack *) calloc(maxN ,sizeof(MyStack));
     return stack_using_queue;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {

     //this array is temporary queue which is used to shift previous queue        elements one place behind in the queue
     int temp_queue[end+front+5];
     // we are shifting elements of main queue 1 step behind so that we can        place new element to the front of queue so that it act like stack
     for (int i =front; i < end; ++i)
     {
         temp_queue[i+1] = obj[i].value;
     }

     temp_queue[front] = x;
     end++;

     for( int i = front ; i < end ; ++i)
     {
        obj[i].value = temp_queue[i];

     }

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

    front++;
    return obj[front-1].value;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {


    return obj[front].value;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(front>=end)
      return 1;
    else
      return 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

