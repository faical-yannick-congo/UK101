#ifndef _DISPLAY_H
#define _DISPLAY_H

class display: public UTFTDisplay {
public:
	virtual void operator= (byte c) { 
		if (c != _mem[_acc]) { _mem[_acc] = c; _draw(_acc, c); } 
	}
	virtual operator byte () { return _mem[_acc]; }

	virtual void checkpoint(Stream &s);
	virtual void restore(Stream &s);

	display() : UTFTDisplay(sizeof(_mem)), _resolution(0) {}
	void begin();
	const char *changeResolution();

protected:
	void _draw(Memory::address a, byte c);

private:
	byte _mem[DISPLAY_RAM_SIZE];
	int _resolution;
};
#endif
