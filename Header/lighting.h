#ifndef _LIGHTING_H
#define _LIGHTING_H

#include "Coord.h"

class Lighting
{
    public:
        Lighting();

        double d,e,m,s;

        bool light0Ligada;

        // Propriedades das fontes de luz
        float lightAmb[4];    // ??
        float lightDif0[4];  // intensidade da difusa do branco
        float lightSpec0[4]; // intensidade da especular do branco
        float lightPos0[4];  // posição ?? da luz
        float globAmb[4];

        // Propriedades do material da esfera
        float matAmbAndDif[4];   // cor ambiente e difusa: branca (ambiente = cor | )
        float matSpec[4];    // cor especular: branca

        void configuraMateriais();  
        void atualizaPropriedadesLuz();
        void informacoesIluminacao(double x, double y, double z);
};



#endif