/*
 * main.cc
 *
 * Copyright 2016 PintuLalM <PintuLalM@DESKTOP-63TR384>
 */

#include "include/list.h"

int main()
{

    list<int> ml =list<int>() ;//= list<int>();
    ml.insert(2);
    ml.insert(3);
    ml.insert(4);

    list<int>gl = list<int>(ml);
    gl.display();
    gl.remove();
    gl.remove();
    ml.remove();
    ml.~list();
    gl.remove();
    gl.display();
    return 0;
}

