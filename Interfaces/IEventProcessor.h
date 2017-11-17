//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_IEVENTPROCESSOR_H
#define DISRUPTOR_PP_IEVENTPROCESSOR_H

#include "ISequence.h"

namespace Disruptor::Interfaces {

    /// <summary>
    /// <see cref="IEventProcessor"/> waitFor events to become available for consumption from the <see cref="RingBuffer{T}"/>
    /// </summary>
    class IEventProcessor {
    public:
        /// <summary>
        /// Return a reference to the <see cref="ISequence"/> being used by this <see cref="IEventProcessor"/>
        /// </summary>
        virtual ISequence GetSequence() = 0;

        /// <summary>
        /// Signal that this <see cref="IEventProcessor"/> should stop when it has finished consuming at the next clean break.
        /// It will call <see cref="ISequenceBarrier.Alert"/> to notify the thread to check status.
        /// </summary>
        virtual void Halt() = 0;

        /// <summary>
        /// Starts this instance
        /// </summary>
        virtual void Run() = 0;

        /// <summary>
        /// Gets if the processor is running
        /// </summary>
        virtual bool IsRunning() = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTPROCESSOR_H
