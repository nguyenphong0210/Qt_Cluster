#ifndef DATADEF_H
#define DATADEF_H
#include <bitset>

enum DataType
{
    DataInvalid,
    SpeedValue,
    SpeedValue1,
    SpeedValue2,
    SpeedValue3,
    SpeedValue4,
    SpeedValue5,
    DataUpdateTypeMax, // Max
};

typedef struct
{
    DataType DataName;
    int DataValue;
} DataModelStruct;

typedef std::bitset<DataUpdateTypeMax> DataUpdateKinds;

#endif
