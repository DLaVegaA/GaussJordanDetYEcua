#include <stdio.h> //Creado por Anuar De la Vega Márquez, ESCOM, 10/06/2022
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i, j, k;
    float c, f, piv, piv1;
    float *cas1, *cas2, *cas3, *cas4, *cas5, *cas6, *cas7, *cas8, *cas9;
    float det = 1, a = 0, s = 0, g = 0, aux = 0;
    float **arr2 = NULL;
    srand(time(NULL));

    printf("Escribe el numero de columnas: ");//Se pregunta el tamaño de columnas
    scanf("%f", &c);

    arr2 = (float **)malloc(sizeof(float *) * c);//Se crea el arreglo bidimensionales con memoria dinámica

    printf("Escribe el numero de filas: ");//Se pregunta el tamaño de filas
    scanf("%f", &f);

    for (i = 0; i < c; i++)
    {
        arr2[i] = (float *)malloc(sizeof(float) * c);//Se termina de crear el arreglo
    }

    if (c == f)//Pregunta si el numero de filas son iguales
    {
        for (i = 0; i < c; i++)
        {
            for (j = 0; j < c; j++)//Se llena el arreglo con números aleatorios y se imprime la matriz
            {
                arr2[i][j] = (rand() % 10); //i = filas, j = columnas//
                printf("%f ", arr2[i][j]);
            }
            printf("\n");
        }

        printf( "\n\n" );

        if (c == 1 && f == 1)//Si el numero de filas y columnas es igual a 1 se hace el determinante del matriz con una fila y una columna
        {
            det = arr2[0][0];//el determinante de una matriz de n = 1 es el mismo valor
            printf("El determinante de la matriz es: %f\n", det);
        }

        if (c == 2 && f == 2)//Si el tamaño de la matriz es igual a 2 se realiza su determinante 
        {
            cas1 = &arr2[0][0];
            cas2 = &arr2[0][1];
            cas3 = &arr2[1][0];
            cas4 = &arr2[1][1];

            det = *cas1 * *cas4 - (*cas3 * *cas2);//Se realiza la operacion multiplicando en cruzado y se imprime el resultado

            printf("El determinante de la matriz es: %f\n", det);
        }
        if (c == 3 && f == 3)//Si la matriz es n = 3 se realiza su determinante por cofactores 
        {
            cas1 = &arr2[0][0];
            cas2 = &arr2[0][1];
            cas3 = &arr2[0][2];
            cas4 = &arr2[1][0];
            cas5 = &arr2[1][1];
            cas6 = &arr2[1][2];
            cas7 = &arr2[2][0];
            cas8 = &arr2[2][1];
            cas9 = &arr2[2][2];

            a = *cas1 * ((*cas5 * *cas9) - (*cas8 * *cas6));
            s = (-1) * (*cas2 * ((*cas4 * *cas9) - (*cas7 * *cas6)));//Se realizan las operaciones y se imprime el resultado
            g = *cas3 * ((*cas4 * *cas8) - (*cas7 * *cas5));

            det = a + s + g;

            printf("El determinante de la matriz es: %f\n", det);
        }

        if (c > 3 && j > 3)//Si la matriz es de tamaño n x n su determinante se va a encontrar por el metodo de Gauss Jordan
        {
            for (i = 0; i < c; i++)//Se recorre el arreglo y se encuentran los numeros dentro de la diagonal
            {
                if ( arr2[i][i] == 0)//Si el numero que se encuentra en la diagonal es igual a 0 se le asigna un nuevo valor decimal al 0
                {
                    arr2[i][i] = 0.00000001;
                }
                piv = arr2[i][i];//Al pivote de la diagonal se le agregan los numeros de la diagonal de la matriz

                for ( j = i+1; j < c; j++ )//En esta seccion se cambian las columas con las filas
                {
                    piv1 = arr2[j][i];//para que se pueda recorrer el arreglo empezando con los numeros que se encuentran debajo de la diagonal
                    aux = piv1/piv;//Se obtienen los numero debajo de la diagonal con el pivote1 y se divide entre el pivote de la diagonal

                    for ( k = 0; k < c; k++ )//la variable k pasa a ser las columnas para que se pueda mover dentro del arreglo y se realice la sig operacion
                    {
                        arr2[j][k] = arr2[j][k] - aux * arr2[i][k];//para toda la fila se multiplica por la variable aux que es la division de los pivotes 
                    } // y se cambian los valores dentro de la matriz
                }
            }

            for ( i = 0; i < c; i++ )//se recorre el arreglo para encontrar nuevamente los numeros de la diagonal
            {
                det *= arr2[i][i];//como cambiaron los valores de la matriz original, para sacar el determinante se realiza la multiplicación de los numeros
            } //de la diagonal

            for (i = 0; i < c; i++)//la varible i vuelve a hacer las filas y la variable j vuelve a hacer las columnas
            {
                for (j = 0; j < c; j++)
                {
                    printf("%f ", arr2[i][j]);//se imprime la matriz modificada
                }
                printf("\n");
            }

            printf( "\nLa determinante de la matriz es: %f\n", det );//se imprime el determinante
        }
    }
    else
    {
        printf("\nERROR! NUMEROS INVALIDOS.\nLos numeros de filas y columnas deben ser iguales.\n");//Si el numero de filas y columnas son diferentes,
    }//se imprime un mensaje de error

    for (i = 0; i < c; i++)//se libera la memoria dinamica
    {
        free(arr2[i]);
    }

    free(arr2);

    return 0;
}
