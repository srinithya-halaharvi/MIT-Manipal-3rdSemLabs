#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;

sem_t full, empty_sem;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int buffer_size;
int num_items;
int *buffer ;


void *producer(void * arg){
    int in =0;
    for (int i=0; i<num_items; i++){
        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);
        buffer[in] = i;
        cout<<"Buffer out"<<i<<endl;
        in = (in + 1)%buffer_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
    
}

void *consumer(void * arg){
    int out = 0;
    for (int i=0; i<num_items; i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        cout<<"Consumer"<<buffer[out]<<endl;
        out = (out +1)%buffer_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
    pthread_exit(NULL);
}

int main(int argc , char** argv){

    if (argc!=3){
        cout<<"Enter correct parameters"<<endl;
        return 1;
    }

    buffer_size = atoi(argv[1]);
    num_items = atoi(argv[2]);

    buffer = new int[buffer_size];

    sem_init(&full, 0, 0);
    sem_init(&empty_sem, 0, buffer_size);

    pthread_t producer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_t consumer_thread;
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    
    //for (int i=0; i<num_items; i++){
        pthread_join(producer_thread, NULL);
        pthread_join(consumer_thread, NULL);
    //}

    sem_destroy(&full);
    sem_destroy(&empty_sem);

    return 0;
}