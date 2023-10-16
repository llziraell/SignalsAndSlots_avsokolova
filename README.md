# Сигналы и слоты

1. Заменить `QProgressBar` на пользовательский класс
   - Добавить в класс возможность изменения цвета бара в зависимости от кол-ва жизней персонажа
   - Добавить возможность изменять пороговое значение, при котором цвет меняется
2. Добавить логику для восстановления жизней персонажа (можно аналогично нанесению урона, как уже реализовано)
3. Добавить `QSlider` и `QLabel`
   - `QSlider` отвечает за изменение порогового значения для пользовательского `QProgressBar`, при котором меняется цвет
   - `QLabel` отображает текущее пороговое значение
- Все взаимодействие между объектами настроить с помощью сигналов и слотов

Возможные стили для пользовательского `QProgressBar`:
```c++
const QString kDangerStyle =
      "QProgressBar::chunk {background: #F44336; Width: 20px; margin: 0.5px;"
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";

 const QString kNormalStyle =
      "QProgressBar::chunk {background: #009688; Width: 20px; margin: 0.5px; "
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";
```
