/*----------------------------------------------------------------------
- nu este permisa utilizarea colectiilor din C++
----------------------------------------------------------------------*/


#include "Dictionar.h"



int main()
{
    Dictionar<int, int> int_dict;
    Dictionar<int, string> str;

    str[10] = "hello";

    int_dict.operator[10] = 21;
    int_dict[22] = 5;
    int_dict[6] = 11;
    int_dict[50] = 4;
    int_dict[15] = 10;
    int_dict[15] = 100;
     cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();

    int_dict[25] = 6;
    int_dict[1] = 9;
    int_dict[4] = 44;
    int_dict[43] = 95;
    int_dict[23] = 36;
    int_dict[32] = 22;
    cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();

    int_dict[22] = 90;
    int_dict[43] = 1;
    cout << int_dict.GetCapacity() << " " << int_dict.GetSize() << endl;
    int_dict.Print();
    
    return 0;
}
/*-------------------------------------------------------------------
10 5
(10:21)
(22:5)
(6:11)
(50:4)
(15:100)

20 11
(10:21)
(22:5)
(6:11)
(50:4)
(15:100)
(25:6)
(1:9)
(4:44)
(43:95)
(23:36)
(32:22)

20 11
(10:21)
(22:90)
(6:11)
(50:4)
(15:100)
(25:6)
(1:9)
(4:44)
(43:1)
(23:36)
(32:22)
-----------------------------------------------------------------------*/
