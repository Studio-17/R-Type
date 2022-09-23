# Dockerfile for Clement's MacBook : )
FROM ubuntu:latest

WORKDIR /home/r-type/

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    pkg-config \
    clang \
    cmake \
    gdb \
    wget \
    python3-pip \
    libboost-all-dev \
    curl \
    libgl-dev \
    libxcb-randr0-dev \
    libxcb-xtest0-dev \
    libxcb-xinerama0-dev \
    libxcb-shape0-dev \
    libxcb-xkb-dev

RUN pip3 install conan

COPY . .

RUN conan profile new --detect .github/files/default

RUN conan install .. --build=missing -c tools.system.package_manager:mode=install
