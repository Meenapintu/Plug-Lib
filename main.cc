/*
 * main.cc
 *
 * Copyright 2016 PintuLalM <PintuLalM@DESKTOP-63TR384>
 */

#include <iostream>
#include "include/List.h"
using namespace std;
int main()
{

    List<int> l = List<int>();
    l.insert(l.begin(),5);
    cout<<l.getsize()<<endl;
    return 0;
}

