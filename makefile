

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

selection:
	$(cpl) -c $(src)selection.c -o $(dest)selection.o $(flags)

insertion:
	$(cpl) -c $(src)insertion.c -o $(dest)insertion.o $(flags)

heap:
	$(cpl) -c $(src)heap.c -o $(dest)heap.o $(flags)

quick:
	$(cpl) -c $(src)quick.c -o $(dest)quick.o $(flags)
merge: 
	$(cpl) -c $(src)merge.c -o $(dest)merge.o $(flags)

merge_t:
	$(cpl) -c $(src)merge_t.c -o $(dest)merge_t.o $(flags) -lpthread
	
counting:
	$(cpl) -c $(src)counting.c -o $(dest)counting.o $(flags)

radix_2:
	$(cpl) -c $(src)radix_2.c -o $(dest)radix_2.o $(flags)

radix_10:
	$(cpl) -c $(src)radix_10.c -o $(dest)radix_10.o $(flags)




sorting_lib:
	ar cr $(algs) \
	$(dest)bogo.o \
	$(dest)bubble.o \
	$(dest)selection.o \
	$(dest)insertion.o \
	$(dest)heap.o \
	$(dest)quick.o \
	$(dest)merge.o \
	$(dest)merge_t.o \
	$(dest)counting.o \
	$(dest)radix_2.o \
	$(dest)radix_10.o \
	
	clear
	@echo "Sorting library created"
	
main:
	$(cpl) -o main.out main.c $(util) $(algs) $(flags)
	./main.out

all:
	make array
	make bogo
	make bubble
	make selection
	make insertion
	make heap
	make quick
	make merge
	make merge_t
	make counting
	make radix_2
	make radix_10
	make sorting_lib
	clear
	@echo "All files compiled successfully."
	


clean:
	rm -rf ./obj/*.o
