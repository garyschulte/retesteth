/*
This file is part of cpp-ethereum.

cpp-ethereum is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

cpp-ethereum is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file StateTests.h
 * StateTests functions.
 */

#pragma once
#include <dataObject/DataObject.h>
#include <retesteth/TestSuite.h>
#include <boost/filesystem/path.hpp>

namespace test
{

class StateTestSuite: public TestSuite
{
public:
    StateTestSuite();
    StateTestSuite(int){};
    DataObject doTests(DataObject const& _input, TestSuiteOptions& _opt) const override;
    TestSuite::TestPath suiteFolder() const override;
    TestSuite::FillerPath suiteFillerFolder() const override;
};

class LegacyConstantinopleStateTestSuite : public StateTestSuite
{
protected:
    bool legacyTestSuiteFlag() const override { return  true; }
public:
    TestSuite::TestPath suiteFolder() const override;
    TestSuite::FillerPath suiteFillerFolder() const override;
};

class StateTestVMSuite: public StateTestSuite
{
public:
    StateTestVMSuite() : StateTestSuite(0){};
    TestSuite::TestPath suiteFolder() const override;
    TestSuite::FillerPath suiteFillerFolder() const override;
};

}


