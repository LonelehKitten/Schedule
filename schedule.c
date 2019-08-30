#include "schedule.h"

typedef struct schedule{
    int id;
    char * name;
    char * address;
    char * city;
    long int phone;

    struct schedule * next;
} Schedule;

Schedule * root;

void init(){
    root = (Schedule *) malloc(sizeof(Schedule));
    root->next = (Schedule *) malloc(sizeof(Schedule));
    root->next->next = NULL;

    root->id = 0;
}

void search(){
    Schedule * s;
    char * name;

    if(root->next->next){
        printf("\n\t\t==== BUSCAR ====\n");

        printf("\n\tName:    ");
        name = getString();

        for(s = root->next; s->next; s = s->next){
            if(strcmp(name, s->name) == 0){
                printf("\n\t== [%d] =========\n\n", s->id);
                printf("\t\tName: %s\n", s->name);
                printf("\t\tEndereço: %s\n", s->address);
                printf("\t\tCidade: %s\n", s->city);
                printf("\t\tTelefone: %ld\n", s->phone);
            }
        }
    }
    else{
        printf("\n\tNão há registros para buscar. Adicione alguns e tente novamente!\n");
    }
}

void put(){

    Schedule * s;
    Schedule * aux;

    aux = (Schedule *) malloc(sizeof(Schedule));

    for(s = root; s->next; s = s->next){
        if(!s->next->next || (s->next->id - s->id) > 1){
            aux->next = s->next;
            s->next = aux;

            aux->id = s->id + 1;
            break;
        }
    }

    printf("\n\t\t==== CADASTRAR ====\n");

    printf("\n\tName:    ");
    aux->name = getString();

    printf("\n\tEndereço:    ");
    aux->address = getString();

    printf("\n\tCidade:    ");
    aux->city = getString();

    printf("\n\tTelefone:    ");
    scanf("%ld", &aux->phone);

    printf("\n\t\tCadastrado com sucesso!\n");

}

void list(){

    Schedule * s;

    printf("\n\t\t==== LISTAR ====\n");

    for(s = root->next; s->next; s = s->next){
        printf("\n\t== [%d] =========\n\n", s->id);
        printf("\t\tName: %s\n", s->name);
        printf("\t\tEndereço: %s\n", s->address);
        printf("\t\tCidade: %s\n", s->city);
        printf("\t\tTelefone: %ld\n", s->phone);
    }
    
}

void pop(){
    Schedule * s;
    Schedule * aux;
    int id;

    if(root->next->next){
        printf("\n\t\t==== REMOVER ====\n");

        printf("\n\tID:    ");
        scanf("%d", &id);

        for(s = root; s->next; s = s->next){
            if(s->next->id == id){
                aux = s->next;
                s->next = aux->next;

                printf("\n\t== [%d] =========\n\n", aux->id);
                printf("\t\tName: %s\n", aux->name);
                printf("\t\tEndereço: %s\n", aux->address);
                printf("\t\tCidade: %s\n", aux->city);
                printf("\t\tTelefone: %ld\n", aux->phone);

                free(aux);
                break;
            }
        }

        printf("\n\t\tRemovido com sucesso!\n");
    }
    else{
        printf("\n\tNão há registros para remover. Adicione alguns e tente novamente!\n");
    }

}

// ===== UTILS ===== //

char * getString(){

    char * word;
    char l;
    int i = 0;

    word = (char *) malloc(sizeof(char));

    while((l = getchar()) != '\n'){
        word[i++] = l;
        word = (char *) realloc(word, (i+1)*sizeof(char));
    }

    word[i] = '\0';

    return word;
}

