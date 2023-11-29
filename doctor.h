#ifndef DOCTOR_H
#define DOCTOR_H

#include <QObject>

class Doctor : public QObject
{
    Q_OBJECT
public:
    explicit Doctor(int recovery, QObject *parent = nullptr);

signals:
    void MakeRecovery(int recovery);

public slots:
    void OnRecoveryButtonClicked();

private:
   int recovery_;

};

#endif // DOCTOR_H
