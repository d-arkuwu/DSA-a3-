#pragma once
#pragma once
class Helper
{
public:
	static int stringLength(const char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			++i;
		}
		return i;
	}
	static void stringCopy(char*& dest, const char*& source)
	{
		int length = stringLength(source);
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = source[i];
		}
		dest[length] = '\0';
	}
	static void stringCopy(char*& dest, char* const source)
	{
		int length = stringLength(source);
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = source[i];
		}
		dest[length] = '\0';
	}
	static int compareString(char* s1, char* s2)
	{
		int length = Helper::stringLength(s1);
		for (int i = 0; i < length; i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	static int compareString(char* s1, const char* s2)
	{
		int length = Helper::stringLength(s1);
		for (int i = 0; i < length; i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
			}
		}
		return 1;
	}
};