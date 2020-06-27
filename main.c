#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
int main()
{
    int max_tarefas,menu,max_tarefas_doing,flag;
    char file[250];
    List_cartao cartoes=cria_lista_cartao();
    List_pessoa pessoas=cria_lista();
    List_ponteiros to_do=cria_lista_ponteiros();
    List_ponteiros doing=cria_lista_ponteiros();
    List_ponteiros done=cria_lista_ponteiros();
    le_ficheiro_pessoas("Pessoas.txt",pessoas);
    le_ficheiro_cartao("Cartoes.txt",cartoes);/*melhotar este ler para quando nao a pessoas associadas etc*/
    conecta(cartoes,pessoas,to_do,doing,done);
    imprime_lista_pessoas(pessoas);
    imprime_lista_cartoes(cartoes);
    imprime_lista_pessoas_cartoes(pessoas);
    imprime_lista_cartoes_pessoas(cartoes);
    printf("---------------to_do---------------\n");
    imprime_lista_ponteiros(to_do);
    printf("-----------------------------------\n");
    printf("---------------doing---------------\n");
    imprime_lista_ponteiros(doing);
    printf("-----------------------------------\n");
    printf("---------------done---------------\n");
    imprime_lista_ponteiros(done);
    printf("-----------------------------------\n");
    menu=-1;
    max_tarefas=1;
    max_tarefas_doing=10;
    while(menu!=0){
    printf("[0].Sair\n");
    printf("[1].Listar pessoas\n");
    printf("[2].Definir o numero maximo de tarefas\n");
    printf("[3].Inserir uma nova tarefa na lista To Do\n");
    printf("[4].Priorizar os cartões em To Do\n");
    printf("[5].Mover cartões de To Do para Doing\n");
    printf("[6].Alterar a pessoa responsável por um cartão em Doing\n");
    printf("[7].Terminar cartão enviando-o para Done\n");
    printf("[8].Enviar cartoes de Done para To Do\n");
    printf("[9].Visualizar o quadro\n");
    printf("[10].Visualizar todas as tarefas de uma pessoa\n");/*falta isto tem de ser uma pessoas expecifica*/
    printf("[11].Visualizar todas as tarefas ordenadas por data de criação\n");
    printf("Opcao:");
    scanf("%d",&menu);
    switch(menu) {
      case 0 :
         escreve_ficheiro_cartao(cartoes);
         escreve_ficheiro_pessoa(pessoas);
         elemina_lista_ponteiros_total(to_do);
         elemina_lista_ponteiros_total(doing);
         elemina_lista_ponteiros_total(done);
         elemina_lista_cartao_total(cartoes);
         elemina_lista_pessoas_total(pessoas);
         printf("Saindo!\n" );
         break;
      case 1 :
        imprime_lista_pessoas(pessoas);
         break;
      case 2:
          altera_max_tarefas(pessoas,&max_tarefas);
         break;
      case 3:
         insere_to_do(to_do,cartoes);
         break;
      case 4 :
         muda_prioridades(to_do);
         break;
      case 5:
         printf("[0].To_do para doing||[1].Doing para to_do\n");
         scanf("%d",&flag);
         if(flag==0){
         troca_to_do_doing(to_do,doing,cartoes,pessoas,max_tarefas,max_tarefas_doing);
         }
         else{
            troca_doing_to_do(to_do,doing,cartoes,pessoas);
         }
         break;
      case 6:
         muda_Responsavel(doing,cartoes,pessoas,max_tarefas);
         break;
      case 7:
         troca_doing_done(doing,done,cartoes);
         break;
      case 8:
         troca_done_to_do(done,to_do,cartoes,pessoas);
         break;
      case 9:
         printf("Pretende guardar os resultados em ficheiros de texto(0-Nao,1-Sim)\n");
         scanf("%d",&flag);
         if(flag==1){
            printf("Com que nome pretende guardar o log?\n");
            scanf(" %s",file);
            visualizar_quadro_ficheiro(to_do,doing,done,file);
         }
         else{
            visualizar_quadro(to_do,doing,done);
         }
         break;
      case 10:
         printf("Pretende guardar os resultados em ficheiros de texto(0-Nao,1-Sim)\n");
         scanf("%d",&flag);
         if(flag==1){
            printf("Com que nome pretende guardar o log?\n");
            scanf(" %s",file);
            imprime_cartoes_atribuidos_ficheiro(pessoas,file);
         }
         else{
            imprime_cartoes_atribuidos(pessoas);
         }
         break;
      case 11:
        printf("Pretende guardar os resultados em ficheiros de texto(0-Nao,1-Sim)\n");
         scanf("%d",&flag);
         if(flag==1){
            printf("Com que nome pretende guardar o log?\n");
            scanf(" %s",file);
            imprime_lista_cartoes_ficheiro(cartoes,file);
         }
            else{
            imprime_lista_cartoes(cartoes);
            }
         break;
      default :
         printf("Opcao invalida,tente outra vez\n" );
         Sleep(1000);
    }
    }
    return 0;
}
