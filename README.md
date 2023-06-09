-ESPECIFICAÇÕES
O programa deve ser implementado em C e ser executável em sistemas Linux, Unix ou macOS
e obrigatoriamente utilizar as seguintes funções:
pthread_mutex_init, pthread_mutex_lock, pthread_mutex_unlock, pthread_cond_init, pthread_cond_signal, pthread_cond_wait, pthread_cond_broadcast

-CONDIÇÕES
1. Não utilize semáforos nem outras primitivas de sincronização
2. Não deve utilizar mais que um único lock em cada struct estacao
3. Deve assumir que nunca haverá mais que um carro na estação por vez, e que todos os carros
e passageiros estão indo para o mesmo destino
4. O código deve permitir que passageiros embarquem simultaneamente, ou seja, precisa ser
permitido que diversos passageiros chamem estacao_espera_pelo_vagao, e que a função
retorne para cada passageiro antes de chamar estacao_embarque
5. O código não deve apresentar busy-wait
6. A compilação deve ser por Makefile, e retornar o arquivo metrorec executável

-PROGRAMAS
1. Para rodar o programa basta ter 3 arquivos: metrorec.c, metrorec-runner.c e Makefile
2. O metrorec.c contem o código da implementação 
3. O metrorec-runner.c contem 1 dos 2 arquivos de teste
4. Arquivo Makefile

- Após pegar os 3 arquivos necessarios, utilizar os seguintes comandos via terminal:
1. make
2. ./metrorec
