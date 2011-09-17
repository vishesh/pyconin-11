#include "mainwindow.h"
#include "canvas.h"
#include "python_exposed.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_canvas = Canvas::instance();
    m_canvas->setMinimumSize(QSize(600, 600));
    initializePythonInterpretor();

    m_scriptEditor = new QTextEdit;
    m_scriptEditor->setMinimumSize(QSize(400, 0));
    m_scriptEditor->setFontFamily("Monospace");
    m_scriptEditor->setTabStopWidth(m_scriptEditor->tabStopWidth()/2);

    m_scriptSelect = new QComboBox;
    m_runScript = new QPushButton("Run Script");
    
    QGridLayout *sideLayout = new QGridLayout;
    sideLayout->addWidget(m_scriptSelect, 0, 0);
    sideLayout->addWidget(m_scriptEditor, 1, 0);
    sideLayout->addWidget(m_runScript, 2, 0);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_canvas);
    layout->addLayout(sideLayout);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);

    connect(m_runScript, SIGNAL(clicked()), this, SLOT(slotRunScript()));
}

MainWindow::~MainWindow()
{
    finalizePythonInterpretor();
}

void MainWindow::initializePythonInterpretor()
{
    Py_Initialize();
    init_python_interface();
    PyImport_ImportModule("canvas_interface");
}

void MainWindow::finalizePythonInterpretor()
{
    Py_Finalize();
}

void MainWindow::runScript(const QString &script)
{
    PyRun_SimpleString(script.toAscii().constData());
}

void MainWindow::slotRunScript()
{
    runScript(m_scriptEditor->toPlainText());
    m_canvas->repaint();
}

