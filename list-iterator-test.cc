#include "List.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

using namespace std;
using namespace linked_list;

int main()
{

	List<char> list_1{ 'a', 'b', 'c' };
	cout << "lista1 skapad\n";

   if (list_1.empty())
      cout << "Listan är tom\n";
   else
      cout << "Listan är inte tom\n";


  cout << "\nTestar utskrift med const iteratorer: \n";

  copy(list_1.cbegin(),list_1.cend(),ostream_iterator<char>(cout, " "));

  cout << "\nTestar utskrift med vanliga iteratorer: \n";

  copy(list_1.begin(),list_1.end(),ostream_iterator<char>(cout, " "));

  auto iter1 = list_1.begin();

  cout << "\nUtskrift av iter1: \n";
  cout << *iter1;

  auto iter2 = iter1;
  cout << "\nUtskrift av iter1 och iter2: \n";
  cout << *iter1 << " " << *iter2;

  cout << "\nJämföra likhet iter1 med iter2: \n";

  if ( iter1 == iter2)
  	cout << "lika";
  else
  	cout << "Inte Lika";


  cout << "\nÖka iter1 med 1 steg: \n";
  iter1++;
  cout << *iter1;

  cout << "\nJämföra olikhet iter1 med iter2: \n";

  if ( iter1 != iter2)
  	cout << "Inte lika";
  else
  	cout << "Lika";

  auto iter3 = iter2;

cout << "\nJämföra likhet iter2 med iter3 (const): \n";

  if ( (iter3 == iter2) && (iter2 == iter3))
  	cout << "Passed";
  else
  	cout << "Big Fail";

cout << "\nJämföra olikhet iter1 med iter3 (const): \n";

  if ( (iter3 != iter1) && (iter1 != iter3))
  	cout << "Passed";
  else
  	cout << "Big Fail";


  cout << "\nUtskrivning via for-loop: \n";
  for (auto it = list_1.begin(); it != list_1.end(); ++it)
  {
  	cout << " " << *it;
  }
  



	cout << endl;
	return 0;
}