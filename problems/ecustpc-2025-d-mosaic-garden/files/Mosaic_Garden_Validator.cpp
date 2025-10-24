#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
 
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Mosaic Garden");
 
    inf.readLine("[a-z,0-9,_,A-Z]{1,100}", "Arbitrary string");
    inf.readEof();
}
