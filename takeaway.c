#include "functions.h"

int main(){
    int i;
    pthread_t p_chef;
    pthread_t p_customers[MAX_CUSTOMERS];

    sem_init(&sem_chef, 0, 0);
    sem_init(&sem_customers, 0, 0);
    sem_init(&mutex, 0, 0);

    pthread_create(&p_chef, NULL, chef, NULL);

    for(i = 0; i < MAX_CUSTOMERS; i++) {   
        pthread_create(&p_customers[i], NULL, customer, NULL);
        if( (i+1)%3 == 0) {
            sleep(3);
            printf("\n");
        }
    }

    sleep(6);
    printf("Main thread exiting\n");
}