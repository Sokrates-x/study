#ifndef SCREEN_H
#define SCREEN_H

class Screen{

public:
	Screen(int px = 0, int py = 0, int h = 0, int w = 0, const char &c = ' ')
		: pos_x_(px), pos_y_(py), height_(h), width_(w), bar_(c) { } 

	void move(int x, int y) { 
		pos_x_ += x;
		pos_y_ += y;
	}

	void resize(int h, int w) {
		height_ += h;
		width_ += w;
	}

	void fill(const char &c) {
		bar_ = c;
	}

	void display() const;

private:

	char bar_;
	int pos_x_;
	int pos_y_;
	int height_;
	int width_;
};

#endif
