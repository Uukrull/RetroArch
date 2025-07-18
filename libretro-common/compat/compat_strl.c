/* Copyright  (C) 2010-2020 The RetroArch team
 *
 * ---------------------------------------------------------------------------------------
 * The following license statement only applies to this file (compat_strl.c).
 * ---------------------------------------------------------------------------------------
 *
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Implementation of strlcpy()/strlcat() based on OpenBSD. */

#ifndef __MACH__
#include <stdlib.h>
#include <ctype.h>

#include <compat/strl.h>

size_t strlcpy(char *s, const char *src, size_t len)
{
   size_t i, _len = 0, __len;
   while (src[_len] != '\0')
      _len++;
   if (len == 0)
      return _len;
   __len = (_len >= len) ? len - 1 : _len;
   for (i = 0; i < __len; i++)
      s[i] = src[i];
   s[__len] = '\0';
   return _len;
}

size_t strlcat(char *s, const char *source, size_t len)
{
   size_t _len = strlen(s);
   s += _len;
   if (_len > len)
      len = 0;
   else
      len -= _len;
   return _len + strlcpy(s, source, len);
}
#endif