#include "functions.h"

int main(){
    int rc;
    intptr_t t;
    pthread_t p_chef;
    pthread_t p_customers[MAX_CUSTOMERS];

    sem_init(&sem_chef, 0, 0);
    sem_init(&sem_customers, 0, 0);
    sem_init(&mutex, 0, 0);

    pthread_create(&p_chef, NULL, chef, NULL);

    for(t = 0; t < MAX_CUSTOMERS; t++) {
        //printf("In main: creating thread %ld\n", (long) t);
        rc = pthread_create(&p_customers[t], NULL, customer, (void *)t);
        if(rc) {
            perror("Failed to create thread\n");
        }
        if( (t+1)%3 == 0) {
            sleep(3);
            printf("\n\n");
        }
    }

    sleep(4);
    printf("\nMain thread exiting\n");
}