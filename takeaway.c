#include "functions.h"

sem_t sem_chef;
sem_t sem_customer;

int main(){
    int i;
    pthread_t p_chef;
    pthread_t p_customers[MAX_CUSTOMERS];

    sem_init(&sem_chef, 0, 0);
    sem_init(&sem_customer, 0, 0);

    pthread_create(&p_chef, NULL, chef, NULL);
    for(i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Creating thread %d\n", i);
        pthread_create(&p_customers[i], NULL, customer, NULL);
        if( (i+1)%3 == 0) {
            printf("Main thread sleeping for some seconds\n");
            sleep(3);
        }
    }

    printf("Main thread exiting\n");
}