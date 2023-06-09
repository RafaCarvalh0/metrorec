ESPECIFICAÇÕES
1. O programa deve ser implementado em C e ser executável em sistemas Linux, Unix ou macOS
e obrigatoriamente utilizar as seguintes funções:
- pthread_mutex_init
- pthread_mutex_lock
- pthread_mutex_unlock
- pthread_cond_init
- pthread_cond_signal
- pthread_cond_wait
- pthread_cond_broadcast

CONDIÇÕES
- Não utilize semáforos nem outras primitivas de sincronização
- Não deve utilizar mais que um único lock em cada struct estacao
- Deve assumir que nunca haverá mais que um carro na estação por vez, e que todos os carros
e passageiros estão indo para o mesmo destino
-O código deve permitir que passageiros embarquem simultaneamente, ou seja, precisa ser
permitido que diversos passageiros chamem estacao_espera_pelo_vagao, e que a função
retorne para cada passageiro antes de chamar estacao_embarque
- O código não deve apresentar busy-wait
- A compilação deve ser por Makefile, e retornar o arquivo metrorec executável
