#include <stdio.h>
#include <string.h>

// Funcao para verificar o acesso com base nas regras fornecidas
int can_Access(int maxCapacity, int* child, int* visitor, int totalChilds) {
    totalChilds += *child + *visitor;
    int diff = 0;
    diff += maxCapacity - totalChilds;
    if (totalChilds <= maxCapacity) {
        return 1;
    }else if (*visitor > 0) {
        return 2;
    }else if(diff > 0 && *visitor > 0){
        return 1;
    } else if((*child + *visitor) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    int maxCapacity, adult, child, visitor;
    int totalChilds = 0, totalAdult = 0;

    // Receba a quantidade maxima de criancas permitidas na piscina
    scanf("%d", &maxCapacity);

        // Arrays para armazenar informacoes de cada grupo
        int adults[100], children[100], visitors[100];
        int groupCount = 0;

    	// Loop para receber multiplos conjuntos de entrada
        // Recebe os grupos ateh que seja inserido um valor negativo para adultos
        while (1) {
            scanf("%d", &adult);
            if (adult < 0) {
                break;
            }

            scanf("%d", &child);
            scanf("%d", &visitor);

            adults[groupCount] = adult;
            children[groupCount] = child;
            visitors[groupCount] = visitor;

            groupCount++;
        }

        // Processamento das informacoes apos receber um valor negativo para adultos
        for (int i = 0; i < groupCount; i++) {

            switch (can_Access(maxCapacity, &children[i], &visitors[i], totalChilds)) {
                case 2:
                    totalAdult += adults[i];
                    totalChilds += children[i] + visitors[i];
                    printf("Acesso permitido devido a presenca de convidado(s).\n");
                    break;
                case 1:
                    totalAdult += adults[i];
                    totalChilds += children[i] + visitors[i];
                    printf("Acesso permitido!\n");
                    break;
                case 0:
                    
                    printf("Capacidade maxima de criancas atingida/excedida.\n");
                    printf("Tem %d crianca(s) a mais que as %d permitidas.\n", ((-1)*(maxCapacity-totalChilds)), maxCapacity);
                    break;
                default:
                    break;
            }

            // Imprime os resultados para cada grupo de entrada
            printf("Adultos na piscina: %d\nCriancas na piscina: %d\n***\n", totalAdult, totalChilds);
        }

    return 0;
}




