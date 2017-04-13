################################################################################
# Matt Noblett
# Ben Commet
# Shift Lines Bash Script
################################################################################
#!/bin/bash

#Check for required arugment
if [ $# -ne 1 ]
then
    echo "File argument required"
    exit 1
fi

#Varible for number of input lines
NUM_IN_LINES=0

#Look through input lines
while read line
do
    NUM_IN_LINES=$((NUM_IN_LINES+1))
    l=$line
    original="$l"
    #Perform all rotations for each line
    while true
    do
        rest=${l##* }
        front=${l% *}
        l="$rest $front"
        echo $l
        case "$l" in
            "$original") break;;
        esac
    done
    #Allow variable to be used in outside scripts
    export -p NUM_IN_LINES
done < $*
