//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H
#define DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H

#include "Interfaces/ISequence.h"

namespace Disruptor {

    /// <summary>
    /// Hides a group of Sequences behind a single Sequence
    /// </summary>
    class FixedSequenceGroup : public Interfaces::ISequence
    {
        Interfaces::ISequence *_sequences; // array of ISequence
    public:
        /// <summary> </summary>
        /// <param name="sequences">sequences the list of sequences to be tracked under this sequence group</param>
        FixedSequenceGroup(Interfaces::ISequence *sequences, const int& length) {
            _sequences = sequences;
        }
    };
}

#endif //DISRUPTOR_PP_FIXEDSEQUENCEGROUP_H
