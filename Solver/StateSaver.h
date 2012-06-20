/***************************************************************************************[Solver.cc]
Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
Copyright (c) 2007-2009, Niklas Sorensson
Copyright (c) 2009-2012, Mate Soos

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**************************************************************************************************/

#ifndef STATESAVER__H
#define STATESAVER__H

#include "Solver.h"

namespace CMSat {

class StateSaver
{
    public:
        StateSaver(Solver& _solver);
        void restore();

    private:
        Solver& solver;
        Heap<Solver::VarOrderLt> backup_order_heap;
        vector<char> backup_polarities;
        vec<uint32_t> backup_activity;
        uint32_t backup_var_inc;
        RestartType backup_restartType;
        double backup_random_var_freq;
        uint64_t backup_propagations;
};

}

#endif //STATESAVER__H
