all: lib/libhelpers.so cat/cat revwords/revwords lenwords/lenwords

clean:
	rm -f lib/helpers.o
	rm -f lib/libhelpers.so
	rm -f cat/cat
	rm -f revwords/revwords
	rm -f lenwords/lenwords



lib/libhelpers.so cat/cat revwords/revwords lenwords/lenwords:
	$(MAKE) -C $(dir $@) $(notdir $@)