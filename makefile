all: q1 q2 q3 q4 q5 q6
.PHONY: all clean q1 q2 q3 q4 q5 q6
q1:
	make -C q1 all
q2:
	make -C q2 all
q3:
	make -C q3 all
q4:
	make -C q4 all
q5:
	make -C q5 all
q6:
	make -C q6 all
clean: clean_q1 clean_q2 clean_q3 clean_q4 clean_q5 clean_q6
clean_q1:
	make -C q1 clean
clean_q2:
	make -C q2 clean
clean_q3:
	make -C q3 clean
clean_q4:
	make -C q4 clean
clean_q5:
	make -C q5 clean
clean_q6:
	make -C q6 clean

 
