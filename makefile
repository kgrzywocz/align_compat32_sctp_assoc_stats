all: testUT testELF

testUT:
	$(CC) test/UT/alignTest.c -Isrc -Itest/UT -o testUT
	./testUT

testELF:
	$(CC) test/ELF/testELF.c -static -l:libsctp.a -m32 -o testELF
	./testELF

clean:
	rm -rf testUT testELF

.PHONY: clean testUT testELF