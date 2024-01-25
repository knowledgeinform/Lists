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

#include "linked_list.h"

using namespace std;

TEST_CASE( "LinkedList ll(2) results in a size of 2", "[linked_list]") {
  LinkedList ll(2);
  REQUIRE( ll.length() == 2 );
}

TEST_CASE( "LinkedList writeNode Key: \"{\" value: \"\"", "[linked_list]") {
  LinkedList ll(2);
  string key = "{";
  string value = "";
  ll.writeNode(key, value, 0);
  // cout << "tests: Line: " << __LINE__ << "\n";
  Node * head = ll.peek(0);
  // cout << "tests: Line: " << __LINE__ << "\n";
  // cout << "tests: key: " << head->key << "\n";
  REQUIRE( head->key.compare("{") == 0 );
  // cout << "tests: Line: " << __LINE__ << "\n";
  REQUIRE( head->value.compare("") == 0 );
}

TEST_CASE( "LinkedList push", "[linked_list]") {
  LinkedList ll;
  ll.push(string("key"), string("value"));
  REQUIRE( ll.length() == 1 );
  REQUIRE( ll.peek()->key.compare("key") == 0 );
  REQUIRE( ll.peek()->value.compare("value") == 0 );
}

TEST_CASE( "LinkedList writeNodes (5 nodes)", "[linked_list]") {
  LinkedList ll(7);
  string keys[] = {"{",
    "p",
    "i",
    "d",
    "}"};
  string values[] = {"",
    "1",
    "2",
    "3",
    ""};
  // cout << "key size: " << keys[1] << "\n";
  size_t startIndex = 1;
  size_t length = 5;
  ll.writeNodes(keys,values,startIndex,length);
  REQUIRE( ll.length() == 7 );
  int i;
  for (i = startIndex; i < length; i++) {
    // cout << "index: " << i << " key: " << ll.peek(i)->key << " keys[i-1]: " << keys[i - 1] << "\n";
    // cout << "index: " << i << " value: " << ll.peek(i)->value << " values[i-1]: " << values[i - 1] << "\n";
    REQUIRE( ll.peek(i)->key.compare(keys[i - 1]) == 0 );
    REQUIRE( ll.peek(i)->value.compare(values[i - 1]) == 0 );
  }
}

TEST_CASE( "LinkedList find d", "[linked_list]") {
  LinkedList ll(7);
  string keys[] = {"{",
    "p",
    "i",
    "d",
    "}"};
  string values[] = {"",
    "1",
    "2",
    "3",
    ""};
  // cout << "key size: " << keys[1] << "\n";
  size_t startIndex = 1;
  size_t length = 5;
  ll.writeNodes(keys,values,startIndex,length);
  REQUIRE( ll.length() == 7 );
  REQUIRE( ll.find("d") == 4 );
}

TEST_CASE( "LinkedList remove d", "[linked_list]") {
  LinkedList ll(7);
  string keys[] = {"{",
    "p",
    "i",
    "d",
    "}"};
  string values[] = {"",
    "1",
    "2",
    "3",
    ""};
  // cout << "key size: " << keys[1] << "\n";
  size_t startIndex = 1;
  size_t length = 5;
  ll.writeNodes(keys,values,startIndex,5);
  REQUIRE( ll.length() == 7 );
  size_t rIndex = ll.find("d");
  REQUIRE( ll.remove(rIndex) == 6 );
  size_t i;
  length--;
  for (i = startIndex; i < length+1; i++) {

    if (i < rIndex) {
      // cout << "index: " << i << " key: " << ll.peek(i)->key << " keys[i-1]: " << keys[i - 1] << "\n";
      // cout << "index: " << i << " value: " << ll.peek(i)->value << " values[i-1]: " << values[i - 1] << "\n";
      REQUIRE( ll.peek(i)->key.compare(keys[i - 1]) == 0 );
      REQUIRE( ll.peek(i)->value.compare(values[i - 1]) == 0 );
    } else {
      // cout << "index: " << i << " key: " << ll.peek(i)->key << " keys[i-1]: " << keys[i] << "\n";
      // cout << "index: " << i << " value: " << ll.peek(i)->value << " values[i-1]: " << values[i] << "\n";
      REQUIRE( ll.peek(i)->key.compare(keys[i]) == 0 );
      REQUIRE( ll.peek(i)->value.compare(values[i]) == 0 );
    }

  }
}

TEST_CASE( "LinkedList insert PV 2", "[linked_list]") {
  LinkedList ll(7);
  string keys[] = {"{",
    "p",
    "i",
    "d",
    "}"};
  string values[] = {"",
    "1",
    "2",
    "3",
    ""};
  // cout << "key size: " << keys[1] << "\n";
  size_t startIndex = 1;
  size_t length = 5;
  ll.writeNodes(keys,values,startIndex,length);
  REQUIRE( ll.length() == 7 );
  REQUIRE( ll.insert(string("PV"), string("2")) == 8);
  REQUIRE( ll.peek(1)->key.compare("PV") == 0 );
  REQUIRE( ll.peek(1)->value.compare("2") == 0 );
}
