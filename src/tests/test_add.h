#ifndef LAB2_2_0_TEST_ADD_H
#define LAB2_2_0_TEST_ADD_H

void test1()
{
    Hash_table<int> a;
    a.add(1,1);
    cout << "Hash table, elements: (1,1)" << endl;
    cout << "add(3,3)" << endl;
    a.add(3,3);
    a.print();
    cout << "add(1,3) " << endl;
    a.add(1,3);
}

#endif //LAB2_2_0_TEST_ADD_H
