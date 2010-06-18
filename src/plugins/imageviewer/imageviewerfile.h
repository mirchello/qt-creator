/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
** Copyright (c) 2010 Denis Mingulov.
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#ifndef IMAGEVIEWERFILE_H
#define IMAGEVIEWERFILE_H

#include <coreplugin/ifile.h>

#include <QtCore/QScopedPointer>

namespace ImageViewer {
namespace Internal {
class ImageViewer;

class ImageViewerFile : public Core::IFile
{
    Q_OBJECT
public:
    explicit ImageViewerFile(ImageViewer *parent = 0);
    ~ImageViewerFile();

    bool save(const QString &fileName = QString());
    void rename(const QString &newName);
    QString fileName() const;

    QString defaultPath() const;
    QString suggestedFileName() const;
    QString mimeType() const;

    bool isModified() const;
    bool isReadOnly() const;
    bool isSaveAsAllowed() const;

    ReloadBehavior reloadBehavior(ChangeTrigger state, ChangeType type) const;
    void reload(ReloadFlag flag, ChangeType type);

    void setMimetype(const QString &mimetype);
    void setFileName(const QString &filename);

private:
    QScopedPointer<struct ImageViewerFilePrivate> d_ptr;
};

}
}

#endif // IMAGEVIEWERFILE_H
