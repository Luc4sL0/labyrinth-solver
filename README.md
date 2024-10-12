## Introdução

Esse trabalho acadêmico busca construir um algoritmo utilizando a linguagem de programação C para encontrar, caso seja possível, um caminho que leva à saída de um labirinto de tamanho 10x10. 
A aplicação construída para esse fim, recebe como entrada um arquivo texto (.txt) com um conjunto de 100 caracteres (cada caractere representa uma posição do labirinto). Foi previamente definido no escopo do problema que o caractere ‘E’ representa a entrada, ‘0’ representa o caminho, ‘X’ denota uma parede e ‘S’ indica a saída. Se o labirinto for processado com êxito pelo programa, o caminho necessário para solucioná-lo é disponibilizado no terminal, no formato (coluna, linha) para cada posição que deve ser percorrida. 

## Estrutura de dados

Para solucionar o problema descrito acima, utilizou-se algumas estruturas de dados, dentre elas: pilha encadeada e vetores bidimensionais. A pilha foi utilizada para gravar o caminho percorrido da entrada até a saída, por sua vez, os vetores bidimensionais foram usados para armazenar o labirinto presente no arquivo. Confira abaixo mais detalhes acerca dessas estruturas.

### Pilha encadeada: 
é uma estrutura de dados no qual o último elemento a ser adicionado é o primeiro que deve ser removido. A manipulação dessa estrutura é similar a uma pilha de pratos, uma vez que, para acessar o primeiro prato é necessário remover todos os outros que estão acima. A pilha escolhida foi alocada dinamicamente, visto que teoricamente, podem existir caminhos compostos por muitas ou poucas posições, dessa maneira, torna-se impreciso definir um tamanho máximo para essa estrutura.

### Vetores bidimensionais: 
é uma estrutura sequencialmente alocada na memória que possui a finalidade de guardar todas as posições do labirinto e seus respectivos caracteres na memória principal. Já que existem linhas e colunas no labirinto, torna-se necessário construir um vetor bidimensional para guardar essas informações. O tamanho máximo dessa estrutura é igual a ,   ℕ ( é o número de linhas e colunas).

É importante ressaltar que cada elemento da pilha corresponde a uma estrutura do tipo pathEl, que possui os campos line, column e next. Por sua vez, cada posição do vetor bidimensional corresponde a uma variável do tipo char.
