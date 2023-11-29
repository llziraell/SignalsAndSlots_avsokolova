#include "healthbar.h"

HealthBar::HealthBar(QWidget *parent)
    : QProgressBar(parent)
{
    setStyleSheet(kNormalStyle);
}

void HealthBar::changeColor(int value) {
    if (value < maximum() / 2) {
        setStyleSheet(kDangerStyle);
    } else {
        setStyleSheet(kNormalStyle);
    }
}
