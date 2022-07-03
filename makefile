

cpl = gcc
flags = -Wall -Ofast

src = ./src/
dest = ./obj/

common = $(dest)array_utilities.o

array:
	$(cpl) -c $(src)array_utilities.c -o $(common) $(flags)

bogo:
	$(cpl) $(src)bogo.c $(common) -o $(dest)bogo.o $(flags)

bubble:
	$(cpl) $(src)bubble.c $(common) -o $(dest)bubble.o $(flags)

counting:
	$(cpl) $(src)counting.c $(common) -o $(dest)counting.o $(flags)

heap:
	$(cpl) $(src)heap.c $(common) -o $(dest)heap.o $(flags)

merge:
	$(cpl) $(src)merge.c $(common) -o $(dest)merge.o $(flags)

merge_t:
	$(cpl) $(src)merge_t.c $(common) -o $(dest)merge_t.o $(flags) -lpthread

radix_2:
	$(cpl) $(src)radix_2.c $(common) -o $(dest)radix_2.o $(flags)

radix_10:
	$(cpl) $(src)radix_10.c $(common) -o $(dest)radix_10.o $(flags)

selection:
	$(cpl) $(src)selection.c $(common) -o $(dest)selection.o $(flags)

