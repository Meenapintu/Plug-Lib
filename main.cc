/*
 * main.cc
 *
 * Copyright 2016 PintuLalM <PintuLalM@DESKTOP-63TR384>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include "include/list.h"

int main()
{

    list<string> ml =list<string>() ;//= list<int>();

    ml.insert("hi thee");
    ml.insert("del");
     ml.insert("hi hgf");
     ml.name("ML");

     list<string>gl = list<string>(ml);
        gl.name("GL");
     //  debug("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
       gl.remove();
       gl.remove();
       ml.remove();
    ml.~list();
       //debug("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
   /** ml.insert(4);
    ml.insert(5);
    ml.insert(2);**/
    //ml.remove("del");
    // ml.remove("del");
      ml.remove();
       ml.remove();
        ml.remove();
  gl.remove();
   // ml.display();
   // ml.display();

    gl.display();
	return 0;
}

