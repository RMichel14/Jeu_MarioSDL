# Makefile Générique Amélioré

# Extensions et compilateur
EXT = c
CXX = gcc
EXEC = MarioSDL

# Dossiers
SRCDIR = filesC
OBJDIR = dependencies
INCDIR = include

# Options de compilation
CXXFLAGS = -Wall -W -pedantic  -I$(INCDIR)
LDFLAGS = 

# Recherche des fichiers sources et génération des objets
SRC = $(wildcard $(SRCDIR)/*.$(EXT))
OBJ = $(SRC:$(SRCDIR)/%.$(EXT)=$(OBJDIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXT) | $(OBJDIR)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

# Création du dossier des objets si nécessaire
$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)/*.o
	@rm -f $(EXEC)

.PHONY: all clean