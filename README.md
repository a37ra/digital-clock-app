# Digital Clock App

Крутое приложение для отображения времени в разных часовых поясах

## Features
- Отображает время в 9 основных часовых поясах
- Обновление в реальном времени
- Красивый UI в консоли 
- Кроссплатформенность (Windows/Linux/Mac)

## Сборка

### Windows
```
mkdir build
cd build
cmake ..
cmake --build .
```

### Linux/Mac
```
mkdir build
cd build
cmake ..
make
```

## Запуск
```
./clock
```

## Часовые пояса
- UTC (London)
- EST (New York)
- CST (Chicago)
- MST (Denver)
- PST (Los Angeles)
- CET (Paris)
- IST (India)
- JST (Tokyo)
- AEST (Sydney)

## TODO
- [ ] Добавить 24 часовых пояса
- [ ] Configureable zones через файл
- [ ] Alarm functionality
- [ ] Web interface
- [ ] Daylight saving time support

## License
MIT
