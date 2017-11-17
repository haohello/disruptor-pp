//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ISEQUENCER_H
#define DISRUPTOR_PP_ISEQUENCER_H

#include <cstdint>
#include "ISequenced.h"
#include "ICursored.h"
#include "ISequence.h"
#include "ISequenceBarrier.h"
#include "IDataProvider.h"
#include "../EventPoller.h"

namespace Disruptor::Interfaces {

    /// <summary>
    /// Coordinator for claiming sequences for access to a data structure while tracking dependent <see cref="Sequence"/>s
    /// </summary>
    template <typename T>
    class ISequencer : public ISequenced, public ICursored
    {
    public:
        /// <summary>
        /// Claim a specific sequence when only one publisher is involved.
        /// </summary>
        /// <param name="sequence">sequence to be claimed.</param>
        virtual void Claim(const int64_t& sequence) = 0;

        /// <summary>
        /// Confirms if a sequence is published and the event is available for use; non-blocking.
        /// </summary>
        /// <param name="sequence">sequence of the buffer to check</param>
        /// <returns>true if the sequence is available for use, false if not</returns>
        virtual bool IsAvailable(const int64_t& sequence) = 0;

        /// <summary>
        /// Add the specified gating sequences to this instance of the Disruptor.  They will
        /// safely and atomically added to the list of gating sequences.
        /// </summary>
        /// <param name="gatingSequences">The sequences to add.</param>
        virtual void AddGatingSequence(ISequence *gatingSequences, const int& length) = 0;

        /// <summary>
        /// Remove the specified sequence from this sequencer.
        /// </summary>
        /// <param name="sequence">to be removed.</param>
        /// <returns>true if this sequence was found, false otherwise.</returns>
        virtual bool RemoveGatingSequence(const ISequence& sequence) = 0;

        /// <summary>
        /// Create a <see cref="ISequenceBarrier"/> that gates on the the cursor and a list of <see cref="Sequence"/>s
        /// </summary>
        /// <param name="sequencesToTrack">All of the sequences that the newly constructed barrier will wait on.</param>
        /// <returns>A sequence barrier that will track the specified sequences.</returns>
        virtual ISequenceBarrier& NewBarrier(ISequence *sequencesToTrack) = 0;

        /// <summary>
        /// Get the minimum sequence value from all of the gating sequences
        /// added to this ringBuffer.
        /// </summary>
        /// <returns>The minimum gating sequence or the cursor sequence if no sequences have been added.</returns>
        virtual int64_t GetMinimumSequence();

        /// <summary>
        /// Get the highest sequence number that can be safely read from the ring buffer.  Depending
        /// on the implementation of the Sequencer this call may need to scan a number of values
        /// in the Sequencer.  The scan will range from nextSequence to availableSequence.  If
        /// there are no available values <code>>= nextSequence</code> the return value will be
        /// <code>nextSequence - 1</code>.  To work correctly a consumer should pass a value that
        /// it 1 higher than the last sequence that was successfully processed.
        /// </summary>
        /// <param name="nextSequence">The sequence to start scanning from.</param>
        /// <param name="availableSequence">The sequence to scan to.</param>
        /// <returns>The highest value that can be safely read, will be at least <code>nextSequence - 1</code>.</returns>
        virtual int64_t GetHighestPublishedSequence(const int64_t& nextSequence,
                                                    const int64_t& availableSequence) = 0;

        /// <summary>
        /// Creates an event poller for this sequence that will use the supplied data provider and
        /// gating sequences.
        /// </summary>
        virtual EventPoller<T>& NewPoller(IDataProvider<T> *provider,
                                          ISequence *gatingSequences, const int& gtLength) = 0;

    };

}

#endif //DISRUPTOR_PP_ISEQUENCER_H