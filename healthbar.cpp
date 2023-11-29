#include "healthbar.h"

HealthBar::HealthBar(QWidget *parent)
    : QProgressBar(parent)
{
    setStyleSheet(kNormalStyle);
}

void HealthBar::changeColor(int value) {
    if (value < maximum() / 2) {
        setStyleSheet(kDangerStyle);
    } else if (value == maximum()) {
        setStyleSheet(kNormalStyle);
    } else {
         setStyleSheet(kRecoveryStyle);
    }
}

void HealthBar::setMaxValue(int newMaxValue) {
    maxValue = newMaxValue;
}
