/**
 * Program to implement Min Stack Code on Leetcode.
 * Compilation : gcc Min_stack.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 5. Assignment_4 - Stacks and Queues.
 *
 */


/*  <---     Leetcode Solution     --->   */ 


// Structure to contain a pair of integers.
typedef struct 
{
    // variable to contain data as first element of pair.
    int data;      
    
    // variable to contain minimum element till now as second element of pair.
    int min_till_now;
    
} MinStack;


// size variable to store size of stack
int size;

// Function to find minimum of 2 integers.
int min(int a , int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}


// Function to create and return stack array of pairs.
MinStack* minStackCreate() 
{
    // making a stack array of pair of size 100005 containing a pair as each element. 
    MinStack *obj = (MinStack *)calloc(100005, sizeof(MinStack)); 
    
    // initializing current size with 0.
    size = 0;
    
    // returning array.
    return obj;
}


// Function to push a pair into stack. 
void minStackPush(MinStack* obj, int val)
{
    // pushing a pair at index 'size' ->
    
    // assigning the value 'val' to first element of pair at index 'size'.
    obj[size].data = val;
    
    /* if size is 0 then second element of pair , which is minimum element till now is 
    also assigned value 'val'. */
    if(size == 0)
    {
        obj[size].min_till_now = val;
    }
    
    /* else second element of pair , which is minimum element till now is assigned
    minimum from ('val' value and minimum element till now in stack) using min() function */
    else
    {
        obj[size].min_till_now = min(val , minStackGetMin(obj));
    }
    
    // increasing the size after adding a pair to stack.
    size++;
}


// Function to pop the top element of stack.
void minStackPop(MinStack* obj) 
{
    // if size of stack is 0 then do nothing just return.
    if(size == 0)
    {
        return;    
    }
    
    // decreasing the size indicating top element is now removed.
    size--;
}


// Function to return data which is at top of stack.
int minStackTop(MinStack* obj) 
{
    // if size of stack is greater than 0 then return the data of top element of stack.
    if(size > 0)
    {
        return obj[size - 1].data;
    }
    
    // else return -1 if size if 0.
    else
    {
        return -1;
    }
}


// Function to return min element from elements currently in stack.
int minStackGetMin(MinStack* obj) 
{
    /* if size of stack is greater than 0 then return the min_till_now from top 
    of stack as it contains the minimum element from elements currently in stack. */
    if(size > 0)
    {
        return obj[size - 1].min_till_now;
    }
    
    // else return -1 if size is 0.
    else
    {
        return -1;
    }
}


// Function to free stack array after use , by using free() function.
void minStackFree(MinStack* obj) 
{
    free(obj);
}

