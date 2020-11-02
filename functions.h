#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CUSTOMERS 9

extern sem_t sem_chef;
extern sem_t sem_customers;
extern sem_t mutex;

void *chef(void *param);

void *customer(void *param);