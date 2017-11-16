cmake_minimum_required(VERSION 3.8)
project(disruptor_pp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp ICursored.h ISequenced.h ISequence.h IEventProcessor.h IDataProvider.h ISequenceBarrier.h SequenceGroups.cpp SequenceGroups.h IWaitStrategy.h IEventSequencer.h ISequencer.h IWorkHandler.h)
add_executable(disruptor_pp ${SOURCE_FILES})