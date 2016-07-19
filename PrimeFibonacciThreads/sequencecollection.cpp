#include "sequencecollection.h"
#include <iostream>

SequenceCollection::SequenceCollection()
    :m_Sequences(), m_Threads(std::vector<std::thread>()), m_Results(new std::queue<std::shared_ptr<Element>>()), m_Running(false)
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

    for(auto it=m_Threads.begin(); it!=m_Threads.end(); it++) {
        it->join();
    }
}

void SequenceCollection::calculateAll(std::shared_ptr<Sequence> sequence)
{
    while(m_Running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        sequence->calculateNext();
        m_ResultsLock.lock();
        m_Results->push(sequence->getCurrent());
        m_ResultsLock.unlock();
    }
}

void SequenceCollection::printFlushAll()
{
    while(m_Running) {
        m_ResultsLock.lock();
        if(m_Results->size() > 0) {
            std::shared_ptr<Element> el = m_Results->front();
            std::cout << el << std::endl;
            m_Results->pop();
        }
        m_ResultsLock.unlock();
    }
}

