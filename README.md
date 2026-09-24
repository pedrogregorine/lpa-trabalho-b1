# Trabalho B1 - Logica de Programacao e Algoritmos

## Descricao
Simulador de entregas desenvolvido em linguagem C, executado em terminal.
O programa calcula o valor de cada solicitacao de entrega com base na
distancia, no peso, na modalidade escolhida, na contratacao de servico
de protecao e na quantidade de tentativas adicionais. Permite processar
varias entregas em uma mesma sessao e, ao final, apresenta um resumo
com os dados acumulados.

## Funcionalidades
- Leitura e validacao da distancia e do peso da entrega (devem ser maiores que zero)
- Leitura e validacao da modalidade (1 - Economica, 2 - Expressa, 3 - Prioritaria)
- Leitura e validacao do servico de protecao (0 - nao contratar, 1 - contratar)
- Leitura e validacao da quantidade de tentativas adicionais (inteiro maior ou igual a zero)
- Calculo do valor-base pela faixa de distancia, acrescido da tarifa por km
- Calculo dos adicionais de peso e de modalidade sobre o subtotal inicial
- Acrescimo do valor de protecao e das tentativas adicionais quando aplicavel
- Processamento de multiplas entregas em uma mesma execucao, com pergunta
  ao usuario se deseja continuar
- Resumo final da sessao: quantidade total de entregas, valor total, valor
  medio, quantidade de entregas por modalidade, maior e menor valor de entrega

## Organizacao da solucao
O programa foi dividido em funcoes com responsabilidades separadas, evitando
concentrar toda a logica na funcao main:

- **Funcoes de leitura e validacao** (criarDistanciaValida, criarPesoValido,
  criarModalidadeValida, criarProtecaoValida, criarTentativasValidas): leem
  um dado do usuario e repetem a leitura ate que o valor seja valido,
  devolvendo o valor por meio de return.
- **Funcoes de regra** (identificarValorBase, identificarPercentualPeso,
  identificarPercentualModalidade): recebem um dado da entrega por parametro
  e devolvem o valor-base ou o percentual correspondente, conforme as faixas
  definidas no roteiro.
- **calcularValorFinal**: recebe os dados da entrega por parametro, chama as
  funcoes de regra, aplica a ordem de calculo definida no roteiro e devolve
  o valor final da entrega.
- **exibirResumo**: recebe os totais acumulados durante a sessao por
  parametro e apresenta o resumo final.
- **main**: coordena o fluxo geral, chamando as demais funcoes dentro de um
  laco de repeticao que processa as entregas ate o usuario optar por encerrar.

Valores fixos das regras (tarifa por km, valor de protecao, valor por
tentativa adicional, valores-base por faixa de distancia e percentuais de
peso e modalidade) foram definidos como constantes com #define no inicio
do arquivo.

## Compilacao
gcc src/main.c -o entregas

## Execucao
./entregas

## Uso de Inteligencia Artificial
Utilizei a ferramenta Claude (Anthropic) como apoio ao aprendizado ao longo
de todo o desenvolvimento, ja que faltei a varias aulas da disciplina e
precisei entender do zero conceitos como funcoes, prototipos, estrutura
do-while e separacao de codigo em arquivos .h e .c.

Prompts e finalidades principais:
- Pedi explicacoes sobre o que e uma funcao, para que servem os prototipos
  e como funciona a divisao entre main.c e um arquivo .h, ja que nao tinha
  acompanhado essas aulas.
- Pedi revisao de trechos de codigo que eu mesmo escrevi para as validacoes
  das faixas de distancia, peso e adicional de peso, verificando se as
  condicoes (<=, <, &&) estavam de acordo com as faixas do roteiro.
- Pedi ajuda para entender e corrigir erros de sintaxe que eu cometi, como
  uso de = no lugar de ==, ausencia de ponto e virgula, uso de virgula em
  vez de ponto em numeros decimais, e blocos com chaves { } mal fechadas.
- Pedi ajuda para estruturar o laco de repeticao do-while que permite
  processar varias entregas na mesma execucao, ja que eu havia montado a
  estrutura de forma incompleta (sem o do correspondente ao while).
- Pedi ajuda para separar o codigo, que inicialmente estava todo dentro da
  main, em funcoes de leitura, funcoes de regra, calculo do valor final e
  exibicao do resumo, seguindo os requisitos de modularizacao do roteiro.
- Pedi ajuda para entender e corrigir o uso de constantes com #define no
  lugar dos valores fixos das regras.
- Pedi orientacao sobre os comandos de Git e GitHub (git init, git clone,
  git add, git commit, git push, git config), pois nunca havia usado
  controle de versao antes.

Todas as sugestoes recebidas foram revisadas, testadas por mim no programa
(incluindo os casos de teste da tabela do roteiro e os valores invalidos de
cada entrada) e ajustadas quando necessario. Compreendo o funcionamento de
cada funcao do codigo entregue e sou capaz de explica-lo.

## Fontes consultadas
Nenhuma alem do material da disciplina e das interacoes com a ferramenta
de IA citada acima.