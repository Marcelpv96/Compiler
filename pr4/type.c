#include "global.h"

Type mkfun(Type args, Type result)
{ Type type = (Type)malloc(strlen(args) + strlen(result) + 3);
  if (!type)
    error("Out of memory");
  sprintf((char*)type, "(%s)%s", args, result);
  return type;
}

Type mkpair(Type type1, Type type2)
{ Type type = (Type)malloc(strlen(type1) + strlen(type2) + 1);
  if (!type)
    error("Out of memory");
  strcpy((char*)type, type1);
  strcat((char*)type, type2);
  return type;
}

Type mkvoid()
{ return "V";
}

Type mkint()
{ return "I";
}

Type mkchar()
{ return "C";
}

Type mkstr()
{ return "Ljava/lang/String;";
}

Type mkfloat()
{ return "F";
}

Type mkret(Type type)
{ const char *s;
  if (type)
  { s = strrchr(type, ')');
    if (s)
      return s + 1;
  }
  return NULL;
}

int isvoid(Type type)
{ return type && !strcmp(type, "V");
}

int isint(Type type)
{ return type && !strcmp(type, "I");
}

int isfloat(Type type)
{ return type && !strcmp(type, "F");
}

int ischar(Type type)
{ return type && !strcmp(type, "C");
}

int isstr(Type type)
{ return type && !strcmp(type, "Ljava/lang/String;");
}

int iseq(Type type1, Type type2)
{ return type1 && type2 && !strcmp(type1, type2);
}
