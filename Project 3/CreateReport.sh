################################################################################
# Matt Noblett
# Ben Commet
# Create Report Bash Script
################################################################################
#!/bin/bash

#Check for required arguments
if [ $# -ne 1 ]
then
    echo "Error: missing output destination"
fi

#Set variable for output count
COUNT=0

#Look through input and count lines
while read -r line
do
    COUNT=$((COUNT+1))
    echo $line
done  > $1

#Output the report
echo "The number of lines in input file: $numLines"
echo "The number of lines in output file: $COUNT"
