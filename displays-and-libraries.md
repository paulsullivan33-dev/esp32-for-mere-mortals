# Displays and Libraries

Outcome: you know how a screen joins
the project — a driver chip, a bus,
and a library that matches both — and
how to judge any library before it
joins yours.

Very few ESP32 programs are written
from bare metal, because the Arduino
world runs on **libraries**: packets
of other people's solved problems that
your sketch calls. A library wraps one
job — a sensor's conversation, a file
format, a screen — behind a handful of
functions. The core's manager installs
them by name (the lab installed
**ArduinoJson** with one command in
chapter 5), and the compiler reports
their cost in the size report of
chapter 6. The lab's third sketch is
the pattern in miniature: it includes
ArduinoJson, hands it a few values, and
gets one tidy line of **JSON** in
this shape —

```json
{"sensor":"workshop-north-wall","temp_c":21.4,"uptime_s":125}
```

— ready for chapter 8's network. The
sketch compiles in transcript
`t03-json-reading-compile.txt`, and its
size against the blink baseline is the
guide's small lesson in what a library
costs: real, measurable, and printed
before you commit to it.

## Judging a library before it joins

Four checks, in order, take a minute
and prevent most library grief. **Is
it maintained?** A release in the last
year or so, and answers on its issue
page, beat a famous name gone quiet.
**Does it name your chip?** "Works on
ESP32" from the ESP8266 era is a
rumour until the readme or examples
say S3 or C3 out loud, if those are
your chips (chapter 2). **What does it
drag in?** Some libraries install
families of dependencies; the install
output lists them, and chapter 6's
size report prices them. **Can you
read it?** A library is code you ship:
if its source is one impenetrable
file, debugging stops at its border.
Popularity is a fifth signal, not a
substitute for the first four — the
most-downloaded library for a job is
usually fine, and "usually" is doing
work in that sentence.

## Screens: driver, bus, library

A display is three choices wearing one
name, and matching them is the whole
craft. The **driver chip** is the
screen's own tiny controller — the
common small colour panels are driven
by chips with names like ILI9341 or
ST7789, and the screen's listing names
its driver in the specifications, not
the headline. The **bus** is how the
ESP32 talks to it: small screens use
**SPI** (chapter 7's shared-lines
pattern — fast enough, few pins);
larger colour panels, including most
all-in-one display boards (chapter 3),
use a parallel bus with many pins
consumed forever. The **library** is
the software match for both: it must
know the driver chip *and* be told the
wiring — which pins, what resolution,
which way is up.

Two library families divide the work.
**Adafruit GFX** and its driver
companions are the gentle slope: one
drawing vocabulary (lines, boxes, text)
across dozens of screens, each screen
enabled by its own small driver
library. **TFT_eSPI** is the workshop
favourite for colour panels: faster,
sharply configurable, and configured
by *editing its own setup file* to
name your driver and pins — a rite of
passage that rewards reading the file
top to bottom once. Either way, the
first program is always the same and
always worth it: fill the screen with
a solid colour, draw one line of text,
and stop. A screen that does that is
wired, configured and believed in; a
screen that does not gets diagnosed
while the program is still eleven
lines long.

Monochrome deserves its sentence: the
little **OLED** panels (driver SSD1306
and kin, usually on I2C) are the
kinder first display — four wires, no
backlight decisions, crisp text — and
for a sensor node's readout they are
very often the right final answer too,
not just the practice one.

## Touch, and the all-in-one bargain

On display boards the **touch**
surface is a second device entirely,
with its own controller chip and
usually its own bus, and it needs its
own library matched the same three
ways. This is chapter 3's bargain felt
from the inside: the maker chose the
pairings, your job is discovering
which they were — the maker's example
code, however rough, is the Rosetta
stone, because its configuration lines
*are* the wiring diagram in disguise.
Run the maker's demo first, before
your own code, so that *screen works*
is a fact and not a hope. Then build.
