#include "main.h"
#include "stdarg.h"
#include "stdlib.h"

/**
 * _printf - printf model
 * @fmt: named argument string
 * return: 0;
 */

int _printf(char *fmt, ...)
{
	char *p = fmt;
	char *s;
	int t;
	va_list ap;

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			_print(*p);
			continue;
		}
		switch (*++p)
		{
			case 's':
				s = va_arg(ap, char *);
				while (*s)
				{
					_print(*s);
					s++;
				}
				*s++ = '\0';
				break;
			default:
				_print(*p);
		}
	}
	va_end(ap);
	t = p - fmt;
	return (t);
}
