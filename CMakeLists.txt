cmake_minimum_required(VERSION 3.8)
project(disruptor_pp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
        Interfaces/IEventTranslator.h Interfaces/ICursored.h Interfaces/IDataProvider.h
        Interfaces/IWorkHandler.h Interfaces/ITimeoutHandler.h Interfaces/ISequenced.h
        Interfaces/IEventProcessor.h Interfaces/ISequence.h Interfaces/ISequenceBarrier.h
        Interfaces/ILifecycleAware.h Interfaces/IExceptionHandler.h Interfaces/IEventReleaser.h
        Interfaces/IEventTranslatorOneArg.h Interfaces/IEventTranslatorTwoArg.h Interfaces/IEventTranslatorThreeArg.h
        Interfaces/IEventTranslatorVararg.h Interfaces/IEventReleaseAware.h Interfaces/IEventSink.h
        Interfaces/IEventHandler.h Interfaces/IBatchStartAware.h Interfaces/IEventSequencer.h
        FixedSequenceGroup.h FixedSequenceGroup.cpp Interfaces/ISequencer.h
        IgnoreExceptionHandler.h Exceptions/InsufficientCapacityException.h EventPoller.h
        Sequence.cpp Sequence.h SequenceGroups.cpp SequenceGroups.h Interfaces/IWaitStrategy.h Util/Utils.h SequenceGroup.cpp SequenceGroup.h Util/AggressiveSpinWait.h Exceptions/AlertException.h Exceptions/TimeoutException.h SequenceArrayWrapper.h)
add_executable(disruptor_pp ${SOURCE_FILES})