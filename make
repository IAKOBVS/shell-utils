#!/bin/sh
mkdir -p ./bin
if [ -s /bin/gcc ]; then
	compiler=gcc
elif [ -s /bin/clang ]; then
	compiler=clang
else
	echo 'No gcc or clang available in /bin/'
	echo 'Compile source files manually in ./src'
	exit 1
fi
cleanext() { echo "$1" | sed 's/\.[^.]*$//';}
src=$(find ./src -name '*.c')
echo 'Compiling...'
for file in $src; do
	$compiler -O3 -flto $(realpath $file) -o ./bin/$(cleanext $(basename $file)) &
done
wait
echo 'Done!'
