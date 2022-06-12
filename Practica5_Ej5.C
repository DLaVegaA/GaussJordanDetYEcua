#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
int main()
{
    int i, j, k;
    float **arr2 = NULL;
    float *res, *res2, *res3, *diag, *diag2, *diag3, *desp, *desp2, *desp3;
    float aux, piv, piv1, x, y, z, a, b, c;

    arr2 = (float **)malloc(sizeof(float *) * 3);//se crea el arreglo bidimensional de forma dinámica con filas de 3
    
    for (i = 0; i < 3; i++)
    {
        arr2[i] = (float *)malloc(sizeof(float) * 4);//van a ser 4 columnas una para la variable x, una para la variable, otra para la varible z
    } //y una para los resultados de dichas expresiones
    
    for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 4; j++ )
        {
            printf( "Escribe los coeficientes de x, y, z y el resultado de la ecuacion: " );//el usuario elige el valor de los coeficientes de x, y, z y
            scanf( "%f", &arr2[i][j] );//su resultado de la ecuacion
        }
        printf( "\n" );
    }
    
   for( i = 0; i < 3; i++ )
    {
        for( j = 0; j < 4; j++)
        {
            printf( "%f ", arr2[i][j] );//se imprimen los valores en forma de matriz
        }
        printf( "\n" );
    }
    
    printf( "\n" );
    
    for (i = 0; i < 3; i++)//Se recorre el arreglo para encontrar las incognitas por el metodo de Gauss Jordan
    {
        if ( arr2[i][i] == 0)//se encuentra la diagonal
        {
            arr2[i][i] = 0.00000001;//si el valor de la diagonal es 0, se le agrega un valor decimal
        }
        piv = arr2[i][i];//el pivote guarda los valores de la diagonal

        for ( j = i+1; j < 3; j++ )//j pasa a ser las filas para recorrer los numeros que se encuentran bajo los valores de la diagonal
        {
            piv1 = arr2[j][i];//al pivote 1 se le guardan estos valores
            aux = piv1/piv;//se hace la division del pivote de la diagonal y del pivote 1, se guarda en el auxiliar

            for ( k = 0; k < 4; k++ )//k ahora son las columnas para que se recorra todo el arreglo
            {
                 arr2[j][k] = arr2[j][k] - aux * arr2[i][k];//la division de los pivotes se multiplica por los valores de todas las lineas debajo de la diagonal
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%f ", arr2[i][j]);//se imprime la nueva matriz
        }
        printf("\n");
    }
    
    res = &arr2[2][3];
    res2 = &arr2[1][3];//se guardan los valores de la nueva matriz en apuntadores para que se facilite el uso en las futuras operaciones
    res3 = &arr2[0][3];//res = valores de los resultados de la ecuacion
    diag = &arr2[2][2];
    diag2 = &arr2[1][1];
    diag3 = &arr2[0][0];//diag = valores de la diagonal
    desp = &arr2[1][2];
    desp2 = &arr2[0][2];
    desp3 = &arr2[0][1];//desp = valores de lo que queda de la matriz para resolver las incognitas
      
    z = *res / *diag;//se despeja z

    a = -1 * (z * *desp);
    y = (*res2 + a) / *diag2;//se despeja y

    b = -1 * (z * *desp2);
    c = -1 * (y * *desp3);
    x = (*res3 + b + c) / *diag3; //se despeja x
    
    
    printf( "\nLa solucion al sistema de ecuaciones es: \n");
    
    printf( "x = %f\n", x);
    printf( "y = %f\n", y);//se imprimen los resultados de los despejes
    printf( "z = %f", z);
     
    for (i = 0; i < 3; i++)
    { 
        free(arr2[i]);//se libera la memoria dinamica
    }

    free(arr2);
    
    
    return 0;
}
