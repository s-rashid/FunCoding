#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCalendarWidget>
#include <QListWidget>
#include <QDateTime>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main window and layout
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(window);

    // Add the current time label to the layout
    QLabel *timeLabel = new QLabel(window);
    timeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(timeLabel);

    // Add the calendar widget to the layout
    QCalendarWidget *calendarWidget = new QCalendarWidget(window);
    layout->addWidget(calendarWidget);

    // Add the to-do list and "Done" button to the layout
    QHBoxLayout *toDoLayout = new QHBoxLayout;
    QListWidget *toDoList = new QListWidget(window);
    QPushButton *doneButton = new QPushButton("Done", window);
    toDoLayout->addWidget(toDoList);
    toDoLayout->addWidget(doneButton);
    layout->addLayout(toDoLayout);

    // Update the current time label every second
    QTimer *timer = new QTimer(window);
    QObject::connect(timer, &QTimer::timeout, [&]() {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        timeLabel->setText(currentDateTimeString);
    });
    timer->start(1000);

    // Add some items to the to-do list
    toDoList->addItem("Task 1");
    toDoList->addItem("Task 2");
    toDoList->addItem("Task 3");

    // Connect the "Done" button to remove the selected item from the to-do list
    QObject::connect(doneButton, &QPushButton::clicked, [&]() {
        QListWidgetItem *selectedItem = toDoList->currentItem();
        if (selectedItem) {
            toDoList->removeItemWidget(selectedItem);
            delete selectedItem;
        }
    });

    // Show the main window
    window->show();
    return app.exec();
}
