FROM ubuntu:20.04

SHELL ["/bin/bash", "-c"]
RUN echo I am now using bash!

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update --yes
RUN apt-get upgrade --yes

RUN apt-get install --yes \
    build-essential \
    clang \
    clang-format \
    clang-tidy \
    cppcheck \
    curl \
    g++ \
    gcc \
    gdb \
    rsync \
    valgrind \
    wget

RUN apt-get install --yes python3-pip
COPY requirements.txt .
RUN pip3 install --requirement requirements.txt

RUN apt-get install --yes ccache &&\
    /usr/sbin/update-ccache-symlinks
ENV PATH "/usr/lib/ccache:${PATH}"

RUN LCOV_VERSION=1.15 &&\
    wget --continue https://github.com/linux-test-project/lcov/archive/v${LCOV_VERSION}.tar.gz --output-document - | tar --extract --ungzip &&\
    pushd lcov-${LCOV_VERSION} &&\
    make install &&\
    popd &&\
    rm --recursive --force lcov-${LCOV_VERSION}

RUN apt-get install --yes ssh &&\
    echo "root:q1W@q1W@" | chpasswd &&\
    sed --in-place "/^#PermitRootLogin prohibit-password/c\PermitRootLogin yes" "/etc/ssh/sshd_config"
EXPOSE 22

ENTRYPOINT service ssh start && bash

#docker build --tag leetcode-solutions .
#docker run --name leetcode-solutions --tty --detach --publish=2222:22 --restart=always --cap-add=SYS_PTRACE leetcode-solutions
