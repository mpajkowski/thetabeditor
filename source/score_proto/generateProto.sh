#!/bin/bash

cd proto;

for proto_file in $(ls *.proto) ; do
  protoc --cpp_out="../gen" $proto_file;
done

cd - > /dev/null 2>&1


