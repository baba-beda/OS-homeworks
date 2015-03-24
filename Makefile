all: lib/libhelpers.so cat/cat revwords/revwords filter/filter

clean:
	rm -f lib/helpers.o
	rm -f lib/libhelpers.so
	rm -f cat/cat
	rm -f revwords/revwords
	rm -f filter/filter



lib/libhelpers.so cat/cat revwords/revwords filter/filter:
	$(MAKE) -C $(dir $@) $(notdir $@)

