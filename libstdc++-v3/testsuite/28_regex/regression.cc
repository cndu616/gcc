// { dg-options "-std=gnu++11" }

//
// Copyright (C) 2015-2016 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <testsuite_hooks.h>
#include <testsuite_regex.h>

using namespace __gnu_test;
using namespace std;

// PR libstdc++/67362
void
test01()
{
  bool test __attribute__((unused)) = true;

  regex re("((.)", regex_constants::basic);
}

void
test02()
{
  bool test __attribute__((unused)) = true;

  std::string re_str
    {
      "/abcd" "\n"
      "/aecf" "\n"
      "/ghci"
    };
  auto rx = std::regex(re_str, std::regex_constants::grep | std::regex_constants::icase);
  VERIFY(std::regex_search("/abcd", rx));
}

// PR libstdc++/78236
void
test06()
{
  char const s[] = "afoo";
  std::basic_regex<char> r("(f+)");
  {
    std::cregex_iterator i(s, s+sizeof(s), r);
    std::cregex_iterator j(s, s+sizeof(s), r);
    VERIFY(i == j);
  }
  // The iterator manipulation code must be repeated in the same scope
  // to expose the undefined read during the execution of the ==
  // operator (stack location reuse)
  {
    std::cregex_iterator i(s, s+sizeof(s), r);
    std::cregex_iterator j;
    VERIFY(!(i == j));
  }
}

int
main()
{
  test01();
  test02();
  test06();
  return 0;
}

