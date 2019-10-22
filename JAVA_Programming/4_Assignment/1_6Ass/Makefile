FILE1=Contain_Inherit
FILE2=Person
FILE3=Address

EXT=.java

all:
	clear
	javac -d . $(FILE3)$(EXT)
	javac -d . $(FILE2)$(EXT)
	javac -d . $(FILE1)$(EXT)

run:
	clear
	java $(FILE1) 

clean:
	clear
	rm *.class
	rm com/*.class
	
