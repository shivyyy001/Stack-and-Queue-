/**
 * Program to implement Sliding Window Maximum on Leetcode.
 * Compilation : gcc Sliding_window_max.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 6. Assignment_4 - Stacks and Queues.
 *
 */


/*  <---     Leetcode Solution     --->   */ 


//  stack implementation starts here . //

#include <stdio.h>
#include <stdlib.h>

// initializing current size of stack array to be 0 and capacity to be 2.
int size = 0;
int capacity = 2;

// creating stack array.
int *stack;


// Function to initialize stack array with initial capacity = 2.
void initialize_stack()
{
    // using calloc function to initialize array with capacity = 2
    stack = (int*)calloc(capacity , sizeof(int));
}


// Function to resize the stack array , if it gets full.
void resize()
{
    // making the capacity double.
    capacity = capacity * 2;

    // creating and initializing a new array of double capacity;
    int *newarr;
    newarr = (int*)calloc(capacity , sizeof(int));

    // copying the stack array elements to this newly created array of double capacity.
    for(int i = 0 ; i < size ; i++)
    {
        newarr[i] = stack[i];
    }

    // pointing the newly created array to stack array.
    stack = newarr;
}


// Function to push an element into stack array.
void push(int value)
{
    // if size has reached capacity ,
    // calling resize() function to double the capacity of array.
    if(size == capacity)
    {
        resize();
    }

    // putting the value at 'size' index.
    stack[size] = value;
    // increasing the size.
    size++;
}


// Function to get and delete recently added element from stack array.
int pop()
{
    // if size is 0 then return -1;
    if(size == 0)
    {
        return -1;
    }

    // else getting the topmost element of stack array.
    int recent = stack[size - 1];

    // decreasing the size.
    size--;

    //returning the topmost element.
    return recent;
}


// Function to return top of the stack array , not delete it.
// top is basically the element which is recently pushed into stack array.
int peek()
{
    // if size is 0 then return -1;
    if(size == 0)
    {
        return -1;
    }

    // else returning the topmost element of stack array.
    return stack[size-1];
}


// Function to check if the stack array is empty or not.
int is_empty()
{
    // if size is zero then return 1 , indicating stack is empty.
    if(size == 0)
    {
        return 1;
    }

    // if size is non zero then return 0 , indicating stack is not empty.
    else
    {
        return 0;
    }
}


// Function to get current size of the array.
int getsize()
{
    return size;
}


// Function to get current capacity of the array.
int get_capacity()
{
    return capacity;
}


// Function to empty stack array.
void emptyit()
{
    // making stack size = 0 , capacity = 2 and initializing the stack again.
    size = 0;
    capacity = 2;
    initialize_stack();
}


//  stack implementation ends here . //



// Function to implement sliding window maximum.
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    // make returnSize = 0 initially.
    *returnSize = 0;
    
    // making an answer array of size numsSize + 5 using malloc function.
    int *answer = (int *)malloc((numsSize + 5) * sizeof(int));
    
    // initializing stack .
    initialize_stack();
    
    // index to fill the answer array , initialized with 0. 
    int index = 0;  
    
    for(int i = 0 ; i < numsSize ; i++)
    {
        // initial count of elements iterated in current k-sized window is 0.
        int count = 0;
        // starting position.
        int pos = i;
        
        // iterate till count is less than k and pos is less than numsSize. 
        while(count < k && pos < numsSize)
        {
            // if stack is empty then push element which is at 'pos' position.
            if(is_empty())
            {
                push(nums[pos]);
            }
            
            // else ->
            else
            {
                /* if top element of stack is greater than element at 'pos' position , then
                store that top element in temp variable and pop it from stack , then push element at 'pos' 
                position into stack ,then push temp again in stack to make sure greatest element always stays
                on top of stack */
                if(peek() > nums[pos])
                {
                    int temp = peek();
                    pop();
                    push(nums[pos]);
                    push(temp);
                }
                
                /* else just push element at 'pos' position into stack as it will be greater than
                any other element currently in stack */
                else
                {
                    push(nums[pos]);
                }
            }
            
            // increasing 'pos' to go to next index.
            pos++;
            // increasing count till it reaches end of current k-sized window.
            count++;
        }
        
        /* if count is equal to k , means we have a k-sized window in stack ,
        with top of stack as the maximum element from that k-sized window */
        if(count == k)
        {
            // filling the answer array with maximum element in every k-sized window.
            answer[index++] = peek();
            // increasing the returnSize.
            (*returnSize)++;
        }
        
        // making stack empty after working on each k-sized window.
        emptyit();
        
    }
    
    // returning answer array. 
    return answer;
}
