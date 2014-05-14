#ifndef FYJLIST_H
#define FYJLIST_H

#include "fyjstd.h"

namespace FYJ
{
	template<typename T>
	class List
	{
	public:
		List();
		~List();
		bool empty();
		void insert( T* item);
		void remove( T* item);
		int size();

		struct ListEntry{
			T *data;
			ListEntry *next;
			ListEntry *prev;
		};

		ListEntry* getHead() {return head;}

	private:
		ListEntry *head;
		ListEntry *tail;
			
	};

	
	template<typename T>
	inline List<T>::List()
	{
		head = tail = NULL;
	}
	
	template<typename T>
	inline List<T>::~List()
	{
		if (empty())
			return;
		while(head != tail) {
			ListEntry *temp = head;
			head = head->next;
			fyj_free(temp->data);
		}
	}
#if 0
	template<typename T>
	List<T>::ListEntry* List<T>::getHead()
	{
		return head;
	}
#endif
	template<typename T>
	inline int List<T>::size()
	{
		ListEntry *temp = head;
		int n = 0;
	
		while(temp != NULL) {
			temp = temp->next;
			n++;
		}
	}
	
	
	template<typename T>
	inline bool List<T>::empty()
	{
		return head == NULL;
	}
	
	template<typename T>
	inline void List<T>::insert( T* data)
	{
		ListEntry *temp = head;
		while(temp != NULL) {
			if (temp->data == data)
				return ;
			temp = temp->next;
		}
	
		temp = (ListEntry*)fyj_malloc(sizeof(ListEntry));
		CHECK_POINTER(temp);
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
	
		if (head == NULL) {
			head = temp;
			tail = temp;
			return ;
		}
		
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	
	template<typename T>
	inline void List<T>::remove( T* data)
	{
		ListEntry *temp = head;
		while(temp != NULL) {
			if (temp->data == data)
				break;
			temp = temp->next;
		}
	
		if (temp == NULL)
			return;
	
		if (temp->prev != NULL)
			temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
		if (temp == head)
			head = temp->next;
		if (temp == tail)
			tail = temp->prev;
		fyj_free(temp);
	}
}

#endif
