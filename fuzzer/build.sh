#!/bin/bash -eu

compile() {

   cd build/
   make -j"$(nproc)"

}

build() {

   export CFLAGS="$1"
   export CXXFLAGS="$1"
   export LIB_FUZZING_ENGINE=-fsanitize=fuzzer

   # echo CC="${CC}"
   # echo CXX="${CXX}"
   # echo CFLAGS="${CFLAGS}"
   # echo CXXFLAGS="${CXXFLAGS}"

   rm -rf build
   mkdir -p build
   cd build/

   cmake --fresh -DFUZZER=ON -DLIB_FUZZING_ENGINE="$LIB_FUZZING_ENGINE" ../../.
   make -j"$(nproc)"

   cd fuzzer/

   mkdir FuzzIxml_corpus
   mkdir FuzzIxml_seed_corpus

   cp ../../../ixml/test/testdata/empty_attribute.xml FuzzIxml_seed_corpus/
   cp ../../../ixml/test/testdata/p43pass1.xml FuzzIxml_seed_corpus/
   cp ../../../ixml/test/testdata/xml.ascc.net/wf/zh-utf8-8.xml FuzzIxml_seed_corpus/
   cp ../../../ixml/test/testdata/xml.ascc.net/wfns/zh-utf8-7.xml FuzzIxml_seed_corpus/
   cp ../../../ixml/test/testdata/xmlconf/014.xml FuzzIxml_seed_corpus/
}

run() {
   DIR=build/fuzzer
   #./$DIR/FuzzIxml $DIR/FuzzIxml_corpus/ $DIR/FuzzIxml_seed_corpus/ -detect_leaks=0
   ./$DIR/FuzzIxml $DIR/FuzzIxml_corpus/ $DIR/FuzzIxml_seed_corpus/
}

usage() {
   echo "usage: $0 ASan | UBSan | MSan | Run | compile"
}

export CC=clang
export CXX=clang++

if [ $# -eq 0 ]; then
   echo "Error: No arguments supplied"
   usage
   exit 1
fi

if [ "$1" == "ASan" ]; then
   build "-g -O0 -fno-omit-frame-pointer -gline-tables-only -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION -fsanitize=address -fsanitize-address-use-after-scope -fsanitize=fuzzer-no-link"
elif [ "$1" == "UBSan" ]; then
   build "-g -O0 -fno-omit-frame-pointer -gline-tables-only -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION \
   -fsanitize=address,array-bounds,bool,builtin,enum,float-divide-by-zero,function,integer-divide-by-zero,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,unsigned-integer-overflow,unreachable,vla-bound,vptr \
   -fno-sanitize-recover=array-bounds,bool,builtin,enum,float-divide-by-zero,function,integer-divide-by-zero,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,unreachable,vla-bound,vptr -fsanitize=fuzzer-no-link"
elif [ "$1" == "MSan" ]; then
   build "-g -O0 -fno-omit-frame-pointer -gline-tables-only -DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION -fsanitize=memory -fsanitize-memory-track-origins -fsanitize=fuzzer-no-link"
elif [ "$1" == "Run" ]; then
   run
elif [ "$1" == "compile" ]; then
   compile
else
   echo "Error: Wrong arguments supplied"
   usage
fi
