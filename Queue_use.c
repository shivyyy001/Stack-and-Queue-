
/**
 * Program to implement Dynamic circular queue in c.
 * Compilation : gcc Queue_use.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 02/8/2021
 * Day_2_Coding_Assignment.
 *
 */


/*

Runtime Complexities of created Functions :

enqueue()      -> O(1) if no resizing needed.
               -> O(size) if resizing needed.

dequeue()      -> O(1).

peek()         -> O(1).

is_empty()     -> O(1).

getsize()      -> O(1).

get_capacity   -> O(1).

resize()       -> o(size).

*/



#include <stdio.h>
#include<stdlib.h>

// initializing variables current size = 0 and current capacity = 2.
int size = 0;
int capacity = 2;

// firstindex is the frontindex to access peak element.
int firstindex = -1;
// putindex is where to put next element .
int putindex = 0;

// creating queue array.
int *queue; 


// Function to initialize queue array with initial capacity = 2.
void initialize_queue()
{
    // using calloc function to initialize array with capacity = 2
    queue = (int*)calloc(capacity , sizeof(int));
}


// Function to resize the queue array , if it gets full.
void resize()
{
    // making the capacity double.
    capacity = capacity * 2;
    
    // creating and initializing a new array of double capacity;
    int *newarr;
    newarr = (int*)calloc(capacity , sizeof(int));
    
    // count represents the current index of new array.
    int count = 0;
    
    // copying the queue array elements to this newly created array of double capacity.
    for(int i = firstindex ; count < size ; i = (i+1)%size)
    {
        newarr[count] = queue[i]; 
        count++;
    }
    
    // making firstindex as 0 and putindex as size because the circular queue is now,
    // copied straight from queue array to new array.
    firstindex = 0;
    putindex = size;
    
    // pointing the newly created array to queue array.
    queue = newarr;
}


// Function to add a new element at tail of the queue.
void enqueue(int value)
{
    // if size equals capacity , then calling resize function.
    if(size == capacity)
    {
        resize();
    }
    
    // putting the value at putindex.
    queue[putindex] = value;
    
    // incrementing the putindex and % it with capacity to ensure elements are put
    // in circular manner if array is not full and putindex has reached end.
    putindex++;
    putindex = putindex % capacity;
    
    // incrementing size.
    size++;
    
    // if size is 1 then firstindex changes from -1 to 0. 
    if(size == 1)
    {
        firstindex = 0;
    }
    
}


// Function to remove and return the element at head of the queue.
int dequeue()
{
    // if size is greater than 0 && firstindex is not -1.
    if(firstindex != -1 && size != 0)
    {
        // extracting the front element.
        int front = queue[firstindex];
        // incrementing the frontindex.
        firstindex++;
        firstindex = firstindex % capacity;
        
        //decreasing the size.
        size--;
        
        // if size is 0 then make firstindex to -1 and putindex to 0 again.
        if(size == 0)
        {
            firstindex = -1;
            putindex = 0;
        }
        
        // return front element.
        return front;
    }
    else
    {
        // else return -1
        return -1;
    }
}


// Function to only return the element at head of the queue , not remove.
int peek()
{
    if(firstindex == -1 || size == 0)
    {
        return -1;
    }
    else
    {
        // returning the front element of queue.
        return queue[firstindex];
    }
}


// Function to check if queue is empty or not.
int is_empty()
{
    // return 1 is queue is empty.
    if(size == 0)
    {
        return 1;
    }
    //else return 0.
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


int main() {
	
    // initializing dynamic circular queue with capacity.
    initialize_queue(); 
	
	
    // Testing queue with all basic operations ->

    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    printf("Adding 2 elements ->\n");
    enqueue(1); 
    enqueue(2);
    
    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    
    printf("Adding 2 more elements ->\n");
    enqueue(3);
    enqueue(4);
    
    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    
    printf("Deleting 2 elements ->\n");
    printf("Dequeued element : %d \n" , dequeue());
    printf("Dequeued element : %d \n" , dequeue());
    
    printf("Adding 2 elements ->\n");
    enqueue(5);
    enqueue(6);
    
    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    
    printf("Deleting 2 elements ->\n");
    printf("Dequeued element : %d \n" , dequeue());
    printf("Dequeued element : %d \n" , dequeue());
    
    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    
    printf("Adding 2 elements ->\n");
    enqueue(7);
    enqueue(8);
    printf("Size = %d , Capacity = %d \n" , getsize() , get_capacity());
    
    printf("Peak element -> %d\n" , peek());
    
    printf("Is queue empty ? -> %d" , is_empty());
    printf("\nPrinting and deleting leftout queue elements -> \n");
    
    int sz = getsize();

    for(int i = 0 ; i < sz ; i++)
    {
        printf("%d ",peek());
        dequeue();
    }
	
    printf("\nIs queue empty ? -> %d \n" , is_empty());
	
    return 1;
	
}
