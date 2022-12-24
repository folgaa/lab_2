#include <iostream>
#include "src/hash_table.h"
#include "src/tests/test_add.h"
#include "src/tests/test_remove.h"
#include "src/tests/test_find.h"
#include "src/tests/test_rehash.h"

int main() {
    Hash_table<int> a = Hash_table<int>();
    while(1)
    {
        int step;
        cout << "1) Add element" << endl;
        cout << "2) Remove element" << endl;
        cout << "3) Check existence" << endl;
        cout << "4) Print table" << endl;
        cout << "5) Tests" << endl;
        cout << "6) Quit" << endl;

        cin >> step;

        switch (step)
        {
            case 1:
            {
                int key, value;
                cout << "Enter key and value of element" << endl;
                cin >> key >> value;
                a.add(key, value);
                break;
            }

            case 2:
            {
                int key;
                cout << "Enter key of element" << endl;
                cin >> key;
                a.remove(key);
                break;
            }

            case 3:
            {
                int key;
                cout << "Enter key of element" << endl;
                cin >> key;
                a.find(key);
                break;
            }

            case 4:
            {
                a.print();
                break;
            }

            case 5:
            {
                int test;
                cout << "Which test?" << endl;
                cout << "1) test add" << endl;
                cout << "2) test remove" << endl;
                cout << "3) test find" << endl;
                cout << "4) test rehash" << endl;
                cin >> test;

                switch(test)
                {
                    case 1:
                    {
                        test1();
                        break;
                    }
                    case 2:
                    {
                        test2();
                        break;
                    }
                    case 3:
                    {
                        test3();
                        break;
                    }
                    case 4:
                    {
                        test4();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect number!" << endl;
                        break;
                    }
                }

            }

            case 6:
            {
                exit(42);
            }

            default:
            {
                cout << "Incorrect number!" << endl;
            }
        }
    }
    return 0;
}
