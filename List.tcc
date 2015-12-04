/*
 * List.cc    Laboration Listan (rekursiv)
 */
#include <iostream>
#include <string>
#include <iterator>
#include <initializer_list>


using namespace std;

//using namespace linked_list;
namespace linked_list {

// template <typename T>
// List<T>::List() : head_(nullptr) {}

template <typename T>	
List<T>::~List() { delete head_; }

// Kopieringskonstruktor, djup kopiering
template <typename T>
List<T>::List(const List<T>& other)
{
   this->head_ = copy(other.head_);
}

// IL-konstruktor
template <typename T>
List<T>::List(std::initializer_list<T> il)
{
   if ( il.size() > 0)
   {
      try
         {
            for (auto it = il.end()-1; it != il.begin()-1; --it)
            {
                head_ = new List_Node<T>{ *it, head_ };
            }
         }
      catch(const bad_alloc& e)
      {
         clear();
         throw ;
      }
      catch (...)
         {
            clear();
         }
   }
 }


// Movekonstrukor
template <typename T>
List<T>::List(List<T>&& other) noexcept
{  
   swap(other);
}

// kopieringstilldelningsoperatorn
template <typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
	delete head_;
	head_ = copy(rhs.head_);
   	return *this;
}

// move-tilldelningsoperator
template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
   swap(rhs);
   return *this;
}
// insert() sätter in ett värde först.
template <typename T>
void List<T>::insert(T value)
{
   head_ = new List_Node<T>{ value, head_ };
}

// append() sätter in ett värde sist. 
template <typename T>
void List<T>::append(T value)
{
   append(value, head_);
}

template <typename T>
void List<T>::append(T value, List_Node<T>*& list)
{
   if (list == nullptr) 
      list = new List_Node<T>{ value, nullptr };
   else 
      append(value, list->next_);
}

// remove() tar bort den först hittade förekomsten av angivet värde, om det
// finns ett sådant värde.
template <typename T>
void List<T>::remove(T value)
{
   remove(value, head_);
}

template <typename T>
void List<T>::remove(T value, List_Node<T>*& list)
{
   if (list == nullptr) 
   {
      return;
   }
   else if (list->data_ == value) 
   {
      List_Node<T>*  garbage{ list };
      list = list->next_;
      garbage->next_ = nullptr;
      delete garbage;
   }
   else 
   {
      remove(value, list->next_);
   }
}

// clear() tömmer listan.
template <typename T>
void List<T>::clear()
{
   delete head_;
   head_ = nullptr;
}

// empty() returnerar sant om listan är tom, falskt annars.
template <typename T>
bool List<T>::empty() const
{
   return head_ == nullptr;
}

// member() returnerar sant om angivet värdet finns i listan, annars falskt.
template <typename T>
bool List<T>::member(T value) const
{
   return member(value, head_);
}
template <typename T>
bool List<T>::member(T value, const List_Node<T>* list)
{
   if (list == nullptr) 
      return false;
   else if (list->data_ == value)
      return true;
   else
      return member(value, list->next_);
}

// medlemsfuntion. Byter huvudena på två olika listor.
template <typename T>
void List<T>::swap(List& rhs)
{
   std::swap(head_,rhs.head_);
}
// icke-meldemsfunktion. Inparametrar två listor.
template <typename T>
void swap(List<T>& lhs, List<T>& rhs)
{
   lhs.swap(rhs);
}

// om ska göra en kopia av en lista av List_Noder; en pekare till listan som 
// ska kopieras ska ges som argument, en pekare till kopian ska returneras
template <typename T>
List_Node<T>* List<T>::copy(const List_Node<T>* other) const
{
   List_Node<T>* temp;

      if(!other)
      {
         return nullptr;
      }
      else if (other->next_ == nullptr) //ändrade 0 till nullptr
      {
         return new List_Node<T>{other->data_, nullptr};
      }
       else   
       try 
   	{
      {
         temp = copy(other->next_);
         return new List_Node<T>{other->data_,temp}; 
      }
   }
   catch(...)
   {
      delete temp;
      throw;
   }
}

}