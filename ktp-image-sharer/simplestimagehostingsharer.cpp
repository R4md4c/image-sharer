/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright 2014  Ahmed I. Khalil <ahmedibrahimkhali@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "simplestimagehostingsharer.h"

#include <QDebug>
#include <QRegExp>

SimplestImageHostingSharer::SimplestImageHostingSharer(const QString& contentPath): AbstractSharer(contentPath)
{
}

KUrl SimplestImageHostingSharer::url() const
{
    KUrl url("http://api.simplest-image-hosting.net/upload:image,default");
    return url;
}

void SimplestImageHostingSharer::parseResponse(const QByteArray& responseData)
{
    QString responseString(responseData);
    QRegExp exp("800\n(http://.+)\n");
    if ( exp.indexIn(responseString) != -1) {
        m_imageUrl = responseString.replace("800", "").replace("\n", "");
    } else {
        m_hasError = true;
        m_errorMessage = responseString;
    }
}

QByteArray SimplestImageHostingSharer::postBody(const QByteArray& imageData)
{
    m_form.addFile("fileName", m_contentPath, imageData);
    m_form.finish();

    return m_form.formData();
}
