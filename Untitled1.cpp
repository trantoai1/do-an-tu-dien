#include <iostream>
#include<io.h>
using namespace std;

int main()
{
    char esc_char = 27; // the decimal code for escape character is 27
cout << esc_char << "[1m" << "Hello Bold!" << esc_char << "[0m" << endl;
}
