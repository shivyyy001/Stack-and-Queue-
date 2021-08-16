/**
 * Program to implement Stack using Queues on Leetcode.
 * Compilation : gcc Stack_using_queue.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 3. Assignment_4 - Stacks and Queues.
 *
 */


/*  <---     Leetcode Solution     --->   */ 


// defining structure to store data.
typedef struct
{
    int data;
    
} MyStack;

// making size , front and end variable.
int size;
int front;
int end;


// function to initialize a queue and return it.
MyStack* myStackCreate() 
{    
    // initializing queue of size 1000.
    MyStack *queue = (MyStack *)calloc(1000 , sizeof(MyStack));
    
    // making initial size = 0, front = 0, end = 0.
    size = 0;
    front = 0;
    end = 0;
    
    // return queue.
    return queue;
}


// function to push an element into queue.
void myStackPush(MyStack* queue, int x) 
{
    // second queue to copy first queue elements to shift them one place ahead after putting new element.
    int queue2[size+1];
    // pointer to fill queue2.
    int pt=0;
    
    // current size of queue.
    int sz=size;
    
    // copying queue elements from original queue to new queue , queue2.
    for(int i=front;i<=end-1;i++)
    {
        queue2[pt++]=queue[i].data;
    }
    
    // initializing original queue again.
    myStackCreate();
    
    /* putting the element 'x' which came as parameter to function as 
    first element of original queue */
    queue[end++].data = x;
    
    // copying new queue elements back to original queue.
    for(int i=0;i<sz;i++)
    {
        queue[end++].data=queue2[i];
    }

    // increasing the size by 1.
    size=sz+1;
}


// funtion to pop front element from queue which will be top element of stack.
int myStackPop(MyStack* queue) 
{
    // storing the front element in ele variable.
    int ele = queue[front].data;
    
    // increasing the front and decreasing the size.
    front++;
    size--;
    
    // returning front element of queue.
    return ele;
}


// function to return front element of queue which will be top element of stack.
int myStackTop(MyStack* queue)
{
    return queue[front].data;
}


// function to return true if queue is empty , else false.
bool myStackEmpty(MyStack* queue) 
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// function to free the queue which is made.
void myStackFree(MyStack* queue) 
{
    free(queue);    
}
