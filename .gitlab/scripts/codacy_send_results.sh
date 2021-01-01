#!/usr/bin/env bash
set -eu

./codacy-clang-tidy-"${CODACY_CLANG_TIDY_VERSION}" |
  curl -XPOST --location --header "project-token: ${CODACY_PROJECT_TOKEN}" \
    --header "Content-type: application/json" -d @- \
    "${CODACY_URL}/2.0/commit/${CI_COMMIT_SHA}/issuesRemoteResults"

curl -XPOST --location --header "project-token: ${CODACY_PROJECT_TOKEN}" \
  --header "Content-type: application/json" \
  "${CODACY_URL}/2.0/commit/${CI_COMMIT_SHA}/resultsFinal"
