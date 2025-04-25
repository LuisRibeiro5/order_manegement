#pragma once
#include "fila_dinamica.h"
#include "pilha_dinamica.h"
#include "lista_dinamica.h"
#include <iostream>
#include <sstream>

using namespace std;

struct Pedido
{
    string id;
    string nomeCliente;
    lista_dinamica<string> listaDeItens;
    pilha_dinamica<string> historicoDeStatus;

};

void visualizarFilaDePedidos(fila_dinamica<Pedido> &fila ){ 
    cout << "\nFila de Pedidos pendentes: [";
    for (int i = 1; i <= numElementos(fila); i++)
    {
        Pedido pedido = getElem(fila, i);

        cout << pedido.id;
        if (i != numElementos(fila)) cout << ", ";
    }
    cout << "]";
}

void visualizarListaDePedidosEmProceso(lista_dinamica<Pedido> &lista ){ 
    cout << "\nLista de pedidos em processo: [";
    for (int i = 1; i <= numeroElementos(lista); i++)
    {
        Pedido pedido = getElem(lista, i);

        cout << pedido.id;
        if (i != numeroElementos(lista)) cout << ", ";
    }
    cout << "]";
}

void receberPedidos(fila_dinamica<Pedido>& filaPedidos){
    Pedido pedido;

    cout << "\nInsira o ID do pedido: ";
    cin >> pedido.id;
    cin.ignore();

    cout << "Insira seu nome: "; 
    getline(cin, pedido.nomeCliente);

    cria(pedido.listaDeItens);
    cout << "Insira os itens do Pedido(separado por ','): ";
    string item;
    getline(cin, item);
    /*while(item != "0"){
        cout << "\digite 0 para parar\nItem:";
        getline(cin, item);

        insere(pedido.listaDeItens, item, numeroElementos(pedido.listaDeItens) + 1);
    }*/
    stringstream itemSs(item);
    string palavra;
    while (getline(itemSs, palavra, ','))
    {
        int start = palavra.find_first_not_of(" \n\t\r");
        int end = palavra.find_last_not_of(" \n\r\t");

        if (start == std::string::npos) continue;

        palavra = palavra.substr(start, end - start + 1);
        
        insere(pedido.listaDeItens, palavra, numeroElementos(pedido.listaDeItens) + 1);
    }

    cria(pedido.historicoDeStatus);

    string status = "Recebido";
    push(pedido.historicoDeStatus, status);

    insere(filaPedidos, pedido);

    cout << "Pedido adicionado com sucesso! status:" << status;
}

Pedido processarPedido(fila_dinamica<Pedido> &fila ){
    Pedido p = retira(fila);
    cout << "\nProcessando pedido id: " << p.id << ", Cliente: " << p.nomeCliente << ", Itens: "; 
    mostra(p.listaDeItens);

    return p;
}



void atualizarStatusPedido(lista_dinamica<Pedido> &pedidos){
    string id;
    cout << "\nDigite o ID do Pedido para atualizar o status: ";
    getline(cin, id);

    bool achou = false;
    for (int i = 1; i <= numeroElementos(pedidos); i++)
    {
        Pedido& p = getRefElem(pedidos, i);

        if (p.id == id)
        {
            achou = true;
            cout << "\nNovo status: ";
            string status;
            getline(cin, status);

            push(p.historicoDeStatus, status);
        }
        
    }
    
    if (!achou) cout << "\nNão há pedidos em processo com esse id";
    
}

void visualizarStatusAtualPedido(lista_dinamica<Pedido>& pedidos ){
    string id;
    cout << "\nDigite o ID do Pedido para atualizar o status: ";
    getline(cin, id);

    bool achou = false;
    for (int i = 1; i <= numeroElementos(pedidos); i++)
    {
        Pedido &p = getRefElem(pedidos, i);

        if (p.id == id)
        {
            achou = true;
            cout << "\nStatus atual do pedido " << id << ": " << getTopo(p.historicoDeStatus);

        }
        
    }
    
    if (!achou) cout << "\nNão há pedidos em processo com esse id";
    
}

void visualizarHistoricoStatusPedido(lista_dinamica<Pedido>& pedidos ){
    string id;
    cout << "\nDigite o ID do Pedido para atualizar o status: ";
    getline(cin, id);

    bool achou = false;
    for (int i = 1; i <= numeroElementos(pedidos); i++)
    {
        Pedido &p = getRefElem(pedidos, i);

        if (p.id == id)
        {
            achou = true;
            cout << "\nHistórico de status do pedido " << id << ": "; mostra(p.historicoDeStatus);

        }
        
    }
    
    if (!achou) cout << "\nNão há pedidos em processo com esse id";
    
}

void destroiFilaPedidos(fila_dinamica<Pedido>& pedidos ){
    for (int i = i; i <= numElementos(pedidos); i++)
    {
        Pedido p = getElem(pedidos, i);

        destroi(p.historicoDeStatus);
        destroi(p.listaDeItens);
    }
    
    destroi(pedidos);
}

void destroiListaPedidos(lista_dinamica<Pedido>& pedidos ){
    for (int i = i; i <= numeroElementos(pedidos); i++)
    {
        Pedido p = getElem(pedidos, i);

        destroi(p.historicoDeStatus);
        destroi(p.listaDeItens);
    }
    
    destroi(pedidos);
}