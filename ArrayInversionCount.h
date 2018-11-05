//
// Created by henric on 2018-11-02.
//

#ifndef ARRAYINVERSION_ARRAYINVERSIONCOUNT_H
#define ARRAYINVERSION_ARRAYINVERSIONCOUNT_H

#include <vector>

using namespace std;

class InversionContainer {
public:
    InversionContainer(const vector<int> &, unsigned long);
    virtual ~InversionContainer();

    const vector<int> &getV() const;
    unsigned long getNumOfInversions() const;
    unsigned long getSize() const;

private:
    vector<int> v;
    unsigned long numOfInversions;
};

class ArrayInversionCount {
public:
    InversionContainer sort_and_count_inv(vector<int> &);
protected:
    InversionContainer merge_and_count_split_inv(const vector<int> &, const vector<int> &);
};

#endif //ARRAYINVERSION_ARRAYINVERSIONCOUNT_H
