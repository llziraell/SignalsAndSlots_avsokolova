#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>

#include "enemy.h"
#include "player.h"
#include "ui_widget.h"
#include "healthbar.h"
#include "doctor.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(10);
  HealthBar *healthBar = new HealthBar;
  Doctor *doctor = new Doctor(10);

  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> recoveryButton = new QPushButton;
  recoveryButton->setText("Восстановить урон");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
   widgetLayout->addWidget(recoveryButton, 2, 0, 1, 2);

  widget->setLayout(widgetLayout);

  int spacerWidth = 1;
  int spacerHeight = 1;
  QSpacerItem *topSpacer = new QSpacerItem(
      spacerWidth, spacerHeight, QSizePolicy::Minimum, QSizePolicy::Expanding);
  QSpacerItem *bottomSpacer = new QSpacerItem(
      spacerWidth, spacerHeight, QSizePolicy::Minimum, QSizePolicy::Expanding);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  setLayout(mainLayout);

  mainLayout->addItem(topSpacer);
  mainLayout->addWidget(widget);
  mainLayout->addItem(bottomSpacer);

  connect(recoveryButton, &QPushButton::clicked, doctor, &Doctor::OnRecoveryButtonClicked);
  connect(doctor, &Doctor::MakeRecovery, player, &Player::GetRecovery); // Предположим, что есть метод Heal(int amount) в классе Player
  connect(damageButton, &QPushButton::clicked, enemy,
          &Enemy::OnDamageButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(player, &Player::HealthChanged, healthBar, &HealthBar::setValue);
  connect(player, &Player::HealthChanged, healthBar, &HealthBar::changeColor);

}

Widget::~Widget() { delete ui; }
