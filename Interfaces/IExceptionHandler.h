//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEXCEPTIONHANDLER_H
#define DISRUPTOR_PP_IEXCEPTIONHANDLER_H

#include <exception>
#include <cstdint>

namespace Disruptor::Interfaces {
    /// <summary>
    /// Callback handler for uncaught exceptions in the event processing cycle of the <see cref="BatchEventProcessor{T}"/>
    /// </summary>
    template <typename T>
    class IExceptionHandler {
    public:
        /// <summary>
        /// Strategy for handling uncaught exceptions when processing an event.
        ///
        /// If the strategy wishes to terminate further processing by the <see cref="BatchEventProcessor{T}"/>
        /// then it should throw a <see cref="ApplicationException"/>
        /// </summary>
        /// <param name="ex">exception that propagated from the <see cref="IEventHandler{T}"/>.</param>
        /// <param name="sequence">sequence of the event which cause the exception.</param>
        /// <param name="event">event being processed when the exception occurred. This can be null</param>
        virtual void HandleEventException(const std::exception& ex, const int64_t& sequence, T *event) = 0;

        /// <summary>
        /// Callback to notify of an exception during <see cref="ILifecycleAware.OnStart"/>
        /// </summary>
        /// <param name="ex">ex throw during the starting process.</param>
        virtual void HandleOnStartException(const std::exception& ex) = 0;

        /// <summary>
        /// Callback to notify of an exception during <see cref="ILifecycleAware.OnShutdown"/>
        /// </summary>
        /// <param name="ex">ex throw during the shutdown process.</param>
        virtual void HandleOnShutdownException(const std::exception& ex) = 0;
    };
}

#endif //DISRUPTOR_PP_IEXCEPTIONHANDLER_H
