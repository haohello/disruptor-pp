//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ISEQUENCE_H
#define DISRUPTOR_PP_ISEQUENCE_H

#include <cstdint>

namespace Disruptor::Interfaces {
    class ISequence {
    public:
        /// <summary>
        /// Current sequence number
        /// </summary>
        virtual int64_t GetValue() = 0;

        /// <summary>
        /// Perform an ordered write of this sequence.  The intent is
        /// a Store/Store barrier between this write and any previous
        /// store.
        /// </summary>
        /// <param name="value">The new value for the sequence.</param>
        virtual void SetValue(const int64_t& value) = 0;


        /// <summary>
        /// Performs a volatile write of this sequence.  The intent is a Store/Store barrier between this write and any previous
        /// write and a Store/Load barrier between this write and any subsequent volatile read.
        /// </summary>
        /// <param name="value"></param>
        virtual void SetValueVolatile(const int64_t& value) = 0;

        /// <summary>
        /// Atomically set the value to the given updated value if the current value == the expected value.
        /// </summary>
        /// <param name="expectedSequence">the expected value for the sequence</param>
        /// <param name="nextSequence">the new value for the sequence</param>
        /// <returns>true if successful. False return indicates that the actual value was not equal to the expected value.</returns>
        virtual bool CompareAndSet(const int64_t& expectedSequence, const int64_t& nextSequence) = 0;

        ///<summary>
        /// Increments the sequence and stores the result, as an atomic operation.
        ///</summary>
        ///<returns>incremented sequence</returns>
        virtual int64_t IncrementAndGet() = 0;

        ///<summary>
        /// Increments the sequence and stores the result, as an atomic operation.
        ///</summary>
        ///<returns>incremented sequence</returns>
        virtual int64_t AddAndGet(const int64_t& value) = 0;
    };
}

#endif //DISRUPTOR_PP_ISEQUENCE_H
