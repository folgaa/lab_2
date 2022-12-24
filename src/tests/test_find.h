#ifndef LAB2_2_0_TEST_FIND_H
#define LAB2_2_0_TEST_FIND_H

#include "../hash_table.h"

void test3()
{
    Hash_table<int> a;
    a.add(1,1);
    a.add(2,2);
    cout << "Hash table, elements: (1,1), (2,2)" << endl;
    cout << "find(1): " << a.find(1) << endl;
    cout << "find(3): " << a.find(3) << endl;
}

#endif //LAB2_2_0_TEST_FIND_H
