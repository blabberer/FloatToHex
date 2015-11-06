#include <engextcpp.hpp>
class EXT_CLASS : public ExtExtension {
public:
    EXT_COMMAND_METHOD(f2h);
};
EXT_DECLARE_GLOBALS();
EXT_COMMAND(f2h,"Float to Hex Convertor","{;s;<float>;example usage !f2h 9.2 will return 41133333}")
{
  PCSTR arg = GetUnnamedArgStr(0);
  char *endptr;
  double in = strtod(arg,&endptr);
  union FloatToChar 
  {
    float f;
    unsigned char  c[4];
  };
  FloatToChar x;
  x.f = (float)in;
  Out( "%02X%02X%02X%02X\n", x.c[3], x.c[2], x.c[1], x.c[0] );
}