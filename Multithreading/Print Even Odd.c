#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 2

pthread_mutex_t mutexCount;
pthread_cond_t  CondOddEven;


int count = 0;

void* printEven(void* arg)
{

    while(1)
    {

        pthread_mutex_lock(&mutexCount);


        while(count%2)
        {
            pthread_cond_wait(&CondOddEven, &mutexCount);
            
        }
        
        if(count % 2 == 0)
        {
            printf("printEven: %d \n", count);
            count++;
        }    
        pthread_mutex_unlock(&mutexCount);
        pthread_cond_signal(&CondOddEven);
    }
}

void* printOdd(void *arg)
{
    while(1)
    {

        pthread_mutex_lock(&mutexCount);
        
        while(count%2 == 0)
        {
            pthread_cond_wait(&CondOddEven, &mutexCount);
            
        }

        if(count % 2)
        {
            printf("printOdd: %d \n", count);
            count++;   
        }    
        pthread_mutex_unlock(&mutexCount);
        pthread_cond_signal(&CondOddEven);
    }
}


int main()
{
    int th[THREAD_NUM] = {0};

    pthread_mutex_init(&mutexCount, NULL);
    pthread_cond_init(&CondOddEven, NULL);
    

    for(int i = 0 ; i < THREAD_NUM; i++)
    {
        if(i = 0)
        {
            pthread_create(&th[i], NULL, (void *) &printEven, NULL);
        }
        else
        {
            pthread_create(&th[i], NULL, (void *) &printOdd, NULL);
        }
    }
    
    for(int i = 0 ; i < THREAD_NUM; i++)
    {
        pthread_join(&th[i], NULL);
    }

    pthread_mutex_destroy(&mutexCount);
    pthread_cond_destroy(&CondOddEven);


    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// If you dont want to use conditional SEMAPHORES
///////////////////////////////////////////////////////////////////////////////////

sem_t semEven;
sem_t semOdd;

void* printEven(void* arg)
{
    for(i = 0; i <= N ; i+=2)
    {
        sem_wait(&semEven);
        printf("Even: %d\n", i);
        sem_post(&semOdd);

    }
}

void* printOdd(void *arg)
{
    for(i = 1; i <= N ; i+=2)
    {
        sem_wait(&semOdd);
        printf("Odd: %d\n", i);
        sem_post(&semEven);
    }

}
int main()
{
    int th[THREAD_NUM] = {0};

    sem_init(&semEven, 0, 1);
    sem_init(&semOdd, 0, 0);
    
    

    for(int i = 0 ; i < THREAD_NUM; i++)
    {
        if(i = 0)
        {
            pthread_create(&th[i], NULL, (void *) &printEven, NULL);
        }
        else
        {
            pthread_create(&th[i], NULL, (void *) &printOdd, NULL);
        }
    }
    
    for(int i = 0 ; i < THREAD_NUM; i++)
    {
        pthread_join(&th[i], NULL);
    }

    sem_destroy(&semEven);
    sem_destroy(&semOdd);

    return 0;
}