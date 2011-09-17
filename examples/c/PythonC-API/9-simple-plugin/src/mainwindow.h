#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <Python.h>

class Canvas;
class QTextEdit;
class QComboBox;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow(); 

    void runScript(const QString &script);

private slots:
    void slotRunScript();

private:
    void initializePythonInterpretor();
    void finalizePythonInterpretor();

private:
    Canvas *m_canvas;
    QTextEdit *m_scriptEditor;
    QComboBox *m_scriptSelect;
    QPushButton *m_runScript;
};

#endif // MAINWINDOW_H
