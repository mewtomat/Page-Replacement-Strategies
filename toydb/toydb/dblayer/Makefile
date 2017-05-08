SRC= db.c
OBJ= db.o
HDR = db.h am.h pf.h amlayer.h pflayer.h

main.o: main.c am.h pf.h db.h
	cc -c main.c

createfile.o: createfile.c am.h pf.h db.h
	cc -c createfile.c

join.o: join.c am.h pf.h db.h
	cc -c join.c

select.o: select.c am.h pf.h db.h
	cc -c select.c

dblayer.o:db.o
	ld -r db.o -o dblayer.o

db.o:db.c $(HDR)

a.out : dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o main.o ../amlayer/amscan.o ../amlayer/amprint.o
	cc dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o main.o ../amlayer/amscan.o ../amlayer/amprint.o


createfile.out : dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o createfile.o ../amlayer/amscan.o ../amlayer/amprint.o
	cc dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o createfile.o ../amlayer/amscan.o ../amlayer/amprint.o -o createfile

join.out : dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o join.o ../amlayer/amscan.o ../amlayer/amprint.o
	cc dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o join.o ../amlayer/amscan.o ../amlayer/amprint.o -o join

select.out : dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o select.o ../amlayer/amscan.o ../amlayer/amprint.o
	cc dblayer.o ../amlayer/am.o ../amlayer/amfns.o ../amlayer/amsearch.o ../amlayer/aminsert.o ../amlayer/amstack.o ../amlayer/amglobals.o ../pflayer/pflayer.o select.o ../amlayer/amscan.o ../amlayer/amprint.o -o select


layersclean:
	rm -f ../pflayer/*.o ../amlayer/*.o ./*.o

clean:
	rm -f *.o ./databases/* *.out

clean2:
	rm -f *.o ./mydata/* createfile.out

cleanjoin:
	rm -f join.out

cleanselect:
	rm -f select.out
