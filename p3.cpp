
//May 7th 2022
//Threads and Fibonacci


#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include<unistd.h>

using namespace std;

int *fib;

void* thread_fib(void *arg)   // Thread function
{
    int i=*((int *)arg);
    if (i == 0)     // if i=0 ,then set first fibonacci number=0
    {
        fib[i] = 0;
    }

    else if (i == 1)   // if i=1 ,then set second  fibonacci number=1
    {
        fib[i] = 1;
    }
    else
    {
        // else calculate fibonacci number as fib[i] = fib[i - 1] + fib[i - 2]
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    pthread_exit(NULL);
}



int main(int argc, char *argv[])
{
    int n,i;

    if (argc != 2)
    {
        cout<<"Not enough arguments"<<endl;
        exit(0);
    }
    n = atoi(argv[1]);
    if (n <=0 )
    {
        cout<<"Include a number greater than zero "<<endl;
        exit(0);
    }


    n = atoi(argv[1]);
    fib = new int[n];  // create array for storing fibonacci numbers

    pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));

    for (i = 0; i < n; i++)
    {
        pthread_create(&threads[i], NULL, thread_fib, (void *) &i);
        sleep(1);
    }


    for (i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }// End of wating the threads to exit.
    for (i=0; i<n; ++i)
        cout<<fib[i]<<endl;

    delete fib;
    pthread_exit(NULL);
    return 0;
}
