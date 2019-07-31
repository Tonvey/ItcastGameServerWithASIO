#/bin/bash
curPath=$(cd `dirname $0`; pwd)
pushd "$curPath" > /dev/null
#产生protoc文件
protoc --cpp_out=./ ./proto/msg.proto
if [ ! -d "$curPath/build" ]
then
    mkdir -p "$curPath/build"
fi
pushd "$curPath/build"
if [ "$curPath/CMakeLists.txt" -nt Makefile ]
then
    cmake .. || exit 1
fi
make
