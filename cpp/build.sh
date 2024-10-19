#!/bin/bash

BASE_DIR=$( cd $( dirname $0 ) ; pwd )

cd $BASE_DIR
mkdir build

cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/tmp/local
cmake --build .

echo "Exec ctest"
