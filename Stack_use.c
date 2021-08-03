/*
 * Program to implement Dynamic Stack in c.
 * Compilation : gcc Stack_use.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 02/8/2021
 * Day_2_Coding_Assignment.
 *
 */


/*

Runtime Complexities of created Functions :

push()         -> O(1) if no resizing needed.
               -> O(size) if resizing needed.

pop()          -> O(1).

peek()         -> O(1).

is_empty()     -> O(1).

getsize()      -> O(1).

get_capacity   -> O(1).

resize()       -> O(size).

*/


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


int main()
{
    // initializing stack with capacity.
    initialize_stack();
    
    // Testing all basic stack operations.
    printf("Adding 2 elements :\n");
    push(1);
    push(2);
    printf("Size = %d Capacity = %d\n" , getsize(), get_capacity());
    
    printf("Adding 1 more element :\n");
    push(3);
    printf("Size = %d Capacity = %d\n" , getsize(), get_capacity());

    printf("Adding 2 elements :\n");
    push(4);
    push(5);
    printf("Size = %d Capacity = %d\n" , getsize(), get_capacity());
    
    printf("Peak element -> %d\n" , peek());
    
    printf("Is stack empty ? -> %d\n" , is_empty());
    printf("Printing and deleting stack elements :\n");
    int x = getsize();
    for(int i = 0 ; i < x ; i++)
    {
        printf("Peek %d \n" ,peek());
        printf("Deleted %d \n" ,pop());
    }
    
    printf("Is stack empty ? -> %d\n" , is_empty());
    printf("\n");


}


