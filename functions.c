#include "functions.h"

sem_t sem_chef;
sem_t sem_customers;
sem_t mutex;

void *chef(void *param) {
    while(1) {
        sem_wait(&sem_customers); // 3
        printf("Chef is ready to take order\n"); // 4
        sem_post(&sem_chef); // 5
        sem_wait(&mutex); // 9
        printf("Order is ready\n\n"); // 10
    }
}

void *customer(void *param) {
    printf("Customer entered souvlatzidiko\n"); // 1
    sem_post(&sem_customers); // 2
    sem_wait(&sem_chef); // 6
    printf("Customer is giving order\n"); // 7
    sem_post(&mutex); // 8
}