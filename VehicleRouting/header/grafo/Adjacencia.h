#ifndef ADJACENCIA_H_INCLUDED
#define ADJACENCIA_H_INCLUDED

#include <iostream>
#include <memory>

using namespace std;

/**
*   Classe que representa as adjac�ncias do grafo,
*   cont�m os ids dos n�s pertencentes ao par (i, j)
*   e o custo da adjac�ncia
**/
class Adjacencia
{
    private:
        int idVertice1; // N� i pertencente a adjac�ncia
        int idVertice2; // N� j pertencente a adjac�ncia

        float weight; // Peso da adjac�ncia
    public:
        Adjacencia(int idVertice1, int idVertice2, float weight);

        int getIdVertice1();
        int getIdVertice2();

        float getWeight();
        void setWeight(float weight);

        // Verifica se duas adjac�ncias s�o iguais
        bool equals(int idVertice1, int idVertice2);
        bool equals(shared_ptr<Adjacencia> adj);
};

#endif // ADJACENCIA_H_INCLUDED
