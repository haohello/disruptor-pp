//
// Created by ubuntu on 17-11-19.
//

#ifndef DISRUPTOR_PP_SEQUENCEGROUP_H
#define DISRUPTOR_PP_SEQUENCEGROUP_H

#include <cstdint>
#include <atomic>
#include <vector>
#include "Interfaces/ISequence.h"
#include "Util/Utils.h"
#include "SequenceArrayWrapper.h"

namespace Disruptor {
    /// <summary>
    /// A <see cref="Sequence"/> group that can dynamically have <see cref="Sequence"/>s added and removed while being
    /// thread safe.
    ///
    /// The <see cref="SequenceGroup.Value"/> get and set methods are lock free and can be
    /// concurrently called with the <see cref="SequenceGroup.Add"/> and <see cref="SequenceGroup.Remove"/>.
    /// </summary>
    class SequenceGroup : public Interfaces::ISequence {
    private:
        //std::atomic
        std::atomic<SequenceArrayWrapper> _seqArrWrpr;

    public:
        int64_t GetValue() override {
            auto seqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
            auto length = seqArrWrpr.GetLength();
            auto sequences = seqArrWrpr.GetValue();
            return Utils::GetMinimumSequence(sequences, length);
        };

        void SetValue(const int64_t& value) override {
            auto seqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
            auto length = seqArrWrpr.GetLength();
            auto sequences = seqArrWrpr.GetValue();

            for(auto i = 0; i < length; i++) {
                sequences[i]->SetValue(value);
            }
            _seqArrWrpr.store(seqArrWrpr, std::memory_order_release);
        };

        bool CompareAndSet(int64_t& expectedSequence, int64_t& nextSequence) override {
            throw "Not supported exception.";
        };

        int64_t IncrementAndGet() override {
            throw "Not supported exception.";
        };

        int64_t AddAndGet(const int64_t& val) override {
            throw "Not supported exception.";
        };
    };
}


#endif //DISRUPTOR_PP_SEQUENCEGROUP_H
