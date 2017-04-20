################################################################################
# Matt Noblett
# Ben Commet
# Filter Noise Bash Script
################################################################################
#!/bin/bash

#Check for required command line arugments
if [ $# -ne 1 ]
then
    echo "Error: missing command line argument"
    exit 1
fi

noiseArray=()
input="noise.txt"
while IFS= read -r word
do
  noiseArray+=("${word}")
done<"$1"



#Read in standard output from last script as input

while read -r line;
do
    set $line
    front=$1
    isNoise=false
    for i in "${noiseArray[@]}"
    do
      if [ "${i}" == "${front}" ]
      then
        isNoise=true
      fi
    done
    if [ $isNoise == false ]
    then
      echo $line
    fi
done
