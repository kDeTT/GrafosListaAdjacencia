#include "../../header/grafo/Vertice.h"

Vertice::Vertice()
{
    this->weight = 0;
    this->coord = NULL;
    this->adjacenciaList = make_shared<OrderedList<Adjacencia>>();
    this->adjInsertType = ListOrdered;
}

shared_ptr<Point> Vertice::getCoord()
{
    return this->coord;
}

void Vertice::setCoord(shared_ptr<Point> coord)
{
    this->coord = coord;
}

void Vertice::setAdjListType(OperationType type)
{
    this->adjInsertType = type;
}

shared_ptr<Adjacencia> Vertice::getAdjacencia(int idVertice2)
{
    return this->adjacenciaList->getNodeInfo(idVertice2);
}

float Vertice::getWeight()
{
    return this->weight;
}

void Vertice::setWeight(float weight)
{
    this->weight = weight;
}

int Vertice::getGrau()
{
    return this->adjacenciaList->getLength();
}

void Vertice::addAdjacencia(int idVertice1, int idVertice2, float weight)
{
    if(!existsAdjacencia(idVertice2))
    {
        this->adjacenciaList->insert(idVertice2, weight, make_shared<Adjacencia>(idVertice1, idVertice2, weight), this->adjInsertType);
    }
    else
    {
        cout << "[ Erro ]: Adjac�ncia j� existe!" << endl;
    }
}

void Vertice::removeAdjacencia(int idVertice2)
{
    this->adjacenciaList->remove(idVertice2);
}

bool Vertice::existsAdjacencia(int idVertice2)
{
    return (this->getAdjacencia(idVertice2) != NULL);
}

shared_ptr<OrderedList<Adjacencia>> Vertice::getAdjacenciaList()
{
    return this->adjacenciaList;
}
