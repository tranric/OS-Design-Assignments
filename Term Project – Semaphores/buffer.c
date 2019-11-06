#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include <pthread.h>

buffer_item buffer[BUFFER_SIZE];

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

int insert item(buffer item item) {
	/* insert item into buffer
	return 0 if successful, otherwise
	return -1 indicating an error condition */
}
int remove item(buffer item *item) {
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











