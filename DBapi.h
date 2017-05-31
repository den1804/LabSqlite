#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName);
void sql_statement(char *sql);
void add_user(int id, char *name, char *surname, char *patronymic, char *date_of_birth,char *address);
void add_book_from_user(int id_user, int id_book, char *date);
void return_book_from_user(int id_user, int id_book, char *date);
void delete_user(int id);
void find_all_book_from_user(int id);
void history(int id);

