//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_SEQUENCE_H
#define DISRUPTOR_PP_SEQUENCE_H

#include <cstdint>
#include <atomic>
#include "Interfaces/ISequence.h"
#include "Util/Utils.h"

namespace Disruptor {

    /**
         *
         * [StructLayout(LayoutKind.Explicit, Size = 120)]
            private struct Fields
            {
                /// <summary>Volatile in the Java version => always use Volatile.Read/Write or Interlocked methods to access this field.</summary>
                [FieldOffset(56)]
                public long Value;

                public Fields(long value)
                {
                    Value = value;
                }
            }
         *
         */

#pragma pack(push)
#pragma pack(1)
    struct Fields {
        /// <summary>Volatile in the Java version => always use Volatile.Read/Write or Interlocked methods to access this field.</summary>
        unsigned char : 56;
        int64_t Value : 64;
        Fields(const int64_t& val) {
            Value = val;
        }
    };
#pragma pack(pop)

    /// <summary>
    /// <p>Concurrent sequence class used for tracking the progress of
    /// the ring buffer and event processors.Support a number
    /// of concurrent operations including CAS and order writes.</p>
    ///
    /// <p>Also attempts to be more efficient with regards to false
    /// sharing by adding padding around the volatile field.</p>
    /// </summary>
    class Sequence : public Interfaces::ISequence
    {
    private:
        std::atomic<Fields> _fields;
        std::atomic_int64_t fid;
    public:
        /// <summary>
        /// Set to -1 as sequence starting point
        /// </summary>
        const int64_t InitialCursorValue = -1;

        /// <summary>
        /// Construct a new sequence counter that can be tracked across threads.
        /// </summary>
        /// <param name="initialValue">initial value for the counter</param>
        Sequence() : _fields(InitialCursorValue) {};
        Sequence(const Sequence& seq) = delete;



        /// <summary>
        /// Current sequence number
        /// </summary>
        int64_t Value() {
            //fid.compare_exchange_strong()
            return _fields.load(std::memory_order_acq_rel).Value;
        };
    };

}


#endif //DISRUPTOR_PP_SEQUENCE_H
