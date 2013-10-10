EMCC=emcc

OBJS=\
Processor.bc \
Process.bc

SCRIPT=\
bug-test-case.js

all: $(SCRIPT)

$(SCRIPT): $(OBJS)
	$(EMCC) -O2 -g2 -s EXPORTED_FUNCTIONS="['_runProcess']" -o $(SCRIPT) $(OBJS)

$(OBJS): %.bc: %.cpp
	$(EMCC) -c -O2 -g2 -o $@ $<

clean:
	rm $(OBJS) $(SCRIPT)
