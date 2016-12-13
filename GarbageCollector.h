#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include "Connection.h"

class GarbageCollector {
    private: 
        Connection * head; 
        Connection * tail;
    public: 
        GarbageCollector();
        void addConnection(Connection * connection);
        void cleanup();
        void terminate();
        ~GarbageCollector();
};

#endif 