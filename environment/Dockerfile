FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update --yes
RUN apt-get upgrade --yes

RUN apt-get install --yes \
    build-essential \
    clang \
    clang-format \
    clang-tidy \
    cppcheck \
    g++ \
    gcc \
    gdb \
    rsync \
    valgrind

RUN apt-get install --yes ccache
RUN /usr/sbin/update-ccache-symlinks
ENV PATH "/usr/lib/ccache:${PATH}"

RUN apt-get install --yes python3-pip
COPY requirements.txt .
RUN pip3 install --requirement requirements.txt

RUN apt-get install --yes ssh
RUN echo "root:q1W@q1W@" | chpasswd
RUN sed --in-place "/^#PermitRootLogin prohibit-password/c\PermitRootLogin yes" "/etc/ssh/sshd_config"
EXPOSE 22

ENTRYPOINT service ssh start && bash

#docker build --tag leetcode-solutions .
#docker run --name leetcode-solutions --tty --detach --publish=2222:22 --restart=always --cap-add=SYS_PTRACE leetcode-solutions
