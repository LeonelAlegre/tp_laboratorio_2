/*
 * Empleados.c
 *
 *  Created on: 16 may. 2020
 *      Author: Leonel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"
#include "utn.h"

static void imprimir(Employee* pEmpleado);


/**
 * \brief Valida que haya un empleado cargado en el sistema
 * \param opcion La opcion guarda 1 (TRUE) or 0 (FALSE)
 * \param mensajeError Mensaje a mostrar al retornar FALSE
 * \return Retorna 1 (TRUE) si se cargo un empleado y 0 (FALSE) si no se empleados cargados
 */
int validarOpcionCarga(int opcion, char* mensajeError){
	int respuesta = 0;			//FALSO falta cargar empleados

	if((opcion == 1 || opcion == 0) && mensajeError != NULL)		//validacion de parametros
	{
		if(opcion == 0)			//
		{
			printf("%s", mensajeError);
			return respuesta;	//retorna 0
		}

		respuesta = 1;			//VERDADERO se cargaron empleados
	}

	return respuesta;			//retorna 1
}
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int respuesta = -1;		//error

	if(list != NULL && len > 0)		//validacion de datos
	{
		respuesta = 0;					//
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return respuesta;
}
/** \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
	int respuesta = -1; //ERROR
	Employee buffer;

	if(list != NULL && len > 0 && id >= 0)	//falta agregar
	{
		if(utn_getNombre(buffer.name,sizeof(buffer.name),"Ingresar nombre \n","Error, nombre incorrecto\n", 2) == 0 &&
		   utn_getNombre(buffer.lastName,sizeof(buffer.lastName),"Ingresar apellido \n","Error, apellido incorrecto\n", 2) == 0 &&
		   utn_getNumeroFlotante(&buffer.salary,"Ingresar salario \n","Error, salario incorrecto\n", 0 ,1000000, 2) == 0 &&
		   utn_getNumero(&buffer.sector,"Ingresar sector \n","Error, sextor incorrecto\n",0 ,100,  2) == 0)
		{
			respuesta = 0;	//carga realizada
			buffer.isEmpty = 0;
			buffer.id = id + 1;
			list[id] = buffer;
		}
	}
	return respuesta;
}
/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		respuesta = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id)
{
	int respuesta = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order)
{
 return 0;
}
/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
	int respuesta = -1;

	if(list != NULL && length > 0)
	{
		respuesta = 0;
		for(int i = 0; i < length; i++)
		{
			imprimir(&list[i]);
		}
	}
	return respuesta;
}
/**
* \brief Imprime los datos de un empleado
* \param pElemento Puntero al producto que se busca imprimir
* \return Retorna 0 (EXITO) y -1 (ERROR)
*
*/
static void imprimir(Employee* pEmpleado)
{
	if(pEmpleado != NULL && pEmpleado->isEmpty == 0)
	{
		printf("\nID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n",
				pEmpleado->id,pEmpleado->name,pEmpleado->lastName,pEmpleado->salary, pEmpleado->sector);
	}
}

/**
 * \brief Buscar primer posicion vacia
 * \param list Array de empleados
 * \param length Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int getEmptyIndex(Employee* list, int length)
{
	int respuesta = -1;

	if(list != NULL && length > 0)
	{
		respuesta = 0;
		for(int i = 0; i < length; i++)
		{
			if(list[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificarArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(buffer.name,sizeof(buffer.name),"Ingresar nombre \n","Error, nombre incorrecto\n", 2) == 0 &&
			utn_getNombre(buffer.lastName,sizeof(buffer.lastName),"Ingresar apellido \n","Error, apellido incorrecto\n", 2) == 0 &&
			utn_getNumeroFlotante(&buffer.salary,"Ingresar salario \n","Error, salario incorrecto\n", 0 ,1000000, 2) == 0 &&
			utn_getNumero(&buffer.sector,"Ingresar sector \n","Error, sextor incorrecto\n",0 ,100,  2) == 0)
		{
			respuesta = 0;
			buffer.id = array[indice].id;
			buffer.isEmpty = 0;
			array[indice] = buffer;
		}
	}
	return respuesta;
}
int infPromedio(Employee* array, int limite, int indice)
{
	int respuesta = -1;
	int contadorId = 0;
	int totalSalario = 0;
	float promedio;

	for(int i = 0; i < limite; i++)
	{
		if(array[i].isEmpty == 1)
		{
			contadorId++;
		}
		totalSalario = array[i].salary + totalSalario;
	}

	promedio = totalSalario / contadorId;
	printf("%.2f", promedio);
	return respuesta;
}















