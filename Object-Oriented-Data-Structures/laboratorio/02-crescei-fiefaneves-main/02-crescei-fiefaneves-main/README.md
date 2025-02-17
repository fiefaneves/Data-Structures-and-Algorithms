[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/S0ec05MS)

# Crescei, transformai-vos e multiplicai-vos

## Descrição

Considere as estruturas lineares 'filas' e 'pilhas' com as habituais operações de inserção e remoção de elementos: insert=enqueue, delete=dequeue, no caso das filas, e insert=push,  delete=pop, no caso das pilhas.

Considere ainda as sequintes operações adicionais split, merge e transform, descritas a seguir.

### FILAS:

* **split**  = divide uma fila em duas metades

```
(head) A B C D E F G H I J K (tail) ----> A B C D E  ,  F G H I J K
```

* **merge**  = une duas filas numa só

```
A B C D E,  F G H  ----> A B C D E F G H
```

* **transform** = tranforma uma fila em pilha

```
(front) A B C D E (rear) ---->   A  (top)
                                 B
                                 C
                                 D
                                 E
```

### PILHAS:

* **split** = divide uma pilha em duas metades

```
A               
B             A       D
C    ---->    B   ,   E
D             C       F
E                     G
F
G
```

* **merge** = une duas pilhas numa só
                      
```
                     A
                     B 
A                    C  
B   ,   D   ---->    D
C       E            E    
```


* **transform** = transforma uma pilha numa fila

```
A (top)
B
C  ---->  (head) A B C D E (tail)
D
E
```

Vamos exercitar essas operações sobre uma sequência de filas ou pilhas de números inteiros. 


## Formato de entrada

A entrada inicia com uma linha com um inteiro
```
N
```
correspondente ao número de casos de teste.

Em seguida temos as definições dos `N` casos de testes.

Em cada caso, temos inicialmente uma sequência contendo apenas uma fila vazia na posição 0.
Teremos então uma lista de operações, podendo cada operação ser uma das seguintes.

- `ADD i v`   = insere o valor `v` na fila/pilha da posição `i`
- `DEL i`     = remove um elemento da fila/pilha da posição `i`, se houver
- `SPL i`     = divide a fila/pilha da posição `i` em duas metades
- `MER i j`   = combina as filas/pilhas das posições `i` e `j` numa só
- `TRA i`     = transforma a fila/pilha da posição `i` numa pilha/fila.
- `END`       = indica o final da sequência de operações 

#### OBSERVAÇÕES

-  Ao se dividir a fila/pilha  da posição `i` em duas metades, as filas/pilhas resultantes passarão a ocupar as posições `i` e `i+1` respectivamente, sendo as filas/pilhas posteriores deslocadas uma posição à direita

-  Ao se dividir uma fila/pilha com uma quantidade ímpar de elementos, `m`, a primeira e segunda fila/pilha resultantes devem ter respectivamente `floor(n/2)` e `ceil(n/2)` elementos.

- Uma remoção de elemento de uma fila/pilha já vazia deve ser considerada como uma operação sem efeito

-  Ao se unir as filas/pilhas das posições `i` e `j`, a fila/pilha resultante passará a ocupar a posição `i`, sendo as filas/pilhas das posições `j+1, j+2, ...`  deslocadas uma posição à esquerda
 
-  Ao final da sequência de operações correspondente a cada caso temos uma linha em branco.


## Formato de saída

Para cada caso no arquivo de entrada, imprimir uma linha no formato
```
caso C: X0 X1 ... Xk`
```
onde,

- `C` = número do caso (iniciado em 0)
- `Xk` = elemento na frente/topo da fila/pilha da posição `k` ao final da sequência de operações. Caso a fila/pilha da posição `k` esteja vazia, imprimir '?'


## Instruções de Implementação

- Completar o arquivo [list.hpp](./list.hpp) que contém as definições dos tipos usados na solução:
    - Uma classe abstrata parametrizada `List<T>` para uma lista de elementos do tipo `T`
    - Uma classe derivada `LinkedList<T>` de `List<T>` 
    - Uma classe abstrata parametrizada `SQ<T>` para uma fila/pilha de elementos do tipo `T`.
    - `SQ<T>` deve usar **composição** para especializar `LinkedList<T>`

- Completar o arquivo [solver.cpp](./solver.cpp) que é usado para gerar o executável da solução
- Não alterar o arquivo [sanity.cpp](./sanity.cpp)
- Não alterar os arquivos de entradas/saidas de teste (*.in, *.out)
- **FAZER COMMIT APENAS DAS MODIFICAÇÕES DOS ARQUIVOS [list.hpp](./list.hpp) e [solver.cpp](./solver.cpp)**. **NÃO ADICIONAR NOVOS ARQUIVOS AO REPOSITÓRIO**.





