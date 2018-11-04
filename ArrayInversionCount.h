//
// Created by henric on 2018-11-02.
//

#ifndef ARRAYINVERSION_ARRAYINVERSIONCOUNT_H
#define ARRAYINVERSION_ARRAYINVERSIONCOUNT_H

#include <vector>

using namespace std;

class InversionContainer {
public:
    InversionContainer(vector<int>, int);
    virtual ~InversionContainer();

    const vector<int> &getV() const;
    int getNumOfInversions() const;
    unsigned long getSize() const;
    void swap(InversionContainer &);

    InversionContainer operator+(InversionContainer &);

private:
    vector<int> v;
    int numOfInversions;
};

class ArrayInversionCount {
public:
    InversionContainer sort_and_count_inv(vector<int> &);
protected:
    InversionContainer merge_and_count_split_inv(vector<int> &, vector<int> &);
};

#endif //ARRAYINVERSION_ARRAYINVERSIONCOUNT_H
