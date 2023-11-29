#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <QProgressBar>

class HealthBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit HealthBar(QWidget *parent = nullptr);
private:
    const QString kDangerStyle =
        "QProgressBar::chunk {background: #F44336;}"
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    const QString kNormalStyle =
        "QProgressBar::chunk {background: #009688;}"
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    const QString kRecoveryStyle =
        "QProgressBar::chunk {background: #ffff00;}";

    int maxValue;
signals:

public slots:
    void changeColor(int value);
    //void changeColorWhenRecovery(int currentValue);
    void setMaxValue(int maxValue);
};

#endif // HEALTHBAR_H
