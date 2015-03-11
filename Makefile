all: lib/libhelpers.so cat/cat revwords/revwords



lib/libhelpers.so cat/cat revwords/revwords:
	$(MAKE) -C $(dir $@) $(notdir $@)