#!/bin/sh
mkdir -p ./bin
__exists__() { test -f /bin/$1 || test -f /usr/bin/$1;}
if __exists__ gcc; then
	compiler=gcc
elif __exists__ clang; then
	compiler=clang
else
	echo 'No gcc or clang available in /bin/'
	echo 'Compile source files manually in ./src'
	exit 1
fi
src=$(find ./src -name '*.c')
echo 'Compiling...'
for file in $src; do
	$compiler -O3 -flto $(realpath $file) -o ./bin/$(basename ${file%.*}) &
done
wait
echo 'Done!'
