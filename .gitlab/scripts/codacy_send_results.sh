#!/usr/bin/env bash
set -eux

./codacy-clang-tidy-${CODACY_CLANG_TIDY_VERSION} |
  curl -XPOST -L -H "project-token: ${CODACY_PROJECT_TOKEN}" \
    -H "Content-type: application/json" -d @- \
    "https://api.codacy.com/2.0/commit/${CI_COMMIT_REF_NAME}/issuesRemoteResults"

curl -XPOST -L -H "project-token: ${CODACY_PROJECT_TOKEN}" \
  -H "Content-type: application/json" \
  "https://api.codacy.com/2.0/commit/${CI_COMMIT_REF_NAME}/resultsFinal"
