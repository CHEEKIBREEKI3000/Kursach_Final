#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/C++Projects/lab_5_4/header.h"
#include "/home/stud/C++Projects/C++Projects/lab_5_4/asd.cpp"
using namespace std;

struct things_fixture{
    serv * pointer;
    things_fixture(){
        pointer = new serv();
    }
    ~things_fixture(){
        delete pointer;
    }
};

SUITE(PROVERKI)
{
    TEST_FIXTURE(things_fixture, Wrong_IP){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/log.txt";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        CHECK_THROW(pointer->get_anything("22222222" , "33333"),error_handler);
    }
    TEST_FIXTURE(things_fixture, Wrong_PORT){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/log.txt";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        CHECK_THROW(pointer->get_anything("127.0.0.1" , "werk2"),error_handler);
    }
    TEST_FIXTURE(things_fixture, Wrong_LOGFILE){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/CHTOTO.txt";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        CHECK_THROW(pointer->get_anything("127.0.0.1" , "33333"),error_handler);
    }
    TEST_FIXTURE(things_fixture, Empty_LOGFILE){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/CHTOTO2.txt";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        CHECK_THROW(pointer->get_anything("127.0.0.1" , "33333"),error_handler);
}
    TEST_FIXTURE(things_fixture, correct_work){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/log.txt";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        pointer->get_anything("127.0.0.1" , "33333");
        CHECK(true);
    }
    TEST_FIXTURE(things_fixture, NO_DUMPFILE){
        pointer->file_name = "/home/stud/C++Projects/C++Projects/lab_5_4/log.txt";
        pointer->dump_name = "";
        CHECK_THROW(pointer->get_anything("127.0.0.1" , "33333"),error_handler);
    }
    TEST_FIXTURE(things_fixture, NO_LOGFILE){
        pointer->file_name = " ";
        pointer->dump_name = "/home/stud/C++Projects/C++Projects/lab_5_4/dump.txt";
        CHECK_THROW(pointer->get_anything("127.0.0.1" , "33333"),error_handler);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}