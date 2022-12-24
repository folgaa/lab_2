#ifndef LAB2_2_0_TEST_REHASH_H
#define LAB2_2_0_TEST_REHASH_H

void test4()
{
    Hash_table<int> a;
    a.add(1,1);
    a.add(2,1);
    a.add(3,1);
    a.add(4,1);
    a.add(5,1);
    a.add(6,1);
    a.add(7,1);
    cout << "Hash table, elements: (1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1)" << endl;
    a.print();
    a.add(8,1);
    cout << "Add (8,1)" << endl;
    a.print();
}

#endif //LAB2_2_0_TEST_REHASH_H
