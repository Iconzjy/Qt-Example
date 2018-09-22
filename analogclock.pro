QT += widgets
HEADERS += \
    analogclock.h

SOURCES += \
    analogclock.cpp \
    main.cpp
  # install
  target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/analogclock
  INSTALLS += target
