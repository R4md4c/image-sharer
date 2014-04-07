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

#include "abstractsharer.h"

AbstractSharer::AbstractSharer(const QString &contentPath) : m_contentPath(contentPath), m_hasError(false)
{
}

QMap< QString, QString > AbstractSharer::headers() const
{
    QMap<QString, QString> headers;
    headers.insert("content-type", m_form.contentType());
    return headers;
}

QString AbstractSharer::errorMessage() const
{
    return m_errorMessage;
}

bool AbstractSharer::hasError() const
{
    return m_hasError;
}


KUrl AbstractSharer::imageUrl() const
{
    return m_imageUrl;
}


AbstractSharer::~AbstractSharer()
{

}

