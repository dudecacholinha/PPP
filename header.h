#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string.h>

typedef struct{
    int ano;
    int mes;
    int dia;
    }Data;
int compara_Data(Data a,Data b){
    if(a.ano==b.ano&&a.mes==b.mes&&a.dia==b.dia){
        return 0;
    }
    else{
        if(a.ano>b.ano){
            return  1;
        }
        if(a.ano==b.ano&&a.mes>b.mes){
            return 1;
        }
        if(a.ano==b.ano&&a.mes==b.mes&&a.dia>b.dia){
            return 1;
        }

    }
    return -1;
    }
int data_existe(Data a){
    int aux[12]={32,29,32,31,32,31,32,32,31,32,31,32};
    if(a.ano%4!=0){/*nao e bisexto*/
        if(a.mes>0&&a.mes<13&&a.dia>0&&a.dia<aux[a.mes-1]&&a.ano>0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(a.mes>0&&a.mes<13){
            if(a.mes!=2){
                if(a.mes>0&&a.mes<13&&a.dia>0&&a.dia<aux[a.mes-1]&&a.ano>0){
                    return 1;
                }
                else{
                    return 0;
                }

            }
            else{
                if(a.mes>0&&a.mes<13&&a.dia>0&&a.dia<30&&a.ano>0){
                    return 1;
                }
                else{
                    return 0;
                }

            }
        }
    }
    return 0;
    }
void le_data(Data *a,int flag){/*falg a 0 data de ciracao*/
    do{
    if(flag==0){
        printf("Data de criaca?:");
    }
    else{
        if(flag==1){
            printf("Data do prazo?:");
        }
        else{
            printf("Data de conclusao?:");
        }
    }
    scanf("%d/%d/%d",&((*a).dia),&((*a).mes),&((*a).ano));
    if(data_existe(*a)==0){
        printf("parece que inseriu uma data impossivel,tente outra vez\n");
    }
    }while(data_existe(*a)==0);
    }
void le_data_2(Data *a,int flag,Data b){/*falg a 0 data de ciracao o b e a criaçao*/
    do{
    if(flag==0){
        printf("Data de criaca?:");
    }
    else{
        if(flag==1){
            printf("Data do prazo?:");
        }
        else{
            printf("Data de conclusao?:");
        }
    }
    scanf("%d/%d/%d",&((*a).dia),&((*a).mes),&((*a).ano));
    if(flag==1&&compara_Data(*a,b)<0){
            printf("Parece que esta a tentar atribuir uma prazo antes da data de criacao(%d/%d/%d),tente outra vez\n",b.dia,b.mes,b.ano);
        }
    if(flag==2&&compara_Data(*a,b)<0){
            printf("Parece que esta a tentar atribuir uma data de conclusao antes da data de criacao(%d/%d/%d),tente outra vez\n",b.dia,b.mes,b.ano);
        }
    if(data_existe(*a)==0){
        printf("parece que inseriu uma data impossivel,tente outra vez\n");
    }
    }while(data_existe(*a)==0||compara_Data(*a,b)<0);
    }
int semana(Data a){
    if(a.dia>7){
        if(a.dia>14){
            if(a.dia>21){
                return 4;
            }
            else{
                return 3;
            }

        }
        else{
            return 2;
        }

    }
    else{
        return 1;
    }
}

typedef struct lnode1 *List_ponteiros;
typedef struct lnode1 {
    struct lnode_cartao *no_cartao;/*vai ser algo do tipo List_Cartoes *no_cartao */
    List_ponteiros next;
} List_node1;

typedef struct pessoas{
    char* nome;
    char* email;
    char *id;
    /*List_ponteiros lista_ponteiros;*/
    }Pessoa;

typedef struct lnode *List_pessoa;
typedef struct lnode {
    Pessoa pessoa;
    List_ponteiros lista_ponteiros;/* E TIRAR DE DENTRO DA PESSOA*/
    List_pessoa next;
} List_node_pessoa;

typedef struct cartoes{
    char* id;
    int prioridade;
    Data criacao;
    char *descricao;
    /*List_pessoa no_pessoa;*/
    char* dono;/*para depois de por em ficheiro detexto saber o que no na lista de pessoas temos de ir buscar*/
    Data prazo;
    Data conclusao;
    int seccao;
}Cartao;

int compara_cartao_To_do(Cartao a,Cartao b){
    if(a.prioridade>b.prioridade){
        return 1;
    }
    else{
        if(a.prioridade<b.prioridade){
            return -1;
        }
        else{
            return compara_Data(a.prazo,b.prazo);

        }
    }
    }

typedef struct lnode_cartao *List_cartao;
typedef struct lnode_cartao{
    Cartao cartao;
    List_cartao next;
    List_pessoa no_pessoa;
} List_node_cartao;
/*cria lista de pessoas com header*/
int vector_disponivel(int*vec,int tamanho);
void imprime_lista_ponteiros(List_ponteiros lista);
int tamanho_lista_ponteiros(List_ponteiros lista);
int tamanho_lista_pessoas(List_pessoa);
int Semana_livre(Data verifica,List_ponteiros lista);
void imprime_lista_cartoes (List_cartao lista);
void imprime_lista_ponteiros(List_ponteiros lista);
void insere_lista_ord_no (List_pessoa lista,List_pessoa pessoa_novo);
void insere_lista_cartao_ord_no(List_cartao lista,List_cartao novo);
void imprime_to_do(List_ponteiros to_do);
void imprime_doing(List_ponteiros doing);
void imprime_done(List_ponteiros done);
void imprime_to_do_ordenada(List_ponteiros to_do);
void imprime_doing_ordenada(List_ponteiros doing);
void imprime_done_ordenada(List_ponteiros done);
List_cartao get_cartao(List_ponteiros lista);
int id_unico(List_cartao cartoes,char *teste);
void imprime_to_do_ordenada_ficheiro(List_ponteiros to_do,FILE*fp);
void imprime_doing_ordenada_ficheiro(List_ponteiros  doing,FILE*fp);
void imprime_to_do_ordenada_ficheiro(List_ponteiros to_do,FILE*fp);
void imprime_done_ordenada_ficheiro(List_ponteiros  done,FILE*fp);
int tamanho_lista_ponteiros_a_fazer(List_ponteiros lista);

List_pessoa cria_lista(void)
{
    List_pessoa aux;
    aux = (List_pessoa) malloc (sizeof (List_node_pessoa));
    if (aux != NULL) {
        aux->pessoa.id="header";
        aux->pessoa.nome="header";
        aux->next = NULL;
    }
    return aux;
}
List_cartao cria_lista_cartao(void)
{
    List_cartao aux;
    aux = (List_cartao) malloc (sizeof (List_node_cartao));
    if (aux != NULL) {
        aux->cartao.id="header";
        aux->next = NULL;
    }
    return aux;
}
/*cria a lista de poenteiras para cartoes*/
List_ponteiros cria_lista_ponteiros (void)
{
    List_ponteiros aux;
    aux = (List_ponteiros) malloc (sizeof (List_node1));
    if (aux != NULL) {
        aux->no_cartao=NULL;/*esta linha e a que ta a dar mal*/
        aux->next = NULL;
    }
    return aux;
}
void procura_lista (List_pessoa lista, char* chave, List_pessoa *ant, List_pessoa *actual)
{/*pequeno senao no while que seria se tivem nomes iaguais secalahr meter mais uma condiçao usando o id*/
    *ant = lista; *actual = lista->next;/*salta logo o header*/
    while ((*actual) != NULL&&(strcmp((*actual)->pessoa.id ,chave)!=0))
    {
        *ant = *actual;
        *actual = (*actual)->next;
        /*printf("%s ",(*actual)->info.indetificador );porqueeeeeeeeeeeeee*/
        }
        if (((*actual) != NULL )&&(strcmp((*actual)->pessoa.id ,chave) != 0)){
            *actual = NULL; /* Se elemento não encontrado*/
            }
}
void procura_lista_Cartao (List_cartao lista, Cartao chave, List_cartao *ant, List_cartao *actual)
{
    *ant = lista; *actual = lista->next;/*salta logo o header*/
    while ((*actual) != NULL&&(compara_Data((*actual)->cartao.criacao ,chave.criacao) <0))
    {
        *ant = *actual;
        *actual = (*actual)->next;
        /*printf("%s ",(*actual)->info.indetificador );porqueeeeeeeeeeeeee*/
        }
        /*printf("%s ",(*actual)->info.indetificador );*/
        if (((*actual) != NULL )&&(compara_Data((*actual)->cartao.criacao ,chave.criacao) != 0)){
            *actual = NULL; /* Se elemento não encontrado*/
            }
}

void procura_lista_Cartao_2 (List_cartao lista, char* chave, List_cartao *ant, List_cartao *actual)
{
    /*supoetamente devia ser tendo em conta a data ded criaçao mas e so para deserascar*/
    *ant = lista; *actual = lista->next;/*salta logo o header*/
    while ((*actual) != NULL&&(strcmp((*actual)->cartao.id ,chave) !=0))
    {
        *ant = *actual;
        *actual = (*actual)->next;
        /*printf("%s ",(*actual)->info.indetificador );porqueeeeeeeeeeeeee*/
        }
        /*printf("%s ",(*actual)->info.indetificador );*/
        if (((*actual) != NULL )&&(strcmp((*actual)->cartao.id ,chave) != 0)){
            *actual = NULL; /* Se elemento não encontrado*/
            }
}

void procura_lista_Ponteiros_2 (List_ponteiros lista, char* chave, List_ponteiros *ant, List_ponteiros *actual)
{
    /*supoetamente devia ser tendo em conta a data ded criaçao mas e so para deserascar*/
    *ant = lista; *actual = lista->next;/*salta logo o header*/
    while ((*actual) != NULL&&(strcmp((*actual)->no_cartao->cartao.id,chave) !=0))
    {
        *ant = *actual;
        *actual = (*actual)->next;
        /*printf("%s ",(*actual)->info.indetificador );porqueeeeeeeeeeeeee*/
        }
        /*printf("%s ",(*actual)->info.indetificador );*/
        /*printf("%s",(*actual)->no_cartao->cartao.id,chave);*/
        if (((*actual) != NULL )&&(strcmp((*actual)->no_cartao->cartao.id,chave) != 0)){
            *actual = NULL; /* Se elemento não encontrado*/
            }
}
void procura_lista_ponteiros (List_ponteiros lista, char* chave, List_ponteiros *ant, List_ponteiros*actual)
{
    List_cartao teste2;
    *ant = lista; *actual = lista->next;
    teste2=((*actual)->no_cartao);
    while (((*actual) != NULL)&& (strcmp(teste2->cartao.id,chave) != 0))
    {
        *ant = *actual;
        *actual = (*actual)->next;
        /*printf("%s ",(*actual)->info.indetificador );*/
        teste2=((*actual)->no_cartao);
        }
        if ((*actual) != NULL && (strcmp ((((*actual)->no_cartao))->cartao.id,chave) != 0))
            *actual = NULL; /* Se elemento não encontrado*/
        /*printf("Anterior %s\n",(*ant)->info.indetificador);*/
}
List_pessoa pesquisa_lista (List_pessoa lista, char* it)
{
    List_pessoa ant;
    List_pessoa actual;
    procura_lista (lista, it, &ant, &actual);
    return (actual);
}

List_cartao pesquisa_cartao(List_cartao lista, char* it)
{
    List_cartao ant;
    List_cartao actual;
    procura_lista_Cartao_2(lista, it, &ant, &actual);
    return (actual);
}

List_ponteiros pesquisa_cartao_ponteiro(List_ponteiros lista, char* it)
{
    List_ponteiros ant;
    List_ponteiros actual;
    procura_lista_Ponteiros_2(lista, it, &ant, &actual);
    return (actual);
}

void insere_lista_cartao_ord(List_cartao lista,List_cartao novo)
{
    List_cartao l,ant;
    Data n;
    n=(novo->cartao.criacao);
    ant=lista;
    l=lista->next;
    while((l)&&compara_Data((l->cartao.criacao),n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}
void insere_lista_To_Do(List_ponteiros lista,List_cartao insere)
{
    List_ponteiros l,ant,novo;
    Cartao n=(insere)->cartao;
    ant=lista;
    l=lista->next;
    novo=(List_ponteiros) malloc (sizeof (List_node1));
    novo->no_cartao=insere;
    while((l)&&compara_cartao_To_do(((l->no_cartao))->cartao,n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}
void insere_lista_To_Do_2(List_ponteiros lista,List_ponteiros novo)
{
    List_ponteiros l,ant;
    Cartao n=novo->no_cartao->cartao;
    ant=lista;
    l=lista->next;
    while((l)&&compara_cartao_To_do(((l->no_cartao))->cartao,n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}

void insere_lista_Doing(List_ponteiros lista,List_cartao insere)
{
    List_ponteiros l,ant,novo;
    char* n=(insere->no_pessoa)->pessoa.nome;
    ant=lista;
    l=lista->next;
    novo=(List_ponteiros) malloc (sizeof (List_node1));
    novo->no_cartao=insere;
    while((l)&&strcmp((((l->no_cartao))->no_pessoa->pessoa.nome),n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}
void insere_lista_Doing_2(List_ponteiros lista,List_ponteiros novo)
{
    List_ponteiros l,ant;
    char* n=novo->no_cartao->no_pessoa->pessoa.nome;
    ant=lista;
    l=lista->next;
    while((l)&&strcmp((((l->no_cartao))->no_pessoa->pessoa.nome),n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}

void insere_lista_Done(List_ponteiros lista,List_cartao insere)
{
    List_ponteiros l,ant,novo;
    Data n=insere->cartao.conclusao;
    ant=lista;
    l=lista->next;
    novo=(List_ponteiros) malloc (sizeof (List_node1));
    novo->no_cartao=insere;
    while((l)&&compara_Data((l->no_cartao->cartao.conclusao),n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}

void insere_lista_Done_2(List_ponteiros lista,List_ponteiros novo)
{
    List_ponteiros l,ant;
    Data n=novo->no_cartao->cartao.conclusao;
    ant=lista;
    l=lista->next;
    while((l)&&compara_Data((l->no_cartao->cartao.conclusao),n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}

List_ponteiros pesquisa_lista_ponteiros (List_ponteiros lista, char *chave)
{
    List_ponteiros ant;
    List_ponteiros actual;
    procura_lista_ponteiros (lista, chave, &ant, &actual);
    return actual;
}
void insere_lista_ponteiros (List_ponteiros lista, List_cartao x)/*acho que tambem nao e usado*/
{
    List_ponteiros l,ant,novo;
    l=lista->next;
    ant=lista;
    novo=(List_ponteiros) malloc (sizeof (List_node1));
    novo->no_cartao=x;
    while(l){
        ant=l;
        l=l->next;
    }
    ant->next=novo;
    novo->next=NULL;
}

void elemina_lista_ponteiros(List_ponteiros lista,char*ID){/*acho que vai no caracas*/
    List_ponteiros l=lista->next;/* Salta o cabeçalho */
    List_ponteiros ant=lista;
    while(l&&strcmp(l->no_cartao->cartao.id,ID)!=0){
        ant=l;
        l=l->next;
    }
    /*vai sempre acontecer mas pronto (codiçao desnesserai)*/
    ant->next=l->next;
    free(l);
}
List_ponteiros elemina_lista_ponteiros_2(List_ponteiros lista,char*ID){

    List_ponteiros l=lista->next;/* Salta o cabeçalho */
    List_ponteiros ant=lista;
    while(l&&strcmp(l->no_cartao->cartao.id,ID)!=0){
        ant=l;
        l=l->next;
    }
    ant->next=l->next;
    return l;
    }
void insere_lista_ponteiros_2(List_ponteiros lista, List_ponteiros novo)/*acho que ja nao uso e para tirar*/
{
    List_ponteiros l,ant;
    l=lista->next;
    ant=lista;
    while(l){
        ant=l;
        l=l->next;
    }
    ant->next=novo;
    novo->next=NULL;
}
/*acho que funciona XD*/
void insere_lista_ponteiros_seccao(List_ponteiros lista, List_cartao x)
{
    int seccao;
    List_ponteiros novo,l,ant;
    l=lista->next;
    ant=lista;
    novo=(List_ponteiros) malloc (sizeof (List_node1));
    novo->no_cartao=x;
    seccao=novo->no_cartao->cartao.seccao;
    while(l&&(l->no_cartao->cartao.seccao<seccao)){
        ant=l;
        l=l->next;
    }
    ant->next=novo;
    novo->next=l;
}

void insere_lista_ponteiros_seccao_2(List_ponteiros lista, List_ponteiros novo)
{
    int seccao;
    List_ponteiros l,ant;
    l=lista->next;
    ant=lista;
    seccao=novo->no_cartao->cartao.seccao;
    while(l&&(l->no_cartao->cartao.seccao<seccao)){
        ant=l;
        l=l->next;
    }
    ant->next=novo;
    novo->next=l;
}


void muda_prioridades(List_ponteiros to_do){
    char *cartao;
    List_ponteiros ant,actual;
    int prioridade;
    List_cartao no_cartao;
    imprime_to_do(to_do);
    no_cartao=get_cartao(to_do);
    cartao=no_cartao->cartao.id;
    do{
    printf("qual a prioridade que quer por?\n");
    scanf("%d",&prioridade);
    }while(prioridade<1||prioridade>10);
    no_cartao->cartao.prioridade=prioridade;
    procura_lista_ponteiros(to_do,cartao,&ant,&actual);
    ant->next=actual->next;
    insere_lista_To_Do_2(to_do,actual);
    }

int * display_pessoas_disponiveis(List_pessoa lista,Data pos,int tamanho,int max_tarefas){
    int i;
    int *vec;
    List_pessoa l;
    l=lista->next;
    i=0;
    vec=(int*)malloc(sizeof(int)*tamanho);
    while(l){
        if(tamanho_lista_ponteiros_a_fazer(l->lista_ponteiros)<max_tarefas){
            if(Semana_livre(pos,l->lista_ponteiros)==1){
                    printf("%d:%s\n",i,l->pessoa.nome);
                    vec[i]=1;
            }
            else{
                vec[i]=-1;
                printf("%d:%s(Nao disponivel semana ocupada)\n",i,l->pessoa.nome);
            }
        }
        else{
            vec[i]=0;
            printf("%d:%s(Nao disponivel cheio)\n",i,l->pessoa.nome);
        }
        l=l->next;
        i++;
        }
    return vec;
}

int * display_pessoas_disponiveis_2(List_pessoa lista,Data pos,int tamanho,List_pessoa responsavel,int max_tarefas){
    int i;
    int *vec;
    List_pessoa l;
    l=lista->next;
    i=0;
    vec=(int*)malloc(sizeof(int)*tamanho);
    while(l){
        if(strcmp(l->pessoa.id,responsavel->pessoa.id)!=0){
        if(tamanho_lista_ponteiros_a_fazer(l->lista_ponteiros)<max_tarefas){
            if(Semana_livre(pos,l->lista_ponteiros)==1){/*wtf semana livre???? argumentos de entrada*/
                    printf("%d:%s\n",i,l->pessoa.nome);
                    vec[i]=1;
            }
            else{
                vec[i]=-1;
                printf("%d:%s(Nao disponivel semana ocupada)\n",i,l->pessoa.nome);
            }
        }
        else{
            vec[i]=0;
            printf("%d:%s(Nao disponivel cheio)\n",i,l->pessoa.nome);
        }
        }
        else{
            printf("%d:%s(Pessoa responsavel)\n",i,l->pessoa.nome);
            vec[i]=-2;
        }
        l=l->next;
        i++;
    }
    return vec;
}
List_pessoa get_pessoa(List_pessoa lista,int i){
    List_pessoa l;
    l=lista->next;
    while(i){
        i--;
        l=l->next;
    }
    return l;
    }
void le_Cartao(Cartao *c,List_cartao cartoes){
    int prioridade;
    do{
    printf("Qual o id do cartao?\n");
    scanf(" %s",(*c).id);
    if(id_unico(cartoes,(*c).id)!=1){
        printf("ups parece que esse id ja exite,tente outro \n");
        }
    }
    while(id_unico(cartoes,(*c).id)!=1);
    printf("Qual a discricao?\n");
    scanf(" %s",(*c).descricao);
    le_data(&(*c).criacao,0);
    (*c).seccao=0;
    (*c).conclusao.dia=-1;
    (*c).conclusao.mes=-1;
    (*c).conclusao.ano=-1;
    (*c).prazo.dia=-1;
    (*c).prazo.mes=-1;
    (*c).prazo.ano=-1;
    (*c).dono="nenhum";
    do{
    printf("qual a prioridade(1-10) que quer por?\n");
    scanf("%d",&prioridade);
    if(prioridade<1||prioridade>10){
        printf("Tentou atribuir uma que nao se encontra no intervalo(1-10),tente outra vez\n");
    }
    }while(prioridade<1||prioridade>10);
    (*c).prioridade=prioridade;
    printf("ole");



}
void insere_to_do(List_ponteiros to_do,List_cartao cartoes){
    Cartao c;
    List_cartao novo;
    c.id=(char*)malloc(sizeof(char)*30);
    c.descricao=(char*)malloc(sizeof(char)*30);
    c.dono=(char*)malloc(sizeof(char)*30);
    le_Cartao(&c,cartoes);
    novo=(List_cartao) malloc (sizeof (List_node_cartao));
    novo->cartao=c;
    insere_lista_To_Do(to_do,novo);
    insere_lista_cartao_ord(cartoes,novo);

    }
int verifica_disponivel(int *disponivel,int tamanho){
    int i;
    do{
    do{
    printf("Escolha um dos numeros associado a pessoa que quer atribuir o cartao\n");
    scanf("%d",&i);
    if(i>tamanho||i<0){
        printf("o numero que escolheu e invalido tente outra vez\n");
    }
    else{
        if(disponivel[i]!=1){
        printf("Essa pessoa nao esta disponivel tente outra vez\n");
    }
    }
    }while(i>tamanho||i<0);
    }while(disponivel[i]!=1);
    return i;
    }
void troca_to_do_doing(List_ponteiros to_do,List_ponteiros doing,List_cartao cartoes,List_pessoa pessoas,int max_tarefas,int max_tarefas_doing){
    /*isto secalahr tem de mudar a escolha das pessoas para o id delas mesmo em vez do numero da posiçao*/
    char *cartao;
    int *disponivel;
    int i,tamanho;
    List_ponteiros aux;/*aux4 e so para ajudar a ver se o cartao existe*/
    List_cartao aux2;
    List_pessoa aux3;
    if(tamanho_lista_ponteiros(to_do)>0){
    if(max_tarefas_doing<=tamanho_lista_ponteiros(doing)){
            printf("Doing cheio\n");
    }
    else{
    imprime_to_do(to_do);
    aux2=get_cartao(to_do);
    cartao=aux2->cartao.id;
    le_data_2(&(aux2->cartao.prazo),1,aux2->cartao.criacao);
    tamanho=tamanho_lista_pessoas(pessoas);
    disponivel=display_pessoas_disponiveis(pessoas,aux2->cartao.prazo,tamanho,max_tarefas);
    if(vector_disponivel(disponivel,tamanho)==1){
    i=verifica_disponivel(disponivel,tamanho);
    aux3=get_pessoa(pessoas,i);
    insere_lista_ponteiros_seccao(aux3->lista_ponteiros,aux2);
    aux2->cartao.seccao=1;
    aux2->no_pessoa=aux3;
    aux2->cartao.dono=aux3->pessoa.id;
    aux=elemina_lista_ponteiros_2(to_do,cartao);/*dar double check nesta funca acho que nao ta bem*/
    insere_lista_Doing_2(doing,aux);/*falta cirar funcoes insere_lista_doing_2 porque nao tou a inserir em ordem*/
    }
    else{
        printf("Parece que todas as pessoas estao ocupadas nao havendo alternativa tente outra vez \n");
    }
    free(disponivel);
    }
}
    else{
        printf("A lista que pretende alterar encontra-se vazia\n");
    }
}

List_cartao get_cartao(List_ponteiros lista){
    char cartao[50];
    List_ponteiros aux;
    List_cartao retorna;
    do{
        fflush(stdin);
        printf("Qual o cartao que quer mudar?\n");
        gets(cartao);
        aux=pesquisa_cartao_ponteiro(lista,cartao);/*isto ta mal acho que ja nao*/
        if(aux==NULL){
            retorna=NULL;
        }
        else{
            retorna=aux->no_cartao;
        }
        }while(retorna==NULL);
        return retorna;

    }
void troca_doing_to_do(List_ponteiros to_do,List_ponteiros doing,List_cartao cartoes,List_pessoa pessoas){
    /*isto secalahr tem de mudar a escolha das pessoas para o id delas mesmo em vez do numero da posiçao*/
    char *cartao;
    List_ponteiros aux;/*aux4 e so para ajudar a ver se o cartao existe*/
    List_cartao aux2;/*cartao*/
    List_pessoa aux3;/*pessoas a que tava atribuida a tarefa*/
    if(tamanho_lista_ponteiros(doing)>0){
    imprime_doing(doing);
    aux2=get_cartao(doing);
    cartao=aux2->cartao.id;
    aux3=aux2->no_pessoa;
    aux2->cartao.seccao=0;
    aux2->no_pessoa=NULL;
    aux2->cartao.dono="nenhum";/*vai lixar alguma coisa*/
    aux2->cartao.prazo.dia=-1;
    aux2->cartao.prazo.mes=-1;
    aux2->cartao.prazo.ano=-1;
    elemina_lista_ponteiros(aux3->lista_ponteiros,cartao);/*tirara a taread a pessoa*/
    aux=elemina_lista_ponteiros_2(doing,cartao);/*dar double check nesta funca acho que nao ta bem*/
    insere_lista_To_Do_2(to_do,aux);
    }
    else{
        printf("A lista que pretende alterar encontra-se vazia\n");
    }

}


void muda_Responsavel(List_ponteiros doing,List_cartao cartoes,List_pessoa pessoas,int max_tarefas){
    char *cartao;
    int i,tamanho;
    int *disponivel;
    List_ponteiros aux;
    List_cartao aux2;/*cartao a ser mudado*/
    List_pessoa aux3,aux4;/*a3 pessoas a receber a tarefa a4 pessoas que tinha a tarefa*/
    imprime_doing(doing);
    aux2=get_cartao(doing);
    cartao=aux2->cartao.id;
    aux4=aux2->no_pessoa;
    tamanho=tamanho_lista_pessoas(pessoas);
    disponivel=display_pessoas_disponiveis_2(pessoas,aux2->cartao.prazo,tamanho,aux4,max_tarefas);
    if(vector_disponivel(disponivel,tamanho)==1){
    i=verifica_disponivel(disponivel,tamanho);
    aux2=pesquisa_cartao(cartoes,cartao);
    aux=elemina_lista_ponteiros_2(aux4->lista_ponteiros,cartao);/*eleminar o carao da lista de cartoes da pessoa que o tinha*/
    aux3=get_pessoa(pessoas,i);
    aux2->no_pessoa=aux3;/*atribuir ao cartao a pessoa nova*/
    aux2->cartao.dono=aux3->pessoa.id;
    insere_lista_ponteiros_seccao_2(aux3->lista_ponteiros,aux);
    }
    else{
        printf("esta tudo cheio tente outra vez \n");
    }
    free(disponivel);
}
void troca_doing_done(List_ponteiros doing,List_ponteiros done,List_cartao cartoes){
    char *cartao;
    List_ponteiros aux,ant,actual;/*aux4 e so para ajudar a ver se o cartao existe*/
    List_cartao aux2;
    if(tamanho_lista_ponteiros(doing)>0){
    imprime_doing(doing);
    aux2=get_cartao(doing);
    cartao=aux2->cartao.id;
    le_data_2(&(aux2->cartao.conclusao),2,aux2->cartao.criacao);
    aux2->cartao.seccao=2;
    procura_lista_ponteiros(aux2->no_pessoa->lista_ponteiros,cartao,&ant,&actual);
    ant->next=actual->next;
    insere_lista_ponteiros_seccao_2(aux2->no_pessoa->lista_ponteiros,actual);
    aux=elemina_lista_ponteiros_2(doing,cartao);/*dar double check nesta funca acho que nao ta bem*/
    insere_lista_Done_2(done,aux);
    }
    else{
        printf("A lista que pretende alterar encontra-se vazia\n");
    }
        }
void troca_done_to_do(List_ponteiros done,List_ponteiros to_do,List_cartao cartoes,List_pessoa pessoas){
    char *cartao;
    List_ponteiros aux;
    List_cartao aux2;
    if(tamanho_lista_ponteiros(done)>0){
    imprime_done(done);
    aux2=get_cartao(done);
    cartao=aux2->cartao.id;
    aux2->cartao.seccao=0;
    aux2->cartao.conclusao.dia=-1;
    aux2->cartao.conclusao.mes=-1;
    aux2->cartao.conclusao.ano=-1;
    aux2->cartao.prazo.dia=-1;
    aux2->cartao.prazo.mes=-1;
    aux2->cartao.prazo.ano=-1;
    aux2->cartao.dono="nenhum";
    elemina_lista_ponteiros(aux2->no_pessoa->lista_ponteiros,cartao);
    aux2->no_pessoa=NULL;
    aux=elemina_lista_ponteiros_2(done,cartao);/*dar double check nesta funca acho que nao ta bem*/
    insere_lista_To_Do_2(to_do,aux);
    }
    else{
        printf("A lista que pretende alterar encontra-se vazia\n");
    }
        }
void imprime_to_do(List_ponteiros to_do){
    printf("---------------to_do---------------\n");
    imprime_to_do_ordenada(to_do);
    printf("-----------------------------------\n");
    }
void imprime_to_do_ficheiro(List_ponteiros to_do,FILE*fp){
    fprintf(fp,"---------------to_do---------------\n");
    imprime_to_do_ordenada_ficheiro(to_do,fp);
    fprintf(fp,"-----------------------------------\n");
    }
void imprime_doing(List_ponteiros doing){
    printf("---------------doing---------------\n");
    imprime_doing_ordenada(doing);
    printf("-----------------------------------\n");
    }
void imprime_doing_ficheiro(List_ponteiros doing,FILE*fp){
    fprintf(fp,"---------------doing---------------\n");
    imprime_doing_ordenada_ficheiro(doing,fp);
    fprintf(fp,"-----------------------------------\n");
    }
void imprime_done(List_ponteiros done){
    printf("---------------done---------------\n");
    imprime_done_ordenada(done);
    printf("-----------------------------------\n");
    }
void imprime_done_ficheiro(List_ponteiros done,FILE*fp){
    fprintf(fp,"---------------done---------------\n");
    imprime_done_ordenada_ficheiro(done,fp);
    fprintf(fp,"-----------------------------------\n");
    }
void imprime_lista_ponteiros(List_ponteiros lista){
    List_ponteiros l;
    l=lista->next;
    printf("Cartoes:");
    while(l){
        printf("%s Data de criacao:%d/%d/%d  prioridade:%d",l->no_cartao->cartao.id,l->no_cartao->cartao.criacao.dia,l->no_cartao->cartao.criacao.mes,l->no_cartao->cartao.criacao.ano,l->no_cartao->cartao.prioridade);
        l=l->next;
        printf("\n");
    }
    printf("\n");
    }
void imprime_lista_ponteiros_seccao(List_ponteiros lista){
    List_ponteiros l;
    l=lista->next;
    while(l){
        printf("\n%s que se encontra na seccao:%d",l->no_cartao->cartao.id,l->no_cartao->cartao.seccao);
        l=l->next;
        printf("\n");
    }
    printf("\n");
    }
void imprime_lista_ponteiros_seccao_ficheiro(List_ponteiros lista,FILE *fp){
    List_ponteiros l;
    l=lista->next;
    while(l){
        fprintf(fp,"\n%s que se encontra na seccao:%d",l->no_cartao->cartao.id,l->no_cartao->cartao.seccao);
        l=l->next;
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n");
    }
void imprime_to_do_ordenada(List_ponteiros to_do){
    List_ponteiros l;
    l=to_do->next;
    printf("Cartoes:\n");
    while(l){
        printf("%s Data de criacao:%d/%d/%d  prioridade:%d",l->no_cartao->cartao.id,l->no_cartao->cartao.criacao.dia,l->no_cartao->cartao.criacao.mes,l->no_cartao->cartao.criacao.ano,l->no_cartao->cartao.prioridade);
        l=l->next;
        printf("\n");
    }
    }
void imprime_to_do_ordenada_ficheiro(List_ponteiros to_do,FILE*fp){
    List_ponteiros l;
    l=to_do->next;
    fprintf(fp,"Cartoes:\n");
    while(l){
        fprintf(fp,"%s Data de criacao:%d/%d/%d  prioridade:%d",l->no_cartao->cartao.id,l->no_cartao->cartao.criacao.dia,l->no_cartao->cartao.criacao.mes,l->no_cartao->cartao.criacao.ano,l->no_cartao->cartao.prioridade);
        l=l->next;
        fprintf(fp,"\n");
    }
    }

void imprime_doing_ordenada(List_ponteiros to_do){
    List_ponteiros l;
    l=to_do->next;
    printf("Cartoes:\n");
    while(l){
        printf("%s a ser tratado por %s",l->no_cartao->cartao.id,l->no_cartao->no_pessoa->pessoa.nome);
        l=l->next;
        printf("\n");
    }
    }
void imprime_doing_ordenada_ficheiro(List_ponteiros to_do,FILE*fp){
    List_ponteiros l;
    l=to_do->next;
    fprintf(fp,"Cartoes:\n");
    while(l){
        fprintf(fp,"%s a ser tratado por %s",l->no_cartao->cartao.id,l->no_cartao->no_pessoa->pessoa.nome);
        l=l->next;
        fprintf(fp,"\n");
    }
    }
void imprime_done_ordenada(List_ponteiros done){
    List_ponteiros l;
    l=done->next;
    printf("Cartoes:\n");
    while(l){
        printf("%s a com data de conclusao %d/%d/%d",l->no_cartao->cartao.id,l->no_cartao->cartao.conclusao.dia,l->no_cartao->cartao.conclusao.mes,l->no_cartao->cartao.conclusao.ano);
        l=l->next;
        printf("\n");
    }
    }
void imprime_done_ordenada_ficheiro(List_ponteiros done,FILE*fp){
    List_ponteiros l;
    l=done->next;
    fprintf(fp,"Cartoes:\n");
    while(l){
        fprintf(fp,"%s a com data de conclusao %d/%d/%d",l->no_cartao->cartao.id,l->no_cartao->cartao.conclusao.dia,l->no_cartao->cartao.conclusao.mes,l->no_cartao->cartao.conclusao.ano);
        l=l->next;
        fprintf(fp,"\n");
    }
    }
void imprime_lista_pessoas (List_pessoa lista)
{
    List_pessoa l = lista->next; /* Salta o header */
    printf("----------------Pessoas----------------\n");
    while (l)
{
        printf("Nome :%s \n", l->pessoa.nome);
        printf("Id :%s \n", l->pessoa.id);
        printf("Email :%s \n", l->pessoa.email);
        /*imprime_lista_ponteiros(l->pessoa.lista_ponteiros);*/
        l=l->next;
        printf("\n");
}
printf("--------------------------------\n");
}

void imprime_lista_pessoas_cartoes (List_pessoa lista)
{
    List_pessoa l = lista->next; /* Salta o header */
    printf("----------------Pessoas_Cartoes----------------\n");
    while (l)
{
        printf("Nome :%s \n", l->pessoa.nome);
        imprime_lista_ponteiros(l->lista_ponteiros);
        /*imprime_lista_ponteiros(l->pessoa.lista_ponteiros);*/
        l=l->next;
        printf("\n");
}

printf("--------------------------------\n");
}

void imprime_lista_cartoes_pessoas(List_cartao lista)
{
    List_cartao l = lista->next; /* Salta o header */
    printf("----------------Cartoes_Pessoas----------------\n");
    while (l)
{
        printf("Cartao :%s \n", l->cartao.id);
        if(l->no_pessoa==NULL){
                /*printf("e nulo\n");*/
        }
        else{
            printf("A ser tratado por %s",l->no_pessoa->pessoa.nome);
        }
        /*imprime_lista_ponteiros(l->pessoa.lista_ponteiros);*/
        l=l->next;
        printf("\n");
}
printf("--------------------------------\n");
}


void imprime_lista_cartoes (List_cartao lista)
{
    Cartao aux;
    List_cartao l = lista->next; /* Salta o header */
    printf("-----------------Cartoes------------------\n");
    while (l)
{
        aux=l->cartao;
        printf("id:%s \nid do dono:%s \ndiscricao: %s \nprioridade:%d\nSeccao:%d\nData de criaçao:%d/%d/%d\nData de conclusao:%d/%d/%d\nData do prazo%d/%d/%d\n",aux.id,aux.dono,aux.descricao,aux.prioridade,aux.seccao,aux.criacao.dia,aux.criacao.mes,aux.criacao.ano,aux.conclusao.dia,aux.conclusao.mes,aux.conclusao.ano,aux.prazo.dia,aux.prazo.mes,aux.prazo.ano);
        l=l->next;
        printf("\n");
}
    printf("-------------------------------------------\n");
}

void imprime_lista_cartoes_ficheiro(List_cartao lista,char*nome)
{
    FILE *fp;
    Cartao aux;
    List_cartao l = lista->next; /* Salta o header */
    fp=fopen(nome,"w");
    fprintf(fp,"-----------------Cartoes------------------\n");
    while (l)
{
        aux=l->cartao;
        fprintf(fp,"id:%s \nid do dono:%s \ndiscricao: %s \nprioridade:%d\nSeccao:%d\nData de criaçao:%d/%d/%d\nData de conclusao:%d/%d/%d\nData do prazo%d/%d/%d\n",aux.id,aux.dono,aux.descricao,aux.prioridade,aux.seccao,aux.criacao.dia,aux.criacao.mes,aux.criacao.ano,aux.conclusao.dia,aux.conclusao.mes,aux.conclusao.ano,aux.prazo.dia,aux.prazo.mes,aux.prazo.ano);
        l=l->next;
}
    fprintf(fp,"-------------------------------------------\n");
    fclose(fp);
}

void imprime_lista_cartoes_teste (List_cartao lista)
{
    List_cartao l = lista->next; /* Salta o header */
    List_pessoa pls;
    while (l)
{
        pls=l->no_pessoa;
        printf("%s a ser tratado por %s\n", l->cartao.id,((pls))->pessoa.nome);
        l=l->next;
}
}

void imprime_lista_pessoas_enderecos(List_pessoa lista)
{
    List_pessoa l = lista->next; /* Salta o header */
    while (l)
{
        printf("Endereço da pessoa %s e %d \n", l->pessoa.nome,&(*l));
        l=l->next;
}
}
void conecta(List_cartao cartoes,List_pessoa pessoas,List_ponteiros to_do,List_ponteiros doing,List_ponteiros done){
    /*extrapushou uma vez quando nao tinha id diferentes */
        List_cartao l;
        List_pessoa l1;
        char *aux;
        l=cartoes->next;
        l1=pessoas->next;
        while(l){
            aux=l->cartao.dono;
            while(l1){
                if(strcmp(l1->pessoa.id,aux)==0){
                    l->no_pessoa=l1;
                    printf("a inserir %s na pessoa %s\n",l->cartao.id,l1->pessoa.nome);
                    insere_lista_ponteiros_seccao(l1->lista_ponteiros,l);
                }
                l1=l1->next;
            }
            if(l->cartao.seccao==0){
                l->no_pessoa=NULL;
                insere_lista_To_Do(to_do,l);
            }
            else{
                if(l->cartao.seccao==1){
                /*esta funcao ta mal nao sei como*/
                    insere_lista_Doing(doing,l);
                }
                else{
                    insere_lista_Done(done,l);
                }
            }
            l1=pessoas->next;
            l=l->next;
        }
}

int tamanho_lista_ponteiros(List_ponteiros lista){
    int i;
    List_ponteiros l;
    l=lista->next;
    i=0;
    while(l){
        i++;
        l=l->next;
    }
    return i;
    }
int tamanho_lista_ponteiros_a_fazer(List_ponteiros lista){
    int i;
    List_ponteiros l;
    l=lista->next;
    i=0;
    while(l){
        if(l->no_cartao->cartao.seccao==1){
        i++;
        }
        l=l->next;
    }
    return i;
    }
int tamanho_lista_pessoas(List_pessoa lista){
    int i;
    List_pessoa l;
    l=lista->next;
    i=0;
    while(l){
        i++;
        l=l->next;
    }
    return i;
    }
void imprime_cartoes_pessoa(List_pessoa lista,char * nome){
    List_pessoa l;
    l=lista->next;
    while(l&&(strcmp(l->pessoa.nome,nome)!=0)){
            l=l->next;
    }
    imprime_lista_ponteiros(l->lista_ponteiros);
}
void imprime_tudo(List_ponteiros to_do,List_ponteiros doing,List_ponteiros done){
    printf("To_do----------\n");
    imprime_lista_ponteiros(to_do);
    printf("doing----------\n");
    imprime_lista_ponteiros(doing);
    }
int Semana_livre(Data verifica,List_ponteiros lista){
    List_ponteiros l;
    Data x;
    l=lista;
    l=lista->next;
    printf("Prazo em questao %d/%d/%d",verifica.dia,verifica.mes,verifica.ano);
    while(l){
    if(l->no_cartao->cartao.seccao==1){
        x=l->no_cartao->cartao.prazo;
        if(verifica.ano==x.ano&&verifica.mes==x.mes){
            if(semana(x)==semana(verifica)){
                return 0;
            }
        }
        }
        l=l->next;
    }
    return 1;
}
void le_ficheiro_pessoas(char *nome_ficheiro,List_pessoa lista){
    List_pessoa novo;
    char *id,*nome,*email;
    FILE *fp;
    fp=fopen(nome_ficheiro,"r");
    nome=(char*)malloc(sizeof(char)*30);
    email=(char*)malloc(sizeof(char)*30);
    id=(char*)malloc(sizeof(char)*30);
    while (fscanf (fp, "%s\t%s\t%[^\n]s",id,email,nome) != EOF){
        novo= (List_pessoa) malloc (sizeof (List_node_pessoa));
        novo->pessoa.email=email;
        novo->pessoa.nome=nome;
        novo->pessoa.id=id;
        novo->lista_ponteiros=cria_lista_ponteiros();
        novo->next=NULL;
        insere_lista_ord_no(lista,novo);
        nome=(char*)malloc(sizeof(char)*30);
        email=(char*)malloc(sizeof(char)*30);
        id=(char*)malloc(sizeof(char)*30);
        /*nao sera melhor criar uma pessoa e depois atribuir a pessoa ao no nem sei como e que isto funciona*/
    }
    fclose(fp);
    }
void le_ficheiro_cartao(char *nome_ficheiro,List_cartao lista){
        int prioridade,seccao;
        Cartao cartao;
        List_cartao novo;
        char*id,*id_dono,*discricao;
        Data data,conclusao,prazo;
        FILE *fp;
        fp=fopen(nome_ficheiro,"r");
        id=(char*)malloc(sizeof(char)*30);
        id_dono=(char*)malloc(sizeof(char)*30);
        discricao=(char*)malloc(sizeof(char)*30);
        while (fscanf (fp,"%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\t%s\t%s\t%[^\n]s",&prioridade,&seccao,&data.dia,&data.mes,&data.ano,&conclusao.dia,&conclusao.mes,&conclusao.ano,&prazo.dia,&prazo.mes,&prazo.ano,id,id_dono,discricao) != EOF){
            /*printf("id:%s \nid do dono:%s \ndiscricao: %s \nprioridade:%d\nSeccao:%d\nData:%d/%d/%d",id,id_dono,discricao,prioridade,seccao,data.dia,data.mes,data.ano);*/
            novo=(List_cartao) malloc (sizeof (List_node_cartao));
            cartao.criacao=data;
            if(seccao==1||seccao==2){
            cartao.dono=id_dono;
            }
            else{
                cartao.dono="nenhum";/*javardice*/
            }
            cartao.id=id;
            cartao.seccao=seccao;
            cartao.prioridade=prioridade;
            cartao.descricao=discricao;
            cartao.conclusao=conclusao;
            cartao.prazo=prazo;
            novo->cartao=cartao;
            novo->next=NULL;
            insere_lista_cartao_ord(lista,novo);
            id=(char*)malloc(sizeof(char)*30);
            id_dono=(char*)malloc(sizeof(char)*30);
            discricao=(char*)malloc(sizeof(char)*30);
        }
        fclose(fp);
        }
void insere_lista_ord_no (List_pessoa lista,List_pessoa pessoa_novo)
{
    List_pessoa l,ant;
    int i;
    char * n;
    /*pessoa_novo.lista_ponteiros=cria_lista_ponteiros();*/
    n=(pessoa_novo->pessoa.nome);
    ant=lista;
    l=lista->next;
    i=0;
    while((l)&&strcmp((l->pessoa.nome),n)<0){
        ant=l;
        l=l->next;
        i++;
    }
    pessoa_novo->next=l;
    ant->next=pessoa_novo;
}
void insere_lista_cartao_ord_no(List_cartao lista,List_cartao novo)
{
    List_cartao l,ant;
    Cartao n;
    n=(novo->cartao);
    ant=lista;
    l=lista->next;
    while((l)&&compara_cartao_To_do(l->cartao,n)<0){
        ant=l;
        l=l->next;
    }
    novo->next=l;
    ant->next=novo;
}
int tarefas_a_fazer(List_pessoa lista){
    List_ponteiros l,ponteiros;
    int n;
    ponteiros=lista->lista_ponteiros;
    l=ponteiros->next;
    n=0;
    while(l){
        if(l->no_cartao->cartao.seccao==1){
            n++;
        }
        l=l->next;
    }
    return n;
    }
void imprime_pessoas_tarefas_a_fazer(List_pessoa pessoas)
    {
    List_pessoa l = pessoas->next; /* Salta o header */
    printf("----------------Pessoas_Cartoes_a_fazer----------------\n");
    while (l)
{
        printf("Nome :%s a fazer %d tarefas", l->pessoa.nome,tarefas_a_fazer(l));
        /*imprime_lista_ponteiros(l->pessoa.lista_ponteiros);*/
        l=l->next;
        printf("\n");
}
printf("--------------------------------\n");

    }
int max_tarefas_a_fazer(List_pessoa pessoas)
    {
    int n;
    List_pessoa l = pessoas->next; /* Salta o header */
    n=0;
    while (l)
{
        if(tarefas_a_fazer(l)>n){
            n=tarefas_a_fazer(l);
        }
        l=l->next;
    }
     return n;
    }
void altera_max_tarefas(List_pessoa lista,int*maximo){
    int aux,aux2;
    aux2=max_tarefas_a_fazer(lista);
    printf("Numero max atual%d\n",*maximo);
    do{
        printf("Para valor que quer alterar?:");
        scanf("%d",&aux);
        if(aux<aux2){
            printf("Parece que ha pessoas com mais tarefas neste momento do que esse valor,tente outra vez\n");
        }
    }while(aux<=aux2);
    *maximo=aux;
    }
void visualizar_quadro(List_ponteiros to_do,List_ponteiros doing,List_ponteiros done){
    imprime_to_do(to_do);
    imprime_doing(doing);
    imprime_done(done);
}
void visualizar_quadro_ficheiro(List_ponteiros to_do,List_ponteiros doing,List_ponteiros done,char*nome){
    FILE *fp;
    fp=fopen(nome,"w");
    imprime_to_do(to_do);
    imprime_to_do_ficheiro(to_do,fp);
    imprime_doing(doing);
    imprime_doing_ficheiro(doing,fp);
    imprime_done(done);
    imprime_done_ficheiro(done,fp);
    fclose(fp);
}
void imprime_cartoes_atribuidos(List_pessoa pessoas){
    char pessoa[50];
    List_pessoa actual;
    imprime_lista_pessoas(pessoas);
    do{
        fflush(stdin);
        printf("Qual o pessoa que quer ver as tarefas?\n");
        gets(pessoa);
        pesquisa_lista(pessoas,pessoa);
        actual=pesquisa_lista(pessoas,pessoa);
        if(actual==NULL){
            printf("Parece que essa pessoa nao exite,tente outra vez\n");
        }
        }while(actual==NULL);
     printf("Nome :%s a fazer as seguintes tarefas:", actual->pessoa.nome);
     imprime_lista_ponteiros_seccao(actual->lista_ponteiros);
    }
void imprime_cartoes_atribuidos_ficheiro(List_pessoa pessoas,char*nome){
    FILE *fp;
    char pessoa[50];
    List_pessoa actual;
    imprime_lista_pessoas(pessoas);
    fp=fopen(nome,"w");
    do{
        fflush(stdin);
        printf("Qual o pessoa que quer ver as tarefas?\n");
        gets(pessoa);
        pesquisa_lista(pessoas,pessoa);
        actual=pesquisa_lista(pessoas,pessoa);
        if(actual==NULL){
            printf("Parece que essa pessoa nao exite,tente outra vez\n");
        }
        }while(actual==NULL);
     fprintf(fp,"Nome :%s a fazer as seguintes tarefas:", actual->pessoa.nome);
     printf("Nome :%s a fazer as seguintes tarefas:", actual->pessoa.nome);
     imprime_lista_ponteiros_seccao(actual->lista_ponteiros);
     imprime_lista_ponteiros_seccao_ficheiro(actual->lista_ponteiros,fp);
     fclose(fp);
    }
int id_unico(List_cartao cartoes,char *teste){
    List_cartao l = cartoes->next;
    while (l)
{
        if(strcmp(l->cartao.id,teste)==0){
            return 0;
        }
        l=l->next;
}
    return 1;
    }
void escreve_ficheiro_cartao(List_cartao cartoes){
    List_cartao l;
    Cartao aux;
    FILE *fp;
    l=cartoes->next;
    fp=fopen("Cartoes.txt","w");
    while(l){
        aux=l->cartao;
        fprintf(fp,"%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\t%s\t%s\t%s\n",aux.prioridade,aux.seccao,aux.criacao.dia,aux.criacao.mes,aux.criacao.ano,aux.conclusao.dia,aux.conclusao.mes,aux.conclusao.ano,aux.prazo.dia,aux.prazo.mes,aux.prazo.ano,aux.id,aux.dono,aux.descricao);
        l=l->next;
    }
    fclose(fp);
    }
void escreve_ficheiro_pessoa(List_pessoa pessoas){
    List_pessoa l;
    Pessoa aux;
    FILE *fp;
    l=pessoas->next;
    fp=fopen("Pessoas.txt","w");
    while(l){
        aux=l->pessoa;
        fprintf(fp,"%s\t%s\t%s\n",aux.id,aux.email,aux.nome);
        l=l->next;
    }
    fclose(fp);
    }
void elemina_lista_ponteiros_total(List_ponteiros lista){
    List_ponteiros l,aux;
    l=lista->next;
    while(l){
        aux=l;
        l=l->next;
        free(aux);
    }
}

void elemina_lista_cartao_total(List_cartao lista){
    List_cartao l,aux;
    l=lista->next;
    while(l){
        aux=l;
        l=l->next;
        free(aux->cartao.descricao);
        free(aux->cartao.id);
        free(aux->cartao.dono);
        free(aux);
    }
}
void elemina_lista_pessoas_total(List_pessoa lista){
    List_pessoa l,aux;
    l=lista->next;
    while(l){
        aux=l;
        l=l->next;
        free(aux->pessoa.email);
        free(aux->pessoa.id);
        free(aux->pessoa.nome);
        elemina_lista_ponteiros_total(aux->lista_ponteiros);
        free(aux);
    }
}
int vector_disponivel(int*vec,int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        if(vec[i]==1){
            return 1;
        }
    }
    return 0;
}

#endif
