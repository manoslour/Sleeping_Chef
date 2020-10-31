#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CUSTOMERS 9

/* Handles chef actions*/
void *chef(void *param);
/* Handles customer actions*/
void *customer(void *param);