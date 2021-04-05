#include <retesteth/configs/Options.h>
using namespace std;
using namespace dataobject;

string const besu_config = R"({
    "name" : "Hyperledger Besu on TCP",
    "socketType" : "tcp",
    "socketAddress" : [
        "127.0.0.1:47710",
        "127.0.0.1:47711",
        "127.0.0.1:47712",
        "127.0.0.1:47713"
        "127.0.0.1:47714",
        "127.0.0.1:47715",
        "127.0.0.1:47716",
        "127.0.0.1:47717"
    ],
    "initializeTime" : "5",
    "forks" : [
        "Frontier",
        "Homestead",
        "EIP150",
        "EIP158",
        "Byzantium",
        "Constantinople",
        "ConstantinopleFix",
        "Istanbul",
        "Berlin",
        "London",
    ],
    "additionalForks" : [
        "FrontierToHomesteadAt5",
        "HomesteadToEIP150At5",
        "EIP158ToByzantiumAt5",
        "HomesteadToDaoAt5",
        "ByzantiumToConstantinopleFixAt5"
    ],
    "exceptions" : {
        "ExtraDataTooBig" : "extra-data too long",
        "InvalidDifficulty" : "invalid difficulty"
    }
})";

string const besu_start = R"(#!/bin/sh
threads=1
if [ "${1:-0}" -gt 1 ]
then
    threads=$1
fi

i=0
while [ "$i" -lt $threads ]; do
    tmpdir=$(mktemp -d -t ci-XXXXXXXXXX)
    besu --Xberlin-enabled true retesteth --rpc-http-port $((47710+$i)) --data-path=$tmpdir &
    i=$(( i + 1 ))
done
)";

string const besu_stop = R"(#!/bin/sh
killall -9 java
)";

besucfg::besucfg()
{
    {
        DataObject obj;
        obj["path"] = "besu/config";
        obj["content"] = besu_config;
        map_configs.addArrayObject(obj);
    }
    {
        DataObject obj;
        obj["exec"] = true;
        obj["path"] = "besu/start.sh";
        obj["content"] = besu_start;
        map_configs.addArrayObject(obj);
    }
    {
        DataObject obj;
        obj["exec"] = true;
        obj["path"] = "besu/stop.sh";
        obj["content"] = besu_stop;
        map_configs.addArrayObject(obj);
    }
}
