#ifndef SEQUENCECOLLECTION_H
#define SEQUENCECOLLECTION_H

#include <vector>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include "sequence.h"
#include "element.h"

class SequenceCollection
{
public:
    SequenceCollection();

    inline void addSequence(Sequence* sequence)
    {
        m_Sequences.push_back(std::shared_ptr<Sequence>(sequence));
    }

    inline void removeSequence(Sequence* sequence)
    {
        // Linear complexity
        for(auto it=m_Sequences.begin(); it!=m_Sequences.end(); it++) {
            if(it->get()==sequence) {
                m_Sequences.erase(it);
            }
        }
    }

    inline void joinAll()
    {
        for(auto it=m_Threads.begin(); it!=m_Threads.end(); it++) {
            it->join();
        }
    }

    void printSequencesSimultaneously();

private:
    std::vector<std::shared_ptr<Sequence>> m_Sequences;
    std::vector<std::thread> m_Threads;
    std::queue<std::shared_ptr<Element>>* m_Results;
    std::mutex m_ResultsLock;
    bool m_Running;

    void calculateAll(std::shared_ptr<Sequence> sequence);

    void printFlushAll();

    inline void run()
    {
        m_Running = true;
    }

    inline void stop()
    {
        m_Running = false;
    }

};

#endif // SEQUENCECOLLECTION_H
