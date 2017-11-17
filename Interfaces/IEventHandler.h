//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTHANDLER_H
#define DISRUPTOR_PP_IEVENTHANDLER_H

#include <cstdint>

namespace Disruptor::Interfaces {
    /// <summary>
    /// Callback interface to be implemented for processing events as they become available in the <see cref="RingBuffer{T}"/>
    /// </summary>
    /// <typeparam name="T">Type of events for sharing during exchange or parallel coordination of an event.</typeparam>
    /// <remarks>See <see cref="BatchEventProcessor{T}.SetExceptionHandler"/> if you want to handle exceptions propagated out of the handler.</remarks>
    template <typename T> // TODO:: Convariance and Contravariance
    class IEventHandler {
    public:
        /// <summary>
        /// Called when a publisher has committed an event to the <see cref="RingBuffer{T}"/>
        /// </summary>
        /// <param name="data">Data committed to the <see cref="RingBuffer{T}"/></param>
        /// <param name="sequence">Sequence number committed to the <see cref="RingBuffer{T}"/></param>
        /// <param name="endOfBatch">flag to indicate if this is the last event in a batch from the <see cref="RingBuffer{T}"/></param>
        virtual void OnEvent(T *data, const int64_t& sequence, const bool& endOfBatch) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTHANDLER_H
