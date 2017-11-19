//
// Created by ubuntu on 17-11-17.
//

#ifndef CACHE_LINE_SIZE_IN_BYTES     // NOLINT
#define CACHE_LINE_SIZE_IN_BYTES 64  // NOLINT
#endif                               // NOLINT
#define ATOMIC_SEQUENCE_PADDING_LENGTH \
  (CACHE_LINE_SIZE_IN_BYTES - sizeof(std::atomic<int64_t>)) / 8
#define SEQUENCE_PADDING_LENGTH (CACHE_LINE_SIZE_IN_BYTES - sizeof(int64_t)) / 8

#ifndef DISRUPTOR_PP_SEQUENCE_H
#define DISRUPTOR_PP_SEQUENCE_H

#include <cstdint>
#include <atomic>
#include "Interfaces/ISequence.h"
#include "Util/Utils.h"

namespace Disruptor {

    // special cursor values
    constexpr int64_t kInitialCursorValue = -1L;
    constexpr int64_t kAlertedSignal = -2L;
    constexpr int64_t kTimeoutSignal = -3L;
    constexpr int64_t kFirstSequenceValue = kInitialCursorValue + 1L;

    /// <summary>
    /// <p>Concurrent sequence class used for tracking the progress of
    /// the ring buffer and event processors.Support a number
    /// of concurrent operations including CAS and order writes.</p>
    ///
    /// <p>Also attempts to be more efficient with regards to false
    /// sharing by adding padding around the volatile field.</p>
    /// </summary>
    class Sequence : public Interfaces::ISequence
    {
    public:
        Sequence(int64_t initial_value = kInitialCursorValue)
                : value(initial_value) {}

        /// <summary>
        /// Current sequence number
        /// </summary>
        int64_t Value();

        /// <summary>
        /// Perform an ordered write of this sequence.  The intent is
        /// a Store/Store barrier between this write and any previous
        /// store.
        /// </summary>
        /// <param name="value">The new value for the sequence.</param>
        void SetValue(const int64_t& val) override;

        bool CompareAndSet(int64_t& expectedSequence, int64_t& nextSequence) override;

        int64_t IncrementAndGet() override;

        int64_t AddAndGet(const int64_t& val) override;

    private:
        // padding
        int64_t padding0_[ATOMIC_SEQUENCE_PADDING_LENGTH];
        // members
        std::atomic<int64_t> value;
        // padding
        int64_t padding1_[ATOMIC_SEQUENCE_PADDING_LENGTH];

        DISALLOW_COPY_MOVE_AND_ASSIGN(Sequence);
    };


    // This counter is not thread safe.
    class MutableLong {
    public:
        MutableLong(int64_t initial_value = kInitialCursorValue) :
                sequence_(initial_value) {}

        int64_t sequence() const { return sequence_; }

        void set_sequence(const int64_t& sequence) { sequence_ = sequence; };

        int64_t IncrementAndGet(const int64_t& delta) { sequence_ += delta; return sequence_; }

    private:
        volatile int64_t sequence_;
    };
}


#endif //DISRUPTOR_PP_SEQUENCE_H
