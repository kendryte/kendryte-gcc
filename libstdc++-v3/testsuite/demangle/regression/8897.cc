// 2003-02-26  Martin v. Loewis  <martin@v.loewis.de>

// Copyright (C) 2003 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// IA 64 C++ ABI - 5.1 External Names (a.k.a. Mangling)

#include <testsuite_hooks.h>

// c++/8897
int main()
{
  using namespace __gnu_test;

  /*
    template<typename T1>
      struct A 
      {
        template<typename T2>
	  operator T2();
      };
    
    A<float> a;
    (int)a;		<-- that function.
  */
  /*  
      Using "operator int()" is ambigious because that
      could be either:
    
      operator int();
      
      or
      
      template<typename T>
      operator T();      
      with T = int.

      - Carlo Wood
  */
  // cplus-dem FAIL  
  // icc FAIL
  // new __cxa_demangle FAIL
  verify_demangle("_ZN1AIfEcvT_IiEEv", "A<float>::operator int<int>()");

  return 0;
}
