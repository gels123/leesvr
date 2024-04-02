#!/bin/bash

echo "==== codegen begin===="
protoc="./libs/phxrpc/third_party/protobuf/bin/protoc"
srcDir="./game/proto"
destDir="./game/proto/gen"

$protoc -I=$srcDir $srcDir/test.proto --cpp_out=$destDir

echo "==== codegen end===="