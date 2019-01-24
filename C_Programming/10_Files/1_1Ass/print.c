/*
 * Experiment to find out what happens when printf argument string contains \x, where x is some character
 * (a,b, c, \, ^ etc). What are your observations.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 
 /*
 *	\x and \u are not a valid secquence
 */
 
 int main()
 {
 	printf("Characters\n");
 	printf("\a \b \c \d \e \f \g \h \i \j \k \l \m \n \o \p \q \r \s \r \t \v \w \y \z");
 	printf("\A \B \C \D \E \G \H \I \J \K \L \M \N \O \P \Q \R \S \T \V \W \X \Y \Z \n\n");
 	
 	printf("Special characters\n");
 	printf("\~ \! \@ \# \$ \% \^ \& \* \( \) \_ \+ \= \- \n\n");
 	
 	return 0;
 }
