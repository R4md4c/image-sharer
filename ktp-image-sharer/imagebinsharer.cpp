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

#include "imagebinsharer.h"

#include <QDebug>

ImageBinSharer::ImageBinSharer(const QString& contentPath) : AbstractSharer(contentPath)
{
}

KUrl ImageBinSharer::url() const
{
    return KUrl("http://imagebin.ca/upload.php");
}

void ImageBinSharer::parseResponse(const QByteArray& responseData)
{
    //Sample Response String that contains the url
    // "status:1I0zzt2xu949
    // url:http://ibin.co/1I0zzt2xu949

    QString responseString = QString(responseData);
    QString urlPrefix = "url:";
    int urlPrefixIndex = responseString.indexOf(urlPrefix);
    if (urlPrefixIndex != -1) {
        QString imageUrl = responseString.mid(urlPrefixIndex + urlPrefix.length()).trimmed();
        m_imageUrl = KUrl(imageUrl);
    } else {
        m_hasError = true;
        m_errorMessage = responseString.replace("status:error:", "");
    }
}

QByteArray ImageBinSharer::postBody(const QByteArray& imageData)
{
    m_form.addFile("file", m_contentPath, imageData);
    m_form.finish();
    return m_form.formData();
}
