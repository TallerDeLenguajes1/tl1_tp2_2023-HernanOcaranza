#include <stdio.h>
#include <stdlib.h>
#define CANT_PCS 5

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};


typedef struct computadora{
    int velocidad;
    int anio;
    int cantidad;
    char* tipo_cpu;
} compu;

void CargarPcs (compu* listaPcs);

void MostrarPc (compu pc);

void MostrarTodasLasPcs (compu* listaPcs);

void MostrarPcMasVieja (compu* listaPcs);

void MostrarPcMasRapida (compu* listaPcs);

int main () {
    compu pcs[CANT_PCS];
    CargarPcs(pcs);
    MostrarTodasLasPcs(pcs);
    MostrarPcMasVieja(pcs);
    MostrarPcMasRapida(pcs);

    return 0;
}

void CargarPcs (compu* listaPcs) {
    int i;
    for (i = 0; i < CANT_PCS; i++) {
        listaPcs[i].anio = 2015 + rand()%8;
        listaPcs[i].cantidad = 1 + rand()%8;
        listaPcs[i].velocidad = 1 + rand()%3;
        listaPcs[i].tipo_cpu = tipos[rand()%6];
    }
}

void MostrarPc (compu pc) {
    printf("\nTipo de PC: %s", pc.tipo_cpu);
    printf("\nAnio de fabricacion: %d", pc.anio);
    printf("\nVelocidad de procesamieto: %d GHz", pc.velocidad);
    printf("\nCantidad de nucleos: %d\n", pc.cantidad);
}

void MostrarTodasLasPcs (compu* listaPcs) {
    int i;
    for (i = 0; i < CANT_PCS; i++) {
        printf("\nPC numero %d", i+1);
        MostrarPc(listaPcs[i]);
    }
}

void MostrarPcMasVieja (compu* listaPcs) {
    int i, masVieja = 9999, indVieja;

    for (i = 0; i < CANT_PCS; i++) {
        if (listaPcs[i].anio < masVieja) {
            masVieja = listaPcs[i].anio;
            indVieja = i;
        }        
    }
    printf("\nLa Pc mas vieja es:");
    MostrarPc(listaPcs[indVieja]);
}

void MostrarPcMasRapida (compu* listaPcs) {
    int i, masRapida = -1, indRapida;

    for (i = 0; i < CANT_PCS; i++) {
        if (listaPcs[i].velocidad > masRapida) {
            masRapida = listaPcs[i].velocidad;
            indRapida = i;
        }        
    }
    printf("\nLa Pc que tiene mayor velocidad es:");
    MostrarPc(listaPcs[indRapida]);
}