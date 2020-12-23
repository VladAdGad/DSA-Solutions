FROM ubuntu:21.04

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update --yes
RUN apt-get upgrade --yes

RUN apt-get install --yes \
    python3-pip

RUN apt-get install --yes \
    clang-tidy \
    clang-format \
    cppcheck \
    valgrind

COPY requirements.txt .
RUN pip3 install --requirement requirements.txt
