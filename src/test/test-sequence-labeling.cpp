/*
 *   Copyright 2012, valabau
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 * 
 * test-sequence-labeling.cpp
 *
 *  Created on: 06/03/2012
 *      Author: valabau
 */




#include <cmath>
#include <memory>

#include <fst/fstlib.h>
#include <openlat/compat.h>
#include <openlat/rmarc.h>
#include <openlat/utils.h>
#include <openlat/query.h>
#include <openlat/verify.h>
#include <openlat/approx-shortest-distance.h>




using namespace fst;
using namespace openlat;

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestSequenceLabeling
#include <boost/test/unit_test.hpp>


struct Lattice {
  LogVectorFst fst;


  Lattice() {
    BOOST_TEST_MESSAGE("initializing fst");

    fst.SetStart(fst.AddState());

    fst.AddArc(0, LogArc(0, 0, -log(0.4), 1));
    fst.AddArc(0, LogArc(0, 1, -log(0.6), 1));

    // Adds state 1 and its arc.
    fst.AddState();
    fst.AddArc(1, LogArc(1, 2, -log(0.5), 2));
    fst.AddArc(1, LogArc(1, 0, -log(0.5), 2));

    // Adds state 2 and set its final weight.
    fst.AddState();
    fst.SetFinal(2, -log(1.0));  // 1st arg is state ID, 2nd arg weigh

    Connect(&fst);
  }

  ~Lattice() {
      BOOST_TEST_MESSAGE("finalizing fst");
  }
};

BOOST_FIXTURE_TEST_SUITE(SequenceLabeling, Lattice)

BOOST_AUTO_TEST_CASE(verifySequenceLabeling)
{
  BOOST_CHECK(Verify(fst));

  size_t len = VerifySequenceLabeling(fst);
  BOOST_CHECK(len == 2);

  { // state with different path lengths
    LogVectorFst *bad_fst = fst.Copy(true);
    bad_fst->AddArc(0, LogArc(0, 1, -log(0.6), 2));

    len = VerifySequenceLabeling(*bad_fst);
    BOOST_CHECK(len == static_cast<size_t>(-1));
    delete bad_fst;
  }

  { // fst with cycles
    LogVectorFst *bad_fst = fst.Copy(true);
    bad_fst->AddArc(1, LogArc(0, 1, -log(0.6), 1));

    len = VerifySequenceLabeling(*bad_fst);
    BOOST_CHECK(len == static_cast<size_t>(-1));
    delete bad_fst;
  }
}

BOOST_AUTO_TEST_SUITE_END()
