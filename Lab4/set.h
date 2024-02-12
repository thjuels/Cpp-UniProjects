#include "container.h"

class Set : public Container {
public:
    Set(int cap);

    void insert(int element);
    bool isSuperSet(const Set* newSet) const;
    Set* unionSet(const Set* newSet) const;
};