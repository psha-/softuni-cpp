#include "sequencecollection.h"
#include <iostream>
#include <stdexcept>

SequenceCollection::SequenceCollection()
    :m_Sequences(), m_Threads(), m_Results(new std::queue<std::shared_ptr<Element>>()), m_Running(false)
{
}

void SequenceCollection::printSequencesSimultaneously()
{
    run();
    for(auto it=m_Sequences.begin(); it!=m_Sequences.end(); it++) {
        m_Threads.push_back(std::thread(&SequenceCollection::calculateAll, this, *it));
    }
    m_Threads.push_back(std::thread(&SequenceCollection::printFlushAll, this));

    std::cin.get();
    stop();

    joinAll();
}

void SequenceCollection::calculateAll(std::shared_ptr<Sequence> sequence)
{
    try {
        while(m_Running) {
            // Give it some air:
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            sequence->calculateNext();
            m_ResultsLock.lock();
            m_Results->push(sequence->getCurrent());
            m_ResultsLock.unlock();
        }
    }
    catch(std::out_of_range e) {
        std::cout << e.what() << " Removing sequence." << std::endl;
        removeSequence(sequence.get());
    }
}

void SequenceCollection::printFlushAll()
{
    while(m_Running) {
        m_ResultsLock.lock();
        if(m_Results->size() > 0) {
            m_Results->front()->print();
            m_Results->pop();
        }
        m_ResultsLock.unlock();
    }
}



