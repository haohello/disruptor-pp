//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_ILIFECYCLEAWARE_H
#define DISRUPTOR_PP_ILIFECYCLEAWARE_H

namespace Disruptor::Interfaces {

    /// <summary>
    /// Implement this interface in your <see cref="IEventHandler{T}"/> to be notified when a thread for the
    /// <see cref="BatchEventProcessor{T}"/> starts and shuts down.
    /// </summary>
    class ILifecycleAware {
    public:
        ///<summary>
        /// Called once on thread start before first event is available.
        ///</summary>
        virtual void OnStart() = 0;

        /// <summary>
        /// Called once just before the thread is shutdown.
        ///
        /// Sequence event processing will already have stopped before this method is called. No events will
        /// be processed after this message.
        /// </summary>
        virtual void OnShutdown() = 0;
    };
}

#endif //DISRUPTOR_PP_ILIFECYCLEAWARE_H
