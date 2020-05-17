/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Leonel Alegre
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleados.h"

#define MAX_EMPL 1000

int main(void)
{
	Employee aEmpleados[MAX_EMPL];
	int auxiliarId = 0;
	int auxiliarIndice;
	char auxiliarNombre[51];
	char auxiliarApellido[51];
	float auxiliarSalario = 0;
	int auxiliarSector = 0;

	int opcion;			//guarda el entero ingresado por el usuario
	int respuesta;		//guarda el return de la funcion utn_getNumero()
	int flagValidacionCarga = 0;

	initEmployees(aEmpleados, MAX_EMPL);

	for(int i = 1; i > 0; i++)
	{
		system("cls");
		printf("********Nomina de empleados********\n\n");

		//respuesta recibe el return de utn_getNumero() y guarda en el puntero &opcion el numero ingresado
		respuesta = utn_getNumero(&opcion, "Seleccione una opccion\n\n1. ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n\n","Error, opcion incorrecta.\n",1, 4,0);

		if(!respuesta)			//si respuesta no es 1 termina la iteracion
		{
			switch(opcion)		//opcion elegida por el usuario
			{
			case 1:	//ALTA
				auxiliarIndice = getEmptyIndex(aEmpleados,MAX_EMPL);
				auxiliarId = auxiliarIndice;

				if(auxiliarIndice >= 0)
				{
					if(addEmployee(aEmpleados, MAX_EMPL, auxiliarId,
					   auxiliarNombre,auxiliarApellido,
					   auxiliarSalario,auxiliarSector) == 0)
					{
						printf("Carga realisada con exito\n");
						flagValidacionCarga = 1;	//si se dio de alta
					}else{
						printf("Error al cargar");
					}
				}
				break;

			case 2:	//MODIFICAR
				if(validarOpcionCarga(flagValidacionCarga, "Error. Falta cargar empleados\n"))
				{
					if(utn_getNumero(&auxiliarId,"Ingresar ID a modificar\n","Error, ID invalida\n", 0, MAX_EMPL, 2) == 0)
					{
						auxiliarIndice = findEmployeeById(aEmpleados, MAX_EMPL, auxiliarId);
						if(auxiliarIndice >= 0 &&
						   modificarArray(aEmpleados,MAX_EMPL, auxiliarIndice)== 0)
						{
							printf("Modificacion realizada con exito\n");
						}
					}else{
						printf("Eror al modificar.\n");
					}
				}
				break;

			case 3:	//BAJA
				if(validarOpcionCarga(flagValidacionCarga, "Error. Falta cargar empleados\n"))
				{
					if(utn_getNumero(&auxiliarId,"Ingresar ID del empleado a eliminar\n","Error, ID invalida\n", 0, MAX_EMPL, 2) == 0)
					{
						auxiliarIndice = findEmployeeById(aEmpleados, MAX_EMPL, auxiliarId);
						if(auxiliarIndice >= 0 &&
						   removeEmployee(aEmpleados, MAX_EMPL, auxiliarIndice) == 0)
						{
							printf("Baja realizada con exito\n");
						}else{
							printf("error.");
						}
					}
				}
				break;

			case 4:	//INFORMAR
/*No logre terminar el caso cuatro asi que
* solo muestra la lista sin ordenar y sin promedio
*
* */
				if(validarOpcionCarga(flagValidacionCarga, "Error. Falta cargar empleados\n"))
				{
					printEmployees(aEmpleados, MAX_EMPL);
					i++;
				}
				break;
			}
		}


	if(i == 2)
	{
		i = 1;
	}
	system("pause");

	}

	return EXIT_SUCCESS;
}











