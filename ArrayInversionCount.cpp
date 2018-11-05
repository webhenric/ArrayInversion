//
// Created by henric on 2018-11-02.
//

#include "ArrayInversionCount.h"
#include <utility>
#include <algorithm>

/*
 * Uses merge sort
 */
InversionContainer ArrayInversionCount::sort_and_count_inv(vector<int> &v) {
    vector<int> first_half;
    vector<int> second_half;

    if (v.size() < 2) {
        return {v, 0};
    }

    first_half.reserve(v.size() / 2);
    copy_n(v.cbegin(), v.size() / 2, inserter(first_half, first_half.begin()));
    InversionContainer leftInversions = sort_and_count_inv(first_half);

    second_half.reserve(v.size() / 2);
    copy(v.cbegin() + (v.size() / 2), v.cend(), inserter(second_half, second_half.begin()));
    InversionContainer rightInversions = sort_and_count_inv(second_half);

    InversionContainer splitInversions = merge_and_count_split_inv(leftInversions.getV(), rightInversions.getV());

    return {splitInversions.getV(),
            splitInversions.getNumOfInversions() +
            leftInversions.getNumOfInversions() +
            rightInversions.getNumOfInversions()};
}

InversionContainer ArrayInversionCount::merge_and_count_split_inv(const vector<int> &vector1, const vector<int> &vector2) {
    unsigned long i = 0, j = 0, k = 0;
    unsigned long size = vector1.size() + vector2.size();
    unsigned long numOfSplitInversions = 0;
    vector<int> vector3;

    for (; k < size - 1 && i < vector1.size() && j < vector2.size(); ++k) {
        if (vector1.at(i) < vector2.at(j)) {
            vector3.push_back(vector1.at(i));
            ++i;
        } else {
            vector3.push_back(vector2.at(j));
            ++j;
            numOfSplitInversions += ((size / 2) - i);
         }
    }

    if (i < j) {
        copy(vector1.cbegin() + i, vector1.cend(), inserter(vector3, vector3.end()));
    } else {
        copy(vector2.cbegin() + j, vector2.cend(), inserter(vector3, vector3.end()));
    }

    return {vector3, numOfSplitInversions};
}

InversionContainer::InversionContainer(const vector<int> &v, unsigned long numOfInversions) : v(v), numOfInversions(numOfInversions) {}

const vector<int> &InversionContainer::getV() const {
    return v;
}

unsigned long InversionContainer::getNumOfInversions() const {
    return numOfInversions;
}

unsigned long InversionContainer::getSize() const {
    return v.size();
}

InversionContainer::~InversionContainer() = default;
