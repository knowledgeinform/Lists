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

#include <stdint.h>

class __FlashStringHelper;
#define F(string_literal) (reinterpret_cast<const __FlashStringHelper *>(PSTR(string_literal)))

class string
{
private:
  size_t len;
public:
  string(const char *cstr = "");
	string(const string &str);
	string(const __FlashStringHelper *str);

  explicit string(char c);
	explicit string(unsigned char, unsigned char base=10);
	explicit string(int, unsigned char base=10);
	explicit string(unsigned int, unsigned char base=10);
	explicit string(long, unsigned char base=10);
	explicit string(unsigned long, unsigned char base=10);
	explicit string(float, unsigned char decimalPlaces=2);
	explicit string(double, unsigned char decimalPlaces=2);

  inline size_t length(void) const {return len;}

  unsigned char concat(const string &str);
	unsigned char concat(const char *cstr);
	unsigned char concat(char c);
	unsigned char concat(unsigned char c);
	unsigned char concat(int num);
	unsigned char concat(unsigned int num);
	unsigned char concat(long num);
	unsigned char concat(unsigned long num);
	unsigned char concat(float num);
	unsigned char concat(double num);
	unsigned char concat(const __FlashStringHelper * str);

	// if there's not enough memory for the concatenated value, the string
	// will be left unchanged (but this isn't signalled in any way)
	string & operator += (const string &rhs)	{concat(rhs); return (*this);}
	string & operator += (const char *cstr)		{concat(cstr); return (*this);}
	string & operator += (char c)			{concat(c); return (*this);}
	string & operator += (unsigned char num)		{concat(num); return (*this);}
	string & operator += (int num)			{concat(num); return (*this);}
	string & operator += (unsigned int num)		{concat(num); return (*this);}
	string & operator += (long num)			{concat(num); return (*this);}
	string & operator += (unsigned long num)	{concat(num); return (*this);}
	string & operator += (float num)		{concat(num); return (*this);}
	string & operator += (double num)		{concat(num); return (*this);}
	string & operator += (const __FlashStringHelper *str){concat(str); return (*this);}
}

#endif
