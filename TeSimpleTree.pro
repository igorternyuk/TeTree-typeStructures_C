TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ternary_tree.c \
    binary_tree.c \
    bst.c

QMAKE_CFLAGS += -std=c11

HEADERS += \
    ternary_tree.h \
    binary_tree.h \
    bst.h
