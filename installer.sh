#!/usr/bin/env bash
i=$(whoami)
if [[ $i != "root" ]]; then
    echo "É preciso ser root!"
    exit 1
fi
mkdir /opt/dirSec
cp dirSec.bin /opt/dirSec/
cp dirsec.sh /sbin/dirsec
chmod 755 /sbin/dirsec
echo "Instalação ok! ;)"