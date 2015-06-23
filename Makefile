all: lib/libhelpers.so lib/libbufio.so cat/cat revwords/revwords filter/filter bufcat/bufcat foreach/foreach

clean:
	rm -f lib/helpers.o
	rm -f lib/libhelpers.so
	rm -f cat/cat
	rm -f revwords/revwords
	rm -f filter/filter
	rm -f bufcat/bufcat
	rm -f bufcat/bufcat.o
	rm -f lib/bufio.o
	rm -f lib/libbufio.so
	rm -f foreach/foreach



lib/libhelpers.so lib/libbufio.so cat/cat revwords/revwords filter/filter bufcat/bufcat foreach/foreach:
	$(MAKE) -C $(dir $@) $(notdir $@)

