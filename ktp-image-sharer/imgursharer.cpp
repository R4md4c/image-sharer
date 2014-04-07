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

#include "imgursharer.h"

#include <QString>
#include <KUrl>
#include <QDebug>

#include <qjson/parser.h>
#include <X11/Xproto.h>


// Taken from "share" Data Engine
// key associated with plasma-devel@kde.org
// thanks to Alan Schaaf of Imgur (alan@imgur.com)
static const QString apiKey = QLatin1String("d0757bc2e94a0d4652f28079a0be9379");

ImgurSharer::ImgurSharer(const QString& contentPath): AbstractSharer(contentPath)
{
}


KUrl ImgurSharer::url() const
{
    KUrl url(QLatin1String("https://api.imgur.com/2/upload.json"));
    url.addQueryItem(QLatin1String("key"), apiKey);
    return url;
}

QByteArray ImgurSharer::postBody(const QByteArray &imageData)
{
    // Create the request body
    m_form.addFile("image", m_contentPath, imageData);
    m_form.finish();
    return m_form.formData();
}

void ImgurSharer::parseResponse(const QByteArray& responseData)
{
    qDebug() << responseData;
    QJson::Parser parser;
    bool ok = false;
    QVariantMap resultMap = parser.parse(responseData, &ok).toMap();
    if ( resultMap.contains("error") ) {
        m_hasError = true;
        QVariantMap errorMap = resultMap["error"].toMap();
        m_errorMessage = errorMap["message"].toString();
    } else {
        QVariantMap uploadMap = resultMap["upload"].toMap();
        QVariantMap linksMap = uploadMap["links"].toMap();
        m_imageUrl = KUrl(linksMap["original"].toString());
    }
}
