/* 
Description: This file implements a record data type to use as element of any data structure.
This will be implemented as template to be used in any data structure.

Author: Maicon de Menezes
Creation Date: 25/02/2024
Version: 0.1.0
*/

// Defination of ID_KEY type for the key of the one record it's used to get access to an record without deal with entire record data
typedef int ID_KEY;

// Defination of RECORD type, it's a struct that contains our record data
typedef struct{
  ID_KEY key;
  // Other fields
} RECORD;
