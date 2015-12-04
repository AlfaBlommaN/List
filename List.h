/*
 * List.h    Laboration Listan (rekursiv)
 */
#ifndef LIST_H
#define LIST_H
#include <iosfwd>
#include <initializer_list>
#include <string>

namespace linked_list {

template <typename T>
struct List_Node
{
   ~List_Node() 
   {
      delete next_;
   }

   List_Node(const T  value, List_Node * tail=nullptr)
            : data_(value), next_(tail) {}

   // Genereras ej!
   List_Node()                                  = delete; 
   List_Node(const List_Node & other)           = delete; 
   List_Node & operator=(const List_Node & rhs) = delete; 
   List_Node(List_Node && other)                = delete; 
   List_Node & operator=(List_Node && rhs)      = delete;
   
   T data_;
   List_Node* next_;
};

template<typename T>
struct List_iterator_
{
   typedef T                              value_type;
   typedef T*                             pointer; 
   typedef T&                             reference;
   typedef std::ptrdiff_t                 difference_type;
   typedef std::forward_iterator_tag      iterator_category;

   List_iterator_() : lpointer{nullptr} {}
   List_iterator_(List_Node<T>* pother) : lpointer{pother} {}

   reference operator*() { return lpointer->data_;}

   pointer operator->() 
   { 
      return &(lpointer->data_);
   }

   List_iterator_ & operator++() 
   { 
      lpointer = lpointer->next_;
      return *this;
   }

   List_iterator_ operator++(int) 
   { 
      List_iterator_ temp {lpointer};
      lpointer = lpointer->next_;
      return temp;
   }

   bool operator==(List_iterator_<T> rhs) const
   {
      return lpointer == rhs.lpointer;
   }

   bool operator!=(List_iterator_<T> rhs) const
   {
      return lpointer == rhs.lpointer;
   }

   List_Node<T>* lpointer; 
};


template<typename T>
struct List_const_iterator_
{
   typedef T                                    value_type;
   typedef const T*                             pointer;
   typedef const T&                             reference;
   typedef std::ptrdiff_t                       difference_type;
   typedef std::forward_iterator_tag            iterator_category;

   List_const_iterator_() : lpointer{nullptr} {}
   List_const_iterator_(List_Node<T>* pother) : lpointer{pother} {}
   List_const_iterator_(List_iterator_<T> iother) : lpointer{iother} {}

   reference operator*() { return lpointer->data_;}
  
   pointer operator->() 
   { 
      return &(lpointer->data_);
   }

   List_const_iterator_ & operator++() 
   { 
      lpointer = lpointer->next_;
      return *this;
   }

   List_const_iterator_ operator++(int) 
   { 
      List_const_iterator_ temp {lpointer};
      lpointer = lpointer->next_;
      return temp;
   }

   bool operator==(List_const_iterator_<T> rhs) const
   {
     return lpointer == rhs.lpointer;
   }

   bool operator!=(List_const_iterator_<T> rhs) const
   {
      return lpointer == rhs.lpointer;
   }  

   // bool operator!=(List_const_iterator_<T> rhs) const;
   List_Node<T> const* lpointer; 
};

   // Externa jämförelseoperatorer
   template <typename T>
   bool operator ==(const List_iterator_<T>  &lhs, const  List_const_iterator_<T> &rhs )
                  {return lhs.lpointer == rhs.lpointer;}
   template <typename T>
   bool operator !=(const List_iterator_<T>  &lhs, const  List_const_iterator_<T> &rhs )
                  {return lhs.lpointer != rhs.lpointer;}
   template <typename T>
   bool operator ==(const  List_const_iterator_<T> &rhs, const List_iterator_<T>  &lhs)
                  {return lhs.lpointer == rhs.lpointer;}
   template <typename T>
   bool operator !=(const  List_const_iterator_<T> &rhs, const List_iterator_<T>  &lhs)
                  {return lhs.lpointer != rhs.lpointer;}


template<typename T>
class List
{
public:
   

   // explicit List(const T data, List_Node<T>* next = nullptr)
   //       {
   //          append(data,next);
   //       }

   List() = default;
   List(const List<T>&);
   List(List<T>&&) noexcept;
   List& operator=(List<T>&& rhs);
   List& operator=(const List<T>& rhs);
   // Initierarlist
   List(std::initializer_list<T> il);
   ~List();

   // Iteratorer
   typedef List_iterator_<T> iterator;
   typedef List_const_iterator_<T> const_iterator;

   iterator begin()                 { return List_iterator_<T>{head_};}
   iterator end()                   { return List_iterator_<T>{nullptr};}
   const_iterator cbegin() const    { return List_const_iterator_<T>{head_};}
   const_iterator cend()   const    { return List_const_iterator_<T>{nullptr};}
   const_iterator begin() const    { return List_const_iterator_<T>{head_};}
   const_iterator end()   const    { return List_const_iterator_<T>{nullptr};}

   // Funktioner
   void insert(const T value);
   void append(const T value);
   void remove(const T value);

   void clear();
   void swap(List&);

   bool empty() const;
   bool member(const T value) const;
 
private:
   
   struct List_Node<T>* head_{ nullptr };

   static void append(T value, List_Node<T>*& list);
   static void remove(T value, List_Node<T>*& list);
   static bool member(T value, const List_Node<T>* list);

   List_Node<T>* copy(const List_Node<T>* rhs) const;

};

template <typename T>
void swap (List<T>& lhs,List<T>& rhs);
}

#include "List.tcc"

#endif
