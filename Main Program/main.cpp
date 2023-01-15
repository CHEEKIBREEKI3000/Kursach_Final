/**
* @file main.h
* @author Шепталин В.С.
* @version 1.0
* @brief Пользователский интерфейс и выполнение проги
* @date 12.01.2023
* @copyright ИБСТ ПГУ
*/
#include "header.h"

int main(int argc, char *argv[]) 
{
string str1;
string str2;
    //создаём элемент класса
    serv proceed;
    //если нет аргументов
    if (argc == 1){
        help();
        return 0;
    }
    int opt;  
    while ((opt = getopt(argc, argv, "hq:w:t:d:"))!= -1){
        switch(opt){
            //help case
            case 'h':
            help();
            return 0;
            
            //ip case
            case 'q':
                str1 = argv[2];
            break;
            
            //port case
            case 'w':
                str2 = string(optarg);
            break;
            
            //pass and id case
            case 't':
                proceed.file_name = string(optarg);
            break;
            
            //dump case
            case 'd':
                proceed.dump_name = string(optarg);
            break;
            
            //unknown case
            case '?':
            cout<<"Параметр не задан или не существует!"<<endl;
            return 0;
        };
    };
    proceed.get_anything(str1,str2);
    return 0;
};