# Bluetooth and BLE

Outcome: you can say which Bluetooth
your project needs, recognise when the
answer is "none of these chips", and
know what BLE is genuinely good at.

**Bluetooth** is not one thing, and on
this family the difference decides
which chip you buy (chapter 2's table
is the authority; this chapter is the
explanation). There are two Bluetooths,
related in name and logo and almost
nothing else.

## Classic Bluetooth: the original's party trick

**Bluetooth Classic** is the older
standard: the one in car stereos, cheap
speakers, and wireless serial cables.
It carries continuous streams — audio,
or a steady serial link — and pairing
the way a phone pairs with a headset.
On the ESP32 family, Classic exists on
exactly one chip: the original ESP32.
The core libraries make it a serial
port with the wire removed
(`BluetoothSerial`), or an audio
source that older speakers accept. If
a project plan says "send audio to a
Bluetooth speaker" or "appear as a
serial cable to an old instrument",
that plan has already chosen its chip,
and the S3 and C3 on the shop shelf,
however shiny, cannot do it.

## BLE: small messages, long sleeps

**Bluetooth Low Energy** — BLE — is the
younger design, and it is on every
family member except the S2. BLE does
not stream; it deals in small, tidy
packets of named data. A BLE device
advertises its presence in short
bursts, and offers **services** —
labelled drawers — containing
**characteristics**, the labelled
compartments inside them: a heart-rate
service with a beats-per-minute
characteristic, a battery service with
a percentage. A phone (the **central**)
connects to the device (the
**peripheral**), reads and writes those
compartments, or subscribes to be told
when one changes. The whole design
points at battery life: a BLE sensor
can chatter for a year on a cell
(chapter 10's arithmetic), because
between chirps it is nearly off.

What BLE is genuinely good at, on this
chip: being a sensor a phone can read
without any app-store drama (a
thermometer, a plant probe, a
workshop door counter); being a
**beacon**, a device that only
advertises — *I am here, my battery is
this, my last reading was that* — to
whoever walks past with a listener;
and being configured by a phone over
short messages where Wi-Fi would be
overkill and a hotspot (chapter 8)
overkill squared. The core's BLE
library spells the services-and-
characteristics model out in classes,
and a minimal "one service, one
readable number" peripheral is a
realistic second-evening project.

## The honest edges

Three, plainly. **Range and walls**:
both Bluetooths are short-range
radios, tens of metres in kind
conditions, and a metal enclosure
(chapter 3's antenna note) eats them
first. **The phone is the platform**:
a BLE project usually means a phone
app or a generic BLE scanner app is
the other half of the system — the
generic scanners are excellent for
development and honest to prototype
with, and a polished product needs
its own app, which is somebody's
whole other project. **And the new
mesh radios are not Bluetooth**: the
C6 and H2 (chapter 2) add Thread and
Zigbee, which are separate standards
with their own hubs and rules; BLE is
how those chips talk to phones, not
how the mesh talks to itself.

Check: take one project idea and state
which radio carries it and why —
continuous audio (Classic, original
chip only), a phone reading a sensor
(BLE, any chip but the S2), a barn
sensor reporting to a distant house
(neither — that is chapter 8's Wi-Fi,
or chapter 13's neighbours).
