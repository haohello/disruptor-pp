//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H
#define DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H

#include "Interfaces/ISequence.h"
#include "Util/Utils.h"
#include <cstdint>
#include <exception>

namespace Disruptor {

    /// <summary>
    /// Hides a group of Sequences behind a single Sequence
    /// </summary>
    class FixedSequenceGroup : public Interfaces::ISequence
    {
    private:
        std::vector<Interfaces::ISequence*> _sequences; // array of ISequence
    public:
        /// <summary> </summary>
        /// <param name="sequences">sequences the list of sequences to be tracked under this sequence group</param>
        FixedSequenceGroup(const std::vector<Interfaces::ISequence*>& sequences) {
            _sequences = sequences;
        }

        int64_t GetValue () override {
            return Utils::GetMinimumSequence(_sequences);
        }

        void SetValue(const int64_t& val) override {
            throw "Not supported exception.";
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

#endif //DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H
