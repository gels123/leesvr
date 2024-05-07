#!/bin/bash

protoc="./3rd/protobuf/bin/protoc"
srcdir="./game/proto"
destdir="./game/proto/cpp"

echo "==== gen code start ===="
set -e  # exit immediately on error
set -x  # display all commands

$protoc -I=$srcdir $srcdir/test.proto --cpp_out=$destdir

set +x  # cancel display all commands
echo "==== gen code success ===="