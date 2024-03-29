//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (C) 2009  Sebastian Mach (*1983)
// * mail: phresnel/at/gmail/dot/com
// * http://phresnel.org
// * http://picogen.org
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef QTSUNSKYEDITOR_HH
#define QTSUNSKYEDITOR_HH



#include "kallisto/common.hh"
#include <QWidget>
#include <QImage>
#include <QMouseEvent>
#include "ui_qtsunskyeditor.h"
#include "redshift.hh"



namespace Ui {
        class qtsunskyeditor;
}



class QtSunSkyEditor : public QWidget {
        Q_OBJECT
public:
        QtSunSkyEditor(QWidget *parent = 0);
        ~QtSunSkyEditor();

protected:
        void changeEvent(QEvent *e);
        void resizeEvent (QResizeEvent*);

        void mouseMoveEvent(QMouseEvent*);
        void mousePressEvent(QMouseEvent*);
        void wheelEvent(QWheelEvent*);

private:
        void redraw(bool drawCross=false, float crossU=0, float crossV=0);
        void updatePreethamSettings();


        struct rgbf {
                rgbf(){}
                rgbf(float r, float g, float b) : r(r), g(g), b(b) {}
                float r,g,b;
        };
        rgbf computeColor (float u, float v) const;

        redshift::optional<redshift::Vector>
                screenToHemisphere (float u, float v) const;
        redshift::Vector screenToHemisphereSat (float u, float v) const;


        Ui::qtsunskyeditor *ui;
        redshift::background::Preetham preetham;

private slots:
        void on_previewResolution_valueChanged(int );
        void on_turbiditySpinBox_valueChanged(double );
        void on_turbidityDial_valueChanged(int position);
        void on_sunIntensitySpinBox_valueChanged(double );
        void on_sunIntensityDial_valueChanged(int position);
        void on_atmosphereIntensitySpinBox_valueChanged(double );
        void on_atmosphereIntensityDial_valueChanged(int position);
};

#endif // QTSUNSKYEDITOR_HH
