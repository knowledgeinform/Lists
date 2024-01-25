///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 The Johns Hopkins University Applied Physics Laboratory LLC (JHU/APL).  All Rights Reserved.
//
// This material may be only be used, modified, or reproduced by or for the U.S. Government pursuant to the license
// rights granted under the clauses at DFARS 252.227-7013/7014 or FAR 52.227-14. For any other permission, please
// contact the Office of Technology Transfer at JHU/APL: Telephone: 443-778-2792, Internet: www.jhuapl.edu/ott
//
// NO WARRANTY, NO LIABILITY. THIS MATERIAL IS PROVIDED "AS IS." JHU/APL MAKES NO REPRESENTATION OR WARRANTY WITH
// RESPECT TO THE PERFORMANCE OF THE MATERIALS, INCLUDING THEIR SAFETY, EFFECTIVENESS, OR COMMERCIAL VIABILITY, AND
// DISCLAIMS ALL WARRANTIES IN THE MATERIAL, WHETHER EXPRESS OR IMPLIED, INCLUDING (BUT NOT LIMITED TO) ANY AND ALL
// IMPLIED WARRANTIES OF PERFORMANCE, MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
// INTELLECTUAL PROPERTY OR OTHER THIRD PARTY RIGHTS. ANY USER OF THE MATERIAL ASSUMES THE ENTIRE RISK AND LIABILITY
// FOR USING THE MATERIAL. IN NO EVENT SHALL JHU/APL BE LIABLE TO ANY USER OF THE MATERIAL FOR ANY ACTUAL, INDIRECT,
// CONSEQUENTIAL, SPECIAL OR OTHER DAMAGES ARISING FROM THE USE OF, OR INABILITY TO USE, THE MATERIAL, INCLUDING,
// BUT NOT LIMITED TO, ANY DAMAGES FOR LOST PROFITS.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <catch2/catch.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "aplJSON.h"

using namespace std;

TEST_CASE( "Blank object JSON", "[aplJSON]") {
  JSON j(2);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{}") == 0 );
}

TEST_CASE( "JSON single key and string value", "[aplJSON]") {
  JSON j;
  j.add(string("key"), string("value"));
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":\"value\",}") == 0 );
}

TEST_CASE( "JSON single key and int value", "[aplJSON]") {
  JSON j;
  j.add(string("key"), 1);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":1,}") == 0 );
}

TEST_CASE( "Useful alternative for int stringify", "[aplJSON]") {
  JSON j;
  int test = 2;
  char * str = new char;
  sprintf(str, "%d", test);

  j.add(string("key"),str);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":2,}") == 0 );
}

TEST_CASE( "JSON single key and double value", "[aplJSON]") {
  JSON j;
  // note that digits beyond 9 are rounded
  j.add(string("key"), 3.141593);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":3.141593,}") == 0 );
}

TEST_CASE( "JSON single key and float value", "[aplJSON]") {
  JSON j;
  // note that digits beyond 9 are rounded
  j.add(string("key"), (float) 3.141592654);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":3.141593,}") == 0 );
}

TEST_CASE( "JSON single key and bool value", "[aplJSON]") {
  JSON j;
  // note that bools are converted to 0/1
  j.add(string("key"), true);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":1,}") == 0 );
}

TEST_CASE( "JSON single key and array string value", "[aplJSON]") {
  JSON j;
  string arrVals[] = {"today", "is", "a", "good", "day"};
  j.add(string("key"), arrVals, 5);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[\"today\",\"is\",\"a\",\"good\",\"day\"],}") == 0 );
}

TEST_CASE( "JSON single key and array int value", "[aplJSON]") {
  JSON j;
  int arrVals[] = {1,2,3,4,5,6};
  j.add(string("key"), arrVals, 5);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[1,2,3,4,5],}") == 0 );
}

TEST_CASE( "JSON single key and array double value", "[aplJSON]") {
  JSON j;
  double arrVals[] = {1.123,2.123,3.123,4.123,5.123,6.123};
  j.add(string("key"), arrVals, 5);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[1.123000,2.123000,3.123000,4.123000,5.123000],}") == 0 );
}

TEST_CASE( "JSON single key and array float value", "[aplJSON]") {
  JSON j;
  float arrVals[] = {1.123,2.123,3.123,4.123,5.123,6.123};
  j.add(string("key"), arrVals, 5);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[1.123000,2.123000,3.123000,4.123000,5.123000],}") == 0 );
}

TEST_CASE( "Nested JSON basic", "[aplJSON]") {
  JSON j, j_inner;
  j.add(string("key"),j_inner.stringify());
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":{},}") == 0 );
}

TEST_CASE( "Array of nested JSONs", "[aplJSON]") {
  JSON j, j_inner1, j_inner2;
  char * charArr[] = {j_inner1.stringify(), j_inner2.stringify()};
  j.add(string("key"),charArr,2);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[{},{}],}") == 0 );
}

TEST_CASE( "JSON multiple keys and string values", "[aplJSON]") {
  JSON j;
  j.add(string("key"), string("value"));
  j.add(string("key2"), string("value2"));
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key2\":\"value2\",\"key\":\"value\",}") == 0 );
}

TEST_CASE( "JSON remove key", "[aplJSON]") {
  JSON j;
  j.add(string("key"), string("value"));
  j.add(string("key2"), string("value2"));
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key2\":\"value2\",\"key\":\"value\",}") == 0 );
  size_t newsize = j.remove(string("key"));
  REQUIRE( newsize == 3);
  res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key2\":\"value2\",}") == 0 );
}

TEST_CASE( "JSON replace single key and string value", "[aplJSON]") {
  JSON j;
  j.add(string("key"), string("value"));
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":\"value\",}") == 0 );
  j.replace(string("key"), string("replacement value"));
  res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":\"replacement value\",}") == 0 );
}

TEST_CASE( "JSON replace single key and string[] values", "[aplJSON]") {
  JSON j;
  string strArr[] = {"string1", "string2"};
  j.add(string("key"), strArr, 2);
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[\"string1\",\"string2\"],}") == 0 );
  string strArr2[] = {"hello", "world"};
  j.replace(string("key"), strArr2, 2);
  res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":[\"hello\",\"world\"],}") == 0 );
}

TEST_CASE( "JSON seq replace", "[aplJSON]") {
  JSON j;
  // add in reverse order so that replacement happens as anticipated
  j.add(string("key2"), string("value2"));
  j.add(string("key"), string("value"));
  char * res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":\"value\",\"key2\":\"value2\",}") == 0 );
  string strArr[] = {"hello","world"};
  j.replaceSeq(0,2,strArr);
  res = j.stringify();
  cout << res << "\n";
  REQUIRE( strcmp(res, "{\"key\":\"hello\",\"key2\":\"world\",}") == 0 );
}
