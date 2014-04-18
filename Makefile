CC=gcc
CFLAGS?=-Wall -Werror -g
AWK?=awk
SORT?=sort
PR?=pr
VPATH?=src/ch-1 src/ch-2

CH1=celc2fahr contig countdigits counts cpio detab entab eof fahr2celc 
CH1+=helloworld lc longestline longlines power reverse splitwords vis wc 
CH1+=wordlength

CH2=expanded-for htoi ranges
SOURCES=$(CH1) $(CH2)

all: $(SOURCES)

$(SOURCES): %: %.c
	$(CC) $(CFLAGS) $< -o out/$@

.PHONY: clean
clean:
	rm -f out/*

.PHONY: help
help:
	@$(MAKE) --print-data-base --question |           \
	$(AWK) '/^[^.%][-A-Za-z0-9_]*:/                  \
	        { print substr($$1,1,length($$1)-1) }' | \
	$(SORT) |                                        \
	$(PR) --omit-pagination --width=80 --columns=4
