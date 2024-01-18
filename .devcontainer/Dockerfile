FROM ubuntu:22.04

RUN apt update;\
    apt install --yes software-properties-common; \
    apt update

RUN DEBIAN_FRONTEND=noninteractive apt install --yes \
        build-essential \
        ccache \
        clang-15 \
        mingw-w64 \
        mingw-w64-tools \
        ninja-build \
        wget \
        git


ARG CMAKE_VERSION=3.27.9
ARG CMAKE_INSTALL_DIR=/opt/cmake-$CMAKE_VERSION
ARG OPENSSL_VERSION=OpenSSL_1_1_1g
ARG USERNAME=app
ARG USER_UID=1000
ARG USER_GID=$USER_UID


RUN wget --output-document=/tmp/cmake.sh https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh \
    && mkdir --parents "$CMAKE_INSTALL_DIR" \
    && sh /tmp/cmake.sh --skip-license --prefix="$CMAKE_INSTALL_DIR" \
    && ln --symbolic --force "$CMAKE_INSTALL_DIR/bin/cmake" /usr/local/bin/cmake


RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install --yes sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME
WORKDIR /home/$USERNAME
