#include <iostream>
#include <ctime>
#include <unistd.h>
#include <fstream>

using namespace std;

string gen_randomCapital(const int len) {

    string tmp_s;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_s;

}

string gen_randomNumber(const int len) {

    string tmp_n;
    static const char alphanum[] =
        "0123456789";
    

    tmp_n.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_n += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_n;

}

string gen_randomAlphaDigit(const int len) {

    string tmp_a;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    

    tmp_a.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_a += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_a;

}

string gen_randomMail(const int len) {

    string tmp_m;
    const string alphanum[3] =
    {"com", "org", "my"};
    

    tmp_m.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_m += alphanum[rand() % 3];

    return tmp_m;

}



int main(int argc, char *argv[]) {

    string data, data_n, data_a, data_a2, data_m;

    ofstream myfile;
    myfile.open ("setB.txt");

    //generate 3 capital letters
    for (int i=0;i<1000000;i++)
    {
        data = gen_randomCapital(3) + "." + gen_randomNumber(3) + "." + gen_randomAlphaDigit(5) + "@" + gen_randomAlphaDigit(6) + "." + gen_randomMail(1);
        // data_n = gen_randomNumber(3);
        // data_a = gen_randomAlphaDigit(5);
        // data_a2 = gen_randomAlphaDigit(6);
        // data_m = gen_randomMail(1);
        cout << data << endl;
        
        myfile << data << endl;
    }

    myfile.close();

    return 0;
}