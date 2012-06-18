/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QVXYMODELMAPPER_H
#define QVXYMODELMAPPER_H

#include <QXYModelMapper>

QTCOMMERCIALCHART_BEGIN_NAMESPACE

class QTCOMMERCIALCHART_EXPORT QVXYModelMapper : public QXYModelMapper
{
    Q_OBJECT
    Q_PROPERTY(int xColumn READ xColumn WRITE setXColumn NOTIFY xColumnChanged)
    Q_PROPERTY(int yColumn READ yColumn WRITE setYColumn NOTIFY yColumnChanged)

public:
    explicit QVXYModelMapper(QObject *parent = 0);
    
    int xColumn() const;
    void setXColumn(int xColumn);

    int yColumn() const;
    void setYColumn(int yColumn);    

Q_SIGNALS:
    void xColumnChanged();
    void yColumnChanged();
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif // QVXYMODELMAPPER_H
