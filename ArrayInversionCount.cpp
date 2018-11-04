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
    v.erase(v.cbegin(), v.cend() - (v.size() / 2));
    InversionContainer leftInversions = sort_and_count_inv(first_half);

    second_half.reserve(v.size());
    copy_n(v.cbegin(), v.size(), inserter(second_half, second_half.begin()));
    InversionContainer rightInversions = sort_and_count_inv(second_half);

    if (leftInversions.getV().at(0) > rightInversions.getV().at(0)) {
        leftInversions.swap(rightInversions);
    }

    return leftInversions + rightInversions;
}

InversionContainer ArrayInversionCount::merge_and_count_split_inv(vector<int> &vector1, vector<int> &vector2) {
    return {vector1, 0};
}

InversionContainer::InversionContainer(vector<int> v, int numOfInversions) : v(v), numOfInversions(numOfInversions) {}

const vector<int> &InversionContainer::getV() const {
    return v;
}

int InversionContainer::getNumOfInversions() const {
    return numOfInversions;
}

unsigned long InversionContainer::getSize() const {
    return v.size();
}

InversionContainer InversionContainer::operator+(InversionContainer &inversionContainer) {
    vector<int> vector1;
    vector<int> vector2 = inversionContainer.getV();
    vector1.reserve(getSize() + inversionContainer.getSize());
    vector1 = getV();
    copy(vector2.cbegin(), vector2.cend(), inserter(vector1, vector1.end()));
    return InversionContainer(vector1, numOfInversions + inversionContainer.numOfInversions);
}

void InversionContainer::swap(InversionContainer &inversionContainer) {
    v.swap(inversionContainer.v);
}

InversionContainer::~InversionContainer() = default;
