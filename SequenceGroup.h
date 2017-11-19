//
// Created by ubuntu on 17-11-19.
//

#ifndef DISRUPTOR_PP_SEQUENCEGROUP_H
#define DISRUPTOR_PP_SEQUENCEGROUP_H

#include <cstdint>
#include <atomic>
#include <vector>
#include "Interfaces/ISequence.h"
#include "Interfaces/ICursored.h"
#include "Util/Utils.h"
#include "SequenceArrayWrapper.h"
#include "SequenceGroups.h"
#include "Sequence.h"

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
        int64_t GetValue() override;

        void SetValue(const int64_t& value) override;

        bool CompareAndSet(int64_t& expectedSequence, int64_t& nextSequence) override;

        int64_t IncrementAndGet() override;

        int64_t AddAndGet(const int64_t& val) override;

        /// <summary>
        /// Add a <see cref="Sequence"/> into this aggregate. This should only be used during
        /// initialisation. Use <see cref="SequenceGroup.AddWhileRunning"/>.
        /// </summary>
        /// <param name="sequence">sequence to be added to the aggregate.</param>
        void Add(Interfaces::ISequence* sequence);

        /// <summary>
        /// Remove the first occurrence of the <see cref="Sequence"/> from this aggregate.
        /// </summary>
        /// <param name="sequence">sequence to be removed from this aggregate.</param>
        /// <returns>true if the sequence was removed otherwise false.</returns>
        bool Remove(Interfaces::ISequence* sequence);

        /// <summary>
        /// Get the size of the group.
        /// </summary>
        int Size();

        /// <summary>
        /// Adds a sequence to the sequence group after threads have started to publish to
        /// the Disruptor.It will set the sequences to cursor value of the ringBuffer
        /// just after adding them.  This should prevent any nasty rewind/wrapping effects.
        /// </summary>
        /// <param name="cursored">The data structure that the owner of this sequence group will be pulling it's events from</param>
        /// <param name="sequence">The sequence to add</param>
        void AddWhileRunning(Interfaces::ICursored* cursored, Interfaces::ISequence* sequence);
    };
}


#endif //DISRUPTOR_PP_SEQUENCEGROUP_H
