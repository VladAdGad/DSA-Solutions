#!/usr/bin/env bash
set -eu

pushd "${1:-build}"
ninja -t compdb >compile_commands.json
popd
