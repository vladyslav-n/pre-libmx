#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c)
{
    char buf[5] = {'\0', '\0', '\0', '\0', '\0'};
  if (c <= 0x7F) {
    // Plain ASCII
    buf[0] = (char) c;
    buf[1] = 0;
    write(1, buf, 1);
    return;
  }
  else if (c <= 0x07FF) {
    // 2-byte unicode
    buf[0] = (char) (((c >> 6) & 0x1F) | 0xC0);
    buf[1] = (char) (((c >> 0) & 0x3F) | 0x80);
    buf[2] = 0;
    write(1, buf, 2);
    return;
  }
  else if (c <= 0xFFFF) {
    // 3-byte unicode
    buf[0] = (char) (((c >> 12) & 0x0F) | 0xE0);
    buf[1] = (char) (((c >>  6) & 0x3F) | 0x80);
    buf[2] = (char) (((c >>  0) & 0x3F) | 0x80);
    buf[3] = 0;
    write(1, buf, 3);
    return;
  }
  else if (c <= 0x10FFFF) {
    // 4-byte unicode
    buf[0] = (char) (((c >> 18) & 0x07) | 0xF0);
    buf[1] = (char) (((c >> 12) & 0x3F) | 0x80);
    buf[2] = (char) (((c >>  6) & 0x3F) | 0x80);
    buf[3] = (char) (((c >>  0) & 0x3F) | 0x80);
    buf[4] = 0;
    write(1, buf, 4);
    return;
  }
  else 
    return;
}

