/*Group Project creted by Richard Tran and Daniel Sacchetto */


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define TRUE 1

typedef int buffer_item;
#define BUFFER_SIZE 5

/*lock for the mutex*/
pthread_mutex_t mutex;

/* the semaphores setup*/
sem_t full, empty;

/* the buffer been initizialized*/
buffer_item buffer[BUFFER_SIZE];

/* counter for the buffer*/
int counter;

pthread_t tid;       //Thread ID
pthread_attr_t attr; //Thread attributes

void *producer(void *param); /* the producer  */
void *consumer(void *param); /* the consumer  */
void initializeData() {

   /* the mutex lock is created*/
   pthread_mutex_init(&mutex, NULL);

   /* the full semaphore is created and initialize to 0 */
   sem_init(&full, 0, 0);

   /* the empty semaphore is created and initialize to BUFFER_SIZE */
   sem_init(&empty, 0, BUFFER_SIZE);

   /* default attributes */
   pthread_attr_init(&attr);

   /* buffer been initialized */
   counter = 0;
}

/* Thread for producing the number*/
void *producer(void *param) {
   buffer_item item;

   while(TRUE) {
      /* sleep for a random period of time */
      int rNum = rand() % 3 + 1;
      sleep(rNum);

      /* generate a random number */
      item = rand();

      /* acquire the empty lock */
      sem_wait(&empty);
      /* acquire the mutex lock */
      pthread_mutex_lock(&mutex);

      if(insert_item(item)) {
         fprintf(stderr, " Producer report error condition\n");
      }
      else {
         printf("Producer produced %d\n", item);
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal full */
      sem_post(&full);
   }
}

/* Thread for consuming the number*/
void *consumer(void *param) {
   buffer_item item;

   while(TRUE) {
      /* sleep been called */
      int rNum = rand() % 3 + 1;
      sleep(rNum);

      /* aquire the full lock */
      sem_wait(&full);
      /* aquire the mutex lock */
      pthread_mutex_lock(&mutex);
      if(remove_item(&item)) {
         fprintf(stderr, "Consumer report error condition\n");
      }
      else {
         printf("Consumer consumed %d\n", item);
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal empty */
      sem_post(&empty);
   }
}

/* Adding an item to the buffer */
int insert_item(buffer_item item) {
   /* When the buffer is not full add the item
      and increment the counter*/
   if(counter < BUFFER_SIZE) {
      buffer[counter] = item;
      counter++;
      return 0;
   }
   else { /* Error the buffer is full */
      return -1;
   }
}

/* Removing an item from the buffer */
int remove_item(buffer_item *item) {
   /* When the buffer is not empty remove the item
      and decrement the counter */
   if(counter > 0) {
      *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else { /* Error buffer empty */
      return -1;
   }
}

int main(int argc, char *argv[]) {
   /* counter for the loop*/
   int i=0;

   /* Verify that the number of arguments were passed in is correct*/
   if(argc != 4) {
      fprintf(stderr, "USAGE:./buffer.c arg1 arg2 arg3");
   }

   int mainSleepTime = atoi(argv[1]); /* sleep on the main method */
   int numProd = atoi(argv[2]); /*  producer threads */
   int numCons = atoi(argv[3]); /*  consumer threads */

   /* app started */
   initializeData();

   /* Creates thread for producer */
   for(i = 0; i < numProd; i++) {
      /* Create the thread */
      pthread_create(&tid,&attr,producer,NULL);
    }

  /* Creates thread for consumer */
   for(i = 0; i < numCons; i++) {
      /* Create the thread */
      pthread_create(&tid,&attr,consumer,NULL);
   }

   /* set sleep for the alloted time declared above */
   sleep(mainSleepTime);

   exit(0);
}
