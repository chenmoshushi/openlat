// compile.h

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: valabau@gmail.com (Vicent Alabau)
//
// \file
// Class to to compile a binary Fst from a lattice in HTK format.

#ifndef HTK_COMPILER_HPP_
#define HTK_COMPILER_HPP_

#include <string>
#include <vector>

#include <iostream>
#include <fstream>

#include <openlat/vector-weight.h>

namespace openlat {

typedef std::set<std::string> Wordlist;

fst::MutableFst<fst::LogArc>*   ReadHtkLogArc(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);
fst::MutableFst<fst::StdArc>*   ReadHtkStdArc(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);
fst::MutableFst<LogLinearArc>*  ReadHtkLogLinearArc(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);

template<typename Arc>
class Lattice {
  fst::VectorFst<Arc> *_fst; 
  std::vector<float> _weights;
  std::vector<std::string> _feature_names;
  public:
  Lattice(): _fst(new fst::VectorFst<Arc>()) { } 
  ~Lattice() { delete _fst; }
  fst::VectorFst<Arc>& getFst() const { return *_fst; };
  fst::VectorFst<Arc>& getFst()       { return *_fst; };
  void setFst(fst::VectorFst<Arc> * fst) { delete _fst; _fst = fst; };
  void setWeights(const std::vector<float> &weights);
  const std::vector<float>& getWeights() const { return _weights; }
  void setFeatureNames(const std::vector<std::string> &feature_names) { _feature_names = feature_names; }
  const std::vector<std::string>& getFeatureNames() const { return _feature_names; }
};

Lattice<fst::LogArc>*  ReadHtkLogLattice(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);
Lattice<fst::StdArc>*  ReadHtkStdLattice(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);
Lattice<LogLinearArc>* ReadHtkLogLinearLattice(std::istream &istrm, const std::string &source, const Wordlist& epsilon_symbols = Wordlist(), int debug_level = -1);

}  // namespace fst

#endif  //HTK_COMPILER_HPP_
