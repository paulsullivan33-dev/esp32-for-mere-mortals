# Over-the-Air Updates

Outcome: a board sealed in a box, up a
pole or inside a greenhouse can receive
new firmware over its own Wi-Fi — and
you know the price: flash space, a
security decision, and a way back from
a bad update.

The USB cable of chapter 5 is a fine
servant and a poor lifestyle. A working
node ends up somewhere awkward, and
every firmware fix would mean a ladder.
**Over-the-air** updating — **OTA** —
is the chip updating itself: the running
firmware receives its replacement over
the network, writes it to flash, and
reboots into it. The Arduino core ships
two faces of the idea: an
`ArduinoOTA` library that lets the tools
on your desk push an update to a board
on the same network, and the plain
building blocks for a board to *pull*
an update from a server with an HTTP
client when told.

## The trick that makes it safe: two homes for firmware

OTA works because of **partitions**.
The flash is divided by a **partition
table** written when the board is first
flashed, and a normal OTA layout keeps
*two* application slots — conventionally
`ota_0` and `ota_1`. The chip runs from
one; the update is written to the other,
never over the running program; a small
**bootloader** at reset chooses the
newest valid slot and can fall back to
the previous one when the new firmware
marks itself bad or fails to mark itself
good. No slot, no safety: that is also
the cost. A board flashed with a
single-app partition table (some minimal
layouts) has nowhere to write an update
and must be re-partitioned by cable
first, and each app slot is half the
flash an equal non-OTA layout would
give — the 4 MB module of chapter 3
becomes, in practice, two homes of
roughly 1.9 MB each. Chapter 6's size
report is where you feel that: the
percentage it prints is against the
slot, not the chip.

## The security paragraph, in the middle where it belongs

An update channel is the most powerful
door a device has: whoever can use it
owns the device, entirely, forever.
So the honest shape of OTA is: updates
over an encrypted connection, from a
source the device has reason to trust,
with the firmware **signed** or at least
checked, and the ArduinoOTA password
option turned *on* rather than admired.
A workshop node on a home network,
updated from your own desk with the
library's password set, is a reasonable
risk knowingly taken. The same node
fetching unsigned firmware over plain
HTTP from the open internet is not an
update mechanism; it is a suggestion
box for strangers. ESP-IDF (chapter 4)
carries the full armour — signed
images, rollback protection, encrypted
flash — and a product that leaves your
bench deserves it; this guide's line is
that the moment a device other people
depend on takes updates over a network,
its update path is a security feature
and gets reviewed like one (chapter 14).

## Living with it

Operationally, OTA changes three habits.
Version your firmware visibly — print
the version at boot, answer with it on
the status page — because a fleet of
boards at unknown versions is a riddle,
not a system. Update one board first
and let it run a day before the rest;
the fallback slot forgives, but it
forgives best rarely. And keep the
cable path working: OTA depends on the
old firmware being alive enough to
receive, so a build that crashes before
the network starts is a ladder job
anyway. The bootloader's fallback
covers a bad *new* firmware; it does
not cover a new firmware that bricks
its own update door. Chapter 15 keeps
the recovery procedure.

Check: on paper, divide your board's
flash by its partition table and state
the largest sketch OTA could ever
deliver to it. If the number surprises
you, it has done that to everyone.
