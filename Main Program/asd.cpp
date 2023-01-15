/**
* @file asd.cpp
* @author Шепталин В.С.
* @version 1.0
* @brief Описание методов классов, описание функций
* @date 12.01.2023
* @copyright ИБСТ ПГУ
*/
#include "header.h"

void error(string name, string fil){
    time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
    ofstream dump;
    dump.open(fil, ios_base::app);
    if (dump.is_open()){
        dump <<"Ошибка: "<<name;
        dump <<"Время ошибки: "<<dt;
        dump <<"Критическая ошибка"<<endl;
    }
}

uint32_t serv::srednee(long int sum, uint32_t kolvo, uint32_t sred){
    sred = sum/kolvo;
    return sred;
}

long int serv::summa(long int sum, uint32_t vect){
    sum = sum + vect;
    return sum;
}

void help(){
        cout <<"Hello i'm Vadick and this is my server"<<endl;
        cout <<"The terminal can recieve the arguments listed below folowed 1 by 1: "<<endl;
        cout <<"Here are some things you can type to the terminal: "<<endl;
        cout <<"-h : call for the help menu"<<endl;
        cout <<"-q : enter the ip addres"<<endl;
        cout <<"-w : enter the port (the Port by default is set to '33333')"<<endl;
        cout <<"-t : enter the document with users and their passwords"<<endl;
        cout <<"-d : enter the file for the errors"<<endl;
}

int serv::get_anything(string str1, string str2){
    
    string pass, imya;
    string type;
     if(str2 == "") {
        str2 = "33333";
    }
    //дамп файл с ошибками
ofstream dump;
dump.open(dump_name, ios_base::app);
    if(!dump){
        throw error_handler(string("File with dump dosent exist or corrupted!"));
    }
    //файл с паролями с юзерами
ifstream file(file_name);
        if(!file){
            type = "File with users dosent exist or corrupted!";
            error(type, dump_name);
            throw error_handler(type);
        }
        if (file.peek() == EOF){
        type = "FIle with users is empty!";
        error(type,dump_name);
        throw error_handler(type);
    }
            //получение пароля и id
        getline(file, imya, ':');
        getline(file, pass);
struct sockaddr_in {
 short sin_family;
 unsigned short sin_port;
 struct in_addr sin_addr;
 char sin_zero[8];
};
struct in_addr {
 unsigned long s_addr;
};
//инициализация сокета
int s = socket(AF_INET, SOCK_STREAM, 0);
if (s == -1) {
    type = "The socket cannot be created!\n";
    error(type, dump_name);
    throw error_handler(type);
}
else
{
    cout<<"Socket successfully created..\n";
}
unsigned int port2;
    //перевод порта в правильный вид
    try{
        port2 = stoi(str2);
    } catch (...){
        type = "Incorrect format of port!\n";
        error(type, dump_name);
        throw error_handler(type);
    }
    port2 = stoi(str2);
    //перевод ip в правильный вид
    
    try{
        char* ip_chars = new char[str1.length()];
        str1.copy(ip_chars, str1.length());
        ip_chars[str1.length()] = '\0';
    } catch (...){
        type = "incorrect format of ip!/n";
        error(type, dump_name);
        throw error_handler(type);
    }
char* ip_chars = new char[str1.length()];
str1.copy(ip_chars, str1.length());
ip_chars[str1.length()] = '\0';

sockaddr_in * self_addr = new (sockaddr_in);
self_addr->sin_family = AF_INET;
self_addr->sin_port = htons(port2);
self_addr->sin_addr.s_addr = inet_addr(ip_chars);

//бинд адресса
int b = bind(s,(const sockaddr*) self_addr,sizeof(sockaddr_in));
if(b == -1) {
    type = "The binding fuction did not reached its end\n";
        error(type, dump_name);
        throw error_handler(type);
} else{
    cout << "Binding succsesful\n";
}
listen(s, SOMAXCONN);
//соединение с клиентом
while(true) {
    sockaddr_in * client_addr = new sockaddr_in;
    socklen_t len = sizeof (sockaddr_in);
    int work_sock = accept(s, (sockaddr*)(client_addr), &len);
    if(work_sock == -1) {
        type = "The connection with client did not reached the end\n";
        error(type, dump_name);
        throw error_handler(type);
        return 0;
    }
    else {
string SALT;
string single_char;
string digest;
string name_from_client;
uint32_t kolvo;
uint32_t numb;
uint32_t vect;
long int sum;
uint32_t sred;
        char HESH[100];
        char vec[100];
        char msg[100];
        cout << "Successfull client connection!\n";
        //создание соли
        string Salt_chars[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
        srand (1);
        for (int w = 0;w<16;w++){
            single_char = Salt_chars[rand()%16];
            SALT = SALT+single_char;
        }
        char chars[SALT.length() + 1];
        SALT.copy(chars, SALT.length() + 1);
        cout<<"SALT хранящяяся на сервере: "<<chars<<endl;
        cout << "name from file: " << imya << endl;
        cout << "password from file: " << pass << endl;
        //создание хеша из соли и пароля
        string HASH = SALT+pass;
        Weak::MD5 hash;
        StringSource(HASH, true,new HashFilter(hash,new HexEncoder(new StringSink(digest))));
        cout<<"НАШ HASH: "<<digest<<endl;
        char ok[] = " OK";
        //получение id от клиента
        recv(work_sock, msg, sizeof(msg), 0);
        cout << "the username from client: " << msg << endl;
        name_from_client = msg;
        //проверка на совпадение id клиента и сервера
        if (imya == name_from_client){
            // отправка соли
            send(work_sock,&chars,sizeof(chars),0);
        }else{
           type = "The id cannot be found in base!\n";
            error(type, dump_name);
            throw error_handler(type);
            close(s);
        }
        //получение HASH от клиента
        recv(work_sock, &HESH,31,0);
        char simvol[] = "5";
        strcat(HESH, simvol);
        cout<<"HASH полученный от клиента: "<<HESH<<endl;
        //проверка на совпадение HASH на сервере и от клиента
        if (digest == HESH){
            send(work_sock,ok,sizeof(ok),0);
            cout<<"Сообщение об успехе отправлено клиенту!"<<endl;
        } else {
            type = "ERROR! The Hash is difrent!";
            error(type, dump_name);
            throw error_handler(type);
            close(s);
        }
        recv(work_sock,vec,sizeof(vec),0);
        //получение количества векторов
        recv(work_sock, &kolvo, sizeof(kolvo), 0);
        cout << "кол-во векторов: "  << kolvo << endl;
        for(uint32_t j=0; j<kolvo; j++){
            sum = 0;
            sred = 0;
            //получение размера вектора
            recv(work_sock, &numb, sizeof(numb), 0);
            cout<<"размер вектора: "<<numb<<endl;
            cout << "вектор номер " << j+1 << ':'<< endl;
            for(uint32_t i=0; i<numb; i++){
                //получение элемента вектора
                recv(work_sock, &vect, sizeof(vect), 0);
                cout << vect<<' ';
                sum = summa(sum, vect);
            }
            //создание и отправка среднего значения вектора
            sred = srednee(sum, kolvo, sred);
            send(work_sock,&sred,sizeof(sred),0);
            cout <<endl<< "среднее вектора " << sred<< endl<<endl;
        }
           //закрытие сокета
        close(s);
    }
}
//закрытие файлов
    dump.close();
    file.close();
return 0;
}