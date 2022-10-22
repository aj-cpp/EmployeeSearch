#include <string.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr,
                                         int tableSize,
                                         const void *targetPtr,
                                         int (*functionPtr)(const void *, PtrToConstEmployee))
{
  PtrToConstEmployee endPtr = ptr + tableSize;

  for (; ptr < endPtr; ptr++)
    if ((*functionPtr)(targetPtr, ptr) == 0)
      return (PtrToEmployee) ptr;

    return NULL;
}

static int compareEmployeePhone(const void *targetPtr,
                               PtrToConstEmployee tableValuePtr)
{
  return strcmp((char *) targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void *targetPtr,
                                 PtrToConstEmployee tableValuePtr)
{
  return * (double *) targetPtr != tableValuePtr->salary; 
}


PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr,
                                   int size,
                                   char *name)
{
  return searchEmployeeTable(ptr, size, name, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr,
                                     int size,
                                     long number)
{
  return searchEmployeeTable(ptr, size, &number, compareEmployeeSalary);
}