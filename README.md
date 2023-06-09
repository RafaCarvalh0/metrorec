I. O PROBLEMA
A METROREC quer melhorar a eficiência, automatizando vagões e embarque de passageiros.
Para isso, contratou você para escrever funções de sincronização que irão garantir o embarque
dos vagões de forma ordenada. Nesse sistema, considere um único vagão por carro de metrô, e
cada vagão e passageiro são controlados por um thread independente. No desenvolvimento
desse sistema, você precisa definir a struct estacao e demais funções descritas abaixo.
Quanto um carro chega à estação e tem as portas abertas, chama-se a função
estacao_preencher_vagao (struct estacao *estacao, int assentos)
, em que assentos indica quantos assentos há no vagão. Essa função não retorna até o vagão
está satisfatoriamente preenchido: todos passageiros sentados, e ou o vagão está cheio ou
todos passageiros que estavam esperando embarcaram.
Quando um passageiro chega à estação, inicialmente chama a função
estacao_espera_pelo_vagao (struct estacao *estacao)
, que não retorna até um vagão está na estação, ou seja, estacao_preencher_vagao está em
execução, e que haja assentos livres no carro para o passageiro sentar-se. Um vez que essa
função retorne, o passageiro irá embarcar e ocupar um assento (esse mecanismo não é uma
preocupação sua). Uma vez o passageiro embarque, a seguinte função será chamada
estacao_embarque (struct estacao * estacao)
, indicando ao vagão que o passageiro embarcou. Importante ressaltar que não há ordem de
chegada, ou seja, o primeiro passageiro a chegar não necessariamente o primeiro a embarcar.
Outro ponto é que quando o vagão chega à estação, todos os passageiros são informados
simultaneamente de sua presença.
Implemente o arquivo metrorec.c que contem a declaração struct estacao e defina as três
funções acima, mais a estacao_init, que será chamada para inicializar o objeto estacao.
II. ESPECIFICAÇÕES
1. O programa deve ser implementado em C e ser executável em sistemas Linux, Unix ou macOS
e obrigatoriamente utilizar as seguintes funções:
- pthread_mutex_init
- pthread_mutex_lock
- pthread_mutex_unlock
- pthread_cond_init

- pthread_cond_signal
- pthread_cond_wait
- pthread_cond_broadcast
A não presença de uma das funções na codificação implica no descarte de toda a submissão
2. Não utilize semáforos nem outras primitivas de sincronização
3. Não deve utilizar mais que um único lock em cada struct estacao
4. Deve assumir que nunca haverá mais que um carro na estação por vez, e que todos os carros
e passageiros estão indo para o mesmo destino
5. O código deve permitir que passageiros embarquem simultaneamente, ou seja, precisa ser
permitido que diversos passageiros chamem estacao_espera_pelo_vagao, e que a função
retorne para cada passageiro antes de chamar estacao_embarque
6. O código não deve apresentar busy-wait
7. A compilação deve ser por Makefile, e retornar o arquivo metrorec executável
III. O QUE SUBMETER NO FORM DO CLASSROOM
1. Um arquivo login.pdf, em que login corresponde as iniciais do e-mail em minúsculas,
indicando de forma clara e objetiva a sua lógica de sincronização. Submissão sem esse
arquivo com as informações correspondentes será descartada. Em caso de descrever no
arquivo que algo foi realizado mas a implementação correspondente não foi identificada,
toda a submissão será descartada. O arquivo deverá conter uma única página e
obrigatoriamente respeitar a seguinte formatação:
• Margens superior e esquerda de 3 cm e margens inferior e direita de 2 cm.
• Página tamanha A4
• Fonte Arial ou Times New Roman (tamanho 12);
• Espaçamento 1,5 no texto
• Alinhamento: Justificado

2. O arquivo de implementação (metrorec.c) de acordo com a descrição apresentada no início
desde documento
IV. PONTUAÇÃO
Relatório - 20% (apenas considerado em caso de funcionamento correto de pelo menos um dos
testes de implementação, e a nota estará de acordo com a clareza do documento)
Implementação Teste 1 - 30%
Implementação Teste 2 - 50%
Caso a turma apresente um teste válido, a pontuação será:

Relatório - 20% (apenas considerado em caso de funcionamento correto de pelo menos um dos
testes de implementação, e a nota estará de acordo com a clareza do documento)
Implementação Teste Turma - 10%
Implementação Teste 1 - 30%
Implementação Teste 2 - 40%
