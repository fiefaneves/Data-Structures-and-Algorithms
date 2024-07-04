#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int nota;
    int idade;
}pessoa;

void merge(pessoa pessoas[], int n, int f, int l){
    pessoa temp[n];
    for(int i=f;i<=l;i++){
        temp[i] = pessoas[i];
    }
    int m = (f+l)/2;
    int i1=f, i2=m+1;
    for (int j=f;j<=l;j++){
        if(i1==m+1){
            pessoas[j]=temp[i2++];
        }
        else{
            if(i2>l){
                pessoas[j] = temp[i1++];
            }
            else{
                if(temp[i1].nota<temp[i2].nota){
                    pessoas[j]=temp[i1++];
                } else if (temp[i1].nota==temp[i2].nota){                
                    if(temp[i1].idade<temp[i2].idade){
                        pessoas[j]=temp[i1++];
                    }else if (temp[i1].idade==temp[i2].idade){
                        pessoas[j]=temp[i2++];
                    }else{
                        pessoas[j]=temp[i2++];
                    }
                }else{
                    pessoas[j]=temp[i2++];
                }
            }
        }
    }
}

void mergesort(pessoa pessoas[], int n, int f, int l){
    if(f<l){
        int m = (f+l)/2;
        mergesort(pessoas, n, f, m);
        mergesort(pessoas, n, m+1, l);
        merge(pessoas, n, f, l);
    }
}

int main(){
    int qtd_cargos;
    scanf("%d", &qtd_cargos);
    
    for(int i=0;i<qtd_cargos;i++){
        int qtd_inscritos, qtd_vagas;
        scanf("%d %d", &qtd_inscritos, &qtd_vagas);
        pessoa pessoas[qtd_inscritos];
        for(int j=0;j<qtd_inscritos;j++){
            scanf("%s", pessoas[j].nome);
            scanf("%d %d", &pessoas[j].nota, &pessoas[j].idade);
        }
        
        mergesort(pessoas, qtd_inscritos, 0, qtd_inscritos-1);
        
        printf("cargo %d:\n", i+1);
        int aux=qtd_inscritos;
        for(int j=0;j<qtd_vagas;j++){
            if(qtd_inscritos>0){
                printf("%s\n", pessoas[aux-1-j].nome);
                qtd_inscritos--;
            }else{
                printf("x\n");
            }
        }
    }
}