#!/bin/tcsh

set total = 0
set average = 0



#if ($# == 0) then
  #echo "no command-line arguments"
  # endif
  # if($#argv > 0) then
    # echo "one or more command line arguments"
    # endif

    set num = 0
    echo -n "Enter a number: "
    set num = "$<"

    echo -n "Enter some numbers into an array:"
    set list = ($<)
    if($#list > 0 && $#list < 8) then
    set max = $list[1]
    foreach t($list)
      if($max < $t) then
        @ max = $t
      endif
    end
    echo "This is the biggest number in the list: $max"

    foreach i($list)
      @ total = $total + $i
    end
    @ average = $total / $#list

    echo "Total of the arguments $total"
    echo "This is the average of the list: $average"
  else
    echo "Incorrect number of command line arguments"
  endif
