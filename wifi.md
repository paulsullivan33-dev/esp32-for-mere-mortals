# Wi-Fi — Client and Access Point

Outcome: your board can join a network
as a client — and you know what it
cannot join — and can also *be* a
network when there is no router to
join.

Wi-Fi is half of why this chip exists
(chapter 1), and the Arduino core makes
the common case almost disappointingly
short. The lab's second sketch,
`esp32-lab/sketches/wifi-scan/`, is the
gentlest start: before joining anything,
the chip listens. It switches its radio
to station mode, asks the air what it
can hear, and prints each network's
name, signal strength and channel. On
real hardware that scan is also your
first honest lesson: every network it
lists is on **2.4 GHz**, because that is
the only band any ESP32 will ever hear
(chapter 2). The sketch compiles in
transcript `t02-wifi-scan-compile.txt`;
its output on a desk is a list only
your desk can produce.

## Joining a network: station mode

A Wi-Fi **client** — the docs say
**station**, shortened to STA — joins
an existing network the way a phone
does: name (the **SSID**), password,
wait for an address. In code it is
three lines and a patient loop, and the
whole craft is in the patience: a real
project checks whether the connection
actually happened, notices when it
drops (routers reboot, signals fade),
and rejoins without being asked. The
core hands the board an address by
**DHCP** like any other device, and from
that moment the chip is a small citizen
of the network: it can fetch a web page,
answer one, send its readings to a
server, or ask the network the time.
Board LEDs across the world's workshops
blink the same sentence: *if the status
never says connected, the password, the
band, or the signal is wrong* — in that
order of likelihood.

Two honest limits belong in this
chapter, not the small print. First,
**enterprise networks** — the kind in
offices and universities that ask for a
username *and* a password, or a
certificate — are a different and
rougher road; the support exists in
ESP-IDF and partly in the core, but a
first project belongs on a home-style
network. Second, the chip's one radio is
shared: it cannot listen on two channels
at once, which is why scanning kicks a
connected board off the air briefly, and
why the next section is a mode, not a
second radio.

## Being a network: access-point mode

Flip the arrangement and the same chip
becomes an **access point**, shortened
to **AP**: it announces its own SSID,
accepts a handful of clients, and hands
out addresses in a tiny network of its
own. No router, no internet — and often
that is exactly the point. The classic
uses are configuration (a new device
wakes up as its own hotspot; your phone
joins it, tells it the real network's
name and password through a little web
page, and it reboots as a citizen) and
field work (a sensor node in a barn
serves its own readings to whoever
stands near it). The core runs both
modes at once, AP plus STA, with the
shared-radio caveat above. Security
honesty applies here too: an access
point with the default name and no
password, left running in a finished
project, is a door you installed and
forgot — name it, password it, or turn
it off when its job is done.

## What a connected chip does all day

The shape of nearly every ESP32 Wi-Fi
project is one of three. **Report**: wake
or loop, measure, send an **HTTP** or
**MQTT** message (MQTT is the little
publish-and-subscribe protocol built for
exactly this; both have libraries the
core's package manager installs in one
command), sleep or idle. **Serve**: hold
a small web server on the board itself —
a status page, a button that works a
relay — which the core's WebServer
library makes a page of code. **Fetch**:
ask the wider internet for something —
time, weather, a configuration file —
and act on the answer, over ordinary or
encrypted connections; the chip does
proper **TLS** encryption with
certificate checking, at a real cost in
memory and milliseconds that chapter 14
counts honestly. The lab's third sketch
is the Report shape in miniature: it
formats one reading as a line of **JSON**
— the text format named in chapter 11 —
ready to be exactly such a message.
