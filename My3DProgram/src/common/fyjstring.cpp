#include "fyjstring.h"

using namespace FYJ;

String::String()
{
	m_data = NULL;
	m_size = 0;
}

String::String(const char * str)
{
	m_data = NULL;
	m_size = 0;
	
	if (str == NULL) {
		ASSERT("pass a NULL pointer to String!");
		return;
	}

	size_t length = fyj_strlen(str);
	CHECK_POINTER(m_data = (uint8*)fyj_malloc(length+1));
	m_size = length;

	fyj_memcpy(m_data, str, length+1);
	
}

String::String(const String &str)
{
	m_size = 0;
	m_data =  NULL;

	if (!str.m_size)
	{
		CHECK_POINTER(m_data = (uint8 *) fyj_malloc (1));
		if(m_data)
		{
			m_data[0] = 0;
		}
		return;
	}
	CHECK_POINTER(m_data = (uint8 *) fyj_malloc (str.m_size + 1));
	if(m_data)
	{
		fyj_memcpy (m_data, str.m_data, str.m_size + 1);
		m_size = str.m_size;
	}
}

String::String(const int initsize)
{
	CHECK_POINTER(m_data = (uint8 *) fyj_malloc (initsize));
	m_size = initsize - 1;
}

String::~String()
{
	if (m_data != NULL)
		fyj_free(m_data);
	m_data = NULL;
	m_size = 0;
}

size_t String::length()
{
	return m_size;
}

uint8 &String::operator[](int i)
{
	if (i < 0 || i > m_size)
		ASSERT("Index Out of Array Bounds!");
	return m_data[i];
}

const uint8 &String::operator [] (int i) const
{
	if (i < 0 || i > m_size)
		ASSERT("Index Out of Array Bounds!");
	return m_data[i];
}

String& String::operator =(const String &str)
{
	if (this == &str) return *this;

	if (m_data) {
		fyj_free (m_data);
	}

	CHECK_POINTER(m_data = (uint8 *) fyj_malloc (str.m_size + 1));
	if(m_data)
	{
		fyj_memcpy (m_data, str.m_data, str.m_size + 1);
		m_size = str.m_size;
	}
	return *this;
}

String& String::operator =(const uint8 *str)
{
	size_t size = fyj_strlen ((const char *)str);
	if (!size) return *this;

	if (m_data) {
		fyj_free (m_data);
	}
	CHECK_POINTER(m_data = (uint8 *) fyj_malloc (size + 1));
	if(m_data)
	{
		fyj_memcpy (m_data, str, size + 1);
		m_size = size;
	}

	return *this;
}

String& String::operator +=(const String& str)
{
	if (!str.m_size) 
		return *this;

	uint8 *data = (uint8 *) fyj_malloc (m_size + str.m_size + 1);
	CHECK_POINTER(data);
	if(!data)
	{
		return *this;
	}

	if (m_data) 
	{
		fyj_memcpy (data, m_data, m_size);
	}

	fyj_memcpy (data + m_size, str.m_data, str.m_size);
	data[m_size + str.m_size] = '\0';
	m_size += str.m_size;
	if (m_data) {
		fyj_free (m_data);
	}
	m_data = data;

	return *this;
}

String FYJ::operator + (const char *str1, const String& str2)
{
	String s(String(str1)+str2);
	return s;
}

String FYJ::operator +(const String& str1, const char *str2)
{
	String s(str1+String(str2));
	return s;
}

String FYJ::operator +(const String& str1, const String& str2)
{
	String s = "";
	if (!(str1.m_size + str2.m_size)) return s;

	s.m_data = (uint8 *) fyj_malloc (str1.m_size + str2.m_size + 1);
	CHECK_POINTER(s.m_data);
	if(s.m_data)
	{
		fyj_memcpy (s.m_data, str1.m_data, str1.m_size);
		fyj_memcpy (s.m_data+str1.m_size, str2.m_data, str2.m_size);

		s.m_data[str1.m_size + str2.m_size] = '\0';
		s.m_size = str1.m_size + str2.m_size;
	}

	return s;
}

char *String::c_str ()
{
	return (char *) m_data;
}

const char *String::c_str () const
{
	return (const char *) m_data;
}

void String::tolower(char *str)
{
	unsigned int len=fyj_strlen(str);
	for(uint32 i=0;i<len;i++)
	{
		str[i]= ::tolower(str[i]);
	}
}

void String::tolower()
{
	for(uint32 i=0; i < m_size; i++)
	{
		m_data[i] = ::tolower(m_data[i]);
	}
}

int String::toInt()
{
	return fyj_atoi((char*)m_data);
}

int String::toInt(char *str)

{
	return fyj_atoi(str);
}

bool String::operator ==(const String &str) const
{
	if( fyj_strcmp( this->c_str(), str.c_str()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator ==(const uint8 *str) const
{
	if (fyj_strcmp(this->c_str(), (const char*)str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}