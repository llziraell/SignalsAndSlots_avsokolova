#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QWidget>
#include <QProgressBar>

class HealthBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit HealthBar(QWidget *parent = nullptr);
    void updateColor(int value);
private:
    const QString kDangerStyle =
        "QProgressBar::chunk {background: #F44336;}"
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    const QString kNormalStyle =
        "QProgressBar::chunk {background: #009688;}"
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";
signals:

};

#endif // HEALTHBAR_H
