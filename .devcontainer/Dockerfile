# Base image
FROM ubuntu:24.04

# Avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Fix sudo install issue (ensure docs dir exists)
RUN mkdir -p /usr/share/doc/sudo

# Install dependencies as root
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    pkg-config \
    xorg-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    mesa-utils \
    libglfw3-dev \
    libglew-dev \
    libglm-dev \
    libx11-dev \
    libxi-dev \
    libxxf86vm-dev \
    libxrandr-dev \
    libxinerama-dev \
    sudo \
 && rm -rf /var/lib/apt/lists/*

# Create non-root user (VS Code default)
ARG USERNAME=ubuntu

# ✅ Fix permissions for workspace
RUN mkdir -p /workspaces/EngineEngine \
    && chown -R ${USERNAME}:${USERNAME} /workspaces

# Switch to non-root user
USER $USERNAME

# Default workdir
WORKDIR /workspaces/EngineEngine

# Default shell
SHELL ["/bin/bash", "-c"]
