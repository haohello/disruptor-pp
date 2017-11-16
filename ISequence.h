//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ISEQUENCE_H
#define DISRUPTOR_PP_ISEQUENCE_H

namespace Disruptor {
    class ISequence {
    public:
        /// <summary>
        /// Current sequence number
        /// </summary>
        virtual long GetValue() = 0;

        /// <summary>
        /// Perform an ordered write of this sequence.  The intent is
        /// a Store/Store barrier between this write and any previous
        /// store.
        /// </summary>
        /// <param name="value">The new value for the sequence.</param>
        virtual void SetValue(long value) = 0;


        /// <summary>
        /// Performs a volatile write of this sequence.  The intent is a Store/Store barrier between this write and any previous
        /// write and a Store/Load barrier between this write and any subsequent volatile read.
        /// </summary>
        /// <param name="value"></param>
        virtual void SetValueVolatile(long value) = 0;

        /// <summary>
        /// Atomically set the value to the given updated value if the current value == the expected value.
        /// </summary>
        /// <param name="expectedSequence">the expected value for the sequence</param>
        /// <param name="nextSequence">the new value for the sequence</param>
        /// <returns>true if successful. False return indicates that the actual value was not equal to the expected value.</returns>
        virtual bool CompareAndSet(long expectedSequence, long nextSequence) = 0;

        ///<summary>
        /// Increments the sequence and stores the result, as an atomic operation.
        ///</summary>
        ///<returns>incremented sequence</returns>
        virtual long INcrementAndGet() = 0;

        ///<summary>
        /// Increments the sequence and stores the result, as an atomic operation.
        ///</summary>
        ///<returns>incremented sequence</returns>
        virtual long AddAndGet(long value) = 0;
    };
}

#endif //DISRUPTOR_PP_ISEQUENCE_H
