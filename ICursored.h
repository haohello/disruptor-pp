//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ICURSORED_H
#define DISRUPTOR_PP_ICURSORED_H

namespace Disruptor {

    /// <summary>
    /// Implementors of this interface must provide a single long value
    /// that represents their current cursor value.Used during dynamic
    /// add/remove of Sequences from a
    /// <see cref="SequenceGroups.AddSequences"/>.
    /// </summary>
    class ICursored {
    public:

        /// <summary>
        /// Get the current cursor value.
        /// </summary>
        virtual long GetCursor() = 0;

    };

}

#endif //DISRUPTOR_PP_ICURSORED_H
