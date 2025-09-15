#
#
#

CC =		arduino-cli
BOARD =		arduino:avr:nano
SERIAL = 	/dev/cu.usb*

all:
	$(CC) compile -v --fqbn $(BOARD)

install:
	$(CC) upload -v -p $(SERIAL) --fqbn $(BOARD)

# EOF
