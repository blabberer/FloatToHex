#include <engextcpp.hpp>
union FloatToChar {
    float           flt;
    unsigned char   fltc[4];
};
union DoubleToChar {
    double          dbl;
    unsigned char   dblc[8];
};
class EXT_CLASS : public ExtExtension
{
public:
    EXT_COMMAND_METHOD(toh);
    EXT_COMMAND_METHOD(f2h);
    EXT_COMMAND_METHOD(d2h);
};
EXT_DECLARE_GLOBALS();
EXT_COMMAND(
    toh,
    "Converts both 32 bit Float and 64 bit Double to HexString",
    "{{opt:+:}}{;s;<float>;example usage !toh 9.2 will return 41133333 and 4022666666666666}"
    )
{
    f2h();
    d2h();
}
EXT_COMMAND(
    f2h,
    "Converts Float to HexString",
    "{{opt:+:}}{;s;<float>;example usage !f2h 9.2 will return 41133333}"
    )
{
    PCSTR arg = GetUnnamedArgStr(0);
    char *endptr;
    double in = strtod(arg,&endptr);
    FloatToChar inflt;
    inflt.flt = (float)in;
    Out(
        "%-30s%02X%02X%02X%02X\n",
        "32_Bit_Float",
        inflt.fltc[3],
        inflt.fltc[2],
        inflt.fltc[1],
        inflt.fltc[0]
    );
}
EXT_COMMAND(
    d2h,
    "Converts DoubleTohexString",
    "{{opt:+:}}{;s;<float>;example usage !d2h 9.2 will return 4022666666666666}"
    )
{
    PCSTR arg = GetUnnamedArgStr(0);
    char *endptr;
    double in = strtod(arg,&endptr);
    DoubleToChar indbl;
    indbl.dbl = (double)in;
    Out(
        "%-30s%02X%02X%02X%02X%02X%02X%02X%02X\n",
        "64_Bit_Double",
        indbl.dblc[7],
        indbl.dblc[6],
        indbl.dblc[5],
        indbl.dblc[4],
        indbl.dblc[3],
        indbl.dblc[2],
        indbl.dblc[1],
        indbl.dblc[0]
    );
}