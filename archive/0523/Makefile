kion-htmlreport5: kion-htmlreportcmd.o readfile.o html-report4.o kionstat.o
	cc -o kion-htmlreport5 kion-htmlreportcmd.o readfile.o html-report4.o kionstat.o

kion-htmlreportcmd.o: kion-htmlreportcmd.c kion-htmlreport.h
	cc -c kion-htmlreportcmd.c

readfile.o: readfile.c kion-htmlreport.h
	cc -c readfile.c

html-report4.o: html-report4.c kion-htmlreport.h kionstat.h
	cc -c html-report4.c

kionstat.o: kionstat.c kionstat.h
	cc -c kionstat.c

test: kion-htmlreport5
	./kion-htmlreport5 kion-201804.csv
	cat report.html

clean:
	rm -f kion-htmlreport5 *.o a.out *~
