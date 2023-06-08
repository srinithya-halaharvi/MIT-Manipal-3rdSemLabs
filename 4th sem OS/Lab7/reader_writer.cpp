#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t mutex_read, mutex_write;
int read_count = 0;
int no_reader, no_writer;

void *reader(void *a){
    int arg = *(int*)a;
    sem_wait(& mutex_read);
    read_count++;
    if (read_count == 1){
        sem_wait(&mutex_write);
    }
    sem_post(&mutex_read);
    cout<<"Reader at work "<<arg<<endl;
    sleep(1);
    sem_wait(&mutex_read);
    read_count--;
    if (read_count == 0){
        sem_post(&mutex_write);
    }
    cout<<"Reader done "<<arg<<endl;
    sem_post(&mutex_read);
    pthread_exit(NULL);
}

void * writer(void * a){
    int arg = *(int*)a;
    sem_wait(&mutex_write);
    cout<<"Writer at work"<<arg<<endl;
    cout<<"Writer done"<<arg<<endl;
    sem_post(&mutex_write);
    pthread_exit(NULL);
}

int main(int argc, char **argv){

    if (argc!=3){
        cout<<"Enter correct parameters"<<endl;
        return 1;
    }

    no_reader = atoi(argv[1]);
    no_writer = atoi(argv[2]);

    pthread_t readers[no_reader];
    pthread_t writers[no_writer];

    int reader_ids[no_reader];
    int writer_ids[no_writer];

    for (int i=0; i<no_reader; i++){
        reader_ids[i] = i+1;
    }

    for (int i=0; i<no_writer; i++){
        writer_ids[i] = i+1;
    }

    sem_init(&mutex_read, 0, 1);
    sem_init(&mutex_write, 0, 1);

    for (int i=0; i<no_reader; i++){
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int j=0; j<no_writer; j++){
        pthread_create(&writers[j], NULL, writer, &writer_ids[j]);
    }

    for (int i=0; i<no_reader; i++){
        pthread_join(readers[i], NULL);
    }

    for (int j=0; j<no_writer; j++){
        pthread_join(writers[j], NULL);
    }

    sem_destroy(&mutex_read);
    sem_destroy(&mutex_write);




    return 0;
}