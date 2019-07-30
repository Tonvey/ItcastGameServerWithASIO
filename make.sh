#/bin/bash
curPath=$(cd `dirname $0`; pwd)
if [ ! -d "$curPath/build" ]
then
    mkdir -p "$curPath/build"
fi
pushd "$curPath/build"
cmake .. || exit 1
make
