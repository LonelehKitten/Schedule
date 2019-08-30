/*

    Nome: Daniel N. de Oliveira

*/

#include "schedule.h"

int main(){

    system("clear");

    int op = 1;

    init();

    do{
        printf("\n\n\t\t==== MENU ====\n\n");
        printf("\t1. Buscar\n\t2. Listar\n\t3. Cadastrar\n\t4. Remover\n\t0. Sair\n\n\t\t>>>>  ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                search();
                break;
            case 2:
                list();
                break;
            case 3:
                put();
                break;
            case 4:
                pop();
                break;
        }
    }while(op);

    return 0;
}