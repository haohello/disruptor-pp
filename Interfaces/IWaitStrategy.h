//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IWAITSTRATEGY_H
#define DISRUPTOR_PP_IWAITSTRATEGY_H

#include <cstdint>
#include "../Sequence.h"
#include "ISequenceBarrier.h"

namespace Disruptor::Interfaces {

    /// <summary>
    /// Strategy employed for making <see cref="IEventProcessor"/>s wait on a <see cref="RingBuffer{T}"/>.
    /// </summary>
    class IWaitStragety {
    public:
        /// <summary>
        /// Wait for the given sequence to be available.  It is possible for this method to return a value
        /// less than the sequence number supplied depending on the implementation of the WaitStrategy.A common
        /// use for this is to signal a timeout.Any EventProcessor that is using a WaitStrategy to get notifications
        /// about message becoming available should remember to handle this case.  The <see cref="BatchEventProcessor{T}"/>
        /// explicitly handles this case and will signal a timeout if required.
        /// </summary>
        /// <param name="sequence">sequence to be waited on.</param>
        /// <param name="cursor">Ring buffer cursor on which to wait.</param>
        /// <param name="dependentSequence">on which to wait.</param>
        /// <param name="barrier">barrier the <see cref="IEventProcessor"/> is waiting on.</param>
        /// <returns>the sequence that is available which may be greater than the requested sequence.</returns>
        /// <exception cref="TimeoutException">if a timeout occurs before waiting completes (not used by some strategies)</exception>
        virtual int64_t WaitFor(const int64_t& sequence, Sequence *cursor, ISequence *dependentSequence, ISequenceBarrier *barrier) = 0;

        /// <summary>
        /// Signal those <see cref="IEventProcessor"/> waiting that the cursor has advanced.
        /// </summary>
        virtual void SignalAllWhenBlocking();
    };

}

#endif //DISRUPTOR_PP_IWAITSTRATEGY_H
