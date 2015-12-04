
/*
 * list_test.cc    Laboration Listan
 */
#include "List.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace linked_list;

template <typename T>
void print(ostream& os, const List<T>& lst)
{
   lst.print(cout, " -> ");
   os << '\n';
}

int main()
{
   List<int> list_1{ 1,2,3,5 };
   cout << "lista1 skapad\n";

   if (list_1.empty())
      cout << "Listan ar tom\n";
   else
      cout << "Listan ar inte tom\n";


   copy(list_1.cbegin(),list_1.cend(), ostream_iterator<int>(cout, " "));


   // if (list_1.empty())
   //    cout << "Listan är tom\n";
   // else
   //    cout << "Listan är inte tom\n";

   // List<int> list2(list_1);

   // cout << endl <<" list 2" << endl;
   // print(cout, list2);

   // cout << "\nlist 3 KTO-test\n";
   // List<int> list3;
   // list3 = std::move(list2);

   // if (list3.empty())
   //    cout << "Listan är tom\n";
   // else
   //    cout << "Listan är inte tom\n";

   // print(cout, list3);

   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // cout << "\nSätter in, i tur och ordning, 4, 5, 6 sist i list2\n";
   // list_2.insert(4);
   // list_2.insert(5);
   // list_2.insert(6);
  

   // if (list_2.empty())
   //    cout << "Listan är tom\n";
   // else
   //    cout << "Listan är inte tom\n";
   // print(cout, list_2);

   // cout << "\nSwap list1 med list2. ";
   // swap(list_1,list_2);
   
   // cout << "\nSkriver ut list1: ";   
   // print(cout, list_1);

   // cout << "\nSkriver ut list2: ";
   // print(cout, list_2);

   // cout << "\nSwap list1 med list2. ";
   // list_2.swap(list_1);

   // cout << "\nSkriver ut list1: ";   
   // print(cout, list_1);

   // cout << "\nSkriver ut list2: ";
   // print(cout, list_2);

   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // if (list_1.member(4))
   //    cout << "\nVärdet 4 finns i listan\n";
   // else
   //    cout << "\nVärdet 4 finns ej i listan\n";

   // if (list_1.member(7))
   //    cout << "Värdet 7 finns i listan\n";
   // else
   //    cout << "Värdet 7 finns ej i listan\n";

   // cout << "\nTar bort 4 ur listan\n";
   // list_1.remove(4);
   
   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // cout << "\nTar bort 1 ur listan\n";
   // list_1.remove(1);
   
   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // cout << "\nTar bort 6 ur listan\n";
   // list_1.remove(6);
   
   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // cout << "\nTömmer listan\n";
   // list_1.clear();

   // if (list_1.empty())
   // {
   //    cout << "Listan är tom\n";
   // }
   // else
   // {
   //    cout << "Listan är inte tom\n";
   //    cout << "Listan innehåller: ";
   //    print(cout, list_1);
   // }

   // cout << "\nSätter in, i tur och ordning, 1, 2, 3 först i listan\n";
   // list_1.insert(1);
   // list_1.insert(2);
   // list_1.insert(3);

   // cout << "Listan innehåller: ";
   // print(cout, list_1);

   // cout << "\nTömmer listan\n";
   // list_1.clear();

   
   // if (list_1.empty())
   // {
   //    cout << "Listan är tom\n";
   // }
   // else
   // {
   //    cout << "Listan är inte tom\n";
   //    cout << "Listan innehåller: ";
   //    print(cout, list_1);
   // }


   // cout << "\nListan destrueras\n";
   // delete list_1;

   cout << endl ;
   return 0;
}
