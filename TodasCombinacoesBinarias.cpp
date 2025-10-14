int totalPossibilidades = 1 << quantidadeElementos;
int maiorSoma = 0;
int indiceMaiorSoma = 0;
for (int i = 0; i < totalPossibilidades; i++)
{
    soma = 0;
    for (int j = 0; j < quantidade; j++)
    {
        resto = ((i >> j) % 2);
        soma += valores[j] * resto;

        if (soma > limite)
        {
            break;
        }
    }

    if (soma == limite)
    {
        indiceMaiorSoma = i;
        maiorSoma = soma;
    }
    else if (soma > maiorSoma && soma <= limite)
    {
        maiorSoma = soma;
        indiceMaiorSoma = i;
    }
}