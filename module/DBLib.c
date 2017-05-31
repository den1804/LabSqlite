#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void sql_statement(char *sql)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   rc = sqlite3_open("lab3DB.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   const char* data = "Callback function called";
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
} 
void add_user(int id, char *name, char *surname, char *patronymic, char *date_of_birth,char *address)
{
   char sql[512];
   snprintf(sql, sizeof(sql),
	"INSERT INTO users (id,name,surname,patronymic,date_of_birth,address) VALUES(%d,'%s','%s','%s','%s','%s')", id,name,surname,patronymic,date_of_birth,address);
   sql_statement(sql);	
}
void add_book_from_user(int id_user, int id_book, char *date)
{
   char sql[512];
   snprintf(sql, sizeof(sql),
	"INSERT INTO book_issued (id_user,id_book,date_of_issue,date_completion) VALUES(%d,%d,'%s','%s')",id_user,id_book,date,"");
   sql_statement(sql);
   //memset(sql,"",sizeof(sql));
}
void return_book_from_user(int id_user, int id_book, char *date)
{
   char sql[512];
   snprintf(sql, sizeof(sql),"UPDATE book_issued set date_completion='%s' WHERE id_user=%d AND id_book=%d",date,id_user,id_book);
   sql_statement(sql);
   //memset(sql,"",sizeof(sql));
}
void delete_user(int id)
{
   char sql[512];
   snprintf(sql, sizeof(sql),
	"DELETE from users WHERE id=%d",id);
   sql_statement(sql);
}
void find_all_book_from_user(int id)
{
   char sql[512];
   snprintf(sql, sizeof(sql),
	"SELECT * from book_issued,books WHERE id_user=%d AND books.id=book_issued.id_book AND date_completion=''",id);
   sql_statement(sql);
}
void history(int id)
{
   char sql[512];
   snprintf(sql, sizeof(sql),
	"SELECT * from book_issued,books WHERE id_user=%d AND books.id=book_issued.id_book",id);
   sql_statement(sql);	
}

