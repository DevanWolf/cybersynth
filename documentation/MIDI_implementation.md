# MIDI Implementation

## Channel Voice Messages

|MIDI Message|HEX Code|Description|Compatibility|
|:---------- |:------ |:--------- |:-----------:|
|NOTE ON|9nH kk vv|Midi channel n(0-15) note ON #kk(0-127), velocity vv(1-127).<br>vv=0 means NOTE OFF|MIDI|
|NOTE OFF|8nH kk vv|Midi channel n(0-15) note OFF #kk(0-127), vv is ignored.|MIDI|
|PITCH BEND|EnH bl bh|Pitch bend as specified by bh\|bl (14 bits).<br>Maximum swing is +/- 1 tone (power-up).<br>Can be changed using « Pitch bend sensitivity ».<br>Center position is 00H 40H.|GM|
|PROGRAM<br>CHANGE|CnH pp|Program (patch) change.<br>Specific action on channel 10 (n=9) : select drumset.|GM/GS|
|CHANNEL<br>AFTERTOUCH|DnH vv|vv pressure value|MIDI|
|CTRL 00|BnH 00H cc|Bank select MSB|GS|
|CTRL 05|BnH 05H cc|Portamento Time|MIDI|
|CTRL 06|BnH 06H cc|Data entry : provides data to RPN and NRPN|MIDI|
|CTRL 07|BnH 07H cc|Volume|MIDI|
|CTRL 10|BnH 0AH cc|Pan|MIDI|
|CTRL 11|BnH 0BH cc|Expression|MIDI/GM|
|CTRL 32|BnH 20H cc|Bank select LSB|GS|
|CTRL 64|BnH 40H cc|Sustain (damper) pedal|MIDI|
|CTRL 65|BnH 41H cc|Portamento|MIDI|
|CTRL 91|BnH 5BH vv|Reverb send level vv=00H to 7FH|GS|
|CTRL 93|BnH 5DH vv|Chorus send level vv=00H to 7FH|GS|
|CTRL 96|BnH 60H vv|Increase RPN/NRPN value|MIDI|
|CTRL 97|BnH 61H vv|Decrease RPN/NRPN value|MIDI|
|CTRL 98|BnH 62H vv|NRPN LSB|MIDI|
|CTRL 99|BnH 63H vv|NRPN MSB|MIDI|
|CTRL 100|BnH 64H vv|RPN LSB|MIDI|
|CTRL 101|BnH 65H vv|RPN MSB|MIDI|
|CTRL 120|BnH 78H xx|All sounds off (abrupt stop of sound on channel n)|MIDI|
|CTRL 121|BnH 79H xx|Reset all controllers|MIDI|
|CTRL 123|BnH 7BH xx|All notes off|MIDI|
|CTRL 124|BnH 7CH xx|Omni off.|MIDI|
|CTRL 125|BnH 7DH xx|Omni on.|MIDI|
|CTRL 126|BnH 7EH xx|Mono on.|MIDI|
|CTRL 127|BnH 7FH xx|Poly on.|MIDI|
|RPN 0000H|BnH 65H 00H 64H 00H 06H vv|Pitch bend sensitivity in semitones|MIDI/GM|
|RPN 0001H|BnH 65H 00H 64H 01H 26H vl 06H vh|Fine tuning in cents (vh,vl=00 00H -100, vh,vl=40 00H 0, vh,vl=7F 7FH +99.99)|MIDI|
|RPN 0002H|BnH 65H 00H 64H 02H 06H vv|Coarse tuning in half-tones (vv=00H -64, vv=40H 0, vv=7FH +64)|MIDI|

## System Exclusive Messages

|Manufacturer ID|HEX Code|Description|Compatibility|
|:------------- |:------ |:--------- |:-----------:|
|Universal Non-Real Time|F0H 7EH 7FH 09H 01H F7H|General MIDI Mode On|GM|
|Universal Non-Real Time|F0H 7EH 7FH 09H 02H F7H|General MIDI Mode Off|GM|
|Roland Corporation|F0H 41H xx 42H 12H 40H 00H 7FH 00H xx F7H|Roland GS Mode On|GS|
|Roland Corporation|F0H 41H xx 42H 12H 40H 00H 7FH 7FH xx F7H|Roland GS Mode Off|GS|
|Roland Corporation|F0H 41H xx 42H 12H 40H 1pH 15H vv xx F7H|Part to rhythm allocation, p is part (0 to 15), vv can select one secondary rhythm part. If vv=00 or 01 then no secondary rhythm part is used, otherwise the part p is used as secondary rhythm part.|GS|

