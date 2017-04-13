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

#Read in standard output from last script as input
sleep 5
while read -r line
do
    set $line
    front=$1
    #Look through noise words and output line if
    #doesn't contain a noise word
    while read noise
    do
        case "$1" in
            *$noise*)
                continue
            ;;
            *)
                echo $line
            ;;
        esac
    done
done < $*
