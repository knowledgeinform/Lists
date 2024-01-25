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

#ifndef APL_JSON_H
#define APL_JSON_H

#include "Lists.h"
// #include <iostream>
// #include <string>

using namespace std;

class JSON
{
private:
  LinkedList ll;
public:
  JSON();
  JSON(size_t);
  size_t add(string, string);
  size_t add(string, char*);
  size_t add(string, int);
  size_t add(string, double);
  size_t add(string, float);
  size_t add(string, bool);
  size_t add(string, string[], size_t);
  size_t add(string, char*[], size_t);
  size_t add(string, int[], size_t);
  size_t add(string, double[], size_t);
  size_t add(string, float[], size_t);
  // size_t add(string[], string[]);

  int replace(string, string);
  int replace(string, char*);
  int replace(string, int);
  int replace(string, double);
  int replace(string, float);
  int replace(string, bool);
  int replace(string, string[], size_t);
  int replace(string, char*[], size_t);
  int replace(string, int[], size_t);
  int replace(string, double[], size_t);
  int replace(string, float[], size_t);

  int replaceSeq(size_t, size_t, string[]);
  int replaceSeq(size_t, size_t, char*[]);
  int replaceSeq(size_t, size_t, int[]);
  int replaceSeq(size_t, size_t, double[]);
  int replaceSeq(size_t, size_t, float[]);
  int replaceSeq(size_t, size_t, bool[]);
  // int replaceSeq(size_t, size_t, string[][], size_t);
  // int replaceSeq(size_t, size_t, char*[][], size_t);
  // int replaceSeq(size_t, size_t, int[][], size_t);
  // int replaceSeq(size_t, size_t, double[][], size_t);
  // int replaceSeq(size_t, size_t, float[][], size_t);

  size_t remove(string);
  size_t remove(string[], size_t);
  char * stringify();
};

#endif
