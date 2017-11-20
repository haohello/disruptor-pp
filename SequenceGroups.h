//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_SEQUENCEGROUPS_H
#define DISRUPTOR_PP_SEQUENCEGROUPS_H

#include <cstdint>
#include <cstdarg>
#include <atomic>
#include <functional>
#include "Interfaces/ISequence.h"
#include "Interfaces/ICursored.h"
#include "Util/Utils.h"
#include "SequenceArrayWrapper.h"

namespace Disruptor {
    class SequenceGroups {
    private:
        static int CountMatching(Interfaces::ISequence** sequences, int length,  Interfaces::ISequence* sequence);
    public:
        /*static void AddSequences(std::atomic<SequenceArrayWrapper>& seqArrWrper, Interfaces::ICursored* cursor, ...);
        static bool RemoveSequence(std::atomic<SequenceArrayWrapper>& seqArrWrper, Interfaces::ISequence* sequence);
    */
         };
}

#endif //DISRUPTOR_PP_SEQUENCEGROUPS_H
