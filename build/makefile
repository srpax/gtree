ODIR=../obj
SDIR=../src
IDIR=../src
BDIR=out

CC=g++
CFLAGS=-I$(IDIR)

_DEPS = node.hpp cmd.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o node.o cmd.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@  $(CFLAGS)

qtree: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: configure
configure:
	mkdir -p $(ODIR) $(BDIR)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 