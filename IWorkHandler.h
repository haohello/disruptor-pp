//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IWORKHANDLER_H
#define DISRUPTOR_PP_IWORKHANDLER_H

namespace Disruptor {

    /// <summary>
    /// Callback interface to be implemented for processing units of work as they become available in the <see cref="RingBuffer{T}"/>
    ///
    /// </summary>
    /// <typeparam name="T">event implementation storing the data for sharing during exchange or parallel coordination of an event.</typeparam>
    template <typename T> // TODO:: covariance and contravariance....
    class IWorkHandler {
    public:
        /// <summary>
        /// Callback to indicate a unit of work needs to be processed.
        /// </summary>
        /// <param name="evt">event published to the <see cref="RingBuffer{T}"/></param>
        virtual void OnEvent(T evt) = 0;
    };
}

#endif //DISRUPTOR_PP_IWORKHANDLER_H
