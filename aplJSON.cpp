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

#include "aplJSON.h"

// #include <iostream>
#include <string>

using namespace std;

JSON::JSON()
{
  ll.push(string("{"), string(""));
  ll.push(string("}"), string(""));
}
JSON::JSON(size_t sz)
{
  ll.push(string("{"), string(""));
  for (int i = 0; i < sz; i++) {
    ll.push(string(""), string(""));
  }
  ll.push(string("}"), string(""));
}

size_t JSON::add(string key, string value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = string("\"")+string(value)+string("\",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, string newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = string("\"")+newValue+string("\",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, string newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(string("\"")+newValues[i]+string("\","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

size_t JSON::add(string key, char * value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = string(value)+string(",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, char * newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = newValue+string(",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, char * newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(string(newValues[i])+string(","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

size_t JSON::add(string key, int value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(value)+string(",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, int newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(newValue)+string(",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, int newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(to_string(newValues[i])+string(","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

size_t JSON::add(string key, double value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(value)+string(",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, double newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(newValue)+string(",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, double newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(to_string(newValues[i])+string(","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

size_t JSON::add(string key, float value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(value)+string(",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, float newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(newValue)+string(",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, float newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(to_string(newValues[i])+string(","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

size_t JSON::add(string key, bool value)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(value)+string(",");

  ll.insert(formattedKey, formattedValue);
  return ll.length();
}
int JSON::replace(string key, bool newValue)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValue = to_string(newValue)+string(",");
  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValue, loc);
  }

  return loc;
}
int JSON::replaceSeq(size_t startIndex, size_t length, bool newValues[])
{
  if (startIndex + length + 2 > ll.length()) {
    return -1;
  }
  Node * cur = ll.peek(0);
  int i;
  // technically, the 0th place in the list is the { "key", so the programmer
  // should only have to concern himself with the actual elements he's added
  for (i = -1; i < (int) startIndex; i++) {
    cur = cur->next;
  }
  for (i = 0; i < (int) length; i++) {
    cur->value.assign(to_string(newValues[i])+string(","));
    cur = cur->next;
  }
  return (int) i+startIndex;
}

// size_t JSON::add(string keys[], string values[], size_t length)
// {
//   ll.insertManyBeforeEnd(keys, values, length);
//   return ll.size();
// }

size_t JSON::add(string key, string values[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append("\""+values[i]+"\",");
  }
  formattedValues.append("\""+values[i]+"\""+"],");
  ll.insert(formattedKey, formattedValues);
  return ll.length();
}
int JSON::replace(string key, string newValues[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append("\""+newValues[i]+"\",");
  }
  formattedValues.append("\""+newValues[i]+"\""+"],");

  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValues, loc);
  }

  return loc;
}

size_t JSON::add(string key, char * values[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(string(values[i])+",");
  }
  formattedValues.append(string(values[i])+"],");
  ll.insert(formattedKey, formattedValues);
  return ll.length();
}
int JSON::replace(string key, char * newValues[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(string(newValues[i])+",");
  }
  formattedValues.append(string(newValues[i])+"],");

  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValues, loc);
  }

  return loc;
}

size_t JSON::add(string key, int values[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(values[i])+",");
  }
  formattedValues.append(to_string(values[i])+"],");
  ll.insert(formattedKey, formattedValues);
  return ll.length();
}
int JSON::replace(string key, int newValues[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(newValues[i])+",");
  }
  formattedValues.append(to_string(newValues[i])+"],");

  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValues, loc);
  }

  return loc;
}

size_t JSON::add(string key, double values[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(values[i])+",");
  }
  formattedValues.append(to_string(values[i])+"],");
  ll.insert(formattedKey, formattedValues);
  return ll.length();
}
int JSON::replace(string key, double newValues[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(newValues[i])+",");
  }
  formattedValues.append(to_string(newValues[i])+"],");

  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValues, loc);
  }

  return loc;
}

size_t JSON::add(string key, float values[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(values[i])+",");
  }
  formattedValues.append(to_string(values[i])+"],");
  ll.insert(formattedKey, formattedValues);
  return ll.length();
}
int JSON::replace(string key, float newValues[], size_t length)
{
  string formattedKey = string("\"")+key+string("\":");
  string formattedValues = "[";
  size_t i;
  for (i = 0; i < length - 1; i++) {
    formattedValues.append(to_string(newValues[i])+",");
  }
  formattedValues.append(to_string(newValues[i])+"],");

  int loc = ll.find(formattedKey);
  if (loc < 0) {
    // could not find key
  } else {
    ll.writeNode(formattedKey, formattedValues, loc);
  }

  return loc;
}

size_t JSON::remove(string key)
{
  string formattedKey = string("\"")+key+string("\":");
  size_t index = ll.find(formattedKey);
  ll.remove(index);
  return ll.length();
}

/**
Extremely time-inefficient removal technique
*/

size_t JSON::remove(string keys[], size_t length)
{
  size_t i;
  for(i = 0; i < length - 1; i++) {
    JSON::remove(keys[i]);
  }
  return JSON::remove(keys[i]);
}

char * JSON::stringify()
{
  string * msg = new string;
  Node * tmp = ll.peek(0);
  while (tmp != NULL) {
    // this logic *might* be necessary if node.js cannot handle the extra
    // comma in a list before the terminating struct.
    // Assuming this isn't necessary, it will soon be deleted.
    // if ((tmp->key.compare("{") == 0 || tmp->key.compare("[") == 0) && tmp->value.compare("") == 0) {
    //
    // } else {
    //
    // }
    // cout << "key: " << tmp->key << " value: " << tmp->value << "\n";
    msg->append(tmp->key);
    msg->append(tmp->value);
    tmp = tmp->next;
  }
  return (char*) msg->c_str();
}
