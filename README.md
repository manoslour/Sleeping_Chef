# Sleeping_Chef
A modified version of the Sleeping barber problem solved with semaphores.

Three semaphores are being used:  
extern sem_t sem_chef;
extern sem_t sem_customers;
extern sem_t mutex;  

The order of code execution in highlighted in comments.  

To run:  
$ make all
$ ./demo