#include <retesteth/configs/Options.h>
#include <string>
using namespace std;
using namespace dataobject;

const string default_London_config = R"({
    "params" : {
       "homesteadForkBlock" : "0x00",
       "EIP150ForkBlock" : "0x00",
       "EIP158ForkBlock" : "0x00",
       "byzantiumForkBlock" : "0x00",
       "constantinopleForkBlock" : "0x00",
       "constantinopleFixForkBlock" : "0x00",
       "istanbulForkBlock" : "0x00",
       "berlinForkBlock" : "0x00",
       "eip1559ForkBlock" : "0x00",
       "chainID" : "0x01"
    },
    "accounts" : {
    }
})";

const string t8ntool_London_config = R"({
    "params" : {
        "fork" : "YOLOv3",
        "constantinopleForkBlock" : "0x00",
        "byzantiumForkBlock" : "0x00",
        "homesteadForkBlock" : "0x00"
    },
    "accounts" : {
    }
})";

genLondonCfg::genLondonCfg()
{
    DataObject obj;
    obj["path"] = "besu/genesis/London.json";
    obj["content"] = default_Berlin_config;
    map_configs.addArrayObject(obj);

    DataObject obj2;
    obj2["path"] = "default/genesis/London.json";
    obj2["content"] = t8ntool_London_config;
    map_configs.addArrayObject(obj2);
}
