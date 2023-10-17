#include "GyverTimer.h"


/**
 * Конструктор по умолчанию МИЛИсекундного таймера
*/
GTimer_ms::GTimer_ms() {}

/**
 * Конструктор с параметром МИЛИсекундного таймера
*/
GTimer_ms::GTimer_ms(uint32_t interval) {
	_interval = interval;
	_timer = millis();
}

/**
 * Метод устанавливает интервал работы таймера
*/
void GTimer_ms::setInterval(uint32_t interval) {
	_interval = interval;
	GTimer_ms::reset();
}

/**
 * Метод устанавливает режим работы:
 * 0 - AUTO
 * 1 - MANUAL
*/
void GTimer_ms::setMode(boolean mode) {
	_mode = mode;
}

/**
 * Метод запускает таймер
*/
void GTimer_ms::start() {
	_state = true;
}

/**
 * Метод останавливает таймер
*/
void GTimer_ms::stop() {
	_state = false;
}

/**
 * Метод возвращает trueпо истечению времени
 * В AUTO режиме сам сбрасывается
 * В MANUAL режиме при нажатии кнопки
*/
boolean GTimer_ms::isReady() {
	if (!_state) return false;
	if ((long)millis() - _timer >= _interval) {
		if (_mode) _timer = millis();
		return true;
	} else {
		return false;
	}
}

/**
 * Метод сбросывает работу таймера
*/
void GTimer_ms::reset() {
	_timer = millis();
}

/**
 * Конструктор по умолчанию МИКРОсекундного таймера
*/
GTimer_us::GTimer_us() {}

/**
 * Конструктор с параметром МИКРОсекундного таймера
*/
GTimer_us::GTimer_us(uint32_t interval) {
	_interval = interval;
	_timer = micros();
}

/**
 * Метод устанавливает интервал работы таймера
*/
void GTimer_us::setInterval(uint32_t interval) {
	_interval = interval;
	_timer = micros();
}

/**
 * Метод устанавливает режим работы:
 * 0 - AUTO
 * 1 - MANUAL
*/
void GTimer_us::setMode(boolean mode) {
	_mode = mode;
}

/**
 * Метод запускает таймер
*/
void GTimer_us::start() {
	_state = true;
}

/**
 * Метод останавливает таймер
*/
void GTimer_us::stop() {
	_state = false;
}

/**
 * Метод возвращает trueпо истечению времени
 * В AUTO режиме сам сбрасывается
 * В MANUAL режиме при нажатии кнопки
*/
boolean GTimer_us::isReady() {
	if (!_state) return false;
	if ((long)micros() - _timer >= _interval) {
		if (_mode) _timer = micros();
		return true;
	} else {
		return false;
	}
}

/**
 * Метод сбросывает работу таймера
*/
void GTimer_us::reset() {
	_timer = micros();
}