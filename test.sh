#!/bin/bash

for i in {1..20}; do
	ARG="$(ruby -e "puts (1..20).to_a.shuffle.join(' ')")"
	./push_swap $ARG | wc -l | xargs
	./push_swap $ARG | ./checker $ARG
	echo ""
done
