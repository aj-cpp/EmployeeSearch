// Compile using the following command:
// gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
  // defined in employeeSearchOne.c
  PtrToEmployee searchEmployeeByNumber(const Employee table[], 
                                       int sizeTable, 
                                       long numberToFind);

  PtrToEmployee searchEmployeeByName(const Employee table[], 
                                       int sizeTable, 
                                       char *nameToFind);

  PtrToEmployee searchEmployeeByPhone(const Employee table[],
                                      int table_size,
                                      char *phone_number);

  PtrToEmployee searchEmployeeBySalary(const Employee table[],
                                       int table_size,
                                       double salary);

  // defined in employeeTable.c
  extern Employee EmployeeTable[];
  extern const int EmployeeTableEntries;

  PtrToEmployee matchPtr; // declaration
  matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

  // Example not found
  if (matchPtr != NULL)
    printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee ID is NOT found in the record\n");

  // Example found
  matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
  if (matchPtr != NULL)
    printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee Tony Bobcat is NOT found in the record\n");

  // TEST: searchEmployeeByPhone
  // Not found
  matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-123-1234");
  if (matchPtr != NULL)
  {
    printf("ERROR! Expected: NULL, but found a record. Line: %d\n", __LINE__);
    return EXIT_FAILURE;
  }
  printf("Searching: 123-123-1234 -> Employee not found.\n");

  // Found
  matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
  if (matchPtr == NULL)
  {
    printf("ERROR! Expected search 714-555-2749, but found NULL. Line: %d\n", __LINE__);
    return EXIT_FAILURE;
  }
  printf("Searching: 714-555-2749 -> Found in record %d\n", matchPtr - EmployeeTable);

  // TEST: searchEmployeeBySalary
  // Not found
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 1.23);
  if (matchPtr != NULL)
  {
    printf("ERROR! Expected: NULL, but found a record. Line: %d\n", __LINE__);
    return EXIT_FAILURE;
  }
  printf("Searching: 0 -> Employee not found.\n");

  // Found
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
  if (matchPtr == NULL)
  {
    printf("ERROR! Expected search 8.78, but found NULL. Line: %d\n", __LINE__);
    return EXIT_FAILURE;
  }
  printf("Searching: 8.78 -> Found in record %d\n", matchPtr - EmployeeTable);


  return EXIT_SUCCESS;
}