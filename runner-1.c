#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "metrorec.c"

volatile int threads_completed = 0;
volatile int load_car_returned = 0;

void *passenger_thread(void *arg)
{
    struct estacao *estacao = (struct estacao *)arg;
    estacao_espera_pelo_vagao(estacao);
    __sync_add_and_fetch(&threads_completed, 1);
    return NULL;
}

struct load_car_args
{
    struct estacao *estacao;
    int free_seats;
};

void *load_car_thread(void *args)
{
    struct load_car_args *ltargs = (struct load_car_args *)args;
    estacao_preencher_vagao(ltargs->estacao, ltargs->free_seats);
    load_car_returned = 1;
    return NULL;
}

int main(void)
{
    struct estacao estacao;
    estacao_init(&estacao);

    int i;
    const int total_passengers = 12;
    for (i = 0; i < total_passengers; i++)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, passenger_thread, &estacao);
    }

    for (i = 0; i <= 2; i++)
    {

        int free_seats = 2 * i + 2;
        printf("car entering station with %d free seats\n", free_seats);
        struct load_car_args args = {&estacao, free_seats};

        pthread_t lt_tid;
        pthread_create(&lt_tid, NULL, load_car_thread, &args);

        int threads_to_reap = free_seats;
        int threads_reaped = 0;

        while (threads_reaped < threads_to_reap)
        {
            if (threads_completed > 0)
            {
                threads_reaped++;
                estacao_embarque(&estacao);
                __sync_sub_and_fetch(&threads_completed, 1);
            }
        }

        printf("car departed station with %d new passenger(s) ",
               threads_reaped);
        printf("(expected %d)%s\n", threads_to_reap,
               (threads_to_reap != threads_reaped) ? " *" : "");
    }

    return 0;
}