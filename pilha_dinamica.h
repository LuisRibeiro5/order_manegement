#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

template<typename T>
struct NodoPilha
{
    T valor;
    NodoPilha<T>* ant;
};

template<typename T>
struct pilha_dinamica
{
    int cardinalidade;
    NodoPilha<T>* topo;
};

template<typename T>
void cria(pilha_dinamica<T>& pilha ){
    pilha.cardinalidade = 0;
    pilha.topo = nullptr;
}

template<typename T>
void destroi(pilha_dinamica<T>& pilha ){
    while (pilha.topo)
    {
        NodoPilha<T>* apagado = pilha.topo;
        pilha.topo = pilha.topo->ant;
        
        delete apagado;
    }

    cria(pilha); 
}

template<typename T>
bool ehVazia(pilha_dinamica<T>& pilha ){
    return pilha.cardinalidade == 0;
}

template<typename T>
int getSize(pilha_dinamica<T>& pilha ){
    return pilha.cardinalidade;
}

template<typename T>
bool existeElemento(pilha_dinamica<T>* pilha, T elem ){
    if (ehVazia(pilha))
    {
        throw "PILHA ESTA VAZIA.";
    }
    NodoPilha<T>* atual = pilha->topo;

    while (atual)
    {
        if (atual->valor == elem) return true;

        atual = atual->ant;
    }
    return false;
}

template<typename T>
bool existePos(pilha_dinamica<T>& pilha, int pos ){
    return pos > 0 && pos <= pilha.cardinalidade;
}

template<typename T>
T getElem(pilha_dinamica<T>& pilha, int pos ){
    if (!existePos(pilha, pos))
    {
        throw "POSICAO INVALIDA.";
    }
    
    NodoPilha<T>* atual = pilha.topo;

    for (int i = 1; i < pos; i++)
    {
        atual = atual->ant;
    }
    
    return atual->valor;
}

template<typename T>
int getPos(pilha_dinamica<T>& pilha, T elem ){
    if (!existeElemento(pilha, elem))
    {
        throw "ELEMENTO NAO EXISTE.";
    }
    
    NodoPilha<T>* atual = pilha.topo;
    int cont = 1;

    while (atual)
    {
        if (atual->valor == elem)
        {
            return cont;
        }
        
        atual = atual->ant;
        cont++;
    }
    
}

template<typename T>
T getTopo(pilha_dinamica<T>& pilha ){
    if (ehVazia(pilha))
    {
        throw "FILA VAZIA.";    
    }
    
    return pilha.topo->valor;
}

template<typename T>
void push(pilha_dinamica<T>& pilha, T elem ){
    NodoPilha<T>* novo = new NodoPilha<T>;
    novo->valor = elem;
    novo->ant = pilha.topo;
    pilha.topo = novo;

    pilha.cardinalidade++;
}

template<typename T>
void pop(pilha_dinamica<T>& pilha ){
    if (ehVazia(pilha))
    {
        throw "PILHA VAZIA.";   
    }
    
    NodoPilha<T>* apagado = pilha.topo;
    pilha.topo = pilha.topo->ant;

    delete apagado;
    pilha.cardinalidade--;
}

template<typename T>
void mostra(pilha_dinamica<T>& pilha) {
    std::cout << "[";
    for (int i = pilha.cardinalidade; i >= 1; i--) {
        if (i != pilha.cardinalidade) std::cout << ", ";
        std::cout << "'" << getElem(pilha, i) << "'";
    }
    std::cout << "]";
}

#endif