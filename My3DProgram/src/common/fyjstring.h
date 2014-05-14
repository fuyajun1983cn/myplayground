#ifndef FYJSTRING_H
#define FYJSTRING_H

#include "fyjstd.h"

namespace FYJ
{
	/**
	  *  Platform independent class for strings
	  */
	  class FYJ_API String
	  {
	  	public:
			String();
			String(const char *str);
			String(const String &str);
			~String();
			size_t length();
			uint8 &operator[](int i);
			String& operator =(const String &str);
			String& operator =(const uint8 *str);
			String& operator +=(const String &str);
			bool operator ==(const String &str) const;
			bool operator ==(const uint8 *str) const;
			const uint8 &operator[] (int i) const;
			bool empty () const { return m_size == 0; }
			char *c_str ();
			const char *c_str () const;
			void push_back (const uint8 c);


			friend FYJ_API String operator +(const char *str1, const String &str2);
			friend FYJ_API String operator +(const String& str1, const char *str2);
			friend FYJ_API String operator +(const String& str1, const String& str2);

			static void tolower(char *str);
			void tolower();
			int toInt();
			static int toInt(char *str);

		private:
			String (const int initsize);

			size_t m_size;
			uint8 *m_data;
	  };
}

#endif
