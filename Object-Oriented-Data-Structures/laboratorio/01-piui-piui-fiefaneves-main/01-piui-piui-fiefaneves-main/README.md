[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/YwbWCKTw)
## Piui-piui

### Descrição

Uma estação ferroviária recebe composições de vagões por uma entrada única e os encaminha através de dois terminais  de comutação. Uma vez chegado à estação, cada vagão é dirigido a um ou outro terminal. Em ambos os terminais, os vagões são admitidos por uma entrada e liberados por uma saída, ambos de sentido único. 


Terminal 0

```

============\    /============ 
 ---->      \\  //    ---->
  entrada    \\//    saída
          |   ||   ^
          |   ||   |
          | ...... | 
          v : || : |
            : || :
            : || :
            : || : area de
            : || : manobra
            : || : 
            :....:
              || 
              --
```


Terminal 1

```

          . . . . .   entrada    . . . . . .      
         /                                  \   
        /    .=========================.\    |
       /    //                          ||   | 
      /    //     ................      ||   / 
  ---+--> // -->  :    area de   :  <- // ---
==================:==============:===================
            //    :    manobra   :      //  
       .-  || <-- :..............: --> // ----+--->
      /    ||                         //     /
      |    '==========================/     /
      |                                    / 
       \ . . . . . .  saída  . . . . . . .   

```


Em outras palavras, no Terminal 0, os vagões admitidos entram numa área de manobra por um acesso único, de onde são depois retirados na ordem inversa de entrada pela mesmo acesso.

No Terminal 1, os vagões que são admitidos na entrada podem entrar na área da manobra tanto pela extremidade esquerda quanto pela direita. Da mesma maneira, um vagão pode sair da área de manobra e, consequentemente, do terminal, tanto pela  esquerda quanto pela direita.

Esses dois terminais permitem permutar a ordem de composição dos vagões. Sua tarefa será a determinar a ordem de saída dos vagões sujeitos a manobras de comutação.


### Formato de Entrada

A entrada consiste de vários casos, cada um correspondendo a um  cenário de comutação. Em cada caso, supomos que os vagões chegam à estação em ordem numérica crescente (vagões #0, 1, 2, 3,...). Os terminais estão incialmente vazios. Ao final, queremos determinar a ordem dos vagões na saída. 

Cada caso consiste, portanto, em uma sequência de "operações", uma por linha. As seis operações possíveis são as seguintes:

* E0 = entrada de vagão no Terminal 0
* S0 = saída de vagão do Terminal 0, se houver vagão na área de manobra
* E1E = entrada de vagão no Terminal 1 pelo acesso da esquerda
* E1D = entrada de vagão no Terminal 1 pelo acesso da direita
* S1E = saída de vagão do Terminal 1 pelo acesso da esquerda, se houver
* S1D = saída de vagão do Terminal 1 pelo acesso da direita, se houver

O final do caso é indicado pela operação 
```
FIM
```

seguido por uma linha em branco.

Por simplicidade, supomos que as áreas de manobra são ilimitadas, isto é, podem acomodar tantos vagões quantos forem solicitados.

Após a operação FIM, podem ainda restar vagões nas áreas de manobra dos terminais.


### Formato de saída

Em cada caso, devem ser impressos o número dos vagões por ordem de  saída da estação, sendo um por linha.  Por fim, devem ser impressas duas linhas contendo o número de vagões restantes nos terminais 0 e 1,  respectivamente, após a operação FIM.

Após cada caso, deve ser impressa uma linha em branco.


### Instruções

* Modifique o arquivo [solver.cpp](solver.cpp) e faça commit sem mudar o nome do arquivo ou qualquer outro arquivo do repositório.
* Atenção às instruções nos comentários desse arquivo.
* A cada commit o sistema tentará executar os testes
```
make test1
...
make test4
```
* Cada teste de número `X=1..4`:
    * Compila o programa `solver.cpp`
    * Executa o programa redirecionando o arquivo `X.in` para a entrada padrão e a saída padrão para o arquivo `saida.X`
    * Compara os arquivo produzido `saida.X` com a saída esperada `X.out`


