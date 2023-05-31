#ifndef Dictionary_ADT_H
#define Dictionary_ADT_H


template <typename Key>
class Dictionary {
private:
    void operator = (const Dictionary&) {}
    Dictionary(const Dictionary&) {}

public:
    Dictionary(){} //Default Constructor

    virtual ~Dictionary() {} //Base Destructor

    virtual void clear() = 0;

    virtual void insert(const Key& k) = 0;

    virtual Key remove(const Key& k) = 0;

    virtual Key removeAny() = 0;

    virtual bool find(const Key& k) const = 0;

    virtual int size() = 0;

};


#endif // Dictionary_ADT_H
