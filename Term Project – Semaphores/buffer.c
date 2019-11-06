#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include <pthread.h>

//the buffer used from buffer.h max size of 5
buffer_item buffer[BUFFER_SIZE];

//to count the buffer to not go above the max buffer size
//and to know where the current buffer is.
int CBuf = 0;

void *producer(void *param) {
	
	buffer_item item;
	
	while (true) {
		/* sleep for a random period of time */
		sleep(rand() % 3 + 1);
		/* generate a random number */
		item = rand();
		if (insert item(item)){
			fprintf("error cannot add item");
		}
		else{
			printf("producer produced %d\n",item);
		}
	}
}
void *consumer(void *param) {
	buffer_item item;
	
	while (true) {
		/* sleep for a random period of time */
		sleep(rand() % 3 + 1);
		if (remove item(&item)){
			fprintf("error cannot remove item");
		}
		else{
			printf("consumer consumed %d\n",item);
		}
	}
}

int insert item(buffer item item) 

	if(CBuf != BUFFER_SIZE){ //checks if the current buffer is full or not 
		buffer[CBuf] = item; //adds item to buffer
		CBuf++; //after adding item to buffer it moves the current buffer count.
		return 0; //success added to buffer
	}
	else{
		return -1 //error = buffer full 
	}
	/* insert item into buffer
	return 0 if successful, otherwise
	return -1 indicating an error condition */
}
int remove item(buffer item *item) {
	//empty value to set as removal of the buffer
	int empty = buffer[0];

	if(CBuf != 0){ //if the buffer is empty it does not run
		*item = empty; //removes the buffer
		CBuf--;	//removing the item from buffer made the buffer 1 less.
		return 0;		//statement was successful
	}
	else{
		return -1;	//error the buffer is empty or cannot be removed.
	}
	/* remove an object from buffer
	placing it in item
	return 0 if successful, otherwise
	return -1 indicating an error condition */
}

int main(int argc, char *argv[]) {
	
	/* 1. Get command line arguments argv[1],argv[2],argv[3]
	*/
	/* 2. Initialize buffer */
	/* 3. Create producer thread(s) */
	/* 4. Create consumer thread(s) */
	/* 5. Sleep */
	/* 6. Exit */
	
}











