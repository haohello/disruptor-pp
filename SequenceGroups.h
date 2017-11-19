//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_SEQUENCEGROUPS_H
#define DISRUPTOR_PP_SEQUENCEGROUPS_H

#include <cstdint>
#include <atomic>
#include <functional>
#include "Interfaces/ISequence.h"
#include "Util/Utils.h"
#include "SequenceArrayWrapper.h"

namespace Disruptor {
    class SequenceGroups {
    public:
        static bool RemoveSequence(std::atomic<SequenceArrayWrapper>& seqArrWrper, Interfaces::ISequence* sequence);
    };
}

#endif //DISRUPTOR_PP_SEQUENCEGROUPS_H
