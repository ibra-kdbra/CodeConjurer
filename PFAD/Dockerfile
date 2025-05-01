# Dockerfile
FROM ubuntu:jammy AS poc_box
LABEL builder=true

# Use Ubuntu's mirror selector for fast, reliable package archives
RUN printf '%s\n' \
    'deb mirror://mirrors.ubuntu.com/mirrors.txt jammy main restricted universe multiverse' \
    'deb mirror://mirrors.ubuntu.com/mirrors.txt jammy-updates main restricted universe multiverse' \
    'deb mirror://mirrors.ubuntu.com/mirrors.txt jammy-security main restricted universe multiverse' \
    'deb mirror://mirrors.ubuntu.com/mirrors.txt jammy-backports main restricted universe multiverse' \
  > /etc/apt/sources.list

ARG LINUX_TYPE_ID=debian
ENV LINUX_TYPE_ID=$LINUX_TYPE_ID \
    DEBIAN_FRONTEND=noninteractive

# Install build tools and dependencies
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
      pkg-config \
      git \
      curl \
      wget \
      gcc \
      g++ \
      cmake \
      make \
      gdb \
      libcapstone-dev \
 && rm -rf /var/lib/apt/lists/*

# Install libelfin from source
RUN git clone https://github.com/aclements/libelfin.git /libelfin \
 && cd /libelfin \
 && make PREFIX=/usr \
 && make PREFIX=/usr install
