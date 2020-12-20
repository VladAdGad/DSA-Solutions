#!/usr/bin/env bash
set -eu

pushd "${1:-build}"
jq 'del(.[] | select(.command == ""))' compile_commands.json | sponge compile_commands.json
jq 'del(.[] | select(.command | contains(": && /usr/bin/c++")))' compile_commands.json | sponge compile_commands.json
jq 'del(.[] | select(.command | contains("--regenerate-during-build")))' compile_commands.json | sponge compile_commands.json
popd
