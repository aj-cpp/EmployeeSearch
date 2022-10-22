#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr,
                                     int table_size,
                                     char *phone_number)
{
  const PtrToConstEmployee endPtr = ptr + table_size;

  for (; ptr < endPtr; ptr++)
  {
    if (strcmp(ptr->phone, phone_number) == 0)
      return (PtrToEmployee) ptr;
  }

  return NULL;
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr,
                                     int table_size,
                                     double salary)
{
  const PtrToConstEmployee endPtr = ptr + table_size;

  for (; ptr < endPtr; ptr++)
  {
    if (ptr->salary == salary)
      return (PtrToEmployee) ptr;
  }

  return NULL;
}