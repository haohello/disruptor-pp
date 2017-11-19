//
// Created by ubuntu on 17-11-20.
//

#ifndef DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H
#define DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H

#include "Interfaces/ISequence.h"

namespace Disruptor {
    class SequenceArrayWrapper {
    private:
        Interfaces::ISequence** _sequences;
        int _length = 0;

    public:
        SequenceArrayWrapper(Interfaces::ISequence** sequences, const int& length) : _sequences(sequences),
                                                                                     _length(length) {};
        Interfaces::ISequence** GetValue() {
            return _sequences;
        }

        int GetLength() {
            return _length;
        }

        void SetValue(Interfaces::ISequence** sequences, const int& length) {
            _sequences = sequences;
            _length = length;
        }

        void SetValue(Interfaces::ISequence** sequences) {
            _sequences = sequences;
        }

        void SetLength(const int& length) {
            _length = length;
        }


    };
}

#endif //DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H
