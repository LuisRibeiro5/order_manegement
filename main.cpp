#include <iostream>
#include "gerenciamentoPedidos.h"
#include "fila_dinamica.h"
#include "lista_dinamica.h"

using namespace std;

int main() {
    fila_dinamica<Pedido> filaDePedidos;
    lista_dinamica<Pedido> listaPedidoEmProcesso;

    cria(filaDePedidos);
    cria(listaPedidoEmProcesso);

    int opcao = 0;
    while (opcao != 7)
    {
        cout << "\n-----------------------------------------------------------------";
        visualizarFilaDePedidos(filaDePedidos);
        visualizarListaDePedidosEmProceso(listaPedidoEmProcesso);
        cout << "\n\n";
        cout << "Escolha uma ação:\n"
            "1. Adicionar Pedido\n"
            "2. Visualizar Fila de Pedidos\n"
            "3. Processar Próximo Pedido\n"
            "4. Atualizar Status do Pedido\n"
            "5. Visualizar Status Atual do Pedido\n"
            "6. Visualizar Histórico de Status do Pedido\n"
            "7. Sair\n";

        do
        {
            cout << ">";
            cin >> opcao;
        } while (opcao < 1 || opcao > 7);
        cin.ignore();
        cout << "\n-----------------------------------------------------------------\n";
        switch (opcao)
        {
        case 1:
            receberPedidos(filaDePedidos);
            break;
        
        case 2:
            visualizarFilaDePedidos(filaDePedidos);
            break;

        case 3:{
                try
                {
                    Pedido p = processarPedido(filaDePedidos);
                    int pos = numeroElementos(listaPedidoEmProcesso) + 1;
                    insere(listaPedidoEmProcesso, p, pos);
                }
                catch(const char* e)
                {
                    std::cerr << e << '\n';
                }
                

                break;
            }
        case 4:{
                visualizarListaDePedidosEmProceso(listaPedidoEmProcesso);
                atualizarStatusPedido(listaPedidoEmProcesso);
                break;
            }
        case 5:{
                visualizarListaDePedidosEmProceso(listaPedidoEmProcesso);
                visualizarStatusAtualPedido(listaPedidoEmProcesso);
                break;
            }

        case 6:{
                visualizarListaDePedidosEmProceso(listaPedidoEmProcesso);
                visualizarHistoricoStatusPedido(listaPedidoEmProcesso);
                break;
            }
        default:
            cout << "\nSaindo...";
            break;
        }
        
    }

    destroiFilaPedidos(filaDePedidos);
    destroiListaPedidos(listaPedidoEmProcesso);
    
    return 0;
}