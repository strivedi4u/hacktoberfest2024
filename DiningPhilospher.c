#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers

sem_t forks[N];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = (id + 1) % N;

    while (1) {
        // Think
        printf("Philosopher %d is thinking.\n", id);

        // Pick up left fork
        sem_wait(&forks[left_fork]);
        printf("Philosopher %d picked up left fork %d.\n", id, left_fork);

        // Pick up right fork
        sem_wait(&forks[right_fork]);
        printf("Philosopher %d picked up right fork %d.\n", id, right_fork);

        // Eat
        printf("Philosopher %d is eating.\n", id);

        // Put down right fork
        sem_post(&forks[right_fork]);
        printf("Philosopher %d put down right fork %d.\n", id, right_fork);

        // Put down left fork
        sem_post(&forks[left_fork]);
        printf("Philosopher %d put down left fork %d.\n", id, left_fork);

        // Repeat the cycle
        sleep(1);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    // Initialize semaphores for each fork
    for (int i = 0; i < N; ++i) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (int i = 0; i < N; ++i) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join philosopher threads (this will never be reached in this simple example)
    for (int i = 0; i < N; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy semaphores
    for (int i = 0; i < N; ++i) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
