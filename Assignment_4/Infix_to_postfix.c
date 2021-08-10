/**
 * Program that converts an arithmetic expression from infix notation to postfix notation.
 * Compilation : gcc Infix_to_postfix.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/8/2021
 * Ques 2. Assignment_4 - Stacks and Queues.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//   Stack implementation starts here  .// 


// initializing current size of stack array to be 0 and capacity to be 2.
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


//   Stack implementation starts here  .// 




// Function to return integer precedence of given operator.
int getprecedence(char ch) 
{
    if(ch == '/' || ch == '*')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}



// Function to convert infix expression to postfix expression.
void convert_to_postfix(char *expression)
{
    // answer string to store answer.
    char answer[1000];
    // index initialized with 0 to fill answer string from start.
    int index = 0;

    // Traversing the expression.
    for(int i = 0 ; i < strlen(expression) ; i++)
    {
        // if current character is a number from 0 to 9 store in answer.
        if(expression[i] >= '0' && expression[i] <= '9')
        {
            answer[index++] = expression[i];
        }
        
        // else if current character is an operator from + , - , * and / . 
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'
        || expression[i] == '/')
        {
            /* keep popping top element from stack and putting in answer till 
            size of stack is greater than 0 and precedence of given character is less than equal
            to precedence of top element of stack */
            while(getsize() != 0 && getprecedence(expression[i]) <= getprecedence(peek()))
            {
                answer[index++] = peek();
                pop();
            }
            
            // push the current operator in stack. 
            push(expression[i]);
            
        }
        
        // else if current character is an opening bracket.
        else if(expression[i] == '(')
        {
            // push in stack. 
            push(expression[i]);
        }
        
        // else if current character is closing bracket.
        else if(expression[i] == ')')
        {
            /* keep popping the top element of stack and putting in answer string
            till top reached '(' . */
            while(peek() != '(')
            {
                answer[index++] = peek();
                pop();
            }
            
            // pop the '(' bracket as well.
            pop();
        }
        
    }
    
    // Pop all the remaining elements from the stack and put in answer.
    while(!is_empty()) 
    {
        answer[index++] = peek();
        pop();
    }
    
    // adding null character at end of string.
    answer[index++] = '\0';
    
    // printing the required answer string.
    printf("Postfix notation : %s\n" , answer);

}


int main()
{
    printf("Enter your expression in infix notation : \n");
    char expression[1000];
    scanf("%s", expression);
    
    // calling this to initialize stack with size = 0 and capacity = 2.
    initialize_stack();
    
    // Calling convert_to_postfix function.
    convert_to_postfix(expression);
    
    return 1;
}
