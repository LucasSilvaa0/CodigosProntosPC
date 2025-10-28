#include <bits/stdc++.h>
using namespace std;

// Esse algoritmo é para começar em um ponto (0,0) e ver se pode chegar no (H-1,W-1)
// Um elemento da fila significa [y, x, estado]. Esse estado tu usa pra definir algo sobre aquela posição

bool ChegaAoFim(int inicio_y, int inicio_x, int fim_y, int fim_x)
{
    queue<tuple<int, int, int>> fila;

    fila.push({inicio_y, inicio_x, 0});
    int novo_x, novo_y, novo_estado;
    while (!fila.empty())
    {
        auto [y, x, estado] = fila.front();
        fila.pop();

        novo_estado = (estado + 1) % 5;
        for (int i = 0; i < 4; i++)
        {
            novo_x = x + dx[i];
            novo_y = y + dy[i];

            if (novo_y >= 0 && novo_y < H && novo_x >= 0 && novo_x < W)
            {
                if (matriz[novo_y][novo_x] == caminho[novo_estado])
                {
                    if (novo_y == H - 1 && novo_x == W - 1)
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