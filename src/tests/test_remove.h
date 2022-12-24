#ifndef LAB2_2_0_TEST_REMOVE_H
#define LAB2_2_0_TEST_REMOVE_H

void test2()
{
    Hash_table<int> a;
    a.add(1,1);
    cout << "Hash table, elements: (1,1)" << endl;
    cout << "remove(1)" << endl;
    a.remove(1);
    cout << "remove(1)" << endl;
    a.remove(1);
}

#endif //LAB2_2_0_TEST_REMOVE_H
