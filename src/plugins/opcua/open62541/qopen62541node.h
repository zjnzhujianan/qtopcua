/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtOpcUa module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOPEN62541NODE_H
#define QOPEN62541NODE_H

#include "qopen62541client.h"
#include <private/qopcuanodeimpl_p.h>

#include <QPointer>

QT_BEGIN_NAMESPACE

class QOpen62541Node : public QOpcUaNodeImpl
{
public:
    explicit QOpen62541Node(const UA_NodeId nodeId, QOpen62541Client *client, const QString nodeIdString);
    ~QOpen62541Node() override;

    bool readAttributes(QOpcUaNode::NodeAttributes attr) override;
    bool enableMonitoring(QOpcUaNode::NodeAttributes attr, const QOpcUaMonitoringParameters &settings);
    bool disableMonitoring(QOpcUaNode::NodeAttributes attr);
    bool modifyMonitoring(QOpcUaNode::NodeAttribute attr, QOpcUaMonitoringParameters::Parameter item, const QVariant &value);
    QStringList childrenIds() const override;
    QString nodeId() const override;

    bool writeAttribute(QOpcUaNode::NodeAttribute attribute, const QVariant &value, QOpcUa::Types type) override;
    bool writeAttributes(const QOpcUaNode::AttributeMap &toWrite, QOpcUa::Types valueAttributeType) override;
    bool callMethod(const QString &methodNodeId, const QVector<QOpcUa::TypedVariant> &args) override;
    QPair<QString, QString> readEui() const override;
    QPair<double, double> readEuRange() const override;

    UA_NodeId nativeNodeId() const;

private:
    QPointer<QOpen62541Client> m_client;
    QString m_nodeIdString;
    UA_NodeId m_nodeId;
};

QT_END_NAMESPACE

#endif // QOPEN62541NODE_H
