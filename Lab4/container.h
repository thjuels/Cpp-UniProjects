class Container {
protected:
    int *storage;
    int capacity;
    int size;  // Current number of elements in the storage array

public:
    Container(int cap);
    ~Container();

    void insert(int element);
    void remove(int element);
    bool contains(int element) const;
    void increaseCapacity(int additionalSpace);
    int getCapacity() const;
    int getSize() const;
};