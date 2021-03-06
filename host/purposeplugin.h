/*
    Copyright (C) 2019 by Kai Uwe Broulik <kde@privat.broulik.de>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#pragma once

#include "abstractbrowserplugin.h"

#include <QPointer>
#include <QScopedPointer>
#include <QString>
#include <QUrl>

namespace Purpose {
class Menu;
}

class PurposePlugin : public AbstractBrowserPlugin
{
    Q_OBJECT

public:
    explicit PurposePlugin(QObject *parent);
    ~PurposePlugin() override;

    bool onUnload() override;

    using AbstractBrowserPlugin::handleData;
    QJsonObject handleData(int serial, const QString &event, const QJsonObject &data) override;

private:
    void showShareMenu(const QJsonObject &data, const QString &mimeType = QString());

    void sendPendingReply(bool success, const QJsonObject &data);

    QScopedPointer<Purpose::Menu> m_menu;

    int m_pendingReplySerial = -1;
};
