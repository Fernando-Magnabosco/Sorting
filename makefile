

cpl = gcc
flags = -Wall -Ofast

array:
	$(cpl) -c array_utilities.c $(flags)

bogo:
	$(cpl) bogo.c array_utilities.o -o bogo.o $(flags)

bubble:
	$(cpl) bubble.c array_utilities.o -o bubble.o $(flags)

counting:
	$(cpl) counting.c array_utilities.o -o counting.o $(flags)

merge:
	$(cpl) merge.c array_utilities.o -o merge.o $(flags)

radix_2:
	$(cpl) radix_2.c array_utilities.o -o radix_2.o $(flags)

radix_10:
	$(cpl) radix_10.c array_utilities.o -o radix_10.o $(flags)

selection:
	$(cpl) selection.c array_utilities.o -o selection.o $(flags)

