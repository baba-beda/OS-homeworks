all: cat/cat revwords/revwords lib/libhelpers.so

cat/cat revwords/revwords lib/libhelpers.so:
	$(MAKE) -C $(dir $@) $(notdir $@)