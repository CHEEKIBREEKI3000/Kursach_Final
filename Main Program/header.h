/**
* @file header.h
* @author Шепталин В.С.
* @version 1.0
* @brief Описание классов, подключение библиотек и переменных
* @date 12.01.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <sstream>
#include <cryptopp/files.h>
#include <cstdlib>
#include <ctime>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/cryptlib.h>
#include <fstream>

using namespace CryptoPP;
using namespace std;
/// @brief Класс в котором находится обмен данным с клиентом и совершение подсчётов
class serv{
public:
    /**
     * @brief передача и обработка информации между сервером и клиентом
     * @param ip айпи адрес по которому будет устанавливаться соединение с клиентом
     * @param port порт по которому будет устанавливаться соединение с клиентом
     * @details
     * <p> сначала открываем файлы с юзерами и дамп файл для записи в него ошибок
     * @code
     * ofstream dump;
     * dump.open(dump_name, ios_base::app);
     * 
     * ifstream file(file_name);
     * @endcode
     * далее мы получаем пароль и пользователя из файла 
     * @code
     * getline(file, imya, ':');
     * getline(file, pass);
     * @endcode
     * Инициализаруем сокет
     * @code
     * int s = socket(AF_INET, SOCK_STREAM, 0);
     * @endcode
     * Далее создаём структуру с введённым адресом и портом
     * @code
     * sockaddr_in * self_addr = new (sockaddr_in);
     * self_addr->sin_family = AF_INET;
     * self_addr->sin_port = htons(port2);
     * self_addr->sin_addr.s_addr = inet_addr(ip_chars);
     * @endcode
     * Производим бинд адреса 
     * @code
     * int b = bind(s,(const sockaddr*) self_addr,sizeof(sockaddr_in));
     * @endcode
     * Производим соединение с клиентом
     * @code
     * sockaddr_in * client_addr = new sockaddr_in;
     * socklen_t len = sizeof (sockaddr_in);
     * int work_sock = accept(s, (sockaddr*)(client_addr), &len);
     * @endcode
     * Если соединение прошло успешно, производится обмен данными и их обработка
     * Для начала создаётся HASH, из пароля и соли хранящихся на сервере
     * @code
     * string HASH = SALT+pass;
     * Weak::MD5 hash;
     * StringSource(HASH, true,new HashFilter(hash,new HexEncoder(new StringSink(digest))));
     * @endcode
     * Далее сервер принимает от клиента имя и сравнивает его с тем, которое хранится в файле
     * Если всё прошло успешно, сервер отправляет соль и ожидает сформированный HASH от клиента
     * Далее сервер сравнивает HASH который хранится на сервере, и HASH который отправил клиент
     * В случае успеха, сервер отправляет сообщение об успехе и переходит в режим принятия векторов и их характеристик, а так же их последующей обработки
     * @code
     * for(uint32_t j=0; j<kolvo; j++){
     *       sum = 0;
     *       sred = 0;
     *       //получение размера вектора
     *       recv(work_sock, &numb, sizeof(numb), 0);
     *       cout<<"размер вектора: "<<numb<<endl;
     *       cout << "вектор номер " << j+1 << ':'<< endl;
     *       for(uint32_t i=0; i<numb; i++){
     *           //получение элемента вектора
     *           recv(work_sock, &vect, sizeof(vect), 0);
     *           cout << vect<<' ';
     *           sum = summa(sum, vect);
     *       }
     *       //создание и отправка среднего значения вектора
     *       sred = srednee(sum, kolvo, sred);
     *       send(work_sock,&sred,sizeof(sred),0);
     *       cout <<endl<< "среднее вектора " << sred<< endl<<endl;
     * @endcode
     * После окончания обмена данными с клиентом, сервер завершат свою работу, закрывает сокет и закрывает файлы с данными
     * @code
     * close(s);
     * 
     * dump.close();
     * file.close();
     * @endcode
     *</p>
     * @return 0
     */
    int get_anything(string ip, string port);
    /**
     * @brief вычисление среднего арифметического по вектору который передаёт клиент
     * @param sum сумма векторов
     * @param sred среднее арифметическое векторов
     * @param kolvo размер вектора передаваемого клиентом
     * @details
     * <p> Происходит вычисление среднего арфметического вектора, посредством деления суммы элементов вектора на размер самого вектора
     * @code
     * sred = sum/kolvo;
     * @endcode
     * </p>
     * @return среднее квадратическое вектора который передаёт клиент
     */
    uint32_t srednee(long int sum, uint32_t sred, uint32_t kolvo);
    /**
     * @brief вычисление суммы элеиентов вектора для последующего вычисления среднего арифметического значения вектора
     * @param sum сумма векторов передаваемых клиентом
     * @param vect вектор который передаёт клиент
     * details
     * <p> Происходит вычисление суммы элементов вектора. для последующего составления среднего арифметического значения вектора
     * Происходит суумирование с помощью последовательного сложения каждого элемента вектора, и запись данной суммы в отдельную переменную
     * @code
     * sum = sum + vect;
     * @endcode
     * @return сумма элементов вектора
     */
    long int summa(long int sum, uint32_t vect);
    //переменная в которой хранится название файла с пользователями, название файла вводит пользователь
    string file_name;
    //переменная в которой хранится название файла в котором будет хранится информация об ошибках возникших в ходе работы сервера, название файла вводит пользователь
    string dump_name;
    //переменные в которых хранится ip адресс и порт сервера для соединения с клиентом
    string ip, port;
};

/**
 * @brief Вывод справки по программе 
 */
void help();
/**
 * @brief Определение ошибки и запись этой ошибки в файл
 * @param name название ошибки, которая возникла в ходе работы сервера
 * @param fil файл в который будет записываться информация о возникшей ошибке
 */
void error(string name, string fil);
///@brief Класс для обработки ошибок возникающих при раоте сервера
class error_handler:
    public invalid_argument
    {
public:
    explicit error_handler (const string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit error_handler (const char* what_arg):
        std::invalid_argument(what_arg) {}
};