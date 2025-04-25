#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

template<typename T>
struct Nodo
{
    T valor;
    Nodo<T>* prox;
};

template<typename T>
struct fila_dinamica
{
    int cardinalidade;
    Nodo<T>* inicio;
};

template<typename T>
void cria(fila_dinamica<T> &fila ){
    fila.cardinalidade = 0;
    fila.inicio = nullptr;
}

template<typename T>
void destroi(fila_dinamica<T>& fila ){
    Nodo<T>* atual;

    while (fila.inicio)
    {
        atual = fila.inicio;
        fila.inicio = fila.inicio->prox;
        delete atual;
    }
    
}

template<typename T>
bool ehVazia(fila_dinamica<T> &fila ){
    return fila.cardinalidade == 0;
}

template<typename T>
int numElementos(fila_dinamica<T> &fila ){
    return fila.cardinalidade;
}

template<typename T>
bool existeElemento(fila_dinamica<T>& fila, T elem ){
    if (ehVazia(fila))
    {
        throw "FILA VAZIA.";
    }
    
    Nodo<T>* atual = fila.inicio;

    while (atual)
    {
        if (atual->valor == elem)
        {
            return true;
        }
        
        atual = atual->prox;
    }
    
    return false;
}

template<typename T>
bool ehPosValida(fila_dinamica<T> &fila, int pos){
    if (ehVazia(fila))
    {
        throw "FILA VAZIA.";
    }
    
    return pos > 0 && pos <= fila.cardinalidade;
}

template<typename T>
T getElem(fila_dinamica<T>& fila, int pos){
    if (!ehPosValida(fila, pos))
    {
        throw "POSICAO INVALIDA.";
    }

    Nodo<T>* atual = fila.inicio;

    for (int i = 1; i < pos; i++)
    {
        atual = atual->prox;
    }
    
    return atual->valor;
}

template<typename T>
int getPosicao(fila_dinamica<T>& fila, T elem ){
    if (!existeElemento(fila, elem))
    {
        throw "ELEMENTO NAO EXISTE.";
    }
    
    Nodo<T>* atual = fila.inicio;

    for (int i = 0; i < fila.cardinalidade; i++)
    {
        if (atual->valor == elem) return i + 1;

        atual = atual->prox;
    }
    
}

template<typename T>
T getFirst(fila_dinamica<T>& fila ){
    fila.inicio->valor;
}

template<typename T>
T getLast(fila_dinamica<T>& fila ){
    Nodo<T>* atual = fila.inicio;

    while (atual->prox)
    {
        atual = atual->prox;
    }
    
    return atual->valor;
}

template<typename T>
void insere(fila_dinamica<T>& fila, T elem ){
    Nodo<T>* novo = new Nodo<T>;
    novo->prox = nullptr;
    novo->valor = elem;

    if (ehVazia(fila))
    {
        fila.inicio = novo;
    } else {
        
        Nodo<T>* atual = fila.inicio;

        while(atual->prox){
            atual = atual->prox;
        }

        atual->prox = novo;
    }
    
    fila.cardinalidade++;
}

template<typename T>
T retira(fila_dinamica<T>& fila ){
    if (ehVazia(fila))
    {
        throw "FILA VAZIA.";
    }
    
    Nodo<T>* apagado = fila.inicio;
    T elem = apagado->valor;

    fila.inicio = fila.inicio->prox;

    delete apagado;
    fila.cardinalidade--;

    return elem;
}

template<typename T>
void mostra(fila_dinamica<T>& fila ){
    Nodo<T>* atual = fila.inicio;
    while (atual)
    {
        std::cout << atual->valor;
        atual->prox ? std::cout << " - " : std::cout << " ";

        atual = atual->prox;
        
    }
    
}

#endif