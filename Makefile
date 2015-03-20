all: lib/libhelpers.so cat/cat revwords/revwords

clean:
	rm -f lib/helpers.o
	rm -f lib/libhelpers.so
	rm -f cat/cat
	rm -f revwords/revwords



lib/libhelpers.so cat/cat revwords/revwords:
	$(MAKE) -C $(dir $@) $(notdir $@)

