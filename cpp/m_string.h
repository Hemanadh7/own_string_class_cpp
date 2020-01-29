#include<iostream>
#include<cstring>
using namespace std;
class str
{
	private:
		char* cp;
	public:
		str();
		str(const char*);
		str(str&);
		str(const str&);
		str operator + (str&);
		char operator [] (int);
	friend ostream& operator << (ostream&, str&);
    friend istream& operator >> (istream&, str&);
    friend int m_strlen(str);
    friend int m_strcmp(const str, const str);
    friend int m_strncmp(const str, const str, int);
    friend char* m_strstr(const str, const str);
	friend char* m_strcasestr(const str, const str);
    friend char* m_strcat(str&, const str);
    friend char* m_strncat(str&, const str, int);
    friend char* m_strchr(const str, int);
    friend char* m_strrchr(const str, int);
    friend char* m_strcpy(str&, const str);
    friend char* m_strncpy(str&, const str, int);
    friend char* strrev(str&);
    friend char* strupper(str&);
    friend char* strlower(str&);
    friend char* strsort(str&);
};

str::str()
{
	cp = 0;
}

str::str(const char* s)
{
	int len = strlen(s);
	cp = new char[len];
	strcpy(cp, s);
}

str::str(str& temp)
{
	int len = strlen(temp.cp);
	cp = new char[len];
	strcpy(cp, temp.cp);
}

str::str(const str& temp)
{
	int len = strlen(temp.cp);
	cp = new char[len];
	strcpy(cp, temp.cp);
}

str str::operator + (str& obj)
{
	int tLen = strlen(cp) + strlen(obj.cp);
	char* np = new char[tLen + 1];
	strcpy(np, cp);
	strcat(np, obj.cp);
	str temp(np);
	return temp;
}

char str::operator [] (int index)
{
	return cp[index];
}

char* strsort(str& s)
{
	for(int i = 0; i < m_strlen(s); i++)
	{
		for(int j = i + 1; j < m_strlen(s); j++)
		{
			if(s[i] > s[j])
			{
				char t = s[i];
				s.cp[i] = s[j];
				s.cp[j] = t;
			}
		}
	}
}

char* strupper(str& s)
{
	for(int i = 0; i < m_strlen(s); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			s.cp[i] = s[i] ^ 32;
	}
	return s.cp;
}

char* strlower(str& s)
{
	for(int i = 0; i < m_strlen(s); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s.cp[i] = s[i] ^ 32;
	}
	return s.cp;
}

char* strrev(str& s)
{
	int i = 0, j = m_strlen(s) - 1;
	for( ; i < j; i++, j--)
	{
		char temp = s[i];
		s.cp[i] = s[j];
		s.cp[j] = temp;
	}
	return s.cp;
}

char* m_strcpy(str& dest, const str src)
{
	return strcpy(dest.cp, src.cp);
}

char* m_strncpy(str& dest, const str src, int n)
{
	return strncpy(dest.cp, src.cp, n);
}

char* m_strrchr(const str s, int c)
{
	return strrchr(s.cp, c);
}

char* m_strchr(const str s, int c)
{
	return strchr(s.cp, c);
}

int m_strncmp(const str s1, const str s2, int size)
{
	return strncmp(s1.cp, s2.cp, size);
}

char* m_strncat(str& dest, const str src, int size)
{
	return strncat(dest.cp, src.cp, size);
}

char* m_strcat(str& dest, const str src)
{
	return strcat(dest.cp, src.cp);
}

char* m_strstr(const str haystack, const str needle)
{
	return strstr(haystack.cp, needle.cp);
}

char* m_strcasestr(const str haystack, const str needle)
{
	return strcasestr(haystack.cp, needle.cp);
}

int m_strcmp(const str s1, const str s2)
{
	return strcmp(s1.cp, s2.cp);
}

int m_strlen(str s)
{
	return strlen(s.cp);
}

ostream& operator << (ostream& out, str& obj)
{
	out << obj.cp;
	return out;
}

istream& operator >> (istream& in, str& obj)
{
	FILE* fp = fopen("buffer", "w+");
	char c = 0;
	for( ; (c = getchar())!= '\n'; )
		fputc(c, fp);
	int size = ftell(fp), i;
	rewind(fp);
	obj.cp = new char[size + 1];
	for(i = 0; (c = fgetc(fp)) != EOF; i++)
		obj.cp[i] = c;
	obj.cp[i] = '\0';
	remove("buffer");
	return in;
}
