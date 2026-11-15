#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Hello");
    window.resize(300, 300);

    QVBoxLayout* layout = new QVBoxLayout(&window);

    QLabel* label = new QLabel("0");

    QPushButton* incButton = new QPushButton("Increase");
    QObject::connect(incButton, &QPushButton::clicked,
                     [label, counter = 0]() mutable {
        counter++;
        label->setText(QString::number(counter));
    });

    QPushButton* exitButton = new QPushButton("Exit");
    QObject::connect(exitButton, &QPushButton::clicked, &app, &QApplication::quit);

    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addWidget(incButton, 0, Qt::AlignCenter);
    layout->addWidget(exitButton, 0, Qt::AlignCenter);

    window.show();
    return app.exec();
}
