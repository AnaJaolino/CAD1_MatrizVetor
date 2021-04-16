/*
 * Aluna: Ana Carolina Jaolino
 * DRE: 117230950
 * Escola Politécnica
 * Universidade Federal do Rio de Janeiro - UFRJ
 * Engenharia de Computacao e Informacao
 */
 
double **instantiate_matrix (int matriz_max)
{
    double **matriz = (double **)malloc((matriz_max + 1) * sizeof(double *));
    for (int linha = 0; linha <= matrix_size; linha++)
        matriz[linha] = (double *)malloc((matriz_max + 1) * sizeof(double));

    return matriz;
}

int main (int argc, char *argv[])
{
    int MAX_SIZE = atoi(argv[1]);
    int nIndice, nIndiceLinha, nIndiceColuna;
    double *vetor = (double *)malloc((MAX_SIZE + 1) * sizeof(double));
    double *resultado = (double *)malloc((MAX_SIZE + 1) * sizeof(double));
    double **matriz = instantiate_matrix(MAX_SIZE);
    clock_t inicio, fim;
    double tempoExecI, tempoExecJ;

    	srand(time(NULL));

    	/*Variando o tamanho da matriz e do vetor, mantando n <= nMax*/
	for (nIndice = 1; nIndice <= MAX_SIZE; (nIndice = nIndice * 3))
	{
        	/*Inicializando randomicamente matriz e vetor, de acordo com o tamanho n*/
		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
        		for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
            		{
                		matriz[nIndiceLinha][nIndiceColuna] = (double)(rand() % MAX_SIZE);
            		}
            		vetor[nIndiceLinha] = (double)(rand() % MAX_SIZE);
            		resultado[nIndiceLinha] = 0;
        	}

        	/*Realizando o produto (i externo ; j interno)*/
        	inicio = clock();
	    	for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
            		for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
            		{
                		resultado[nIndiceLinha] = resultado[nIndiceLinha] + (matriz[nIndiceLinha][nIndiceColuna] * vetor[nIndiceColuna]);
            		}
        	}
        	fim = clock();
        	tempoExecI = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

		
        	/*Zerando o vetor resultado*/
		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
            		resultado[nIndiceLinha] = 0;
        	}

    
        	/*Realizando o produto (j externo ; i interno)*/
        	inicio = clock();
	    	for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
        	{
            		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
            		{
                		resultado[nIndiceLinha] = resultado[nIndiceLinha] + (matriz[nIndiceLinha][nIndiceColuna] * vetor[nIndiceColuna]);
            		}
        	}
        	fim = clock();
        	tempoExecJ = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

	}
	
    	printf("\n I Externo: %f \n J Externo: %f\n",tempoExecI, tempoExecJ);

	return 0;
}
