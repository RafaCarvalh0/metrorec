#include <pthread.h>

struct estacao
{
    int assentos_disponiveis;
    int passageiros_esperando;
    int passageiros;
    pthread_mutex_t lock;
    pthread_cond_t vagao_chegou;
    pthread_cond_t vagao_partiu;
};

void estacao_init(struct estacao *estacao)
{
    estacao->assentos_disponiveis = 0;
    estacao->passageiros_esperando = 0;
    estacao->passageiros = 0;
    pthread_mutex_init(&estacao->lock, NULL);
    pthread_cond_init(&estacao->vagao_chegou, NULL);
    pthread_cond_init(&estacao->vagao_partiu, NULL);
}

void estacao_preencher_vagao(struct estacao *estacao, int assentos)
{
    pthread_mutex_lock(&estacao->lock);

    while (estacao->passageiros < assentos && estacao->passageiros_esperando > 0)
    {
        pthread_cond_signal(&estacao->vagao_chegou);
        pthread_cond_broadcast(&estacao->vagao_partiu);
        pthread_cond_wait(&estacao->vagao_partiu, &estacao->lock);
    }
    estacao->assentos_disponiveis = 0;
    estacao->passageiros = 0;
    pthread_mutex_unlock(&estacao->lock);
}

void estacao_espera_pelo_vagao(struct estacao *estacao)
{
    pthread_mutex_lock(&estacao->lock);
    estacao->passageiros_esperando++;
    pthread_cond_wait(&estacao->vagao_chegou, &estacao->lock);
    estacao->passageiros_esperando--;
    estacao->assentos_disponiveis--;
    pthread_mutex_unlock(&estacao->lock);
}

void estacao_embarque(struct estacao *estacao)
{
    pthread_mutex_lock(&estacao->lock);
    estacao->passageiros++;
    pthread_cond_signal(&estacao->vagao_partiu);
    pthread_mutex_unlock(&estacao->lock);
}