/********************************************************************************
 *
 * Copyright (c) 2018 ROCm Developer Tools
 *
 * MIT LICENSE:
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/
#include "rvsactionbase.h"

#include <chrono>
#include <unistd.h>


using namespace std;

rvs::actionbase::actionbase() {
}

rvs::actionbase::~actionbase() {
}

int rvs::actionbase::property_set(const char* pKey, const char* pVal) {
  property.insert( pair<string, string>(pKey, pVal));
  return 0;
}

void rvs::actionbase::sleep(const unsigned int ms) {
  ::usleep(1000*ms);
}

bool rvs::actionbase::has_property(const string& key, string& val) {

  auto it = property.find(key);
  if(it != property.end()) {
    val = it->second;
    return true;
  }

  return false;
}

bool rvs::actionbase::has_property(const string& key) {
  string val;
  return has_property(key, val);
}