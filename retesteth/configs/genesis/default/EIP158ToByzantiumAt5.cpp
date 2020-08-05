#include <retesteth/configs/Options.h>
#include <string>
using namespace std;
using namespace dataobject;

const string default_EIP158ToByzantiumAt5_config = R"({
    "params" : {
        "homesteadForkBlock" : "0x00",
        "EIP150ForkBlock" : "0x00",
        "EIP158ForkBlock" : "0x00",
        "byzantiumForkBlock" : "0x05"
    },
    "accounts" : {
    }
})";

const string t8ntool_EIP158ToByzantiumAt5_config = R"({
    "params" : {
        "fork" : "EIP158ToByzantiumAt5",
        "byzantiumForkBlock" : "0x05",
        "homesteadForkBlock" : "0x00"
    },
    "accounts" : {
    }
})";

genEIP158ToByzantiumCfg::genEIP158ToByzantiumCfg()
{
    DataObject obj;
    obj["path"] = "default/genesis/EIP158ToByzantiumAt5.json";
    obj["content"] = default_EIP158ToByzantiumAt5_config;
    map_configs.addArrayObject(obj);

    DataObject obj2;
    obj2["path"] = "t8ntool/genesis/EIP158ToByzantiumAt5.json";
    obj2["content"] = t8ntool_EIP158ToByzantiumAt5_config;
    map_configs.addArrayObject(obj2);
}
