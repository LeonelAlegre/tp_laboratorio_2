/*
 * Empleados.h
 *
 *  Created on: 16 may. 2020
 *      Author: Leonel
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int validarOpcionCarga(int opcion, char* mensajeError);
int printEmployees(Employee* list, int length);
int getEmptyIndex(Employee* list, int length);
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int modificarArray(Employee* array,int limite, int indice);
int removeEmployee(Employee* list, int len, int id);
int infPromedio(Employee* array, int limite, int indice);
#endif /* EMPLEADOS_H_ */
