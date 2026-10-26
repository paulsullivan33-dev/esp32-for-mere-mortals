# Troubleshooting

Outcome: when a board misbehaves, you
have a short ordered list of suspects —
and most of them are not your code.

ESP32 debugging has a folklore because
the failures repeat. Work the list in
order; each entry names the symptom,
the cause the lab and the community
meet most, and the check that settles
it.

**The board is not seen by the
computer at all.** No serial port
appears when the cable lands. Suspects,
in order: a **charge-only USB cable**
(the classic — it carries power and no
data, and looks identical to a real
one; swap the cable before anything
else); a missing driver for the board's
USB-to-serial chip (the common chips
are named in chapter 5, and the board
maker's page says which yours carries);
a dead port or hub. The check is the
port list before and after plugging in
— chapter 5's first command.

**Uploads fail although the port
exists.** The tool talks but the board
will not take the program: "failed to
connect", timing out while "connecting".
The board is not in download mode —
hold the BOOT button as the upload
starts (chapter 5), or check whatever
hangs on GPIO 0 and GPIO 2 (chapter 7's
strapping pins: a peripheral holding
them wrong vetoes the whole ceremony).
A different cable fixes a share of
these too, because a cable can carry
data badly as well as not at all.

**The board resets, randomly,
especially when Wi-Fi starts.** The
serial log says `Brownout detector was
triggered` — believe it. The radio's
transmit peaks (chapter 1) exceed what
a weak USB port, a tired cable or a
breadboard rail can give, the voltage
sags, and the chip restarts to protect
itself. Feed it from a known-good port
or supply, shorten the cable, and if a
capacitor across the board's power pins
is the community's folk remedy in your
notes, this is the case it is for.

**It boots, but into the wrong mode,
or prints garbage.** A boot loop with
stray characters at reset is a
strapping pin held wrong (chapter 7)
or a serial monitor set to the wrong
speed — the boot log speaks 115200 on
nearly everything, and a monitor at
another speed shows hieroglyphs from a
healthy board. Garbage *after* a clean
boot log is your sketch's own serial
speed disagreeing with the monitor's.

**It worked on the desk; it fails in
the box.** Heat, a metal enclosure
eating the antenna's reach (chapter 3),
a battery sagging under transmit load
(chapter 10), or a sensor lead turned
aerial. The desk is the kindest
environment the project will ever see;
chapter 10's arithmetic and a margin
of signal are the cures.

**The sketch compiles for one board
and fails for another.** Different
chips are different targets (chapter
2): an FQBN naming the original will
not describe an S3's pins, and
libraries test against the chips they
test against. Compile per target, and
let the transcript (chapter 6) record
which target each build meant.

**Analogue readings are nonsense.**
The pin is on ADC2 while Wi-Fi is on
(chapter 7), the input exceeds 3.3 V
and clips, or the value was believed
without averaging. Move the sensor to
an ADC1 pin, divide the signal down to
range, average a handful of samples.

**OTA updates stopped working after an
update.** The new firmware crashes
before it starts the network, or was
built against a partition table
without a second slot (chapter 12).
The recovery is the cable: hold BOOT,
flash by USB, and let the lesson
reorder your release habits — one
board, one day, then the fleet.

**Everything above failed and it still
misbehaves.** Remove the project: flash
the blink sketch from chapter 6 to the
bare board, nothing attached. A board
that blinks is innocent, and the fault
is in what was added — reintroduce the
wiring one piece at a time. A board
that will not blink, fed by a known
cable from a known port, has told you
its own sad answer, and a replacement
costs less than the weekend.
