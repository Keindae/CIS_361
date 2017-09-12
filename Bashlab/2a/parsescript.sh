#!/bin/bash

filename='classes.txt'
echo start


while read class proj p; do
  echo ${class}
done < classes.txt
