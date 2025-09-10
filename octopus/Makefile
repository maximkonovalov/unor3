#
#
#

CC =		arduino-cli
BOARD =		arduino:avr:uno
# XXX gross hack as it seems macos likes to change its name often
SERIAL = 	/dev/cu.usbserial-*

all:
	$(CC) compile -v --fqbn $(BOARD)

install:
	$(CC) upload -v -p $(SERIAL) --fqbn $(BOARD)

# EOF
