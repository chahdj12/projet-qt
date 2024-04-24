QT       += core gui
QT       += core gui
QT+=sql
QT+=widgets
QT += charts

QT += multimedia

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
unix:!mac:!vxworks:!integrity:!haiku:LIBS += -lm
SOURCES += \
    SmtpClient-for-Qt/src/emailaddress.cpp \
    SmtpClient-for-Qt/src/mimeattachment.cpp \
    SmtpClient-for-Qt/src/mimecontentformatter.cpp \
    SmtpClient-for-Qt/src/mimefile.cpp \
    SmtpClient-for-Qt/src/mimehtml.cpp \
    SmtpClient-for-Qt/src/mimeinlinefile.cpp \
    SmtpClient-for-Qt/src/mimemessage.cpp \
    SmtpClient-for-Qt/src/mimemultipart.cpp \
    SmtpClient-for-Qt/src/mimepart.cpp \
    SmtpClient-for-Qt/src/mimetext.cpp \
    SmtpClient-for-Qt/src/quotedprintable.cpp \
    SmtpClient-for-Qt/src/smtpclient.cpp \
    associations.cpp \
    connection.cpp \
    customwidget.cpp \
    employe.cpp \
    gestion_donation.cpp \
    gestion_employee.cpp \
    gestion_guests.cpp \
    gestion_oeuvre.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    notification.cpp \
    oeuvre.cpp \
    secdialog.cpp \
    smtp.cpp

HEADERS += \
    SmtpClient-for-Qt/src/SmtpMime \
    SmtpClient-for-Qt/src/emailaddress.h \
    SmtpClient-for-Qt/src/mimeattachment.h \
    SmtpClient-for-Qt/src/mimecontentformatter.h \
    SmtpClient-for-Qt/src/mimefile.h \
    SmtpClient-for-Qt/src/mimehtml.h \
    SmtpClient-for-Qt/src/mimeinlinefile.h \
    SmtpClient-for-Qt/src/mimemessage.h \
    SmtpClient-for-Qt/src/mimemultipart.h \
    SmtpClient-for-Qt/src/mimepart.h \
    SmtpClient-for-Qt/src/mimetext.h \
    SmtpClient-for-Qt/src/quotedprintable.h \
    SmtpClient-for-Qt/src/smtpclient.h \
    SmtpClient-for-Qt/src/smtpexports.h \
    associations.h \
    connection.h \
    customwidget.h \
    employe.h \
    gestion_donation.h \
    gestion_employee.h \
    gestion_guests.h \
    gestion_oeuvre.h \
    mainwindow.h \
    menu.h \
    notification.h \
    oeuvre.h \
    secdialog.h \
    smtp.h \


FORMS += \
    gestion_donation.ui \
    gestion_employee.ui \
    gestion_guests.ui \
    gestion_oeuvre.ui \
    mainwindow.ui \
    menu.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ba.qrc

DISTFILES += \
    ../icons/BellRinging.png \
    ../icons/Files.png \
    ../icons/Group 2.png \
    ../icons/Key.png \
    ../icons/Light template (1).png \
    ../icons/MacOS Frame Template (Community).qtbridge \
    ../icons/Mask Group.png \
    ../icons/Put your demo inside here (1).png \
    ../icons/Put your demo inside here.png \
    ../icons/RECT.png \
    ../icons/Rectangle 1.png \
    ../icons/Rectangle 104.png \
    ../icons/TEMP.png \
    ../icons/Top bar (1).png \
    ../icons/Top bar.png \
    ../icons/Vector.png \
    ../icons/add.png \
    ../icons/bell.png \
    ../icons/capilot.png \
    ../icons/cart.png \
    ../icons/chat.png \
    ../icons/clor.png \
    ../icons/edit.png \
    ../icons/file-pdf.png \
    ../icons/graph.png \
    ../icons/history.png \
    ../icons/home.png \
    ../icons/logo pet.png \
    ../icons/logo.png \
    ../icons/menu.png \
    ../icons/more icon.png \
    ../icons/off.png \
    ../icons/on.png \
    ../icons/remarques.txt \
    ../icons/save changes.png \
    ../icons/search (2).png \
    ../icons/search.png \
    ../icons/setting-2.png \
    ../icons/time.png \
    ../icons/wallet-2.png \
    ../icons/wishlist.png
