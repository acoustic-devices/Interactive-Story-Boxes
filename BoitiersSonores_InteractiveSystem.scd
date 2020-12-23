s.boot;

SerialPort.listDevices; // check which ports arduino is connected to.

~port1 = ArduinoSMS("COM16", 115200); // tell SC to read the serial ports for the computer.


~capsule = Buffer.read(s, "C:/Users/User/Documents/TD/Work/FactumLab Transmedia/ML S2/Labo d'Idees 2/LaboIdees2.wav");

~player = SynthDef("Capsule",{ arg out = 0, bufnum; // bufnum the key variable
    Out.ar( out,
        PlayBuf.ar(2, ~capsule, BufRateScale.kr(bufnum)) // change number of channels based on sample chosen.
    )
}).add;

//~player.play


~port1.action = { |... msg|
	y=msg[0].postln;
	if (y == "PLAY") {g = {
	s.freeAll;
	1.wait;
	~player.play;
	//250.wait; // set wait to fit the chosen samples. - should be 5.225 nominally

}.fork};
};



//SerialPort.closeAll