
set -e  # exit immediately on error
set -x  # display all commands

mkdir -p 3rd
mkdir -p 3rd/protobuf
dir=`pwd`/3rd/protobuf
cd ${dir}

if [ ! -f bin/protoc ]; then
	if [ ! -f protobuf-cpp-3.0.0.tar.gz ]; then
	  wget https://github.com/google/protobuf/releases/download/v3.0.0/protobuf-cpp-3.0.0.tar.gz
	fi

	tar -zxvf protobuf-cpp-3.0.0.tar.gz
	cd protobuf-3.0.0
	./configure --prefix=${dir}
	make -j2
	make install
	cd ..
	rm -rf protobuf-3.0.0
fi

exit $?
