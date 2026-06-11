#!/bin/env bash
# gostou? me contrata!
humam=$(whoami)
if [[ $humam != "root" ]]; then
    echo "Você é root?"
    exit 1
fi
echo "(!)---> DIRSEC v0.1 by: felipe unix <---(!)"
echo -n "key: "
read key
echo -n "0 = encripta/1 = decripta: "
read fun
echo -n "dir: "
read direc
ls $direc > filesList.txt
files=$(cat filesList.txt)
for f in $files; do
    # out => argv[1]; key => argv[2]; fun => argv[3];
    /opt/dirSec/dirSec.bin $f $key $fun
    rm $f
done
echo "Obrigado por usar tecnologia Kernel Panic Cybers Team :)"