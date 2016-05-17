/*
 MabiMe Character Simulator - by Yai (Sophie N)
 Email: sinoc300@gmail.com
 Copyright (C) 2016

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include "mabimeglwidget.h"
#include "PackReader/packmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void close();
    void show();
private slots:
    void startTimer();
    void cameraChange(CameraInfo camera);
    void on_action_Options_triggered();

    void on_action_Exit_MabiMe_triggered();
    void onLayerCloseButtonClicked(QTreeWidgetItem *i);
    void onLayerVisibilityButtonClicked(QTreeWidgetItem *i);
    void repaintLayers();
    void onLayerItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_b_move_layer_up_clicked();
    void on_b_move_layer_down_clicked();
    void on_s_zoom_sliderMoved(int position);

    void on_s_zoom_valueChanged(int value);

private:
    void insertPMG(QString modelName, QString PMG, QString FRM = "");
    void loadPackages();
    PackManager *p;
    QTreeWidgetItem *selectedLayer;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
