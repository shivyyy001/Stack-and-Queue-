/**
 * Program that checks whether the sequence of brackets in the given string is balanced or not.
 * Compilation : gcc Valid_paranthesis.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 1. Assignment_4 - Stacks and Queues.
 *
 */


//   stack implementation starts here . //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int size = 0;
int capacity = 2;

// creating stack array.
char *stack;


// Function to initialize stack array with initial capacity = 2.
void initialize_stack()
{
    // using calloc function to initialize array with capacity = 2
    stack = (char*)calloc(capacity , sizeof(char));
}


// Function to resize the stack array , if it gets full.
void resize()
{
    // making the capacity double.
    capacity = capacity * 2;

    // creating and initializing a new array of double capacity;
    char *newarr;
    newarr = (char*)calloc(capacity , sizeof(char));

    // copying the stack array elements to this newly created array of double capacity.
    for(int i = 0 ; i < size ; i++)
    {
        newarr[i] = stack[i];
    }

    // pointing the newly created array to stack array.
    stack = newarr;
}


// Function to push an element into stack array.
void push(char value)
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
char pop()
{
    // if size is 0 then return -1;
    if(size == 0)
    {
        return -1;
    }

    // else getting the topmost element of stack array.
    char recent = stack[size - 1];

    // decreasing the size.
    size--;

    //returning the topmost element.
    return recent;
}


// Function to return top of the stack array , not delete it.
// top is basically the element which is recently pushed into stack array.
char peek()
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

//   stack implementation ends here . //




// Function to check whether the sequence of brackets in the given string is balanced or not.
bool isValid(char * s)
{
    // initializing stack.
    initialize_stack();
    
    // traversing the string.
    for(int i = 0 ; i < strlen(s) ; i++)
    {
        // if stack is empty then push the current character into stack.
        if(getsize() == 0)
        {
            push(s[i]);
        }
        
        // else if current character is '}' and top of stack is '{' then pop the top element.
        else if(s[i] == '}' && peek() == '{')
        {
            pop();
        }
        
        // else if current character is ')' and top of stack is '(' then pop the top element.
        else if(s[i] == ')' && peek() == '(')
        {
            pop();
        }
        
        // else if current character is ']' and top of stack is '[' then pop the top element.
        else if(s[i] == ']' && peek() == '[')
        {
            pop();
        }
        
        // else push the current character into stack.
        else
        {
            push(s[i]);
        }
    }
    
    // get size of stack in sz variable.
    int sz = getsize();
    
    // empty stack.
    emptyit();
    
    // if stack is empty means it is valid paranthesis , then return true.
    if(sz == 0)
    {
        return true;
    }
    
    // else if stack is not empty , return false.
    else
    {
        return false;
    }
}




int main()
{
    printf("Enter your expression : \n");
    
    char expression[1000];
    scanf("%s" , expression);
    
    /* Call isValid() Function to check whether sequence of brackets in given string
    is balanced or not */
    if(isValid(expression))
    {
        // print true if valid.
        printf("true \n");
    }
    
    else
    {
        // print false if not valid.
        printf("false \n");
    }
    
    return 1;
    
}


