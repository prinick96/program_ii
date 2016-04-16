#include "headers/core.h"

void explode(char ***arr_ptr, char *str, char delimiter)
{
  char *src = str, *end, *dst;
  char **arr;
  int size = 1, i;

  while ((end = strchr(src, delimiter)) != NULL)
    {
      ++size;
      src = end + 1;
    }

  arr = malloc(size * sizeof(char *) + (strlen(str) + 1) * sizeof(char));

  src = str;
  dst = (char *) arr + size * sizeof(char *);
  for (i = 0; i < size; ++i)
    {
      if ((end = strchr(src, delimiter)) == NULL)
        end = src + strlen(src);
      arr[i] = dst;
      strncpy(dst, src, end - src);
      dst[end - src] = '\0';
      dst += end - src + 1;
      src = end + 1;
    }
  *arr_ptr = arr;
}
