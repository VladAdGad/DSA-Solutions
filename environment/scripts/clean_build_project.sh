#!/usr/bin/env bash
set -eu

build_folder=${1:-build}

rm --recursive --force "${build_folder}"
mkdir "${build_folder}"

pushd "${build_folder}"
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
ninja

popd
