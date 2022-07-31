

cpl 	= gcc
flags 	= -Wall -Ofast

src		= ./src/
dest	= ./obj/
algs 	= ./lib/sorting.a

util 	= $(dest)array_utilities.o


array:
	$(cpl) -c $(src)array_utilities.c -o $(util) $(flags)

bogo:
	$(cpl) -c $(src)bogo.c -o $(dest)bogo.o $(flags)
	
bubble:
	$(cpl) -c $(src)bubble.c -o $(dest)bubble.o $(flags)

counting:
	$(cpl) -c $(src)counting.c -o $(dest)counting.o $(flags)

heap:
	$(cpl) -c $(src)heap.c -o $(dest)heap.o $(flags)

merge: 
	$(cpl) -c $(src)merge.c -o $(dest)merge.o $(flags)

merge_t:
	$(cpl) -c $(src)merge_t.c -o $(dest)merge_t.o $(flags) -lpthread
radix_2:
	$(cpl) -c $(src)radix_2.c -o $(dest)radix_2.o $(flags)

radix_10:
	$(cpl) -c $(src)radix_10.c -o $(dest)radix_10.o $(flags)

selection:
	$(cpl) -c $(src)selection.c -o $(dest)selection.o $(flags)

quick:
	$(cpl) -c $(src)quick.c -o $(dest)quick.o $(flags)
	
sorting_lib:
	ar cr $(algs) \
	$(dest)bogo.o \
	$(dest)bubble.o \
	$(dest)counting.o \
	$(dest)heap.o \
    $(dest)merge.o \
	$(dest)merge_t.o \
	$(dest)radix_2.o \
	$(dest)radix_10.o \
	$(dest)selection.o \
	$(dest)quick.o \

	clear
	@echo "Sorting library created"
	
main:
	$(cpl) -o main.out main.c $(util) $(algs) $(flags)

all:
	make array
	make bogo
	make bubble
	make counting
	make heap
	make merge
	make merge_t
	make radix_2
	make radix_10
	make selection
	make quick
	make sorting_lib
	clear
	@echo "All files compiled successfully."
	


clean:
	rm -rf ./obj/*.o
