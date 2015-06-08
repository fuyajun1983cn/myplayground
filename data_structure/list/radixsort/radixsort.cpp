#include <iostream>

#define BINSORT_TEST 1

#include "../list3.h"

//基数为10
inline int GeWei(int& x) { return x%10; }
inline int ShiWei(int& x) { return x/10%10; }
inline int BaiWei(int& x) { return x/100; }
    
int main(int argc, const char *argv[])
{
    Chain<int> X;
    int numbers[] = {
        216, 521, 425, 116, 91, 515, 124, 34, 96, 24};

    for (int i = 0; i < 10; i++)
        X.Insert(0, numbers[i]);
    std::cout<<"X is "<<X<<std::endl;
    X.BinSort(9, GeWei);
    std::cout<<"after BinSort, X is "<<X<<std::endl;
    X.BinSort(9, ShiWei);
    std::cout<<"after BinSort, X is "<<X<<std::endl;
    X.BinSort(9, BaiWei);
    std::cout<<"after BinSort, X is "<<X<<std::endl;
    return 0;
}


