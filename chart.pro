QT       += core gui sql \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    associations.cpp \
    connexion.cpp \
    customwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    associations.h \
    connexion.h \
    customwidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Downloads/Clean - Booking UI Template (Community) (2)/About us/Group 62606.png \
    ../../../Downloads/MacOS Frame Template (Community).qtbridge \
    ../../Bureau/icons/BellRinging.png \
    ../../Bureau/icons/Files.png \
    ../../Bureau/icons/Group 2.png \
    ../../Bureau/icons/Group 2.png \
    ../../Bureau/icons/Key.png \
    ../../Bureau/icons/Light template (1).png \
    ../../Bureau/icons/Light template (1).png \
    ../../Bureau/icons/MacOS Frame Template (Community).qtbridge \
    ../../Bureau/icons/MacOS Frame Template (Community).qtbridge \
    ../../Bureau/icons/Mask Group.png \
    ../../Bureau/icons/Mask Group.png \
    ../../Bureau/icons/Put your demo inside here (1).png \
    ../../Bureau/icons/Put your demo inside here (1).png \
    ../../Bureau/icons/Put your demo inside here.png \
    ../../Bureau/icons/Put your demo inside here.png \
    ../../Bureau/icons/RECT.png \
    ../../Bureau/icons/Rectangle 1.png \
    ../../Bureau/icons/Rectangle 1.png \
    ../../Bureau/icons/Rectangle 104.png \
    ../../Bureau/icons/Rectangle 104.png \
    ../../Bureau/icons/TEMP.png \
    ../../Bureau/icons/Top bar (1).png \
    ../../Bureau/icons/Top bar (1).png \
    ../../Bureau/icons/Top bar.png \
    ../../Bureau/icons/Top bar.png \
    ../../Bureau/icons/Vector.png \
    ../../Bureau/icons/add.png \
    ../../Bureau/icons/bell.png \
    ../../Bureau/icons/capilot.png \
    ../../Bureau/icons/cart.png \
    ../../Bureau/icons/chat.png \
    ../../Bureau/icons/clor.png \
    ../../Bureau/icons/fi-rr-edit.png \
    ../../Bureau/icons/file-pdf.png \
    ../../Bureau/icons/graph.png \
    ../../Bureau/icons/history.png \
    ../../Bureau/icons/home.png \
    ../../Bureau/icons/logo pet.png \
    ../../Bureau/icons/logo pet.png \
    ../../Bureau/icons/logo.png \
    ../../Bureau/icons/menu.png \
    ../../Bureau/icons/more icon.png \
    ../../Bureau/icons/more icon.png \
    ../../Bureau/icons/off.png \
    ../../Bureau/icons/on.png \
    ../../Bureau/icons/remarques.txt \
    ../../Bureau/icons/save changes.png \
    ../../Bureau/icons/save changes.png \
    ../../Bureau/icons/search (2).png \
    ../../Bureau/icons/search (2).png \
    ../../Bureau/icons/search.png \
    ../../Bureau/icons/setting-2.png \
    ../../Bureau/icons/time.png \
    ../../Bureau/icons/wallet-2.png \
    ../../Bureau/icons/wishlist.png


