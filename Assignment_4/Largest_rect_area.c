/**
 * Program to calculate area of largest rectangle of histogram on Leetcode.
 * Compilation : gcc Largest_rect_area.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 4. Assignment_4 - Stacks and Queues.
 *
 */


/*  <---     Leetcode Solution     --->   */ 


//  Stack implementation starts here . //

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
 
//  Stack implementation ends here . //



// Function to calculate area of largest rectangle in histogram.
int largestRectangleArea(int* heights, int heightsSize)
{
    // initialize stack.
    initialize_stack();
    
    // make left and right array of heightsSize.
    int left[heightsSize];
    int right[heightsSize];
    
    // iterating the heights array to fill left array. 
    for(int i = 0 ; i < heightsSize ; i++)
    {
        /* while stack is not empty and while height at peek index >= height at current index ,
        keep popping. */
        while(!is_empty() && heights[peek()] >= heights[i])
        {
            pop();
        }
        
        /* if stack is empty then means left[i] = 0 , means there is no height to left which is 
        greater than or equal to current height */
        if(is_empty())
        {
            left[i] = 0; 
        }
        
        /* else left[i] = top element of stack(which stores index) + 1 , means the height which is greater 
        or equal to current height is at top element of stack(which stores index) + 1. */
        else
        {
            left[i] = peek() + 1;
        }
        
        // push the current index to stack.
        push(i);
    }
    
    // empty the stack to fill right array.
    emptyit();
    
    // iterating the heights array from behind to fill right array.
    for(int i = heightsSize - 1 ; i >= 0 ; i--)
    {
        /* while stack is not empty and while height at peek index >= height at current index
        keep popping. */
        while(!is_empty() && heights[peek()] >= heights[i])
        {
            pop();
        }
        
        /* if stack is empty then means right[i] = heightsSize -1 , means there is no height to right 
        which is greater than or equal to current height */
        if(is_empty())
        {
            right[i] = heightsSize - 1; 
        }
        
        /* else right[i] = top element of stack(which stores index) - 1 , means the height which is greater 
        or equal to current height is at top element of stack(which stores index) - 1. */
        else
        {
            right[i] = peek() - 1;
        }
        
        // push the current index to stack
        push(i);
    }
    
    // make initial answer = 0.
    int ans = 0;
    
    for(int i = 0 ; i < heightsSize ; i++)
    {
        // calculating the area of maximum rectangle in histogram and storing in ans variable. 
        if(ans <=  heights[i] * (right[i] - left[i] + 1))
        {
            ans = heights[i] * (right[i] - left[i] + 1) ;
        }
    }
    
    // making stack empty.
    emptyit();
    
    // returning ans.
    return ans;
    
}
