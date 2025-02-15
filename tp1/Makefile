# Environnement de compilation
CXX=g++ 
C11=--std=c++11

# Liste des fichiers sources
SRC_TAB= $(wildcard *_tableau.cpp)
SRC_INT= $(wildcard *_bigint.cpp)

# Liste des exécutables correspondants
EXEC_TAB= $(SRC_TAB:.cpp=)
EXEC_INT= $(SRC_INT:.cpp=)

# Tout compilé et exécuté
all: $(EXEC_TAB) $(EXEC_INT)

# Régle de compilation pour garder les mêmes noms sans le .cpp
%: %.cpp
	$(CXX) $(C11) -o $@ $< 

# Cible pour rouler les tests de la classe Tableau
tableau: $(EXEC_TAB)
	@for exec in $(EXEC_TAB); do \
		./$$exec; \
	done

# Cible pour rouler les tests de la classe Bint
bint: $(EXEC_INT)
	@for exec in $(EXEC_INT); do \
		if [ $$exec = "11_bigint" ]; then \
			./$$exec < deux; \
		else \
			./$$exec; \
		fi \
	done; \

# Cible pour rouler les tests mémoire
memoire: $(EXEC_INT) $(EXEC_TAB)
	@./memoire.sh

# Supprimer les exécutables
clean:
	rm -f $(EXEC_TAB)
	rm -f $(EXEC_INT)
