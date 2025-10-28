#include <bits/stdc++.h>
using namespace std;

// Esse algoritmo é para começar em um ponto (0,0) e ver se pode chegar no (H-1,W-1)
// Um elemento da fila significa [y, x, estado]. Esse estado tu usa pra definir algo sobre aquela posição.
// H é a altura da matriz, W a largura.

bool ChegaAoFim(int H, int W, int fim_y, int fim_x, int inicio_y = 0, int inicio_x = 0)
{
    queue<tuple<int, int, int>> fila;

    fila.push({inicio_y, inicio_x, 0});
    int novo_x, novo_y, novo_estado;
    while (!fila.empty())
    {
        auto [y, x, estado] = fila.front();
        fila.pop();

        // Aqui tu tem que registrar se o próximo estado é obrigado a ser algo específico. Ex.: tô no num 1 e o próximo tem que ser num 2.
        novo_estado = (estado + 1) % 5;
        for (int i = 0; i < 4; i++)
        {
            novo_x = x + dx[i];
            novo_y = y + dy[i];

            if (novo_y >= 0 && novo_y < H && novo_x >= 0 && novo_x < W)
            {
                // Nesse if tu tem que colocar a restrição: o que o estado precisa ter para aquela posição ser aceita como um nó que pode passar?
                if (matriz[novo_y][novo_x] == novo_estado)
                {
                    if (novo_y == fim_y - 1 && novo_x == fim_y - 1)
                    {
                        return true;
                    }

                    if (!passados[novo_y][novo_x])
                    {
                        passados[novo_y][novo_x] = true;
                        fila.push({novo_y, novo_x, novo_estado});
                    }
                }
            }
        }
    }

    return false;
}