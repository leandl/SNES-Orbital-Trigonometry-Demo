FROM ubuntu:latest

# Atualiza o sistema e instala dependências
RUN apt-get update && apt-get install -y \
    build-essential \
    make \
    wget \
    unzip \
    git \
    libpng-dev \
    && rm -rf /var/lib/apt/lists/*

# Define o diretório de trabalho
WORKDIR /opt

# Baixa e instala o PVSnesLib
RUN wget https://github.com/alekmaul/pvsneslib/releases/download/4.4.0/pvsneslib_440_64b_linux.zip \
    && unzip pvsneslib_440_64b_linux.zip \
    && rm pvsneslib_440_64b_linux.zip

# Define a variável de ambiente para o PVSnesLib
ENV PVSNESLIB_HOME=/opt/pvsneslib
ENV PATH="$PVSNESLIB_HOME/bin:$PATH"

# Define o diretório de trabalho para o desenvolvimento
WORKDIR /opt/snesdev
