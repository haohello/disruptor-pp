//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ISEQUENCEBARRIER_H
#define DISRUPTOR_PP_ISEQUENCEBARRIER_H

namespace Disruptor {
    /// <summary>
    /// Coordination barrier for tracking the cursor for producers and sequence of
    /// dependent <see cref="IEventProcessor"/>s for a <see cref="RingBuffer{T}"/>
    /// </summary>
    class ISequenceBarrier {
    public:

        /// <summary>
        /// Wait for the given sequence to be available for consumption.
        /// </summary>
        /// <param name="sequence">sequence to wait for</param>
        /// <returns>the sequence up to which is available</returns>
        /// <exception cref="AlertException">if a status change has occurred for the Disruptor</exception>
        /// <exception cref="TimeoutException">if a timeout occurs while waiting for the supplied sequence.</exception>
        virtual long WaitFor(long sequence) = 0;

        /// <summary>
        /// Delegate a call to the <see cref="Sequencer.Cursor"/>
        /// Returns the value of the cursor for events that have been published.
        /// </summary>
        virtual long GetCursor() = 0;

        /// <summary>
        /// The current alert status for the barrier.
        /// Returns true if in alert otherwise false.
        /// </summary>
        virtual bool IsAlerted() = 0;

        /// <summary>
        ///  Alert the <see cref="IEventProcessor"/> of a status change and stay in this status until cleared.
        /// </summary>
        virtual void Alert() = 0;

        /// <summary>
        /// Clear the current alert status.
        /// </summary>
        virtual void ClearAlert() = 0;

        /// <summary>
        /// Check if an alert has been raised and throw an <see cref="AlertException"/> if it has.
        /// </summary>
        /// <exception cref="AlertException">if alert has been raised.</exception>
        virtual void CheckAlert();
    };
}

#endif //DISRUPTOR_PP_ISEQUENCEBARRIER_H
