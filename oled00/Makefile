#
#
#

CC =		arduino-cli
BOARD =		arduino:avr:uno
SERIAL = 	/dev/cu.usbmodem141101

all:
	$(CC) compile -v --fqbn $(BOARD)

install:
	$(CC) upload -v -p $(SERIAL) --fqbn $(BOARD)

# EOF
