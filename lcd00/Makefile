#
#
#

CC =		arduino-cli
BOARD =		arduino:avr:uno
SERIAL = 	/dev/cu.usbserial-14130

all:
	$(CC) compile -v --fqbn $(BOARD)

install:
	$(CC) upload -v -p $(SERIAL) --fqbn $(BOARD)

# EOF
